#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/entities/player.h"
#include "../include/maps/mapa1.h"
#include "../include/maps/mapa2.h"
#include "../include/maps/mapa3.h"
#include "../include/utils/utils.h"
#include "gemini.h"
#include "chart.h"
#include <string.h>
#include "../include/utils/constants.h"


#define NOTE_SPEED 400.0f
#define NOTE_WIDTH 80
#define NOTE_HEIGHT 20
#define NUM_LANES 5
#define HIT_WINDOW 0.15f // Seconds
#define COMBO_FADE_TIME 1.0f
#define MAX_NOTES 500
#define MAX_CHART_NOTES 1000
#define MAX_SONGS 5
// Define the note highway dimensions (1/3 of screen width centered)
#define HIGHWAY_WIDTH (SCREEN_WIDTH / 3)
#define HIGHWAY_LEFT ((SCREEN_WIDTH - HIGHWAY_WIDTH) / 2)
#define LANE_WIDTH (HIGHWAY_WIDTH / NUM_LANES)
// Adjust target position
#define TARGET_Y (SCREEN_HEIGHT - 200)
// Make rock meter more forgiving
#define ROCK_METER_HIT_GAIN 0.1f  // Increased from 0.083f
#define ROCK_METER_MISS_PENALTY 0.15f  // Reduced from 0.25f

typedef struct {
    int score;
    int combo;
    int maxCombo;
    int hits[4]; // 0=Perfect, 1=Great, 2=Good, 3=OK
    int misses;
    float streakFxTimer;
    float starPower;
    bool starPowerActive;
    float starPowerTimer;
    float multiplier;
    int multiplierLevel;
    int streakBonus;
    float rockMeter; // New: Rock Meter value (0.0 to 1.0)
    bool songFailed; // New: Track if player failed the song
} GameStats;

typedef struct {
    char title[50];
    char artist[50];
    Note charts[200];
    char musicFile[100];
    Texture2D albumArt;
    float duration;
    int difficulty;
} Song;

typedef enum {
    MAIN_MENU,
    SONG_SELECT,
    PLAYING,
    MAPAS,
    RESULTS
} GameState;

typedef enum {
    MAPA1,
    MAPA2,
    MAPA3
} CurrentMap; // Enum para controlar o mapa atual

Song songs[MAX_SONGS] = {
        {"Skyfall", "Adele", {0}, "assets/musics/skyfall.mp3", (Texture2D){0}, 283.0f, 3},
        {"Thunderstruck", "AC/DC", {0}, "assets/musics/thunderstruck.mp3", (Texture2D){0}, 292.0f, 4},
        {"Sweet Child O'Mine", "Guns N' Roses", {0}, "assets/musics/sweet_child.mp3", (Texture2D){0}, 356.0f, 3},
        {"Smoke on the Water", "Deep Purple", {0}, "assets/musics/smoke.mp3", (Texture2D){0}, 340.0f, 2},
        {"Enter Sandman", "Metallica", {0}, "assets/musics/sandman.mp3", (Texture2D){0}, 331.0f, 4}
};

void initSongs() {
    memcpy(songs[0].charts, skyfallChart, sizeof(skyfallChart));
}

float Lerp2(float start, float end, float amount) {
    return start + amount * (end - start);
}

int Clamp2(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

void DrawRockMeter(float value, int x, int y, int width, int height) {
    // Draw meter background
    DrawRectangle(x, y, width, height, (Color){20, 20, 20, 255});

    // Calculate the fill width based on the rock meter value
    float fillWidth = width * value;

    // Draw the fill with gradient based on value
    if (value < 0.25f) {
        // Red zone - danger
        DrawRectangleGradientH(x, y, fillWidth, height, RED, (Color){255, 100, 0, 255});
    } else if (value < 0.5f) {
        // Yellow zone - warning
        DrawRectangleGradientH(x, y, fillWidth, height, (Color){255, 100, 0, 255}, YELLOW);
    } else {
        // Green zone - safe
        DrawRectangleGradientH(x, y, fillWidth, height, YELLOW, GREEN);
    }

    // Draw outline
    DrawRectangleLines(x, y, width, height, WHITE);

    // Draw marker for fail threshold (25%)
    DrawLine(x + width * 0.25f, y, x + width * 0.25f, y + height, WHITE);
}

int main(void) {
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ROCK HERO");
    InitAudioDevice();
    initSongs();
    SetTargetFPS(60);

    // Get actual screen size after going fullscreen
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    // Load resources
    Sound noteMissSound = LoadSound("assets/sounds/miss.wav");
    SetSoundVolume(noteMissSound, 0.3f);
    Sound starPowerSound = LoadSound("assets/sounds/starpower.wav");
    Sound menuSelectSound = LoadSound("assets/sounds/select.wav");
    Sound menuScrollSound = LoadSound("assets/sounds/scroll.wav");

    // Load fonts
    Font titleFont = LoadFontEx("assets/font/Vampire Wars.ttf", 72, 0, 0);
    Font mainFont = LoadFontEx("assets/font/Vampire Wars.ttf", 36, 0, 0);

    // Game state
    Note notes[MAX_NOTES] = {0};
    GameStats stats = {0};
    float musicPosition = 0;
    GameState gameState = MAIN_MENU;
    bool keysPressed[NUM_LANES] = {false};
    bool keysDown[NUM_LANES] = {false};
    int nextChartNote = 0;
    int activeNoteCount = 0;
    int selectedSong = 0;
    float scrollOffset = 0.0f;
    float scrollSpeed = 0.0f;
    Music gameMusic = {0};
    Note* currentChart = NULL;

    // Colors
    Color laneColors[NUM_LANES] = {
            (Color){255, 50, 50, 255},    // Red
            (Color){255, 150, 50, 255},   // Orange
            (Color){50, 255, 50, 255},   // Green
            (Color){50, 150, 255, 255},  // Blue
            (Color){200, 50, 255, 255}   // Purple
    };

    Color laneColorsDark[NUM_LANES] = {
            (Color){150, 0, 0, 255},      // Dark Red
            (Color){150, 75, 0, 255},     // Dark Orange
            (Color){0, 150, 0, 255},      // Dark Green
            (Color){0, 75, 150, 255},     // Dark Blue
            (Color){100, 0, 150, 255}     // Dark Purple
    };

    Color hitColors[4] = {
            (Color){255, 255, 100, 255},  // Perfect - Yellow
            (Color){100, 255, 100, 255},  // Great - Green
            (Color){100, 100, 255, 255},  // Good - Blue
            (Color){255, 100, 100, 255}  // OK - Red
    };

    // Key bindings
    int laneKeys[NUM_LANES] = {KEY_A, KEY_S, KEY_J, KEY_K, KEY_L};

    Player player;
    InitPlayer(&player);
    player.frozen = false;

    MapData map1;
    InitMap1(&map1);  // Mapa 1 carregado inicialmente

    MapData map2;
    InitMap2(&map2); // Mapa 2 carregado

    MapData map3;
    InitMap3(&map3); // Mapa 3 carregado

    CurrentMap currentMap = MAPA1; // Começa com o mapa 1

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        // Update music stream if playing
        if (gameState == PLAYING) {
            UpdateMusicStream(gameMusic);
            musicPosition = GetMusicTimePlayed(gameMusic);

            // Check if song ended (fixed bug by using musicPosition >= duration)
            if (musicPosition >= songs[selectedSong].duration) {
                gameState = RESULTS;
            }

            // Check if player failed (rock meter in red zone)
            if (stats.rockMeter <= 0.166f && !stats.songFailed) {
                stats.songFailed = true;
                gameState = RESULTS;
            }
        }

        // Update scrolling for song select
        if (gameState == SONG_SELECT) {
            if (IsKeyPressed(KEY_DOWN) && selectedSong < MAX_SONGS - 1) {
                selectedSong++;
                PlaySound(menuScrollSound);
                scrollSpeed = 100.0f;
            }
            if (IsKeyPressed(KEY_UP) && selectedSong > 0) {
                selectedSong--;
                PlaySound(menuScrollSound);
                scrollSpeed = -100.0f;
            }

            // Smooth scrolling
            scrollOffset += scrollSpeed * deltaTime;
            scrollSpeed *= 0.9f;
            if (fabs(scrollSpeed) < 1.0f) scrollSpeed = 0.0f;
        }

        if (gameState == MAPAS) {
            // Verifica se a tecla "G" foi pressionada para alternar entre os mapas
            if (IsKeyPressed(KEY_G)) {
                if (currentMap == MAPA1) {
                    currentMap = MAPA2;
                } else if (currentMap == MAPA2) {
                    currentMap = MAPA3;
                } else {
                    currentMap = MAPA1;
                }
            }
        }

        switch (gameState) {
            case MAIN_MENU: {
                if (IsKeyPressed(KEY_ENTER)) {
                    PlaySound(menuSelectSound);
                    gameState = MAPAS;
                }
                if (IsKeyPressed(KEY_ESCAPE)) {
                    break; // Exit game
                }
            } break;

            case SONG_SELECT: {
                if (IsKeyPressed(KEY_ENTER)) {
                    PlaySound(menuSelectSound);

                    // Load selected song
                    UnloadMusicStream(gameMusic);
                    gameMusic = LoadMusicStream(songs[selectedSong].musicFile);

                    // Set up chart (in a real game, you'd load this from file)
                    currentChart = skyfallChart;

                    // Reset game state
                    memset(notes, 0, sizeof(notes));
                    memset(&stats, 0, sizeof(stats));
                    stats.multiplier = 1.0f;
                    stats.multiplierLevel = 1;
                    stats.rockMeter = 0.5f; // Start in middle
                    stats.songFailed = false;
                    nextChartNote = 0;
                    activeNoteCount = 0;

                    // Start music
                    PlayMusicStream(gameMusic);
                    SeekMusicStream(gameMusic, 0);
                    gameState = PLAYING;
                }
                if (IsKeyPressed(KEY_ESCAPE)) {
                    PlaySound(menuSelectSound);
                    gameState = MAIN_MENU;
                }
            } break;

            case PLAYING: {
                // Spawn notes from chart
                while (nextChartNote < MAX_CHART_NOTES &&
                       currentChart[nextChartNote].lane != -1 &&
                       currentChart[nextChartNote].spawnTime <= musicPosition) {

                    for (int i = 0; i < MAX_NOTES; i++) {
                        if (!notes[i].active) {
                            notes[i] = currentChart[nextChartNote];
                            notes[i].active = true;
                            notes[i].rect = (Rectangle){
                                    HIGHWAY_LEFT + notes[i].lane * LANE_WIDTH + (LANE_WIDTH - NOTE_WIDTH)/2,
                                    -NOTE_HEIGHT,
                                    NOTE_WIDTH,
                                    NOTE_HEIGHT
                            };
                            notes[i].color = laneColors[notes[i].lane];
                            notes[i].hit = false;
                            activeNoteCount++;
                            break;
                        }
                    }
                    nextChartNote++;
                }

                // Update active notes
                for (int i = 0; i < MAX_NOTES; i++) {
                    if (notes[i].active) {
                        // Move note
                        float timeSinceSpawn = musicPosition - notes[i].spawnTime;
                        notes[i].rect.y = timeSinceSpawn * NOTE_SPEED - NOTE_HEIGHT;

                        // Check if note passed hit window without being hit
                        if (notes[i].rect.y > TARGET_Y + 50 && !notes[i].hit) {
                            notes[i].active = false;
                            activeNoteCount--;
                            stats.misses++;
                            stats.combo = 0;
                            stats.multiplier = 1.0f;
                            stats.multiplierLevel = 1;
                            stats.starPower = fmaxf(0, stats.starPower - 1.0f);

                            // Update rock meter (miss moves it left by 3 steps)
                            stats.rockMeter = fmaxf(0, stats.rockMeter - 0.25f);

                            PlaySound(noteMissSound);
                        }
                    }
                }

                // Update effects
                if (stats.streakFxTimer > 0) stats.streakFxTimer -= deltaTime;
                if (stats.starPowerActive && (stats.starPowerTimer -= deltaTime) <= 0) {
                    stats.starPowerActive = false;
                }

                // Update multiplier
                if (stats.combo >= 30) {
                    stats.multiplierLevel = 4;
                    stats.multiplier = 4.0f;
                } else if (stats.combo >= 20) {
                    stats.multiplierLevel = 3;
                    stats.multiplier = 3.0f;
                } else if (stats.combo >= 10) {
                    stats.multiplierLevel = 2;
                    stats.multiplier = 2.0f;
                } else {
                    stats.multiplierLevel = 1;
                    stats.multiplier = 1.0f;
                }

                for (int lane = 0; lane < NUM_LANES; lane++) {
                    keysPressed[lane] = IsKeyPressed(laneKeys[lane]);
                    keysDown[lane] = IsKeyDown(laneKeys[lane]);

                    if (keysPressed[lane] && keysDown[lane]) {
                        bool hit = false;

                        // Check for notes to hit
                        for (int i = 0; i < MAX_NOTES; i++) {
                            if (notes[i].active && notes[i].lane == lane && !notes[i].hit) {
                                float notePos = notes[i].rect.y + notes[i].rect.height;
                                float hitDiff = fabs(notePos - TARGET_Y);
                                float hitWindowPixels = HIT_WINDOW * NOTE_SPEED;

                                if (hitDiff <= hitWindowPixels) {
                                    // Determine hit quality
                                    int hitQuality;
                                    if (hitDiff < hitWindowPixels * 0.2f) hitQuality = 0; // Perfect
                                    else if (hitDiff < hitWindowPixels * 0.4f) hitQuality = 1; // Great
                                    else if (hitDiff < hitWindowPixels * 0.6f) hitQuality = 2; // Good
                                    else hitQuality = 3; // OK

                                    // Register hit
                                    notes[i].hit = true;
                                    stats.hits[hitQuality]++;
                                    stats.combo++;
                                    if (stats.combo > stats.maxCombo) stats.maxCombo = stats.combo;

                                    // Calculate score
                                    int baseScore = 50 * (4 - hitQuality);
                                    if (stats.starPowerActive) baseScore *= 2;
                                    stats.score += baseScore * stats.multiplier;
                                    stats.streakBonus += baseScore / 10;
                                    stats.starPower += 0.5f;

                                    // Update rock meter (hit moves it right by 1 step)
                                    stats.rockMeter = fminf(1.0f, stats.rockMeter + ROCK_METER_HIT_GAIN);

                                    if (stats.starPower >= 10.0f && !stats.starPowerActive) {
                                        stats.starPowerActive = true;
                                        stats.starPowerTimer = 5.0f;
                                        stats.starPower = 0;
                                        PlaySound(starPowerSound);
                                    }

                                    // Clean up note
                                    notes[i].active = false;
                                    activeNoteCount--;

                                    // Add effects
                                    stats.streakFxTimer = COMBO_FADE_TIME;

                                    hit = true;
                                    break;
                                }
                            }
                        }

                        // Penalize for missed notes
                        if (!hit) {
                            stats.score = fmaxf(0, stats.score - 50);
                            stats.misses++;
                            stats.combo = 0;
                            stats.multiplier = 1.0f;
                            stats.multiplierLevel = 1;
                            stats.starPower = fmaxf(0, stats.starPower - 1.0f);

                            // Update rock meter (miss moves it left by 3 steps)
                            stats.rockMeter = fmaxf(0, stats.rockMeter - ROCK_METER_MISS_PENALTY);

                            PlaySound(noteMissSound);
                        }
                    }
                }
            } break;

            case MAPAS: {
                // Atualiza o mapa atual
                if (currentMap == MAPA1) {
                    UpdateMap1(&map1, &player);  // Atualiza o mapa 1
                } else if (currentMap == MAPA2) {
                    UpdateMap2(&map2, &player); // Atualiza o mapa 2
                } else {
                    UpdateMap3(&map3, &player); // Atualiza o mapa 3
                }
            } break;

            case RESULTS: {
                if (IsKeyPressed(KEY_ENTER)) {
                    gameState = MAIN_MENU;
                }
            } break;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        switch (gameState) {
            case MAIN_MENU: {
                // Draw animated background
                for (int i = 0; i < 50; i++) {
                    float x = sin(GetTime() + i) * 100 + screenWidth/2;
                    float y = cos(GetTime() * 0.5f + i) * 100 + screenHeight/2;
                    DrawCircle(x, y, 2, Fade(laneColors[i%NUM_LANES], 0.5f));
                }

                // Draw title
                const char *titleText = "ROCK HERO";
                Vector2 titleSize = MeasureTextEx(titleFont, titleText, 72, 0);
                Vector2 titlePos = {screenWidth/2 - titleSize.x/2, 150};
                DrawTextEx(titleFont, titleText, titlePos, 72, 0, WHITE);

                // Draw menu options
                const char *playText = "PLAY";
                Vector2 playSize = MeasureTextEx(mainFont, playText, 36, 0);
                Vector2 playPos = {screenWidth/2 - playSize.x/2, 350};
                DrawTextEx(mainFont, playText, playPos, 36, 0, WHITE);

                // Draw instructions
                const char *instructionText = "Press ENTER to select";
                int instructionWidth = MeasureText(instructionText, 20);
                DrawText(instructionText, screenWidth/2 - instructionWidth/2, screenHeight - 100, 20, GRAY);
            } break;

            case SONG_SELECT: {
                // Draw background
                DrawRectangleGradientV(0, 0, screenWidth, screenHeight, (Color){20, 20, 40, 255}, (Color){10, 10, 20, 255});

                // Draw title
                DrawTextEx(titleFont, "SELECT SONG", (Vector2){screenWidth/2 - MeasureTextEx(titleFont, "SELECT SONG", 60, 0).x/2, 50}, 60, 0, WHITE);

                // Draw song list
                int startY = 150 - scrollOffset;
                for (int i = 0; i < MAX_SONGS; i++) {
                    float yPos = startY + i * 100;

                    // Only draw if visible
                    if (yPos > -100 && yPos < screenHeight) {
                        // Background for selected song
                        if (i == selectedSong) {
                            DrawRectangle(screenWidth/2 - 300, yPos, 600, 80, (Color){50, 50, 80, 255});
                        }

                        // Song info
                        DrawTextEx(mainFont, TextFormat("%s - %s", songs[i].artist, songs[i].title),
                                   (Vector2){screenWidth/2 - 280, yPos + 20}, 24, 0, WHITE);

                        // Difficulty stars
                        for (int j = 0; j < 5; j++) {
                            DrawCircle(screenWidth/2 + 200 + j * 20, yPos + 40, 5,
                                       j < songs[i].difficulty ? YELLOW : (Color){50, 50, 50, 255});
                        }
                    }
                }

                // Draw instructions
                DrawText("Press ENTER to play", screenWidth/2 - MeasureText("Press ENTER to play", 20)/2, screenHeight - 50, 20, GRAY);
                DrawText("UP/DOWN to select song", 50, screenHeight - 50, 20, GRAY);
            } break;

            case PLAYING: {
                // Draw dark background
                ClearBackground((Color){10, 10, 20, 255});

                // Draw highway background (dark gray)
                DrawRectangle(HIGHWAY_LEFT, 0, HIGHWAY_WIDTH, screenHeight, (Color){30, 30, 40, 255});

                // Draw lane dividers
                for (int i = 1; i < NUM_LANES; i++) {
                    DrawLine(HIGHWAY_LEFT + i * LANE_WIDTH, 0,
                             HIGHWAY_LEFT + i * LANE_WIDTH, screenHeight,
                             Fade(WHITE, 0.2f));
                }

                // Draw lane highlights when keys are pressed
                for (int i = 0; i < NUM_LANES; i++) {
                    if (keysDown[i]) {
                        DrawRectangle(HIGHWAY_LEFT + i * LANE_WIDTH, 0,
                                      LANE_WIDTH, screenHeight,
                                      Fade(laneColors[i], 0.1f));
                    }
                }

                // Draw fret board at bottom (simplified)
                for (int i = 0; i < NUM_LANES; i++) {
                    Rectangle fretRect = {
                            HIGHWAY_LEFT + i * LANE_WIDTH,
                            TARGET_Y - HIT_WINDOW,
                            LANE_WIDTH,
                            40
                    };
                    Color fretColor = keysDown[i] ? laneColors[i] : laneColorsDark[i];
                    DrawRectangleRounded(fretRect, 0.0f, 5, fretColor);
                }

                // Draw target line with simple design
                DrawRectangle(HIGHWAY_LEFT, TARGET_Y - 2, HIGHWAY_WIDTH, 2, WHITE);

                // Draw notes
                for (int i = 0; i < MAX_NOTES; i++) {
                    if (notes[i].active) {
                        // Note body
                        DrawRectangleRec(notes[i].rect, notes[i].color);
                    }
                }


                // Draw star power meter with improved visuals (top left)
                if (stats.starPower < 10.0f) {
                    DrawRectangle(20, 20, 200, 20, Fade(DARKGRAY, 0.7f));
                    DrawRectangle(20, 20, 200 * (stats.starPower / 10.0f), 20, Fade(SKYBLUE, 0.7f));
                    DrawRectangleLines(20, 20, 200, 20, WHITE);
                    DrawTextEx(mainFont, "STAR POWER", (Vector2){20, 45}, 15, 2, WHITE);
                } else {
                    // Flash when ready
                    float flash = sin(GetTime() * 10) * 0.5f + 0.5f;
                    DrawTextEx(mainFont, "STAR POWER READY!", (Vector2){20, 45}, 15, 2, (Color){255, 255, 0, (unsigned char)(flash * 255)});
                }

                // Star power effect
                if (stats.starPowerActive) {
                    DrawRectangle(0, 0, screenWidth, screenHeight, Fade(SKYBLUE, 0.1f));

                    // Draw star particles
                    for (int i = 0; i < 20; i++) {
                        float x = sin(GetTime() * 2 + i) * 100 + screenWidth/2;
                        float y = cos(GetTime() * 3 + i) * 100 + screenHeight/2;
                        DrawCircle(x, y, 3, Fade(YELLOW, 0.5f));
                    }
                }

                // Combo effect with improved visuals
                if (stats.streakFxTimer > 0 && stats.combo >= 10) {
                    float alpha = stats.streakFxTimer / COMBO_FADE_TIME * 255;
                    char comboText[20];
                    sprintf(comboText, "%d COMBO!", stats.combo);

                    // Scale effect
                    float scale = 1.0f + (1.0f - stats.streakFxTimer / COMBO_FADE_TIME) * 0.5f;

                    // Draw text with outline
                    int fontSize = 30 + (int)(10 * (1.0f - stats.streakFxTimer / COMBO_FADE_TIME));
                    Color textColor = (Color){255, 255, 255, (unsigned char)alpha};
                    Color outlineColor = (Color){0, 0, 0, (unsigned char)(alpha * 0.7f)};

                    Vector2 textPos = {screenWidth/2 - MeasureText(comboText, fontSize)/2, screenHeight/2 - 100};

                    // Draw outline
                    for (int i = -2; i <= 2; i++) {
                        for (int j = -2; j <= 2; j++) {
                            if (i != 0 || j != 0) {
                                DrawTextEx(mainFont, comboText, (Vector2){textPos.x + i, textPos.y + j}, fontSize, 2, outlineColor);
                            }
                        }
                    }

                    // Draw main text
                    DrawTextEx(mainFont, comboText, textPos, fontSize, 2, textColor);
                }

                // Draw HUD - Simplified like Guitar Hero (top right)

                // Score display
                DrawTextEx(mainFont, TextFormat("%08d", stats.score), (Vector2){screenWidth - 220, 20}, 30, 2, WHITE);

                // Multiplier
                DrawTextEx(mainFont, TextFormat(" x%d", stats.multiplierLevel), (Vector2){screenWidth - 80, 20}, 30, 2,
                           stats.multiplierLevel >= 4 ? YELLOW : WHITE);

                // Rock Meter (bottom right)
                DrawRockMeter(stats.rockMeter, screenWidth - 220, screenHeight - 100, 200, 20);
                DrawTextEx(mainFont, "ROCK METER", (Vector2){screenWidth - 220, screenHeight - 120}, 15, 2, WHITE);

            } break;

            case MAPAS: {
                // Desenha o mapa atual
                if (currentMap == MAPA1) {
                    DrawMap1(&map1, &player);  // Desenha o mapa 1
                } else if (currentMap == MAPA2) {
                    DrawMap2(&map2, &player); // Desenha o mapa 2
                } else {
                    DrawMap3(&map3, &player); // Desenha o mapa 3
                }

                // Desenha o player
                DrawPlayer(&player);

                // Informação de posição
                DrawText(TextFormat("Posição Player: (%.0f, %.0f)", player.position.x, player.position.y),
                         10, 10, 20, DARKGRAY);
                DrawText("Use as setas para mover", 10, 40, 20, DARKGRAY);

                // Texto informativo sobre o mapa atual
                if (currentMap == MAPA1) {
                    DrawText("Mapa 1 Carregado", 10, 70, 20, GREEN);
                } else if (currentMap == MAPA2) {
                    DrawText("Mapa 2 Carregado", 10, 70, 20, GREEN);
                } else {
                    DrawText("Mapa 3 Carregado", 10, 70, 20, GREEN);
                }
            } break;

            case RESULTS: {
                // Draw results screen background
                DrawRectangleGradientV(0, 0, screenWidth, screenHeight, (Color){30, 10, 40, 255}, (Color){10, 10, 20, 255});

                // Calculate accuracy
                int totalHits = stats.hits[0] + stats.hits[1] + stats.hits[2] + stats.hits[3];
                int totalNotes = totalHits + stats.misses;
                float accuracy = totalNotes > 0 ? (totalHits * 100.0f) / totalNotes : 100.0f;

                // Determine rating
                const char* rating;
                Color ratingColor;
                if (stats.songFailed) {
                    rating = "FAILED!";
                    ratingColor = RED;
                } else if (accuracy >= 95.0f) {
                    rating = "5 STARS!";
                    ratingColor = GOLD;
                } else if (accuracy >= 90.0f) {
                    rating = "4 STARS";
                    ratingColor = ORANGE;
                } else if (accuracy >= 80.0f) {
                    rating = "3 STARS";
                    ratingColor = YELLOW;
                } else if (accuracy >= 70.0f) {
                    rating = "2 STARS";
                    ratingColor = WHITE;
                } else {
                    rating = "1 STAR";
                    ratingColor = GRAY;
                }

                // Draw title
                DrawTextEx(titleFont, stats.songFailed ? "SONG FAILED!" : "SONG COMPLETE!",
                           (Vector2){screenWidth/2 - MeasureTextEx(titleFont, stats.songFailed ? "SONG FAILED!" : "SONG COMPLETE!", 60, 0).x/2, 80},
                           60, 0, WHITE);

                // Draw rating
                DrawTextEx(titleFont, rating,
                           (Vector2){screenWidth/2 - MeasureTextEx(titleFont, rating, 50, 0).x/2, 150},
                           50, 0, ratingColor);

                // Draw stats
                int startY = 250;
                int spacing = 40;

                DrawTextEx(mainFont, TextFormat("FINAL SCORE: %08d", stats.score),
                           (Vector2){screenWidth/2 - 250, (float)startY}, 30, 0, WHITE);
                startY += spacing;

                DrawTextEx(mainFont, TextFormat("ACCURACY: %.2f%%", accuracy),
                           (Vector2){screenWidth/2 - 250, (float)startY}, 30, 0, WHITE);
                startY += spacing;

                DrawTextEx(mainFont, TextFormat("MAX COMBO: %d", stats.maxCombo),
                           (Vector2){screenWidth/2 - 250, (float)startY}, 30, 0, WHITE);
                startY += spacing;

                DrawTextEx(mainFont, TextFormat("PERFECT: %d", stats.hits[0]),
                           (Vector2){screenWidth/2 - 250, (float)startY}, 30, 0, hitColors[0]);
                startY += spacing;

                DrawTextEx(mainFont, TextFormat("GREAT: %d", stats.hits[1]),
                           (Vector2){screenWidth/2 - 250, (float)startY}, 30, 0, hitColors[1]);
                startY += spacing;

                DrawTextEx(mainFont, TextFormat("GOOD: %d", stats.hits[2]),
                           (Vector2){screenWidth/2 - 250, (float)startY}, 30, 0, hitColors[2]);
                startY += spacing;

                DrawTextEx(mainFont, TextFormat("OK: %d", stats.hits[3]),
                           (Vector2){screenWidth/2 - 250, (float)startY}, 30, 0, hitColors[3]);
                startY += spacing;

                DrawTextEx(mainFont, TextFormat("MISS: %d", stats.misses),
                           (Vector2){screenWidth/2 - 250, (float)startY}, 30, 0, RED);

                // Draw continue prompt
                DrawText("Press ENTER to Continue", screenWidth/2 - MeasureText("Press ENTER to Continue", 20)/2,
                         screenHeight - 50, 20, GRAY);
            } break;
        }



        EndDrawing();
    }

    // Limpeza dos recursos
    UnloadTexture(player.spriteSheet);
    UnloadSound(noteMissSound);
    UnloadSound(starPowerSound);
    UnloadSound(menuSelectSound);
    UnloadSound(menuScrollSound);
    UnloadMusicStream(gameMusic);
    UnloadFont(titleFont);
    UnloadFont(mainFont);
    if (currentMap == MAPA1) {
        UnloadTexture(map1.npc.spriteSheet);
        if (map1.background.id != 0) UnloadTexture(map1.background);
        UnloadSound(map1.typeSound);
    } else if (currentMap == MAPA2) {
        UnloadTexture(map2.npc.spriteSheet);
        if (map2.background.id != 0) UnloadTexture(map2.background);
        UnloadSound(map2.typeSound);
    } else {
        UnloadTexture(map3.npc.spriteSheet);
        if (map3.background.id != 0) UnloadTexture(map3.background);
        UnloadSound(map3.typeSound);
    }
    CloseAudioDevice();

    CloseWindow();

    return 0;
}
