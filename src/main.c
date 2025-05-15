#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/entities/player.h"
#include "../include/maps/mapa.h"
#include "../include/maps/mapa1.h"
#include "../include/maps/mapa2.h"
#include "../include/maps/mapa3.h"
#include "../include/utils/utils.h"
#include "gemini.h"
#include "chart.h"
#include <string.h>
#include "../include/utils/constants.h"

#define NOTE_SPEED 500.0f
#define NOTE_WIDTH 125
#define NOTE_HEIGHT 40
#define NUM_LANES 5
#define HIT_WINDOW 0.15f // Seconds
#define COMBO_FADE_TIME 1.0f
#define MAX_NOTES 500
#define MAX_CHART_NOTES 1000
#define MAX_SONGS 11
// Define the note highway dimensions (1/3 of screen width centered)
#define HIGHWAY_WIDTH (SCREEN_WIDTH / 3)
#define HIGHWAY_LEFT ((SCREEN_WIDTH - HIGHWAY_WIDTH) / 2)
#define LANE_WIDTH (HIGHWAY_WIDTH / NUM_LANES)
// Adjust target position
#define TARGET_Y (SCREEN_HEIGHT - 200)
// Make rock meter more forgiving
#define ROCK_METER_HIT_GAIN 0.05f
#define ROCK_METER_MISS_PENALTY 0.1f
// FIRE effect
#define MAX_HIT_EFFECTS 20
#define HIT_EFFECT_DURATION 0.15f
// Adicione no início do arquivo, com as outras constantes
#define MAX_BLESSINGS 6

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
    int forgivenessMisses;  // Contador de misses ignorados
    int perfectStreak;      // Contador de Perfects consecutivos
    int rhythmShields;      // Contador de escudos sonoros
    float comboMultiplier;  // Multiplicador extra do Combo Eterno
} GameStats;

typedef struct {
    char title[50];
    char artist[50];
    Note charts[500];
    char musicFile[100];
    float duration;
    int difficulty;
} Song;

typedef struct {
    int lane;
    float timer;
    bool active;
    bool isStart; // Se é a animação inicial (burning_start) ou final (burning_end)
} HitEffect;

typedef enum {
    MAIN_MENU,
    SONG_SELECT,
    PLAYING,
    MAPAS,
    RESULTS,
    CHALLENGE,
    BLESS
} GameState;

typedef enum {
    MENU_STORY,
    MENU_QUICKPLAY,
    MENU_CONTROLS,
    MENU_CREDITS,
    MENU_EXIT
} MenuOption;

typedef enum {
    MAPA1,
    MAPA2,
    MAPA3
} CurrentMap; // Enum para controlar o mapa atual

Song songs[MAX_SONGS] = {
    {"Thunderstruck", "AC/DC", {}, "assets/musics/thunderstruck.mp3", 5.0f, 4},
    {"Sweet Child O'Mine", "Guns N' Roses", {}, "assets/musics/sweet_child.mp3", 356.0f, 3},
    {"In The End", "Linkin Park", {}, "assets/musics/in_the_end.mp3", 216.0f, 3},
    {"Killer Queen", "Queen", {}, "assets/musics/killer_queen.mp3", 179.0f, 1},
    {"Smells Like Teen Spirit", "Nirvana", {}, "assets/musics/teen_spirit.mp3", 301.0f, 3},
    {"Enter Sandman", "Metallica", {}, "assets/musics/sandman.mp3", 331.0f, 4},
    {"Paranoid", "Black Sabbath", {}, "assets/musics/paranoid.mp3", 171.0f, 3},
    {"The Trooper", "Iron Maiden", {}, "assets/musics/the_trooper.mp3", 243.0f, 5},
    {"Livin' on a Prayer", "Bon Jovi", {}, "assets/musics/livin_prayer.mp3", 250.0f, 2},
    {"Dream On", "Aerosmith", {}, "assets/musics/dream_on.mp3", 270.0f, 3},
    {"Toxicity", "System of a Down", {}, "assets/musics/toxicity.mp3", 214.0f, 4}
};

HitEffect hitEffects[MAX_HIT_EFFECTS];
Texture2D burningStartTex;
Texture2D burningEndTex;

bool inBlessingSelection = false;
int selectedOption = 0;
int currentMilestone = 0;
RockBlessing blessingOptions[2]; // Para armazenar as opções de bênção
bool blessingOptionsInitialized = false;
float deltaTime; // Adicione esta linha para ter acesso ao deltaTime

void initSongs();

// Inicializa o sistema de fama
void InitFameSystem(Player* player);

void DrawRockMeter(float value, int x, int y, int width, int height);

// Desenha a barra de fama
void DrawFameMeter(Player* player, int screenWidth, Font font);

void DrawControlsScreen(int screenWidth, int screenHeight, Font titleFont, Font mainFont);

void DrawCreditsScreen(int screenWidth, int screenHeight, Font titleFont, Font mainFont);

void DrawHitEffects();

void SpawnHitEffect(int lane);

void CheckForMilestone(Player* player);

void UpdateHitEffects(float deltaTime);

// Aplica os efeitos das bênçãos ativas
void ApplyBlessings(Player* player, GameStats* stats, float deltaTime);

// Verifica se a música é a favorita do público no mapa atual
bool IsFavoriteSong(int songIndex, int mapLevel);

bool HasBlessing(Player* player, RockBlessing blessing);

void SpawnShieldEffect();

void SpawnComboEffect(int combo);

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

    burningStartTex = LoadTexture("assets/sprites/burning_start_1.png");
	burningEndTex = LoadTexture("assets/sprites/burning_end_1.png");

    for (int i = 0; i < MAX_HIT_EFFECTS; i++) {
        hitEffects[i].active = false;
    }

    // Game state
    MenuOption currentMenuOption = MENU_STORY;
    bool inSubMenu = false;
    bool instory = false;
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

    MapNode* mapList = NULL;
    MapNode* currentMap = NULL;
    mapList = CreateMapList();
    currentMap = mapList; // Começa no mapa 1

    while (!WindowShouldClose()) {
        deltaTime = GetFrameTime();

        // Update music stream if playing
        if (gameState == PLAYING) {
            UpdateMusicStream(gameMusic);
            UpdateHitEffects(deltaTime);
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
            // Handle selection change
            if (IsKeyPressed(KEY_DOWN) && selectedSong < MAX_SONGS - 1) {
                selectedSong++;
                PlaySound(menuScrollSound);
                scrollSpeed = 220.0f;
            }
            if (IsKeyPressed(KEY_UP) && selectedSong > 0) {
                selectedSong--;
                PlaySound(menuScrollSound);
                scrollSpeed = -220.0f;
            }

            // Smooth scroll
            scrollOffset += scrollSpeed * deltaTime;
            scrollSpeed *= 0.9f;

            // Snap to correct position when almost stopped
            if (fabs(scrollSpeed) < 1.0f) {
                scrollSpeed = 0.0f;
                scrollOffset = selectedSong * 37.5; // Ajusta para a posição exata
            }
        }

        if (gameState == MAPAS) {

            if (currentMap->mapId == 1){
                float distance2 = fabs(790 - (player.position.x + FRAME_WIDTH * PLAYER_SCALE));
                if (distance2 < 150.0f ){
                    if (IsKeyPressed(KEY_M)){
                       gameState = SONG_SELECT;
                    }
                }
            }
            else if (currentMap->mapId == 2){
                float distance2 = fabs(1550 - (player.position.x + FRAME_WIDTH * PLAYER_SCALE));
                if (distance2 < 150.0f && player.fama >= 30){
                    if (IsKeyPressed(KEY_M)){
                        gameState = SONG_SELECT;
                    }
                }
            }
            else if (currentMap->mapId == 3){
                float distance2 = fabs(590 - (player.position.x + FRAME_WIDTH * PLAYER_SCALE));
                if (distance2 < 150.0f && player.fama >= 60){
                    if (IsKeyPressed(KEY_M)){
                        gameState = SONG_SELECT;
                    }
                }
            }
        }

        if (inSubMenu) {
            BeginDrawing();
            ClearBackground(BLACK);

            switch(currentMenuOption) {
            case MENU_CONTROLS:
                DrawControlsScreen(screenWidth, screenHeight, titleFont, mainFont);
                break;

            case MENU_CREDITS:
                DrawCreditsScreen(screenWidth, screenHeight, titleFont, mainFont);
                break;

            default:
                inSubMenu = false;
                break;
            }

            if (IsKeyPressed(KEY_ENTER)) {
                inSubMenu = false;
                PlaySound(menuSelectSound);
            }

            EndDrawing();
            continue; // Pula o resto do loop para ficar na tela atual
        }

        switch (gameState) {
            case MAIN_MENU: {
                if (IsKeyPressed(KEY_ENTER)) {
                    PlaySound(menuSelectSound);

                    switch (currentMenuOption) {
                    case MENU_STORY:
                        instory = true;
                        InitFameSystem(&player);
                        gameState = MAPAS;
                        break;

                    case MENU_QUICKPLAY:
                        gameState = SONG_SELECT;
                        break;

                    case MENU_CONTROLS:
                    case MENU_CREDITS:
                        inSubMenu = true;
                        break;

                    case MENU_EXIT:
                        CloseWindow();
                        break;
                    }
                }
            } break;

            case SONG_SELECT: {
                if (IsKeyPressed(KEY_ENTER)) {
                    PlaySound(menuSelectSound);

                    // Load selected song
                    UnloadMusicStream(gameMusic);
                    gameMusic = LoadMusicStream(songs[selectedSong].musicFile);

                    // Set up chart (in a real game, you'd load this from file)
                    currentChart = songs[selectedSong].charts;

                    // Reset game state
                    memset(notes, 0, sizeof(notes));
                    memset(&stats, 0, sizeof(stats));
                    stats.multiplier = 1.0f;
                    stats.multiplierLevel = 1;
                    stats.rockMeter = 0.5f;
                    stats.songFailed = false;
                    stats.forgivenessMisses = 0;
                    stats.perfectStreak = 0;
                    stats.rhythmShields = 0;
                    stats.comboMultiplier = 1.0f;
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
                ApplyBlessings(&player, &stats, deltaTime);

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
                            bool ignoreMiss = false;

                            // Verifica bênçãos que podem ignorar o miss
                            for (int j = 0; j < player.blessings.count; j++) {
                                if (player.blessings.blessings[j] == BLESS_FORGIVENESS &&
                                    stats.forgivenessMisses < 3) {
                                    ignoreMiss = true;
                                    stats.forgivenessMisses++;
                                    break;
                                }
                                else if (player.blessings.blessings[j] == BLESS_RHYTHM_SHIELD &&
                                         stats.rhythmShields > 0) {
                                    ignoreMiss = true;
                                    stats.rhythmShields--;
                                    break;
                                }
                            }

                            if (!ignoreMiss) {
                                notes[i].active = false;
                                activeNoteCount--;
                                stats.misses++;

                                // Penalidade reduzida por bênçãos
                                float penalty = ROCK_METER_MISS_PENALTY;
                                if (HasBlessing(&player, BLESS_ROCK_METER)) {
                                    penalty *= 0.5f; // 50% menos penalidade
                                }
                                if (HasBlessing(&player, BLESS_FORGIVENESS)) {
                                    penalty *= 0.3f; // 70% menos penalidade
                                }

                                stats.rockMeter = fmaxf(0, stats.rockMeter - penalty);

                                // Penalidade de score reduzida se tiver combo alto
                                if (HasBlessing(&player, BLESS_FORGIVENESS) && stats.combo > 15) {
                                    stats.score = fmaxf(0, stats.score - 25); // Metade da penalidade
                                } else {
                                    stats.score = fmaxf(0, stats.score - 50);
                                }

                                stats.combo = 0;
                                stats.multiplier = 1.0f;
                                stats.multiplierLevel = 1;
                                stats.starPower = fmaxf(0, stats.starPower - 1.0f);

                                PlaySound(noteMissSound);
                            }
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

                                    // Combo não quebra com OK se tiver a bênção
                                    if (!(hitQuality == 3 && HasBlessing(&player, BLESS_COMBO))) {
                                        stats.combo++;
                                    }

                                    if (stats.combo > stats.maxCombo) stats.maxCombo = stats.combo;
                                    SpawnHitEffect(notes[i].lane);

                                    // Calculate score with blessings
                                    int baseScore = 50 * (4 - hitQuality);

                                    // Bônus de 10% da Fama Instantânea
                                    if (HasBlessing(&player, BLESS_SCORE_BOOST)) {
                                        baseScore *= 1.1f;
                                    }

                                    if (stats.starPowerActive) baseScore *= 2;

                                    // Multiplicador aumentado pelo Combo Eterno
                                    float comboMultiplier = stats.multiplier;
                                    if (HasBlessing(&player, BLESS_COMBO)) {
                                        comboMultiplier += floor(stats.combo / 10) * 0.5f;
                                        comboMultiplier = fminf(comboMultiplier, 5.0f);
                                    }

                                    stats.score += baseScore * comboMultiplier;
                                    stats.streakBonus += baseScore / 10;
                                    stats.starPower += 0.5f;

                                    // Update rock meter with blessing bonus
                                    float gain = ROCK_METER_HIT_GAIN;
                                    if (HasBlessing(&player, BLESS_ROCK_METER)) {
                                        gain *= 1.3f; // 30% mais ganho
                                    }
                                    stats.rockMeter = fminf(1.0f, stats.rockMeter + gain);

                                    // Star Power com bênção
                                    if (stats.starPower >= 10.0f && !stats.starPowerActive) {
                                        stats.starPowerActive = true;
                                        stats.starPowerTimer = 5.0f;

                                        // +2 segundos com a bênção
                                        if (HasBlessing(&player, BLESS_STAR_POWER)) {
                                            stats.starPowerTimer += 2.0f;
                                        }

                                        // Limpa penalidades
                                        if (HasBlessing(&player, BLESS_STAR_POWER)) {
                                            stats.forgivenessMisses = 0;
                                            if (stats.rockMeter < 0.5f) {
                                                stats.rockMeter = 0.5f;
                                            }
                                        }

                                        stats.starPower = 0;
                                        PlaySound(starPowerSound);
                                    }

                                    // Escudo Sonoro - 3 Perfects dão um escudo
                                    if (hitQuality == 0) {
                                        stats.perfectStreak++;
                                        if (HasBlessing(&player, BLESS_RHYTHM_SHIELD) &&
                                            stats.perfectStreak >= 3) {
                                            stats.rhythmShields = fmin(stats.rhythmShields + 1, 2);
                                            stats.perfectStreak = 0;
                                            // Efeito visual do escudo
                                            SpawnShieldEffect();
                                        }
                                    } else {
                                        stats.perfectStreak = 0;
                                    }

                                    // Bônus de combo para Fama Instantânea
                                    if (HasBlessing(&player, BLESS_SCORE_BOOST) &&
                                        stats.combo % 10 == 0) {
                                        stats.score += 200;
                                    }

                                    // Clean up note
                                    notes[i].active = false;
                                    activeNoteCount--;

                                    // Add effects
                                    stats.streakFxTimer = COMBO_FADE_TIME;

                                    // Efeito especial para Combo Eterno
                                    if (HasBlessing(&player, BLESS_COMBO) && stats.combo % 10 == 0) {
                                        SpawnComboEffect(stats.combo);
                                    }

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
                if (currentMap->mapId == 1) {
                    UpdateMap1(&currentMap->data, &player);
                } else if (currentMap->mapId == 2) {
                    UpdateMap2(&currentMap->data, &player);
                } else {
                    UpdateMap3(&currentMap->data, &player);
                }

                float distance2 = fabs(SCREEN_WIDTH - (player.position.x + FRAME_WIDTH * PLAYER_SCALE));
                if (IsKeyPressed(KEY_G)) {
                    if (distance2 < 200.0f) {
                        if (currentMap->next != NULL) {
                            currentMap = currentMap->next; // Vai para o próximo mapa
                            player.position.x = 0;
                        }
                    } else if (player.position.x < 100) {
                        if (currentMap->prev != NULL){
                            currentMap = currentMap->prev; // Volta para o mapa anterior
                            player.position.x = SCREEN_WIDTH - 100;
                        }
                    }
                }
            } break;

            case BLESS: {
                if (inBlessingSelection) {
                    // Atualiza a seleção
                    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_UP)) {
                        selectedOption = 1 - selectedOption;
                    }

                    // Confirma seleção
                    if (IsKeyPressed(KEY_ENTER)) {
                        player.blessings.blessings[player.blessings.count] = blessingOptions[selectedOption];
                        player.blessings.count++;
                        inBlessingSelection = false;
                        blessingOptionsInitialized = false;
                        gameState = MAPAS;
                    }
                } else {
                    gameState = MAPAS;
                }
            }

            case CHALLENGE: {
                if (IsKeyPressed(KEY_SPACE)) {
                    instory = false;
                    gameState = MAIN_MENU;
                }
            } break;

            case RESULTS: {
                if (instory) {
                    if (IsKeyPressed(KEY_SPACE)) {
                        int totalHits = stats.hits[0] + stats.hits[1] + stats.hits[2] + stats.hits[3];
                        int totalNotes = totalHits + stats.misses;
                        float accuracy = totalNotes > 0 ? (totalHits * 100.0f) / totalNotes : 100.0f;

                        int stars;
                        if (accuracy >= 95.0f) stars = 5;
                        else if (accuracy >= 90.0f) stars = 4;
                        else if (accuracy >= 80.0f) stars = 3;
                        else if (accuracy >= 70.0f) stars = 2;
                        else stars = 1;

                        bool isFavorite = IsFavoriteSong(selectedSong, currentMap + 1); // +1 porque currentMap começa em 0

                        // Redução de fama ao falhar a música
                        if (stats.songFailed) {
                            int fameLoss = 0;
                            switch (currentMap + 1) {
                                case 1: fameLoss = 5; break;
                                case 2: fameLoss = 10; break;
                                case 3: fameLoss = 15; break;
                            }

                            player.fama -= fameLoss;
                            if (player.fama < 0) player.fama = 0;
                        }
                        // Ganho de fama ao completar a música
                        else {
                            bool canGainFame = true;

                            switch (currentMap + 1) {
                                case 1: {
                                        if (player.fama >= 40) canGainFame = false;
                                } break;
                                case 2: {
                                        if (player.fama >= 70) canGainFame = false;
                                } break;
                            }

                            if (canGainFame) {
                                int fameGain = 0;

                                switch (stars) {
                                    case 5: fameGain = 15; break;
                                    case 4: fameGain = 10; break;
                                    default: fameGain = 5; break;
                                }

                                if (isFavorite) {
                                    fameGain += 5;
                                }

                                player.fama += fameGain;

                                if (player.fama > 100) player.fama = 100;
                            }

                            CheckForMilestone(&player);
                        }
                        gameState = BLESS;
                    }
                }
                else {
                    if (IsKeyPressed(KEY_SPACE)) {
                        gameState = MAIN_MENU;
                    }
                }
            } break;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        switch (gameState) {
            case MAIN_MENU: {
                // Draw animated background
                for (int i = 0; i < 100; i++) {
                    float x = sin(GetTime() + i) * 200 + screenWidth/2;
                    float y = cos(GetTime() * 0.5f + i) * 200 + screenHeight/2;
                    DrawCircle(x, y, 3, Fade(laneColors[i%NUM_LANES], 0.5f));
                }

                // Draw title
                const char *titleText = "ROCK HERO";
                Vector2 titleSize = MeasureTextEx(titleFont, titleText, 200, 0);
                Vector2 titlePos = {screenWidth/2 - titleSize.x/2, 50};
                DrawTextEx(titleFont, titleText, titlePos, 200, 0, WHITE);

                // Menu options
                const char* menuOptions[] = {"STORY", "QUICKPLAY", "CONTROLS", "CREDITS", "EXIT"};
                int numOptions = sizeof(menuOptions)/sizeof(menuOptions[0]);

                int startY = 380;
                int optionSpacing = 70;

                for (int i = 0; i < numOptions; i++) {
                    Color color = (i == currentMenuOption) ? YELLOW : WHITE;
                    float scale = (i == currentMenuOption) ? 1.1f : 1.0f;

                    Vector2 textSize = MeasureTextEx(mainFont, menuOptions[i], 40 * scale, 0);
                    Vector2 textPos = {
                        screenWidth/2 - textSize.x/2,
                        startY + i * optionSpacing
                    };

                    DrawTextEx(mainFont, menuOptions[i], textPos, 40 * scale, 0, color);
                }

                // Navigation
                if (IsKeyPressed(KEY_DOWN)) {
                    currentMenuOption = (currentMenuOption + 1) % numOptions;
                    PlaySound(menuScrollSound);
                }
                if (IsKeyPressed(KEY_UP)) {
                    currentMenuOption = (currentMenuOption - 1 + numOptions) % numOptions;
                    PlaySound(menuScrollSound);
                }

                if (IsKeyPressed(KEY_ENTER)) {
                    PlaySound(menuSelectSound);

                    switch (currentMenuOption) {
                        case MENU_STORY:
                            gameState = MAPAS;
                            break;

                        case MENU_QUICKPLAY:
                            gameState = SONG_SELECT;
                            break;

                        case MENU_CONTROLS:
                            break;

                        case MENU_CREDITS:
                            break;

                        case MENU_EXIT:
                            CloseWindow();
                            break;
                    }
                }

                if (IsKeyPressed(KEY_ESCAPE)) {
                    if (inSubMenu) {
                        inSubMenu = false;
                    } else {
                        CloseWindow();
                    }
                }

                // Draw instructions
                const char *instructionText = "Use ARROWS to navigate | ENTER to select";
                DrawTextEx(mainFont, instructionText,
                          (Vector2){screenWidth/2 - MeasureTextEx(mainFont, instructionText, 25, 2).x/2,
                          screenHeight - 50}, 25, 2, GRAY);
            } break;

            case SONG_SELECT: {
                    // Desenhar fundo com gradiente
                    DrawRectangleGradientV(0, 0, screenWidth, screenHeight, (Color){20, 20, 40, 255}, (Color){10, 10, 20, 255});

                    // Título
                    const char *title = "SELECT SONG";
                    Vector2 titleSize = MeasureTextEx(titleFont, title, 80, 0);
                    DrawTextEx(titleFont, title, (Vector2){screenWidth / 2 - titleSize.x / 2, 50}, 80, 0, WHITE);

                    // Scissor: delimita a área rolável para a lista de músicas
                    int listStartY = 150; // onde começa a lista (abaixo do título)
                    int listHeight = screenHeight - listStartY - 100; // altura da área rolável
                    BeginScissorMode(0, listStartY, screenWidth, listHeight);

                    // Lista de músicas
                    int startY = listStartY + 50 - scrollOffset; // scrollOffset ajusta rolagem
                    for (int i = 0; i < MAX_SONGS; i++) {
                        float yPos = startY + i * 100;

                        // Verifica se está visível dentro da área
                        if (yPos > -100 && yPos < screenHeight) {
                            // Destaque da música selecionada
                            if (i == selectedSong) {
                                DrawRectangle(screenWidth / 2 - 300, yPos, 600, 80, (Color){50, 50, 80, 255});
                            }

                            // Texto da música
                            DrawTextEx(mainFont, TextFormat("%s - %s", songs[i].artist, songs[i].title),
                                       (Vector2){screenWidth / 2 - 280, yPos + 20}, 24, 0, WHITE);

                            // Estrelas de dificuldade
                            for (int j = 0; j < 5; j++) {
                                DrawCircle(screenWidth / 2 + 200 + j * 20, yPos + 40, 5,
                                           j < songs[i].difficulty ? YELLOW : (Color){50, 50, 50, 255});
                            }
                        }
                    }

                    EndScissorMode(); // Finaliza área rolável

                    // Instruções na parte inferior
                    DrawText("Press ENTER to play", screenWidth / 2 - MeasureText("Press ENTER to play", 20) / 2, screenHeight - 40, 20, GRAY);
                    DrawText("UP/DOWN to select song", 50, screenHeight - 40, 20, GRAY);
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

                // Star power meter
                if (stats.starPower < 10.0f) {
                    DrawRectangle(50, 50, 300, 30, Fade(DARKGRAY, 0.7f));
                    DrawRectangle(50, 50, 300 * (stats.starPower / 10.0f), 30, Fade(SKYBLUE, 0.7f));
                    DrawRectangleLines(50, 50, 300, 30, WHITE);
                    DrawTextEx(mainFont, "STAR POWER", (Vector2){50, 85}, 25, 2, WHITE);
                } else {
                    // Flash when ready
                    float flash = sin(GetTime() * 10) * 0.5f + 0.5f;
                    DrawTextEx(mainFont, "STAR POWER READY!", (Vector2){50, 85}, 25, 2, (Color){255, 255, 0, (unsigned char)(flash * 255)});
                }

                // Score display (top right - maior e mais destacado)
                DrawTextEx(mainFont, TextFormat("%08d", stats.score), (Vector2){screenWidth - 400, 50}, 40, 2, WHITE);

                // Multiplier (ao lado do score)
                DrawTextEx(mainFont, TextFormat("x%d", stats.multiplierLevel), (Vector2){screenWidth - 150, 50}, 40, 2,
                           stats.multiplierLevel >= 4 ? YELLOW : WHITE);

                // Rock Meter (centro inferior - maior)
                DrawRockMeter(stats.rockMeter, screenWidth/2 - 200, screenHeight - 80, 400, 30);
                DrawTextEx(mainFont, "ROCK METER", (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "ROCK METER", 25, 2).x/2, screenHeight - 110}, 25, 2, WHITE);

                // Combo effect (maior e mais centralizado)
                if (stats.streakFxTimer > 0 && stats.combo >= 10) {
                    float alpha = stats.streakFxTimer / COMBO_FADE_TIME * 255;
                    char comboText[20];
                    sprintf(comboText, "%d COMBO!", stats.combo);

                    int fontSize = 50 + (int)(20 * (1.0f - stats.streakFxTimer / COMBO_FADE_TIME));
                    Color textColor = (Color){255, 255, 255, (unsigned char)alpha};
                    Color outlineColor = (Color){0, 0, 0, (unsigned char)(alpha * 0.7f)};

                    Vector2 textPos = {screenWidth/2 - MeasureTextEx(mainFont, comboText, fontSize, 2).x/2,
                                      screenHeight/2 - 150};

                    // Draw outline
                    for (int i = -2; i <= 2; i++) {
                        for (int j = -2; j <= 2; j++) {
                            if (i != 0 || j != 0) {
                                DrawTextEx(mainFont, comboText, (Vector2){textPos.x + i, textPos.y + j}, fontSize, 2, outlineColor);
                            }
                        }
                    }

                    DrawTextEx(mainFont, comboText, textPos, fontSize, 2, textColor);
                }

                if (stats.starPowerActive) {
                    DrawRectangle(0, 0, screenWidth, screenHeight, Fade(SKYBLUE, 0.05f));

                    // Draw star particles (mais partículas)
                    for (int i = 0; i < 50; i++) {
                        float x = sin(GetTime() * 2 + i) * 200 + screenWidth/2;
                        float y = cos(GetTime() * 3 + i) * 200 + (screenHeight/2 - 100);
                        DrawCircle(x, y, 4, Fade(YELLOW, 0.7f));
                    }
                }

                DrawHitEffects();
            } break;

            case MAPAS: {
                if (currentMap->mapId == 1) {
                    DrawMap1(&currentMap->data, &player);
                } else if (currentMap->mapId == 2) {
                    DrawMap2(&currentMap->data, &player);
                } else {
                    DrawMap3(&currentMap->data, &player);
                }


                DrawPlayer(&player);

                DrawFameMeter(&player, screenWidth, mainFont);

                // Texto informativo sobre o mapa atual
                if (currentMap == MAPA1) {
                    DrawDialogue(&map1.dialogue);
                } else if (currentMap == MAPA2) {
                    DrawDialogue(&map2.dialogue);
                } else {
                    DrawDialogue(&map3.dialogue);
                }
            } break;

            case BLESS: {
                if (inBlessingSelection) {
                    // Desenha o fundo do menu de seleção
                    DrawRectangle(0, 0, screenWidth, screenHeight, (Color){0, 0, 0, 200});

                    // Título
                    DrawTextEx(titleFont, "BENCAO DO ROCK!",
                              (Vector2){screenWidth/2 - MeasureTextEx(titleFont, "BENCAO DO ROCK!", 60, 0).x/2, 100},
                              60, 0, GOLD);

                    DrawTextEx(mainFont, TextFormat("Voce alcancou %d%% de fama!", currentMilestone),
                              (Vector2){screenWidth/2 - MeasureTextEx(mainFont, TextFormat("Voce alcancou %d%% de fama!", currentMilestone), 40, 0).x/2, 180},
                              40, 0, WHITE);

                    DrawTextEx(mainFont, "Escolha sua bencao:",
                              (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "Escolha sua bencao:", 35, 0).x/2, 250},
                              35, 0, SKYBLUE);

                    // Descreve as opções
                    const char* descriptions[MAX_BLESSINGS] = {
                        "Resistência do Rock: -50% penalidade no Rock Meter, +30% ganho e cura passiva",
                        "Explosão Estelar: Star Power +50% rápido, +2s duração e limpa penalidades",
                        "Fama Instantânea: +20pts/s, +200pts a cada 10x combo e +10% score global",
                        "Perdão do Público: Ignora 3 primeiros erros, -70% penalidade e protege combos altos",
                        "Combo Eterno: Multiplicador extra a cada 10x combo (max x5) e proteção contra OK",
                        "Escudo Sonoro: A cada 3 Perfects, ganha escudo que bloqueia 1 erro (max 2)"
                    };

                    // Desenha as opções
                    for (int i = 0; i < 2; i++) {
                        Color color = (i == selectedOption) ? YELLOW : WHITE;
                        DrawTextEx(mainFont, TextFormat("%d. %s", i+1, descriptions[blessingOptions[i]-1]),
                                  (Vector2){screenWidth/2 - 300, 320 + i * 80},
                                  30, 0, color);
                    }
                }
            } break;

            case CHALLENGE: {
                // Tela de desafio do Rei do Rock
                ClearBackground(BLACK);

                DrawTextEx(titleFont, "DESAFIO DO REI DO ROCK",
                          (Vector2){screenWidth/2 - MeasureTextEx(titleFont, "DESAFIO DO REI DO ROCK", 70, 0).x/2, 100},
                          70, 0, GOLD);

                DrawTextEx(mainFont, "Voce alcancou 100% de fama!",
                          (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "Voce alcancou 100% de fama!", 40, 0).x/2, 200},
                          40, 0, WHITE);

                DrawTextEx(mainFont, "O Deus do Rock te desafia para uma batalha final!",
                          (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "O Deus do Rock te desafia para uma batalha final!", 40, 0).x/2, 250},
                          40, 0, WHITE);

                DrawTextEx(mainFont, "Toque PERFEITAMENTE todas as musicas em sequencia",
                          (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "Toque PERFEITAMENTE todas as musicas em sequencia", 30, 0).x/2, 350},
                          30, 0, YELLOW);

                DrawTextEx(mainFont, "para se tornar o verdadeiro REI DO ROCK!",
                          (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "para se tornar o verdadeiro REI DO ROCK!", 30, 0).x/2, 400},
                          30, 0, YELLOW);

                DrawTextEx(mainFont, "Pressione SPACE para comecar o desafio",
                          (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "Pressione SPACE para comecar o desafio", 25, 0).x/2, 550},
                          25, 0, GRAY);
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

                // Draw title (maior)
                DrawTextEx(titleFont, stats.songFailed ? "SONG FAILED!" : "SONG COMPLETE!",
                           (Vector2){screenWidth/2 - MeasureTextEx(titleFont, stats.songFailed ? "SONG FAILED!" : "SONG COMPLETE!", 80, 0).x/2, 100},
                           80, 0, WHITE);

                // Draw rating (maior)
                DrawTextEx(titleFont, rating,
                           (Vector2){screenWidth/2 - MeasureTextEx(titleFont, rating, 70, 0).x/2, 200},
                           70, 0, ratingColor);

                // Draw stats (maiores e melhor espaçados)
                int startY = 300;
                int spacing = 50;

                DrawTextEx(mainFont, TextFormat("FINAL SCORE: %08d", stats.score),
                           (Vector2){screenWidth/2 - 300, (float)startY}, 40, 0, WHITE);
                startY += spacing;

                DrawTextEx(mainFont, TextFormat("ACCURACY: %.2f%%", accuracy),
                           (Vector2){screenWidth/2 - 300, (float)startY}, 40, 0, WHITE);
                startY += spacing;

                DrawTextEx(mainFont, TextFormat("MAX COMBO: %d", stats.maxCombo),
                           (Vector2){screenWidth/2 - 300, (float)startY}, 40, 0, WHITE);
                startY += spacing;

                DrawTextEx(mainFont, TextFormat("PERFECT: %d", stats.hits[0]),
                           (Vector2){screenWidth/2 - 300, (float)startY}, 40, 0, hitColors[0]);
                startY += spacing;

                DrawTextEx(mainFont, TextFormat("GREAT: %d", stats.hits[1]),
                           (Vector2){screenWidth/2 - 300, (float)startY}, 40, 0, hitColors[1]);
                startY += spacing;

                DrawTextEx(mainFont, TextFormat("GOOD: %d", stats.hits[2]),
                           (Vector2){screenWidth/2 - 300, (float)startY}, 40, 0, hitColors[2]);
                startY += spacing;

                DrawTextEx(mainFont, TextFormat("OK: %d", stats.hits[3]),
                           (Vector2){screenWidth/2 - 300, (float)startY}, 40, 0, hitColors[3]);
                startY += spacing;

                DrawTextEx(mainFont, TextFormat("MISS: %d", stats.misses),
                           (Vector2){screenWidth/2 - 300, (float)startY}, 40, 0, RED);

                // Draw continue prompt (maior)
                DrawTextEx(mainFont, "Press SPACE to Continue",
                          (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "Press SPACE to Continue", 30, 2).x/2,
                          screenHeight - 100}, 30, 2, GRAY);
            } break;
        }

        EndDrawing();
    }

    // Limpeza dos recursos
    UnloadTexture(player.spriteSheet);
    UnloadTexture(burningStartTex);
    UnloadTexture(burningEndTex);
    UnloadSound(noteMissSound);
    UnloadSound(starPowerSound);
    UnloadSound(menuSelectSound);
    UnloadSound(menuScrollSound);
    UnloadMusicStream(gameMusic);
    UnloadFont(titleFont);
    UnloadFont(mainFont);
    UnloadTexture(currentMap->data.npc.spriteSheet);
    if (mapList != NULL) {
        MapNode* current = mapList;
        do {
            UnloadTexture(current->data.npc.spriteSheet);
            if (current->data.background.id != 0) {
                UnloadTexture(current->data.background);
            }
            UnloadSound(current->data.typeSound);
            current = current->next;
        } while (current != mapList);

        FreeMapList(mapList);
    }
    CloseAudioDevice();

    CloseWindow();

    return 0;
}


void initSongs() {
    memcpy(songs[0].charts, thunderChart, sizeof(thunderChart));
    memcpy(songs[1].charts, thunderChart, sizeof(thunderChart));
    memcpy(songs[2].charts, thunderChart, sizeof(thunderChart));
    memcpy(songs[3].charts, thunderChart, sizeof(thunderChart));
    memcpy(songs[4].charts, thunderChart, sizeof(thunderChart));
    memcpy(songs[5].charts, thunderChart, sizeof(thunderChart));
    memcpy(songs[6].charts, thunderChart, sizeof(thunderChart));
    memcpy(songs[7].charts, thunderChart, sizeof(thunderChart));
    memcpy(songs[8].charts, thunderChart, sizeof(thunderChart));
    memcpy(songs[9].charts, thunderChart, sizeof(thunderChart));
    memcpy(songs[10].charts, thunderChart, sizeof(thunderChart));
}

// Inicializa o sistema de fama
void InitFameSystem(Player* player) {
    player->fama = 0;
    player->blessings.count = 0;
    for (int i = 0; i < 3; i++) {
        player->blessings.blessings[i] = BLESS_NONE;
    }
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

// Desenha a barra de fama
void DrawFameMeter(Player* player, int screenWidth, Font font) {
    // Fundo da barra
    DrawRectangle(screenWidth/2 - 150, 20, 300, 30, (Color){30, 30, 30, 200});

    // Barra de fama
    float fillWidth = 300 * (player->fama / 100.0f);
    DrawRectangle(screenWidth/2 - 150, 20, (int)fillWidth, 30, (Color){255, 215, 0, 255});

    // Marcadores de bênção (25%, 50%, 75%)
    for (int i = 1; i <= 3; i++) {
        int markerX = screenWidth/2 - 150 + (300 * i / 4);
        DrawLine(markerX, 20, markerX, 50, WHITE);
    }

    // Texto
    DrawTextEx(font, TextFormat("FAMA: %d%%", player->fama),
              (Vector2){screenWidth/2 - 50, 25}, 20, 0, BLACK);
}

void DrawControlsScreen(int screenWidth, int screenHeight, Font titleFont, Font mainFont) {
    // Fundo
    DrawRectangleGradientV(0, 0, screenWidth, screenHeight, (Color){20, 20, 40, 255}, (Color){10, 10, 20, 255});

    // Título
    DrawTextEx(titleFont, "CONTROLS",
              (Vector2){screenWidth/2 - MeasureTextEx(titleFont, "CONTROLS", 80, 0).x/2, 100},
              80, 0, WHITE);

    // Conteúdo
    int startY = 250;
    int spacing = 40;

    DrawTextEx(mainFont, "NOTES GAMEPLAY:", (Vector2){screenWidth/2 - 300, (float)startY}, 30, 0, YELLOW);
    startY += spacing;

    DrawTextEx(mainFont, "LANE 1 (RED):    A KEY", (Vector2){screenWidth/2 - 300, (float)startY}, 30, 0, WHITE);
    startY += spacing;
    DrawTextEx(mainFont, "LANE 2 (ORANGE): S KEY", (Vector2){screenWidth/2 - 300, (float)startY}, 30, 0, WHITE);
    startY += spacing;
    DrawTextEx(mainFont, "LANE 3 (GREEN):  J KEY", (Vector2){screenWidth/2 - 300, (float)startY}, 30, 0, WHITE);
    startY += spacing;
    DrawTextEx(mainFont, "LANE 4 (BLUE):   K KEY", (Vector2){screenWidth/2 - 300, (float)startY}, 30, 0, WHITE);
    startY += spacing;
    DrawTextEx(mainFont, "LANE 5 (PURPLE): L KEY", (Vector2){screenWidth/2 - 300, (float)startY}, 30, 0, WHITE);
    startY += spacing*2;

    DrawTextEx(mainFont, "MENU CONTROLS:", (Vector2){screenWidth/2 - 300, (float)startY}, 30, 0, YELLOW);
    startY += spacing;

    DrawTextEx(mainFont, "UP/DOWN:    Navigate menu", (Vector2){screenWidth/2 - 300, (float)startY}, 30, 0, WHITE);
    startY += spacing;
    DrawTextEx(mainFont, "ENTER:      Select option", (Vector2){screenWidth/2 - 300, (float)startY}, 30, 0, WHITE);
    startY += spacing;
    DrawTextEx(mainFont, "ESCAPE:     Back/Exit", (Vector2){screenWidth/2 - 300, (float)startY}, 30, 0, WHITE);

    // Voltar
    DrawTextEx(mainFont, "Press ENTER to return",
              (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "Press ENTER to return", 25, 2).x/2,
              screenHeight - 100}, 25, 2, GRAY);
}

void DrawCreditsScreen(int screenWidth, int screenHeight, Font titleFont, Font mainFont) {
    // Fundo
    DrawRectangleGradientV(0, 0, screenWidth, screenHeight, (Color){20, 20, 40, 255}, (Color){10, 10, 20, 255});

    // Título
    DrawTextEx(titleFont, "CREDITS",
              (Vector2){screenWidth/2 - MeasureTextEx(titleFont, "CREDITS", 80, 0).x/2, 100},
              80, 0, WHITE);

    // Conteúdo
    int startY = 250;
    int spacing = 40;

    DrawTextEx(mainFont, "ROCK HERO", (Vector2){screenWidth/2 - 100, (float)startY}, 40, 0, YELLOW);
    startY += spacing*2;

    DrawTextEx(mainFont, "Developed by:", (Vector2){screenWidth/2 - 300, (float)startY}, 30, 0, WHITE);
    startY += spacing;
    DrawTextEx(mainFont, "JERAROSS AND JP", (Vector2){screenWidth/2 - 300, (float)startY}, 30, 0, SKYBLUE);
    startY += spacing*2;

    DrawTextEx(mainFont, "Special thanks to:", (Vector2){screenWidth/2 - 300, (float)startY}, 30, 0, WHITE);
    startY += spacing;
    DrawTextEx(mainFont, "Raylib - Simple and easy-to-use library", (Vector2){screenWidth/2 - 300, (float)startY}, 30, 0, GRAY);
    startY += spacing;
    DrawTextEx(mainFont, "All the artists for the music", (Vector2){screenWidth/2 - 300, (float)startY}, 30, 0, GRAY);

    // Voltar
    DrawTextEx(mainFont, "Press ENTER to return",
              (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "Press ENTER to return", 25, 2).x/2,
              screenHeight - 100}, 25, 2, GRAY);
}

void DrawHitEffects() {
    for (int i = 0; i < MAX_HIT_EFFECTS; i++) {
        if (hitEffects[i].active) {
            int lane = hitEffects[i].lane;
            float progress = hitEffects[i].timer / (hitEffects[i].isStart ? HIT_EFFECT_DURATION : HIT_EFFECT_DURATION/2);
            float xPos = HIGHWAY_LEFT + lane * LANE_WIDTH;
            float yPos = TARGET_Y - 55; // Ajustado para aparecer mais acima
            if (hitEffects[i].isStart) {
                // burning_start_1.png (96x32 com 4 frames)
                int frame = (int)((1.0f - progress) * 4);
                frame = clamp(frame, 0, 3);
                Rectangle src = {frame * 24.0f, 0, 24.0f, 32.0f};
                Rectangle dest = {xPos, yPos, 96.0f, 54.0f}; // Ajustado para tamanho real
                DrawTexturePro(burningStartTex, src, dest, (Vector2){0}, 0, WHITE);
            } else {
                // burning_end_1.png (120x32 com 5 frames)
                int frame = (int)((1.0f - progress) * 5);
                frame = clamp(frame, 0, 4);
                Rectangle src = {frame * 24.0f, 0, 24.0f, 32.0f};
                Rectangle dest = {xPos, yPos, 120.0f, 54.0f}; // Ajustado para tamanho real
                DrawTexturePro(burningEndTex, src, dest, (Vector2){0}, 0, WHITE);
            }
        }
    }
}

void SpawnHitEffect(int lane) {
    for (int i = 0; i < MAX_HIT_EFFECTS; i++) {
        if (!hitEffects[i].active) {
            hitEffects[i].lane = lane;
            hitEffects[i].timer = HIT_EFFECT_DURATION;
            hitEffects[i].active = true;
            hitEffects[i].isStart = true;
            break;
        }
    }
}

void UpdateHitEffects(float deltaTime) {
    for (int i = 0; i < MAX_HIT_EFFECTS; i++) {
        if (hitEffects[i].active) {
            hitEffects[i].timer -= deltaTime;

            // Quando a animação inicial terminar, começa a final
            if (hitEffects[i].isStart && hitEffects[i].timer <= HIT_EFFECT_DURATION/2) {
                hitEffects[i].isStart = false;
                hitEffects[i].timer = HIT_EFFECT_DURATION/2;
            }

            if (hitEffects[i].timer <= 0) {
                hitEffects[i].active = false;
            }
        }
    }
}

// Verifica se o jogador alcançou um novo marco de bênção
void CheckForMilestone(Player* player) {
    int milestones[] = {25, 50, 75};

    for (int i = 0; i < 3; i++) {
        if (player->fama >= milestones[i] && player->blessings.count == i) {
            inBlessingSelection = true;
            currentMilestone = milestones[i];
            selectedOption = 0;

            // Gerar opções aleatórias de bênção
            blessingOptions[0] = (RockBlessing)(1 + GetRandomValue(0, MAX_BLESSINGS-1));
            do {
                blessingOptions[1] = (RockBlessing)(1 + GetRandomValue(0, MAX_BLESSINGS-1));
            } while (blessingOptions[1] == blessingOptions[0]);

            blessingOptionsInitialized = true;
            break;
        }
    }
}

// Verifica se a música é a favorita do público no mapa atual
bool IsFavoriteSong(int songIndex, int mapLevel) {
    switch (mapLevel) {
    case 1: return songIndex == 0; // Thunderstruck no mapa 1
    case 2: return songIndex == 1; // Sweet Child no mapa 2
    case 3: return songIndex == 8; // Livin' on a Prayer no mapa 3
    default: return false;
    }
}

// Aplica os efeitos das bênçãos ativas
void ApplyBlessings(Player* player, GameStats* stats, float deltaTime) {
    for (int i = 0; i < player->blessings.count; i++) {
        switch (player->blessings.blessings[i]) {
        case BLESS_ROCK_METER: {
                // Resistência do Rock - Melhorado
                stats->rockMeter += 0.03f * deltaTime; // Cura passiva

                // Se estiver abaixo de 30%, cura extra
                if (stats->rockMeter < 0.3f) {
                    stats->rockMeter += 0.01f * deltaTime;
                }
        } break;

        case BLESS_STAR_POWER: {
                // Explosão Estelar - Melhorado
                stats->starPower += 0.15f * deltaTime; // 50% mais rápido
        } break;

        case BLESS_SCORE_BOOST: {
                // Fama Instantânea - Melhorado
                stats->score += (int)(20 * deltaTime); // +20 pontos por segundo
        } break;

        case BLESS_FORGIVENESS: {
        } break;

        case BLESS_COMBO: {
        } break;

        case BLESS_RHYTHM_SHIELD: {
        } break;

        default:
            break;
        }
    }
}

// Verifica se o jogador tem uma bênção específica
bool HasBlessing(Player* player, RockBlessing blessing) {
    for (int i = 0; i < player->blessings.count; i++) {
        if (player->blessings.blessings[i] == blessing) {
            return true;
        }
    }
    return false;
}

// Efeito visual de escudo
void SpawnShieldEffect() {
    Vector2 center = {HIGHWAY_LEFT + HIGHWAY_WIDTH / 2, TARGET_Y};

    for (int i = 0; i < 3; i++) {
        float radius = 30 + i * 10;
        float alpha = 1.0f - (i * 0.3f);
        Color faded = Fade(BLUE, alpha);
        DrawCircleLines((int)center.x, (int)center.y, radius, faded);
    }
}

// Efeito visual de combo
void SpawnComboEffect(int combo) {
    Color comboColors[] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
    Color c = comboColors[combo % (sizeof(comboColors)/sizeof(comboColors[0]))];

    for (int i = 0; i < 10; i++) {
        float offsetX = GetRandomValue(-30, 30);
        float offsetY = GetRandomValue(-30, 30);
        float angle = GetRandomValue(0, 360);
        Vector2 pos = {HIGHWAY_LEFT + HIGHWAY_WIDTH/2 + offsetX, TARGET_Y + offsetY};
        DrawRectanglePro((Rectangle){pos.x, pos.y, 10, 3}, (Vector2){5, 1.5f}, angle, c);
    }
}