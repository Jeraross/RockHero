#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/entities/player.h"
#include "scoreboard.h"
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
#define MAX_NOTES 1000
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
#define ROCK_METER_MISS_PENALTY 0.075f
// FIRE effect
#define MAX_HIT_EFFECTS 20
#define HIT_EFFECT_DURATION 0.15f
// Adicione no início do arquivo, com as outras constantes
#define MAX_BLESSINGS 6
// Forgive bless
#define FORGIVENESS_CHARGES 6
#define FORGIVENESS_EFFECT_DURATION 1.0f
// CHALLENGE WOW
#define GOD_MODE_COMBO_THRESHOLD 150
#define GOD_MODE_WIN_COMBO 300
#define SPECIAL_NOTE_FIRE 1
#define SPECIAL_NOTE_POISON 2
#define SPECIAL_NOTE_INVISIBLE 3

typedef struct {
    int score;
    int combo;
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
    bool showForgivenessEffect; // Flag para mostrar efeito visual
    int forgivenessLane;        // Lane onde ocorreu o forgiveness
    int perfectStreak;      // Contador de Perfects consecutivos
    int rhythmShields;      // Contador de escudos sonoros
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
    bool isForgiveness;
} HitEffect;

typedef enum {
    MAIN_MENU,
    SONG_SELECT,
    PLAYING,
    MAPAS,
    RESULTS,
    CHALLENGE,
    BLESS,
    SCOREBOARD
} GameState;

typedef enum {
    MENU_STORY,
    MENU_QUICKPLAY,
    MENU_CONTROLS,
    MENU_CREDITS,
    MENU_SCOREBOARD,
    MENU_EXIT
} MenuOption;

typedef struct {
    char message[100];
    float showTime;
    float timer;
} TemporaryWarning;

// No seu arquivo de variáveis globais
typedef struct {
    bool active;
    float displayTime;
    float timer;
} FameWarning;

ScoreEntry topScores[MAX_SCORES];
int numScores = 0;

char playerName[MAX_NAME_LENGTH] = "";
int nameLength = 0;
bool enteringName = false;

float storyStartTime = 0.0;
float storyEndTime = 0.0f;
float totalTime = 0.0f;

bool showFinalScoreboard = false;
float scoreboardTimer = 0.0f;
bool scoreAlreadySaved = false;

void ResetScoreboardState() {
    scoreAlreadySaved = false;
    enteringName = false;
    showFinalScoreboard = false;
    nameLength = 0;
    playerName[0] = '\0';
    totalTime = 0.0f;
}

FameWarning fameWarning = {false, 0.2f, 0}; // 0.2s de delay mínimo

TemporaryWarning tempWarning = {0};

Song songs[MAX_SONGS] = {
    {"Killer Queen", "Queen", {}, "assets/musics/killer_queen.mp3", 114.469f, 1},
    {"Livin' on a Prayer", "Bon Jovi", {}, "assets/musics/livin_prayer.mp3", 96.2281f, 2},
    {"Smells Like Teen Spirit", "Nirvana", {}, "assets/musics/teen_spirit.mp3", 301.0f, 3},
    {"Eye of the Tiger", "Survivor", {}, "assets/musics/tiger.mp3", 270.0f, 3},
    {"Sweet Child O'Mine", "Guns N' Roses", {}, "assets/musics/sweet_child.mp3", 90.5f, 3},
    {"Bring Me To Life", "Evanescence", {}, "assets/musics/bring_me_to_life.mp3", 140.0f, 3},
    {"Paranoid", "Black Sabbath", {}, "assets/musics/paranoid.mp3", 171.0f, 3},
    {"Enter Sandman", "Metallica", {}, "assets/musics/sandman.mp3", 331.0f, 4},
    {"Thunderstruck", "AC/DC", {}, "assets/musics/thunderstruck.mp3", 0.0f, 4},
    {"Toxicity", "System of a Down", {}, "assets/musics/toxicity.mp3", 214.0f, 4},
    {"The Trooper", "Iron Maiden", {}, "assets/musics/trooper.mp3", 97.8397f, 5}
};

HitEffect hitEffects[MAX_HIT_EFFECTS];
Color laneColors[NUM_LANES];
Texture2D burningStartTex;
Texture2D burningEndTex;
Texture2D burningLoopPurple;
Texture2D burningLoopWhite;
Texture2D burningLoopGreen;
Texture2D menuBackgroundTex;
Texture2D godBackgroundTex;
Texture2D quickBackgroundTex;
Texture2D godTex;

RockBlessing blessingOptions[2];
bool inBlessingSelection = false;
bool ignoreMiss;
int selectedOption = 0;
int currentMilestone = 0;
bool blessingOptionsInitialized = false;
float deltaTime;
int cutsceneState = 0;
float cutsceneTimer = 0;

bool godModeActive = false;
float lastRiffTime = 0.0f;
float comboModeTimer = 0.0f;
float invisibleModeTimer = 0.0f;
float noteSpeedMultiplier = 1.0f;
int currentMapIndex = 1;

void initSongs();

// Inicializa o sistema de fama
void InitFameSystem(Player* player);

void DrawRockMeter(float value, int x, int y, int width, int height, bool hasBlessing);

// Desenha a barra de fama
void DrawFameMeter(Player* player, int screenWidth, Font font);

void DrawControlsScreen(int screenWidth, int screenHeight, Font titleFont, Font mainFont);

void DrawCreditsScreen(int screenWidth, int screenHeight, Font titleFont, Font mainFont);

void DrawHitEffects(Font mainFont);

void DrawShieldIndicator(int shieldsAvailable, int screenWidth, int screenHeight, Font font);

void SpawnHitEffect(int lane);

void CheckForMilestone(Player* player);

void UpdateHitEffects(float deltaTime);

// Aplica os efeitos das bênçãos ativas
void ApplyBlessings(Player* player, GameStats* stats, float deltaTime);

// Verifica se a música é a favorita do público no mapa atual
bool IsFavoriteSong(int songIndex, int mapLevel);

bool HasBlessing(Player* player, RockBlessing blessing);

void SpawnShieldEffect();

void SpawnForgivenessEffect(int lane, GameStats* stats);

bool ShouldIgnoreMiss(Player *player, GameStats* stats, int lane);

void ShowTempWarning(const char* message, float duration);

void AddSpecialNote(Note* notes, int maxNotes, int lane, float spawnTime, int specialType);

void GenerateGodModeNotes(Note* notes, int maxNotes, float currentTime, Music* gameMusic, GameStats* stats);

void ResetGodModeState(Note* notes, GameStats* stats, Music* gameMusic);

void InsertScore(const char* name, float time);

void DrawScoreboard(Font font, int x, int y);

void SaveScoreboardToFile(const char* filename);

void LoadScoreboardFromFile(const char* filename);

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
    SetSoundVolume(starPowerSound, 1.5f);
    Sound menuSelectSound = LoadSound("assets/sounds/select.wav");
    Sound menuScrollSound = LoadSound("assets/sounds/scroll.wav");
    Sound guitarSound = LoadSound("assets/sounds/guitar_scream.wav");
    Sound godSound = LoadSound("assets/sounds/criatura.wav");

    // Load fonts
    Font titleFont = LoadFontEx("assets/font/Vampire Wars.ttf", 72, 0, 0);
    Font mainFont = LoadFontEx("assets/font/Vampire Wars.ttf", 36, 0, 0);

    burningStartTex = LoadTexture("assets/sprites/burning_start.png");
	burningEndTex = LoadTexture("assets/sprites/burning_end.png");
    burningLoopPurple = LoadTexture("assets/sprites/burning_loop_purple.png");
	burningLoopWhite = LoadTexture("assets/sprites/burning_loop_white.png");
	burningLoopGreen = LoadTexture("assets/sprites/burning_loop_green.png");

    menuBackgroundTex = LoadTexture("assets/maps/menu_bg.jpg");
    godBackgroundTex = LoadTexture("assets/maps/boss_bg.png");
	quickBackgroundTex = LoadTexture("assets/maps/quick_bg.png");
    godTex = LoadTexture("assets/sprites/rockgod.png");

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
    Music menuMusic = LoadMusicStream("assets/musics/love_rock.mp3");
    SetMusicVolume(menuMusic, 0.2f);
    Music map1Music = LoadMusicStream("assets/musics/bad_name.mp3");
    SetMusicVolume(map1Music, 0.05f);
    Music map2Music = LoadMusicStream("assets/musics/jungle.mp3");
    SetMusicVolume(map2Music, 0.1f);
    Music map3Music = LoadMusicStream("assets/musics/hell.mp3");
    SetMusicVolume(map3Music, 0.1f);
    PlayMusicStream(menuMusic);
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

    LoadScoreboardFromFile("scoreboard.txt");

    while (!WindowShouldClose()) {
        deltaTime = GetFrameTime();

        // Update music stream if playing
        if (gameState == PLAYING) {
            UpdateMusicStream(gameMusic);
            UpdateHitEffects(deltaTime);
            musicPosition = GetMusicTimePlayed(gameMusic);

            if (musicPosition >= songs[selectedSong].duration && !godModeActive) {
                gameState = RESULTS;
            }

            // Check if player failed (rock meter in red zone)
            if (stats.rockMeter <= 0.15f && !stats.songFailed) {
                stats.songFailed = true;
                gameState = RESULTS;
            }
        }

        // Update scrolling for song select
        if (gameState == SONG_SELECT) {
            // Handle selection change
            if (!instory) {
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
            } else {
            float rapidez;
            int x, y;
            switch (currentMap->mapId) {
              	case 1: {rapidez = 60.0f; x = 0; y = 3;}
            	break;
            	case 2: {rapidez = 80.0f; x = 3; y = 7;}
                break;
                case 3: {rapidez = 80.0f; x = 7; y = 11;}
                break;
            }
            if (IsKeyPressed(KEY_DOWN) && selectedSong < y - 1) {
                selectedSong++;
                PlaySound(menuScrollSound);
                scrollSpeed = rapidez;
            }
            if (IsKeyPressed(KEY_UP) && selectedSong > x) {
                selectedSong--;
                PlaySound(menuScrollSound);
                scrollSpeed = rapidez * -1;
            }

            // Smooth scroll
            scrollOffset += scrollSpeed * deltaTime;
            scrollSpeed *= 0.9f;

            // Snap to correct position when almost stopped
            if (fabs(scrollSpeed) < 1.0f) {
                scrollSpeed = 0.0f;
            }
            }
        }

        if (gameState == MAPAS) {
            if (currentMap->mapId == 1) {
                float distance2 = fabs(790 - (player.position.x + FRAME_WIDTH * PLAYER_SCALE));
                if (distance2 < 150.0f) {
                    if (IsKeyPressed(KEY_M)) {
                        if (player.fama >= 40) {
                            fameWarning.active = true;
                            fameWarning.timer = 0;
                        } else {
                          selectedSong = 0;
                            gameState = SONG_SELECT;
                        }
                    }
                }
            }
            else if (currentMap->mapId == 2) {
                float distance2 = fabs(1550 - (player.position.x + FRAME_WIDTH * PLAYER_SCALE));
                if (distance2 < 150.0f) {
                    if (player.fama < 30) {
                        // Aviso temporário se fama < 30 (não deixa prosseguir)
                        if (IsKeyPressed(KEY_M)) {
                            ShowTempWarning("Voce precisa de pelo menos 30 de fama!", 2.0f);
                        }
                    }
                    else if (IsKeyPressed(KEY_M)) {
                        if (player.fama >= 70) {
                            fameWarning.active = true;
                            fameWarning.timer = 0;
                        } else {
                          selectedSong = 3;
                            gameState = SONG_SELECT; // Prossegue direto (aviso temporário)
                        }
                    }
                }
            }
            else if (currentMap->mapId == 3) {
                float distance2 = fabs(590 - (player.position.x + FRAME_WIDTH * PLAYER_SCALE));
                if (distance2 < 150.0f) {
                    if (player.fama < 60) {
                        // Aviso temporário se fama < 60 (não deixa prosseguir)
                        if (IsKeyPressed(KEY_M)) {
                            ShowTempWarning("Voce precisa de pelo menos 60 de fama!", 2.0f);
                        }
                    }
                    else if (IsKeyPressed(KEY_M)) {
                      selectedSong = 7;
                        gameState = SONG_SELECT; // Prossegue direto
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
                UpdateMusicStream(menuMusic);
                if (IsKeyPressed(KEY_ENTER)) {
                    PlaySound(menuSelectSound);
                    switch (currentMenuOption) {
                        case MENU_STORY:
                            instory = true;
                            PlayMusicStream(map1Music);
                            InitPlayer(&player);
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

                        case MENU_SCOREBOARD:
                            gameState = SCOREBOARD;
                            break;

                        case MENU_EXIT:
                            exit(0);
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
                    nextChartNote = 0;
                    activeNoteCount = 0;

                    // Start music
                    PlayMusicStream(gameMusic);
                    SeekMusicStream(gameMusic, 0);
                    gameState = PLAYING;
                }
            } break;

            case PLAYING: {
                ApplyBlessings(&player, &stats, deltaTime);

                if (godModeActive) {
                    noteSpeedMultiplier = 1.5f;

                    if (invisibleModeTimer > 0) {
                        invisibleModeTimer -= deltaTime;
                    }

                    if (comboModeTimer > 0) {
                        comboModeTimer -= deltaTime;
                    }

                    // Gera notas especiais
                    if (IsMusicStreamPlaying(gameMusic)) {
        				GenerateGodModeNotes(notes, MAX_NOTES, musicPosition, &gameMusic, &stats);
    				}
                } else {
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
                }



                // Update active notes
                for (int i = 0; i < MAX_NOTES; i++) {
                    if (notes[i].active) {
                        // Move note
                        float timeSinceSpawn = musicPosition - notes[i].spawnTime;

                        notes[i].rect.y = timeSinceSpawn * NOTE_SPEED * noteSpeedMultiplier - NOTE_HEIGHT;

                        // Check if note passed hit window without being hit
                        if (notes[i].rect.y > TARGET_Y + 50 && !notes[i].hit) {
                            if (!ShouldIgnoreMiss(&player, &stats, notes[i].lane)) {
                                // Aplica penalidade
                                notes[i].active = false;
                                activeNoteCount--;
                                stats.misses++;

                                float penalty;

                                switch (currentMap->mapId) {
                                    case 1: penalty = ROCK_METER_MISS_PENALTY; break;
                                    case 2: penalty = 0.1f; break;
                                    case 3: penalty = 0.125f; break;
                                    default: penalty = ROCK_METER_MISS_PENALTY;
                                }

                                stats.rockMeter = fmaxf(0, stats.rockMeter - penalty);

                                if (HasBlessing(&player, BLESS_COMBO) && stats.combo >= 30) {
                                    stats.combo -= 15;
                                } else {
                                    stats.combo = 0;
                                    stats.multiplier = 1.0f;
                                    stats.multiplierLevel = 1;
                                }

                                if (godModeActive && notes[i].specialType == SPECIAL_NOTE_FIRE) {
                                  	comboModeTimer = 10.0f;
    							}

                                if (godModeActive && notes[i].specialType == SPECIAL_NOTE_INVISIBLE) {
                                  	invisibleModeTimer = 5.0f;
    							}

                                if (godModeActive && notes[i].specialType == SPECIAL_NOTE_POISON) {
                                  	stats.rockMeter = 0.0f;
    							}

                                stats.starPower = fmaxf(0, stats.starPower - 1.0f);

                                PlaySound(noteMissSound);
                            } else {
                                notes[i].active = false;
                                activeNoteCount--;
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
                if (HasBlessing(&player, BLESS_COMBO)) {
    				// Com a bênção Combo Eterno, combo pode ir até x8
    				int level = 1 + (stats.combo / 10);
    				stats.multiplierLevel = (level > 8) ? 8 : level;
    				stats.multiplier = (float)stats.multiplierLevel;
                } else {
                    // Sem a bênção, comportamento normal com limite de x4
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
                                float hitWindowPixels = HIT_WINDOW * (NOTE_SPEED * noteSpeedMultiplier);

                                if (hitDiff <= hitWindowPixels) {
                                    int hitQuality;

                                    if (hitDiff < hitWindowPixels * 0.3f) hitQuality = 0; // Perfect
                                    else if (hitDiff < hitWindowPixels * 0.45f) hitQuality = 1; // Great
                                    else if (hitDiff < hitWindowPixels * 0.6f) hitQuality = 2; // Good
                                    else hitQuality = 3; // OK

                                    // Register hit
                                    notes[i].hit = true;
                                    stats.hits[hitQuality]++;

                    				if (!godModeActive || !(comboModeTimer > 0)) {
                                        if (stats.starPowerActive) stats.combo += 2;
                        				else stats.combo++;
                    				}

                                    if (godModeActive && stats.combo >= GOD_MODE_WIN_COMBO) {
                                        gameState = RESULTS;
                                    }

                                    SpawnHitEffect(notes[i].lane);

                                    // Calculate score with blessings
                                    int baseScore = 50 * (4 - hitQuality);

                                    if (stats.starPowerActive) baseScore *= 2;

                                    // Multiplicador aumentado pelo Combo Eterno
                                    float comboMultiplier = stats.multiplier;

                                    stats.score += baseScore * comboMultiplier;
                                    stats.streakBonus += baseScore / 10;
                                    stats.starPower += 0.25f;

                                    // Update rock meter with blessing bonus
                                    float gain = ROCK_METER_HIT_GAIN;
                                    if (HasBlessing(&player, BLESS_ROCK_METER)) {
                                        gain *= 1.3f;
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

                                        stats.starPower = 0;
                                        PlaySound(starPowerSound);
                                    }

                                    // Escudo Sonoro - 3 Perfects dão um escudo
                                    if (hitQuality == 0) {
                                        stats.perfectStreak++;
                                        if (HasBlessing(&player, BLESS_RHYTHM_SHIELD) &&
                                            stats.perfectStreak >= 3) {
                                            stats.rhythmShields = fmin(stats.rhythmShields + 1, 3);
                                            stats.perfectStreak = 0;
                                        }
                                    } else {
                                        stats.perfectStreak = 0;
                                    }

                                    if (HasBlessing(&player, BLESS_SCORE_BOOST) &&
                                        stats.combo % 10 == 0) {
                                        stats.score += 500;
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

                            if (!ShouldIgnoreMiss(&player, &stats, lane)) {

                                stats.misses++;

                                if (HasBlessing(&player, BLESS_COMBO) && stats.combo >= 20) {
                                    stats.combo -= 10;
                                } else {
                                    stats.combo = 0;
                                    stats.multiplier = 1.0f;
                                    stats.multiplierLevel = 1;
                                }

                                float penalty;
                                switch (currentMap->mapId) {
                                    case 1: penalty = ROCK_METER_MISS_PENALTY; break;
                                    case 2: penalty = 0.1f; break;
                                    case 3: penalty = 0.125f; break;
                                    default: penalty = ROCK_METER_MISS_PENALTY; // Fallback
                                }
                                stats.rockMeter = fmaxf(0, stats.rockMeter - penalty);

                                stats.starPower = fmaxf(0, stats.starPower - 1.0f);

                                PlaySound(noteMissSound);
                            }
                        }
                    }
                }
            } break;

            case MAPAS: {
                if (IsKeyPressed(KEY_C)) {gameState = CHALLENGE; cutsceneState = 0; cutsceneTimer = 0;}
                // Atualiza o mapa atual
                if (currentMap->mapId == 1) {
                    UpdateMusicStream(map1Music);
                    UpdateMap1(&currentMap->data, &player);
                } else if (currentMap->mapId == 2) {
                    UpdateMusicStream(map2Music);
                    UpdateMap2(&currentMap->data, &player);
                } else {
                    UpdateMusicStream(map3Music);
                    UpdateMap3(&currentMap->data, &player);
                }

                if (tempWarning.timer < tempWarning.showTime) {
                    tempWarning.timer += GetFrameTime();

                    // Fechar com a tecla F
                    if (IsKeyPressed(KEY_F)) {
                        tempWarning.timer = tempWarning.showTime; // Fecha o aviso
                    }
                }

                // No update (antes do draw)
                if (fameWarning.active) {
                    fameWarning.timer += GetFrameTime();

                    // Só permite fechar após o tempo mínimo
                    if (fameWarning.timer >= fameWarning.displayTime) {
                        if (IsKeyPressed(KEY_Y)) {
                            fameWarning.active = false;
                            gameState = SONG_SELECT;
                        }
                        else if (IsKeyPressed(KEY_N)) {
                            fameWarning.active = false;
                            // Lógica adicional se necessário
                        }
                    }
                }

                float distance2 = fabs(SCREEN_WIDTH - (player.position.x + FRAME_WIDTH * PLAYER_SCALE));
                static Music* currentMusic = NULL;

                if (IsKeyPressed(KEY_G)) {
                    bool changedMap = false;

                    if (distance2 < 200.0f && currentMap->next != NULL && currentMapIndex < 3) {
                        currentMap = currentMap->next;
                        currentMapIndex++;
                        player.position.x = 0;
                        changedMap = true;
                    } else if (player.position.x < 100 && currentMap->prev != NULL && currentMapIndex > 1) {
                        currentMap = currentMap->prev;
                        currentMapIndex--;
                        player.position.x = SCREEN_WIDTH - 100;
                        changedMap = true;
                    }

                    if (changedMap) {
                        // Para música atual (se houver)
                        if (currentMusic != NULL) StopMusicStream(*currentMusic);

                        // Seleciona nova música com base no índice do mapa
                        switch (currentMapIndex) {
                        case 1:
                            currentMusic = &map1Music;
                            break;
                        case 2:
                            currentMusic = &map2Music;
                            break;
                        case 3:
                            currentMusic = &map3Music;
                            break;
                        }

                        PlayMusicStream(*currentMusic);
                    }
                }
            } break;

            case BLESS: {
                if (inBlessingSelection) {
                    // Atualiza a seleção
                    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_UP)) {
                        PlaySound(menuScrollSound);
                        selectedOption = 1 - selectedOption;
                    }

                    // Confirma seleção
                    if (IsKeyPressed(KEY_ENTER)) {
                        PlaySound(menuSelectSound);
                        player.blessings.blessings[player.blessings.count] = blessingOptions[selectedOption];
                        player.blessings.count++;
                        inBlessingSelection = false;
                        blessingOptionsInitialized = false;
                        gameState = MAPAS;
                    }
                } else {
                    gameState = MAPAS;
                }
            } break;

            case CHALLENGE: {
				if (IsKeyPressed(KEY_ENTER)) {
                    PlaySound(guitarSound);
        			ResetGodModeState(notes, &stats, &gameMusic);

        			// Configura o modo Deus
        			godModeActive = true;

                    ResetScoreboardState();

                    // Começa a música
        			PlayMusicStream(gameMusic);
        			SeekMusicStream(gameMusic, 0);
        			gameState = PLAYING;
				}
            } break;

            case SCOREBOARD:{

            } break;

            case RESULTS: {
                if (instory && !godModeActive) {
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

                        bool isFavorite = IsFavoriteSong(selectedSong, currentMap->mapId); // +1 porque currentMap começa em 0

                        // Redução de fama ao falhar a música
                        if (stats.songFailed) {
                            int fameLoss = 0;
                            switch (currentMap->mapId) {
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

                            switch (currentMap->mapId) {
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

                                if (HasBlessing(&player, BLESS_SCORE_BOOST)) {
                                    fameGain += 5;
                                }

                                player.fama += fameGain;
                            }

                            CheckForMilestone(&player);
                        }
                        if (player.fama >= 100) {cutsceneState = 0; cutsceneTimer = 0; gameState = CHALLENGE;}
                        else gameState = BLESS;
                    }
                } else {
                    if (IsKeyPressed(KEY_SPACE) && godModeActive && !stats.songFailed) {
                        for (int i = 0; i < 3; i++) {
                            player.blessings.blessings[i] = BLESS_NONE;
                        }
                        currentMapIndex = 1;
                        currentMap = currentMap->prev->prev;
                        noteSpeedMultiplier = 1.0f;
                        instory = false;
                      	godModeActive = false;
                        gameState = MAIN_MENU;
                    } else if (IsKeyPressed(KEY_SPACE) && !godModeActive) {
                      	gameState = MAIN_MENU;
                    }
                  	if (IsKeyPressed(KEY_C) && stats.songFailed && godModeActive) {
                        cutsceneState = 2;
                        cutsceneTimer = 0;
                    	gameState = CHALLENGE;
                  	}
                }
            } break;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        switch (gameState) {
            case MAIN_MENU: {
                Rectangle source = { 0.0f, 0.0f, menuBackgroundTex.width, menuBackgroundTex.height };
                Rectangle dest = { 0.0f, 0.0f, (float)screenWidth, (float)screenHeight };
                Vector2 origin = { 0.0f, 0.0f };

                DrawTexturePro(menuBackgroundTex, source, dest, origin, 0.0f, WHITE);

                for (int i = 0; i < 75; i++) {
                    float x = sin(GetTime() + i) * 225 + screenWidth/2;
                    float y = cos(GetTime() * 0.25f + i) * 225 + screenHeight/2;
                    DrawCircle(x, y, 3, Fade(laneColors[i%NUM_LANES], 0.5f));
                }
                for (int i = 0; i < 50; i++) {
                    float x = sin(GetTime() * 0.75f + i) * 200 + screenWidth/2;
                    float y = cos(GetTime() + i) * 200 + screenHeight/2;
                    DrawCircle(x, y, 3, Fade(laneColors[i%NUM_LANES], 0.5f));
                }

                // Draw title
                const char *titleText = "ROCK HERO";
                Vector2 titleSize = MeasureTextEx(titleFont, titleText, 200, 0);
                Vector2 titlePos = {screenWidth/2 - titleSize.x/2, 50};
                DrawTextEx(titleFont, titleText, titlePos, 200, 0, WHITE);

                // Menu options
                const char* menuOptions[] = {"STORY", "QUICKPLAY", "CONTROLS", "CREDITS", "SCOREBOARD", "EXIT"};
                int numOptions = sizeof(menuOptions)/sizeof(menuOptions[0]);

                int startY = 340;
                int optionSpacing = 70;

                for (int i = 0; i < numOptions; i++) {
                    Color color = (i == currentMenuOption) ? RED : MAROON;
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

                        case MENU_SCOREBOARD:
                            gameState = SCOREBOARD;
                            break;

                        case MENU_EXIT:
                            exit(0);
                            CloseWindow();
                            break;
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
                    if (instory) {
                    int x, y, z = 0;
            		switch (currentMap->mapId) {
              			case 1: {x = 0; y = 3;}
            			break;
            			case 2: {x = 3; y = 7;}
                		break;
            			case 3: {x = 7; y = 11;}
            		    break;
            		}
                    for (int i = x; i < y; i++) {
                        float yPos = startY + z++ * 100;

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
                    } else {
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
                    }


                    EndScissorMode(); // Finaliza área rolável

                    // Instruções na parte inferior
                    DrawText("Press ENTER to play", screenWidth / 2 - MeasureText("Press ENTER to play", 20) / 2, screenHeight - 40, 20, GRAY);
                    DrawText("UP/DOWN to select song", 50, screenHeight - 40, 20, GRAY);
            } break;

            case PLAYING: {
                // Draw dark background
                ClearBackground((Color){10, 10, 20, 255});

                if (godModeActive) {
                    Rectangle source = { 0.0f, 0.0f, godBackgroundTex.width/1.082, godBackgroundTex.height };
                	Rectangle dest = { 0.0f, 0.0f, (float)screenWidth, (float)screenHeight };
                	Vector2 origin = { 0.0f, 0.0f };

                	DrawTexturePro(godBackgroundTex, source, dest, origin, 0.0f, WHITE);

         	        for (int i = 0; i < 50; i++) {
         	        	float x = sin(GetTime() * 2 + i) * screenWidth;
         	        	float y = screenHeight - fmodf(cutsceneTimer * 100 + i * 10, screenHeight);
         	        	DrawCircle(x, y, 3 + sin(GetTime() + i), Fade(ORANGE, 0.5f));
         	        }
    	        } else {
                    Rectangle source = { quickBackgroundTex.width/2 - (quickBackgroundTex.width/1.3)/2, 0.0f, quickBackgroundTex.width/1.3, quickBackgroundTex.height/1.3 };
                	Rectangle dest = { 0.0f, 0.0f, (float)screenWidth, (float)screenHeight };
                	Vector2 origin = { 0.0f, 0.0f};

                	DrawTexturePro(quickBackgroundTex, source, dest, origin, 0.0f, WHITE);
    	        }

                DrawRectangle(HIGHWAY_LEFT, 0, HIGHWAY_WIDTH, screenHeight, (Color){0, 0, 0, 250}); // 30 30 40

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
                        bool shouldDraw = true;

    					// Verifica se está no modo invisível
    					if (godModeActive && invisibleModeTimer > 0 &&
    					    notes[i].rect.y > TARGET_Y - 200) {
    						shouldDraw = false;
    					}

    					if (shouldDraw) {
            				// Primeiro desenha a nota base (sempre)
            				DrawRectangleRec(notes[i].rect, notes[i].color);

            				// Depois desenha os efeitos especiais (se for o caso)
            				if (godModeActive && notes[i].specialType > 0) {
                				notes[i].specialTimer += deltaTime;
                				int frameWidth = burningLoopPurple.width / 8;
                				int frame = ((int)(notes[i].specialTimer * 10) % 8) * frameWidth;

                				Rectangle srcRect = {frame, 0, frameWidth, burningLoopPurple.height};
                				Rectangle destRect = {
                				    notes[i].rect.x + notes[i].rect.width/2 - frameWidth*5,
                				    notes[i].rect.y - 120,
                				    240.0f,
                				    120.0f
                				};

                				Texture2D* currentTexture = NULL;
                				switch (notes[i].specialType) {
                				    case SPECIAL_NOTE_FIRE:    currentTexture = &burningLoopPurple; break;
                				    case SPECIAL_NOTE_POISON:  currentTexture = &burningLoopGreen; break;
                				    case SPECIAL_NOTE_INVISIBLE: currentTexture = &burningLoopWhite; break;
                				}

                				if (currentTexture) {
                    				DrawTexturePro(*currentTexture, srcRect, destRect, (Vector2){0}, 0, WHITE);
                				}
            				}
        				}
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

                // Efeito especial para Combo Eterno
                if (HasBlessing(&player, BLESS_COMBO)) {
                    for (int i = 0; i < 20; i++) {
                        float x = sin(GetTime() + i) * 30 + screenWidth - 129;
                        float y = cos(GetTime() * 10.0f + i) * 30 + 70;
                        DrawCircle(x, y, 3, Fade(laneColors[i%NUM_LANES], 0.5f));
                    }
                    for (int i = 0; i < 20; i++) {
                        float x = sin(GetTime() * 10.0f + i) * 30 + screenWidth - 129;
                        float y = cos(GetTime() + i) * 30 + 70;
                        DrawCircle(x, y, 3, Fade(laneColors[i%NUM_LANES], 0.5f));
                    }
                }

                // Score display (top right - maior e mais destacado)
                DrawTextEx(mainFont, TextFormat("%010d", stats.score), (Vector2){screenWidth - 400, 50}, 40, 2, WHITE);

                // Multiplier (ao lado do score)
                DrawTextEx(mainFont, TextFormat("x%d", stats.multiplierLevel), (Vector2){screenWidth - 150, 50}, 40, 2,
                           stats.multiplierLevel >= 4 ? YELLOW : WHITE);

                // Rock Meter (centro inferior - maior)
                DrawRockMeter(stats.rockMeter, screenWidth/2 - 200, screenHeight - 80, 400, 30, HasBlessing(&player, BLESS_ROCK_METER));
                DrawTextEx(mainFont, "ROCK METER", (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "ROCK METER", 25, 2).x/2, screenHeight - 110}, 25, 2, WHITE);

                // Combo effect (maior e mais centralizado)
                if (stats.streakFxTimer > 0 && stats.combo >= 10) {
                    float alpha = stats.streakFxTimer / COMBO_FADE_TIME * 255;
                    char comboText[20];
                    sprintf(comboText, "%d COMBO!", stats.combo);

                    int fontSize = 50 + (int)(20 * (1.0f - stats.streakFxTimer / COMBO_FADE_TIME));
                    Color textColor = (Color){255, 255, 255, (unsigned char)alpha};
                    Color textColorBless = (Color){255, 255, 0, (unsigned char)alpha};
                    Color outlineColor = (Color){0, 0, 0, (unsigned char)(alpha * 0.7f)};

                    Vector2 textPos = {screenWidth/2 - MeasureTextEx(mainFont, comboText, fontSize, 2).x/2,
                                      screenHeight/2 - 150};

                    // Draw outline
                    for (int i = -2; i <= 2; i++) {
                        for (int j = -2; j <= 2; j++) {
                            if ((i != 0 || j != 0) && !(HasBlessing(&player, BLESS_SCORE_BOOST) && stats.combo % 10 == 0)) {
                                DrawTextEx(mainFont, comboText, (Vector2){textPos.x + i, textPos.y + j}, fontSize, 2, outlineColor);
                            }
                        }
                    }

                    if (HasBlessing(&player, BLESS_SCORE_BOOST) && stats.combo % 10 == 0) {
                        int boostedFontSize = fontSize + 10;  // Aumenta ainda mais o tamanho do texto
                        Vector2 boostedTextPos = {
                            screenWidth/2 - MeasureTextEx(mainFont, comboText, boostedFontSize, 2).x/2,
                            screenHeight/2 - 150
                        };

                        // Redesenha o contorno maior também
                        for (int i = -2; i <= 2; i++) {
                            for (int j = -2; j <= 2; j++) {
                                if (i != 0 || j != 0) {
                                    DrawTextEx(mainFont, comboText,
                                               (Vector2){boostedTextPos.x + i, boostedTextPos.y + j},
                                               boostedFontSize, 2, outlineColor);
                                }
                            }
                        }

                        DrawTextEx(mainFont, comboText, boostedTextPos, boostedFontSize, 2, textColorBless);
                    } else {
                        DrawTextEx(mainFont, comboText, textPos, fontSize, 2, textColor);
                    }
                }

                if (HasBlessing(&player, BLESS_FORGIVENESS)) {
                    int baseX = 40;
                    int baseY = screenHeight - 150;

                    for (int i = 0; i < FORGIVENESS_CHARGES; i++) {
                        int cx = baseX + 60 + i * 50;
                        int cy = baseY + 45;
                        Color chargeColor = (i < FORGIVENESS_CHARGES - stats.forgivenessMisses) ? GREEN : Fade(GREEN, 0.3f);

                        DrawCircle(cx, cy, 22, Fade(GREEN, 0.2f));    // Aura
                        DrawCircle(cx, cy, 15, chargeColor);          // Corpo
                        DrawCircleLines(cx, cy, 15, WHITE);           // Borda
                    }
                }

                if (HasBlessing(&player, BLESS_RHYTHM_SHIELD)) {
                    DrawShieldIndicator(stats.rhythmShields, screenWidth, screenHeight, mainFont);
                }

                if (stats.starPowerActive) {
                    for (int i = 0; i < 50; i++) {
                        float x = sin(GetTime() * 2 + i) * 200 + screenWidth/2;
                        float y = cos(GetTime() * 3 + i) * 200 + (screenHeight/2 - 100);
                        DrawCircle(x, y, 4, Fade(YELLOW, 0.5f));
                    }

                    if (HasBlessing(&player, BLESS_STAR_POWER)) {
                        for (int i = 0; i < 75; i++) {
                            float x = sin(GetTime() * 3 + i) * 225 + screenWidth/2;
                            float y = cos(GetTime() * 2 + i) * 225 + (screenHeight/2 - 100);
                            DrawCircle(x, y, 4, Fade(YELLOW, 0.5f));
                        }
                    }
                }

                DrawHitEffects(mainFont);

// Adicione um HUD especial para o modo Deus:
if (godModeActive) {
    // Efeito de pulsação quando o combo está alto
    float pulseIntensity = 0.0f;
    if (stats.combo >= GOD_MODE_COMBO_THRESHOLD) {
        pulseIntensity = (stats.combo - GOD_MODE_COMBO_THRESHOLD) /
                       (float)(GOD_MODE_WIN_COMBO - GOD_MODE_COMBO_THRESHOLD);
    }

    // ---- Barra de progresso épica ----
    float progress = stats.combo / (float)GOD_MODE_WIN_COMBO;
    int barWidth = 500;
    int barHeight = 30;
    int barX = screenWidth/2 - barWidth/2;
    int barY = 120;

    // Fundo da barra com detalhes
    DrawRectangle(barX, barY, barWidth, barHeight, Fade((Color){40, 40, 40, 255}, 0.8f));
    DrawRectangleLines(barX, barY, barWidth, barHeight, Fade(WHITE, 0.3f));

    // Preenchimento da barra com efeitos
    if (progress > 0) {
        // Gradiente de cor
        Color fillStart = stats.combo >= GOD_MODE_COMBO_THRESHOLD ?
                         (Color){255, 50, 50, 255} : (Color){255, 215, 0, 255};
        Color fillEnd = stats.combo >= GOD_MODE_COMBO_THRESHOLD ?
                       (Color){150, 0, 0, 255} : (Color){200, 100, 0, 255};

        DrawRectangleGradientH(barX, barY, barWidth * progress, barHeight, fillStart, fillEnd);

        // Efeito de brilho pulsante quando está alto
        if (pulseIntensity > 0) {
            DrawRectangleGradientH(barX, barY, barWidth * progress, barHeight,
                                 ColorAlpha(WHITE, pulseIntensity * 0.3f),
                                 ColorAlpha(YELLOW, pulseIntensity * 0.1f));
        }
    }

    // Marcador do threshold
    float thresholdPos = GOD_MODE_COMBO_THRESHOLD / (float)GOD_MODE_WIN_COMBO;

    DrawLine(barX + barWidth * thresholdPos, barY - 5,
             barX + barWidth * thresholdPos, barY + barHeight + 5,
             Fade(WHITE, 0.5f));

    // ---- Contador numérico ----
    char godComboText[50];
    sprintf(godComboText, "%d/%d", stats.combo, GOD_MODE_WIN_COMBO);

    Vector2 textSize = MeasureTextEx(mainFont, godComboText, 40, 0);
    Color textColor = stats.combo >= GOD_MODE_COMBO_THRESHOLD ?
                     ColorAlpha(RED, 0.9f + sin(GetTime()*10)*0.1f) : WHITE;

    // Sombra do texto
    DrawTextEx(mainFont, godComboText,
              (Vector2){screenWidth/2 - textSize.x/2 + 2, 155 + 2},
              40, 0, Fade(BLACK, 0.7f));

    // Texto principal
    DrawTextEx(mainFont, godComboText,
              (Vector2){screenWidth/2 - textSize.x/2, 155},
              40, 0, textColor);

    // ---- Efeitos especiais ativos ----
    int yPos = 200;

    if (comboModeTimer > 0) {
        DrawTextEx(mainFont, TextFormat("NO RESPECT: %.1fs", comboModeTimer),
                  (Vector2){50, yPos}, 30, 0,
                  ColorAlpha((Color){255, 100, 100, 255},
                             0.8f + sin(GetTime()*10)*0.2f));
        yPos += 40;
    }

    if (invisibleModeTimer > 0) {
        DrawTextEx(mainFont, TextFormat("INVISIBLE NOTES: %.1fs", invisibleModeTimer),
                  (Vector2){50, yPos}, 30, 0,
                  ColorAlpha((Color){100, 100, 255, 255},
                             0.8f + sin(GetTime()*8)*0.2f));
        yPos += 40;
    }

    // Efeito de partículas quando o combo está alto
    if (pulseIntensity > 0) {
        for (int i = 0; i < 5; i++) {
            float angle = GetTime() + i;
            float radius = 50 + pulseIntensity * 50;
            Vector2 pos = {
                screenWidth/2 + cos(angle * (2 + i)) * radius,
                barY + barHeight/2 + sin(angle * (3 + i)) * radius
            };
            DrawCircleV(pos, 2 + pulseIntensity * 3, Fade(RED, 0.7f));
        }
    }

    if (stats.combo >= GOD_MODE_COMBO_THRESHOLD) {
        // Efeitos de partículas de fogo (sobrepostas à imagem)
        for (int i = 0; i < 50; i++) {
         	float x = sin(GetTime() * 1.8 + i) * screenWidth;
         	float y = screenHeight - fmodf(cutsceneTimer * 100 + i * 10, screenHeight);
         	DrawCircle(x, y, 3 + sin(GetTime() + i), Fade(ORANGE, 0.6f));
        }
    }
}
            } break;

            case MAPAS: {
                // Desenha o mapa atual
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
                DrawDialogue(&currentMap->data.dialogue);

                if (fameWarning.active) {
                    // Fundo semi-transparente (aparece imediatamente)
                    DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.7f));

                    // Caixa de diálogo (sem delay)
                    Rectangle dialogBox = {
                            screenWidth/2 - 375,
                            screenHeight/2 - 125,
                            750,
                            250
                    };
                    DrawRectangleRec(dialogBox, BLACK);
                    DrawRectangleLinesEx(dialogBox, 3, WHITE);

                    // Texto principal (sem delay)
                    const char* lines[] = {
                            "Voce nao ganhara mais fama tocando",
                            "nesse mapa, deseja continuar mesmo assim?"
                    };

                    float startY = dialogBox.y + 50;
                    for (int i = 0; i < 2; i++) {
                        Vector2 textSize = MeasureTextEx(titleFont, lines[i], 28, 1);
                        DrawTextEx(titleFont, lines[i],
                                   (Vector2){dialogBox.x + dialogBox.width/2 - textSize.x/2, startY + i*40},
                                   28, 1, WHITE);
                    }

                    // Botões (centralizados horizontalmente)
                    float totalButtonsWidth = 120 * 2 + 60; // 2 botões de 120 + 60 de espaçamento
                    float startX = dialogBox.x + (dialogBox.width - totalButtonsWidth) / 2;

                    Rectangle btnYes = {startX, dialogBox.y + 180, 120, 50};
                    Rectangle btnNo = {startX + 180, dialogBox.y + 180, 120, 50};

                    // Cores e desenho (mantidos da sua versão)
                    Color btnYesColor = (fameWarning.timer >= fameWarning.displayTime && CheckCollisionPointRec(GetMousePosition(), btnYes)) ? GREEN : LIME;
                    Color btnNoColor = (fameWarning.timer >= fameWarning.displayTime && CheckCollisionPointRec(GetMousePosition(), btnNo)) ? PINK : RED;

                    DrawRectangleRec(btnYes, btnYesColor);
                    DrawRectangleRec(btnNo, btnNoColor);

                    // Textos dos botões (ajuste fino de centralização)
                    DrawTextEx(titleFont, "SIM (Y)",
                               (Vector2){btnYes.x + btnYes.width/2 - MeasureTextEx(titleFont, "SIM (Y)", 24, 1).x/2,
                                         btnYes.y + btnYes.height/2 - 12},
                               24, 1, WHITE);

                    DrawTextEx(titleFont, "NAO (N)",
                               (Vector2){btnNo.x + btnNo.width/2 - MeasureTextEx(titleFont, "NÃO (N)", 24, 1).x/2,
                                         btnNo.y + btnNo.height/2 - 12},
                               24, 1, WHITE);

                    // Controles (só funcionam após o delay)
                    if (fameWarning.timer >= fameWarning.displayTime) {
                        if (IsKeyPressed(KEY_Y) || (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), btnYes))) {
                            fameWarning.active = false;
                            gameState = SONG_SELECT;
                        }
                        else if (IsKeyPressed(KEY_N) || (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), btnNo))) {
                            fameWarning.active = false;
                        }
                    }
                }

				// ----- AVISO TEMPORÁRIO DE FAMA (sobrepõe tudo) -----
                if (tempWarning.timer < tempWarning.showTime) {
                    // Fundo semi-transparente
                    DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.7f));

                    // Texto principal (centralizado)
                    const char* warningText = tempWarning.message;
                    float fontSize = 28;
                    Vector2 textSize = MeasureTextEx(titleFont, warningText, fontSize, 1);

                    Vector2 textPos = {
                            screenWidth / 2 - textSize.x / 2,
                            screenHeight / 2 - textSize.y / 2
                    };
                    DrawTextEx(titleFont, warningText, textPos, fontSize, 1, YELLOW);

                    // Texto de instrução (pressione F para fechar)
                    const char* pressKeyText = "Pressione F para fechar";
                    Vector2 pressKeyTextSize = MeasureTextEx(titleFont, pressKeyText, 20, 1);
                    Vector2 pressKeyPos = {
                            screenWidth / 2 - pressKeyTextSize.x / 2,
                            textPos.y + textSize.y + 20
                    };
                    DrawTextEx(titleFont, pressKeyText, pressKeyPos, 20, 1, WHITE);
                }

            } break;

            case SCOREBOARD: {
                // Fundo
                DrawRectangleGradientV(0, 0, screenWidth, screenHeight,
                                       (Color){10, 10, 30, 255},
                                       (Color){5, 5, 15, 255});

                // Título
                const char* titleText = "PLACAR DE HEROIS DO ROCK";
                Vector2 titleSize = MeasureTextEx(titleFont, titleText, 60, 0);
                DrawTextEx(titleFont, titleText,
                           (Vector2){screenWidth/2 - titleSize.x/2, 80},
                           60, 0, GOLD);

                // Lista de scores centralizada
                for (int i = 0; i < numScores; i++) {
                    char line[64];
                    sprintf(line, "%2d. %-20s  %.2f s", i + 1, topScores[i].name, topScores[i].time);

                    Vector2 lineSize = MeasureTextEx(mainFont, line, 32, 0);
                    DrawTextEx(mainFont, line,
                               (Vector2){screenWidth/2 - lineSize.x/2, 160 + i * 40},
                               32, 0, WHITE);
                }

                // Instrução de retorno
                const char* backText = "PRESS SPACE TO RETURN";
                Vector2 backSize = MeasureTextEx(mainFont, backText, 24, 0);
                DrawTextEx(mainFont, backText,
                           (Vector2){screenWidth/2 - backSize.x/2, screenHeight - 60},
                           24, 0, GRAY);

                // Voltar ao menu
                if (IsKeyPressed(KEY_SPACE)) {
                    gameState = MAIN_MENU;
                }
            } break;


            case BLESS: {
                if (inBlessingSelection) {
                    // Fundo com textura
                    DrawRectangleGradientV(0, 0, screenWidth, screenHeight, (Color){20, 20, 40, 255}, (Color){10, 10, 20, 255});

                    // Efeito de vinil ampliado
                    static float rotationAngle = 0;
                    rotationAngle += deltaTime * 45;
                    float vinylSize = 400.0f;
                    DrawCircle(screenWidth/2, screenHeight/2, vinylSize, Fade(BLACK, 0.8f));

                    // Linhas do vinil giratório
                    for(int i = 0; i < 360; i += 15) {
                        float ripple = sin(rotationAngle + i * DEG2RAD) * 20;
                        DrawCircleLines(screenWidth/2, screenHeight/2,
                                       vinylSize - 30 + ripple,
                                       Fade(WHITE, 0.1f + sin(GetTime() + i)*0.05f));
                    }

                    // Efeito de centro do vinil
                    DrawCircle(screenWidth/2, screenHeight/2, 50, DARKGRAY);
                    DrawCircleLines(screenWidth/2, screenHeight/2, 50, WHITE);

                    // Camada escura semi-transparente
                    DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.4f));

                    // Título
                    DrawTextEx(titleFont, "BENCAO DO ROCK!",
                              (Vector2){screenWidth/2 - MeasureTextEx(titleFont, "BENCAO DO ROCK!", 80, 0).x/2, 50},
                              80, 0, YELLOW);

                    // Opções de bênção
                    const char* blessingNames[MAX_BLESSINGS] = {
                        "DURO NA QUEDA",
                        "FAMA INSTANTANEA",
                        "AURA INABALAVEL",
                        "ESCUDO SONORO",
                        "COMBO ETERNO",
                        "ESTRELA CADENTE"
                    };

                    const char* blessingDescs[MAX_BLESSINGS] = {
                        "Ganho maior no Rock Meter e cura passiva",
                        "Bonus de fame e 500pts a cada 10 hits",
                        "Ignora os 6 primeiros erros",
                        "A cada 3 Perfects, ganha 1 escudo (max 3)",
                        "Multiplicador ate 8x e protege combos",
                        "Star Power dura +2s e ganho passivo"
                    };

                    for (int i = 0; i < 2; i++) {
                        bool isSelected = (i == selectedOption);
                        float yBase = 325 + i * 325;

                        // Nome da bênção
                        Color nameColor = isSelected ? YELLOW : WHITE;
                        Vector2 nameSize = MeasureTextEx(mainFont, blessingNames[blessingOptions[i]-1], 36, 0);
                        DrawTextEx(mainFont, blessingNames[blessingOptions[i]-1],
                                  (Vector2){screenWidth/2 - nameSize.x/2, yBase},
                                  36, 0, nameColor);


                        float lineY = yBase + nameSize.y + 5;
                        // Descrição centralizada
                        Vector2 descSize = MeasureTextEx(mainFont, blessingDescs[blessingOptions[i]-1], 28, 0);
                        DrawTextEx(mainFont, blessingDescs[blessingOptions[i]-1],
                                  (Vector2){screenWidth/2 - descSize.x/2, lineY + 15},
                                  28, 0, WHITE);

                    }

                    // Instruções na parte inferior
                    const char* instructions = "USE AS SETAS PARA SELECIONAR  |  PRESSIONE ENTER PARA CONFIRMAR";
                    Vector2 instrSize = MeasureTextEx(mainFont, instructions, 28, 0);
                    DrawTextEx(mainFont, instructions,
                              (Vector2){screenWidth/2 - instrSize.x/2, screenHeight - 50},
                              28, 0, (Color){180, 180, 180, 255});
                }
            } break;

case CHALLENGE: {
    storyStartTime = GetTime();  // marca o tempo inicial
    cutsceneTimer += deltaTime;

    // Fundo com efeito de fogo
    if (cutsceneState == 0 || cutsceneState == 1) {
        DrawRectangleGradientV(0, 0, screenWidth, screenHeight,
                        (Color){10, 0, 0, 255},
                        (Color){40, 0, 0, 255});
    } else if (cutsceneState == 2) {
        // Apresentação do Deus do Rock
        DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
    }

    // Efeitos de partículas de fogo (sobrepostas à imagem)
    for (int i = 0; i < 50; i++) {
        float x = sin(GetTime() * 2 + i) * screenWidth;
        float y = screenHeight - fmodf(cutsceneTimer * 100 + i * 10, screenHeight);
        DrawCircle(x, y, 3 + sin(GetTime() + i), Fade(ORANGE, 0.7f));
    }

    switch (cutsceneState) {
        case 0: { // Introdução
            const char* text1 = "O DEUS DO ROCK TE DESAFIA!";
            const char* text2 = "Voce alcancou 100% de fama...";
            const char* text3 = "Mas sera que consegue enfrentar o criador do rock?";

            float textAlpha = fminf(1.0f, cutsceneTimer * 0.8f);

            DrawTextEx(titleFont, text1,
                     (Vector2){screenWidth/2 - MeasureTextEx(titleFont, text1, 60, 0).x/2, 100},
                     60, 0, Fade(GOLD, textAlpha));

            if (cutsceneTimer > 1.5f) {
                float alpha2 = fminf(1.0f, (cutsceneTimer-1.5f) * 0.8f);
                DrawTextEx(mainFont, text2,
                         (Vector2){screenWidth/2 - MeasureTextEx(mainFont, text2, 40, 0).x/2, 200},
                         40, 0, Fade(WHITE, alpha2));
            }

            if (cutsceneTimer > 3.0f) {
                float alpha3 = fminf(1.0f, (cutsceneTimer-3.0f) * 0.8f);
                DrawTextEx(mainFont, text3,
                         (Vector2){screenWidth/2 - MeasureTextEx(mainFont, text3, 40, 0).x/2, 260},
                         40, 0, Fade(WHITE, alpha3));
            }

            // Instrução para continuar
    		if (cutsceneTimer > 3.5f) { // Mostra depois que todas as chamas apareceram
    		    DrawTextEx(mainFont, "Pressione E para avancar",
    		             (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "Pressione E para avancar", 30, 0).x/2,
    		             screenHeight - 50}, 30, 0, Fade(GRAY, 0.5f + sin(GetTime()*5)*0.5f));
    		}

            if (IsKeyPressed(KEY_E)) {
                PlaySound(guitarSound);
                cutsceneState = 1;
                cutsceneTimer = 0;
            }
        } break;

case 1: { // Explicação das chamas do destino
    // Título
    DrawTextEx(titleFont, "CHAMAS DO DESTINO",
             (Vector2){screenWidth/2 - MeasureTextEx(titleFont, "CHAMAS DO DESTINO", 60, 0).x/2, 80},
             60, 0, GOLD);

    // Explicação geral
    DrawTextEx(mainFont, "Para vencer, alcance um combo de 300!",
             (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "Para vencer, alcance um combo de 300!", 30, 0).x/2, 150},
             30, 0, WHITE);

    // Animação frame (8 frames total)
    int frame = ((int)(cutsceneTimer * 10) % 8);
    int frameWidth = burningLoopPurple.width / 8;

    // Configurações para cada chama
    struct FlameInfo {
        Texture2D* texture;
        const char* text;
        Color color;
        Vector2 position;
    } flames[3] = {
        {&burningLoopPurple, "FOGO ROXO: Se errar, nao ganha combo por 10s", (Color){252, 140, 212, 255}, {screenWidth/2 - 150, 250}},
        {&burningLoopGreen,  "FOGO VERDE: Se errar, perde INSTANTANEAMENTE", (Color){212, 252, 124, 255}, {screenWidth/2 - 150, 400}},
        {&burningLoopWhite,  "FOGO BRANCO: Se errar, notas ficam invisiveis por 5s", (Color){228, 252, 252, 255}, {screenWidth/2 - 150, 550}}
    };

    // Desenha todas as chamas com suas animações
    for (int i = 0; i < 3; i++) {
        // Efeito de fade-in sequencial para cada chama
        float flameAlpha = fminf(1.0f, (cutsceneTimer - i * 1.0f) * 2.0f);
        float textAlpha = fminf(1.0f, (cutsceneTimer - (i * 1.0f + 0.5f)) * 2.0f);

        if (flameAlpha > 0) {
            // Desenha a animação da chama
            Rectangle flameSrc = {frame * frameWidth, 0, frameWidth, flames[i].texture->height};
            Rectangle flameDest = {screenWidth/2 - 50, flames[i].position.y, 100, 100};
            DrawTexturePro(*flames[i].texture, flameSrc, flameDest, (Vector2){0}, 0, Fade(WHITE, flameAlpha));

            // Texto explicativo abaixo da chama
            if (textAlpha > 0) {
                Vector2 textSize = MeasureTextEx(mainFont, flames[i].text, 28, 0);
                DrawTextEx(mainFont, flames[i].text,
                         (Vector2){screenWidth/2 - textSize.x/2, flames[i].position.y + 120},
                         28, 0, Fade(flames[i].color, textAlpha));
            }
        }
    }

    // Instrução para continuar
    if (cutsceneTimer > 3.5f) { // Mostra depois que todas as chamas apareceram
        DrawTextEx(mainFont, "Pressione E para avancar",
                 (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "Pressione E para avancar", 30, 0).x/2,
                 screenHeight - 50}, 30, 0, Fade(GRAY, 0.5f + sin(GetTime()*5)*0.5f));
    }

    if (IsKeyPressed(KEY_E) && cutsceneTimer > 3.5f) {
        PlaySound(guitarSound);
        PlaySound(godSound);
        cutsceneState = 2;
        cutsceneTimer = 0;
    }
} break;

        case 2: { // Apresentação final do Deus do Rock
            float godAlpha = fminf(1.0f, cutsceneTimer * 0.2f);

            // Desenha a imagem com fade-in e efeito de brilho
            float godScale = 1.0f;
            Rectangle godSrc = {0, 0, godTex.width, godTex.height};
            Rectangle godDest = {
                screenWidth/2 - (godTex.width * godScale)/2,
                screenHeight/2 - (godTex.height * godScale)/2,
                godTex.width * godScale,
                godTex.height * godScale
            };

            // Desenha a imagem com fade-in
            DrawTexturePro(godTex, godSrc, godDest, (Vector2){0}, 0, Fade(WHITE, godAlpha));
			DrawRectangleGradientV(0, 0, screenWidth, screenHeight,
                        (Color){10, 0, 0, 40},
                        (Color){40, 0, 0, 150});
    		// Efeitos de partículas de fogo (sobrepostas à imagem)
    		for (int i = 0; i < 50; i++) {
    		    float x = sin(GetTime() * 2 + i) * screenWidth;
    		    float y = screenHeight - fmodf(cutsceneTimer * 100 + i * 10, screenHeight);
    		    DrawCircle(x, y, 3 + sin(GetTime() + i), Fade(ORANGE, 0.7f));
    		}

            // Diálogo
            const char* godText = "\"ENFRENTE-ME SE FOR CAPAZ, CRIATURA!\"";
            float textAlpha = fminf(1.0f, cutsceneTimer * 2.0f);

            DrawTextEx(titleFont, godText,
                     (Vector2){screenWidth/2 - MeasureTextEx(titleFont, godText, 50, 0).x/2,
                     screenHeight - 150},
                     50, 0, Fade(WHITE, textAlpha));

            // Instrução para começar
            if (cutsceneTimer > 3.5f) {
                DrawTextEx(mainFont, "Pressione ENTER para comecar o desafio",
                         (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "Pressione ENTER para comecar o desafio", 30, 0).x/2,
                         screenHeight - 50}, 30, 0, Fade(GRAY, 0.5f + sin(GetTime()*5)*0.5f));
            }
        } break;
    }
} break;

            case RESULTS: {
                // Fundo padrão
                DrawRectangleGradientV(0, 0, screenWidth, screenHeight,
                                       (Color){10, 0, 0, 255},
                                       (Color){40, 0, 0, 255});

                // Vitória no modo Deus
                if (godModeActive) {
                    if (!stats.songFailed) {
                    	// Captura o tempo apenas uma vez
                    	if (totalTime == 0.0f) {
                    	    storyEndTime = GetTime();
                    	    totalTime = storyEndTime - storyStartTime;
                    	}

                    	// Etapa 1: Tela de vitória + entrada de nome
                    	if (!showFinalScoreboard) {
                    	    DrawTextEx(titleFont, "VOCE VENCEU O DEUS DO ROCK!",
                    	               (Vector2){screenWidth/2 - MeasureTextEx(titleFont, "VOCE VENCEU O DEUS DO ROCK!", 70, 0).x/2, 150},
                    	               70, 0, GOLD);

                    	    DrawTextEx(mainFont, "Voce provou ser o verdadeiro Rei do Rock!",
                                   (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "Voce provou ser o verdadeiro Rei do Rock!", 40, 0).x/2, 250},
                                   40, 0, WHITE);


                        // Entrada de nome
                   		    if (!scoreAlreadySaved) enteringName = true;

                    	    if (enteringName) {
                            	int key = GetCharPressed();
                           		while (key > 0) {
                            	    if (key >= 32 && key <= 125 && nameLength < MAX_NAME_LENGTH - 1) {
                           		        playerName[nameLength++] = (char)key;
                            	        playerName[nameLength] = '\0';
                            	    }
                            	    key = GetCharPressed();
                            	}

                            	if (IsKeyPressed(KEY_BACKSPACE) && nameLength > 0) {
                            	    nameLength--;
                            	    playerName[nameLength] = '\0';
                            	}

                            	const char* tempoStr = TextFormat("Tempo final: %.2f segundos", totalTime);
                            	Vector2 tempoSize = MeasureTextEx(mainFont, tempoStr, 30, 0);
                            	DrawTextEx(mainFont, tempoStr,
                                       (Vector2){screenWidth/2 - tempoSize.x/2, 320}, 30, 0, WHITE);

                            	const char* promptStr = "Digite seu nome:";
                            	Vector2 promptSize = MeasureTextEx(mainFont, promptStr, 30, 0);
                            	DrawTextEx(mainFont, promptStr,
                                       (Vector2){screenWidth/2 - promptSize.x/2, 370}, 30, 0, WHITE);

                            	Vector2 nameSize = MeasureTextEx(mainFont, playerName, 30, 0);
                            	DrawTextEx(mainFont, playerName,
                                       (Vector2){screenWidth/2 - nameSize.x/2, 410}, 30, 0, YELLOW);

                            	if (IsKeyPressed(KEY_ENTER) && nameLength > 0) {
                            	    InsertScore(playerName, totalTime);
                            	    SaveScoreboardToFile("scoreboard.txt");
                            	    enteringName = false;
                            	    scoreAlreadySaved = true;
                            	    showFinalScoreboard = true;
                            	}
                        	}
                    	}

                        if (showFinalScoreboard) {
                            DrawText("PLACAR DE HERÓIS DO ROCK", screenWidth/2 - 200, 80, 30, YELLOW);
                            DrawScoreboard(mainFont, screenWidth/2 - 200, 130);

                            DrawText("Pressione ESPAÇO para voltar ao menu", screenWidth/2 - 200, 500, 20, GRAY);

                            if (IsKeyPressed(KEY_SPACE)) {
                                // Resetar tudo
                                showFinalScoreboard = false;
                                scoreAlreadySaved = false;
                                enteringName = false;
                                nameLength = 0;
                                playerName[0] = '\0';
                                godModeActive = false;
                                instory = false;
                                currentMapIndex = 1;
                                totalTime = 0.0f;
                                gameState = MAIN_MENU;
                            }
                        }

                            // Etapa 1: entrada de nome
                        else if (!stats.songFailed) {
                            if (totalTime == 0.0f) {
                                storyEndTime = GetTime();
                                totalTime = storyEndTime - storyStartTime;
                            }

                            DrawTextEx(titleFont, "VOCE VENCEU O DEUS DO ROCK!",
                                       (Vector2){screenWidth/2 - MeasureTextEx(titleFont, "VOCE VENCEU O DEUS DO ROCK!", 70, 0).x/2, 150},
                                       70, 0, GOLD);

                            DrawTextEx(mainFont, "Voce provou ser o verdadeiro Rei do Rock!",
                                       (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "Voce provou ser o verdadeiro Rei do Rock!", 40, 0).x/2, 250},
                                       40, 0, WHITE);

                            if (!scoreAlreadySaved) enteringName = true;

                            if (enteringName) {
                                int key = GetCharPressed();
                                while (key > 0) {
                                    if (key >= 32 && key <= 125 && nameLength < MAX_NAME_LENGTH - 1) {
                                        playerName[nameLength++] = (char)key;
                                        playerName[nameLength] = '\0';
                                    }
                                    key = GetCharPressed();
                                }

                                if (IsKeyPressed(KEY_BACKSPACE) && nameLength > 0) {
                                    nameLength--;
                                    playerName[nameLength] = '\0';
                                }


                                if (IsKeyPressed(KEY_ENTER) && nameLength > 0) {
                                    InsertScore(playerName, totalTime);
                                    enteringName = false;
                                    scoreAlreadySaved = true;
                                    showFinalScoreboard = true;
                                }
                            }
                        }
                        for (int i = 0; i < 50; i++) {
         					float x = sin(GetTime() * 2 + i) * screenWidth;
         					float y = screenHeight - fmodf(cutsceneTimer * 100 + i * 10, screenHeight);
         					DrawCircle(x, y, 3 + sin(GetTime() + i), Fade(ORANGE, 0.7f));
        				}
                    } else {
                        DrawTextEx(titleFont, "O DEUS DO ROCK TE DERROTOU!",
                                  (Vector2){screenWidth/2 - MeasureTextEx(titleFont, "O DEUS DO ROCK TE DERROTOU!", 70, 0).x/2, 150},
                                  70, 0, RED);

                        DrawTextEx(mainFont, "Tente novamente quando estiver preparado... (C)",
                                  (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "Tente novamente quando estiver preparado... (C)", 40, 0).x/2, 250},
                                  40, 0, WHITE);

                        for (int i = 0; i < 50; i++) {
         					float x = sin(GetTime() * 2 + i) * screenWidth;
         					float y = screenHeight - fmodf(cutsceneTimer * 100 + i * 10, screenHeight);
         					DrawCircle(x, y, 3 + sin(GetTime() + i), Fade(ORANGE, 0.7f));
        				}
                    }
                }
                else {
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
                	          (Vector2){screenWidth/2 - MeasureTextEx(titleFont, stats.songFailed ? "SONG FAILED!" : "SONG COMPLETE!", 80, 0).x/2, 80},
                	          80, 0, WHITE);

                	// Draw rating
                	DrawTextEx(titleFont, rating,
                	          (Vector2){screenWidth/2 - MeasureTextEx(titleFont, rating, 70, 0).x/2, 160},
                	          70, 0, ratingColor);

                	// Draw stats
                	int startY = 250;
                	int spacing = 40;

                	DrawTextEx(mainFont, TextFormat("FINAL SCORE: %08d", stats.score),
                	          (Vector2){screenWidth/2 - 300, (float)startY}, 40, 0, WHITE);
                	startY += spacing;

                	DrawTextEx(mainFont, TextFormat("ACCURACY: %.2f%%", accuracy),
                	          (Vector2){screenWidth/2 - 300, (float)startY}, 40, 0, WHITE);
                	startY += spacing;

                	// Seção específica para o modo história
                	if (instory) {
                	    // Linha divisória
                	    DrawRectangle(screenWidth/2 - 300, startY, 600, 2, Fade(WHITE, 0.3f));
                	    startY += 20;

                	    if (stats.songFailed) {
                	        // Mensagem de falha
                	        int fameLoss = 0;
                	        switch (currentMap->mapId) {
                	            case 1: fameLoss = 5; break;
               	 	            case 2: fameLoss = 10; break;
                	            case 3: fameLoss = 15; break;
                	    }

                 		DrawTextEx(mainFont, TextFormat("Voce perdeu %d%% de fama!", fameLoss),
                        	      (Vector2){screenWidth/2 - 300, (float)startY}, 40, 0, RED);
                        startY += spacing;
                    } else {
                    	// Detalhes do ganho de fama
                    	bool isFavorite = IsFavoriteSong(selectedSong, currentMap->mapId);
                    	int stars;
                    	if (accuracy >= 95.0f) stars = 5;
                   		else if (accuracy >= 90.0f) stars = 4;
                    	else if (accuracy >= 80.0f) stars = 3;
                        else if (accuracy >= 70.0f) stars = 2;
                    	else stars = 1;

                        int baseFameGain = 0;
                        switch (stars) {
                        	case 5: baseFameGain = 15; break;
                        	case 4: baseFameGain = 10; break;
                        	default: baseFameGain = 5; break;
                        }

                        int bonusFame = 0;
                       	if (isFavorite) bonusFame += 5;
                        if (HasBlessing(&player, BLESS_SCORE_BOOST)) bonusFame += 5;

                        if (isFavorite) {
                        	DrawTextEx(mainFont, "Bonus: Musica favorita do publico (+5%)",
                        	          (Vector2){screenWidth/2 - 300, (float)startY}, 40, 0, GREEN);
                        	startY += spacing;
                        }

                        if (HasBlessing(&player, BLESS_SCORE_BOOST)) {
                       		DrawTextEx(mainFont, "Bonus: Bencao de Fama (+5%)",
                        	          (Vector2){screenWidth/2 - 300, (float)startY}, 40, 0, GREEN);
                        	startY += spacing;
                        }

                        DrawTextEx(mainFont, TextFormat("Fama ganha: %d%%", baseFameGain + bonusFame),
                        	      (Vector2){screenWidth/2 - 300, (float)startY}, 40, 0, GOLD);
                        startY += spacing;
                    }
                }

                if (!instory) {
                    // Hit breakdown
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
                    startY += spacing;
                }

                // Continue prompt
                DrawTextEx(mainFont, "Press SPACE to Continue",
                          (Vector2){screenWidth/2 - MeasureTextEx(mainFont, "Press SPACE to Continue", 30, 2).x/2,
                          screenHeight - 50}, 30, 2, GRAY);
				}

            } break;
        }

        EndDrawing();
    }

    // Limpeza dos recursos
    UnloadTexture(player.spriteSheet);
    UnloadTexture(burningStartTex);
    UnloadTexture(burningEndTex);
    UnloadTexture(burningLoopPurple);
	UnloadTexture(burningLoopWhite);
	UnloadTexture(burningLoopGreen);
    UnloadTexture(menuBackgroundTex);
    UnloadTexture(godBackgroundTex);
    UnloadSound(noteMissSound);
    UnloadSound(guitarSound);
    UnloadSound(godSound);
    UnloadSound(starPowerSound);
    UnloadSound(menuSelectSound);
    UnloadSound(menuScrollSound);
    UnloadMusicStream(gameMusic);
    UnloadMusicStream(menuMusic);
    UnloadMusicStream(map1Music);
    UnloadMusicStream(map2Music);
    UnloadMusicStream(map3Music);
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
    memcpy(songs[0].charts, KillerQueen, sizeof(KillerQueen));
    memcpy(songs[1].charts, Livin_Prayer, sizeof(Livin_Prayer));
    memcpy(songs[2].charts, Thunder, sizeof(Thunder));
    memcpy(songs[3].charts, Thunder, sizeof(Thunder));
    memcpy(songs[4].charts, SweetChildOMine, sizeof(SweetChildOMine));
    memcpy(songs[5].charts, BringMeToLife, sizeof(BringMeToLife));
    memcpy(songs[6].charts, Thunder, sizeof(Thunder));
    memcpy(songs[7].charts, Thunder, sizeof(Thunder));
    memcpy(songs[8].charts, Thunder, sizeof(Thunder));
    memcpy(songs[9].charts, Thunder, sizeof(Thunder));
    memcpy(songs[10].charts, TheTrooper, sizeof(TheTrooper));
}

// Inicializa o sistema de fama
void InitFameSystem(Player* player) {
    player->fama = 0;
    player->blessings.count = 0;
    for (int i = 0; i < 3; i++) {
        player->blessings.blessings[i] = BLESS_NONE;
    }
}

void DrawRockMeter(float value, int x, int y, int width, int height, bool hasBlessing) {
    // Draw meter background
    DrawRectangle(x, y, width, height, (Color){20, 20, 20, 255});

    // Calculate the fill width
    float fillWidth = width * value;

    if (value < 0.25f) {
        DrawRectangleGradientH(x, y, fillWidth, height, RED, (Color){255, 100, 0, 255});
    } else if (value < 0.5f) {
        DrawRectangleGradientH(x, y, fillWidth, height, (Color){255, 100, 0, 255}, YELLOW);
    } else {
        if (hasBlessing) {
          DrawRectangleGradientH(x, y, fillWidth, height, SKYBLUE, BLUE);
        } else {
          DrawRectangleGradientH(x, y, fillWidth, height, YELLOW, GREEN);
        }
    }

    // Outline especial para bênção ativa
    if (hasBlessing) {
        DrawRectangleLinesEx((Rectangle){x, y, width, height}, 2, GOLD);

        // Marcador de fail threshold com efeito
        float thresholdX = x + width * 0.25f;
        DrawLineEx((Vector2){thresholdX, y},
                  (Vector2){thresholdX, y + height},
                  2, ColorAlpha(GOLD, 0.5f));
    } else {
        // Outline normal
        DrawRectangleLines(x, y, width, height, WHITE);
        DrawLine(x + width * 0.25f, y, x + width * 0.25f, y + height, WHITE);
    }
}

// Desenha a barra de fama
void DrawFameMeter(Player* player, int screenWidth, Font font) {
    int barWidth = 500;
    int barHeight = 40;
    int barX = screenWidth/2 - barWidth/2;
    int barY = 20;

    // Fundo com borda e sombra (camadas)
    DrawRectangle(barX + 4, barY + 4, barWidth, barHeight, (Color){0, 0, 0, 120}); // Sombra
    DrawRectangle(barX, barY, barWidth, barHeight, (Color){40, 40, 40, 255});      // Fundo principal
    DrawRectangleLines(barX, barY, barWidth, barHeight, (Color){255, 255, 255, 180}); // Moldura branca

    // Barra de fama preenchida com cor dourada e brilho
    float fillWidth = barWidth * (player->fama / 100.0f);
    Color fameColor = (Color){255, 215, 0, 255}; // Ouro
    DrawRectangle(barX, barY, (int)fillWidth, barHeight, fameColor);

    // Marcadores de "bênção" (25%, 50%, 75%)
    for (int i = 1; i <= 3; i++) {
        int markerX = barX + (barWidth * i / 4);
        DrawLine(markerX, barY, markerX, barY + barHeight, (Color){255, 255, 255, 100});
    }

    // Texto de FAMA estilizado como manchete
    const char* text = TextFormat("FAMA: %d%%", player->fama);
    int fontSize = 28;
    Vector2 textSize = MeasureTextEx(font, text, fontSize, 0);
    Vector2 textPos = { screenWidth/2 - textSize.x/2, barY + barHeight/2 - textSize.y/2 };

    // Contorno (preto)
    DrawTextEx(font, text, (Vector2){textPos.x + 2, textPos.y + 2}, fontSize, 0, BLACK);

    // Texto principal (branco)
    DrawTextEx(font, text, textPos, fontSize, 0, WHITE);
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

void DrawHitEffects(Font mainFont) {
    for (int i = 0; i < MAX_HIT_EFFECTS; i++) {
        if (hitEffects[i].active) {
            int lane = hitEffects[i].lane;
            float duration = hitEffects[i].isForgiveness ? FORGIVENESS_EFFECT_DURATION :
                              hitEffects[i].isStart ? HIT_EFFECT_DURATION : HIT_EFFECT_DURATION / 2;

            if (duration <= 0.0f) continue; // Evita divisão por zero

            float progress = hitEffects[i].timer / duration;
            progress = clamp(progress, 0.0f, 1.0f);

            float xPos = HIGHWAY_LEFT + lane * LANE_WIDTH;
            float yPos = TARGET_Y - 55;

            if (hitEffects[i].isForgiveness) {
                // Aura verde crescente (menor, mais à direita)
                float radius = 30.0f * (1.0f + progress); // menor
                Color fadeColor = Fade(GREEN, 0.7f * progress);

            // Aura externa com deslocamento à direita
                DrawCircle(xPos + 60, yPos, radius, Fade(GREEN, 0.2f * progress));
            // Anéis concêntricos (também mais pra baixo e à direita)
                for (int r = 1; r <= 3; r++) {
                    DrawCircleLines(xPos + 60, yPos, radius - r * 8, fadeColor);
                }

                // Texto "FORGIVEN" menor e mais pra baixo/direita
                const char* text = "FORGIVEN";
                int fontSize = 20;
                Vector2 textSize = MeasureTextEx(mainFont, text, fontSize, 0);
                DrawTextEx(mainFont, text,
                           (Vector2){xPos + 64 - textSize.x / 2, yPos - 10 - (1.0f - progress) * 30},
                           fontSize, 0, fadeColor);
            } else if (hitEffects[i].lane == -1) {
                // Efeito de escudo ativado
                float progress = hitEffects[i].timer / 1.0f;
                progress = clamp(progress, 0.0f, 1.0f);

                Vector2 center = {
                    HIGHWAY_LEFT + HIGHWAY_WIDTH / 2,
                    TARGET_Y
                };

                // Aura pulsante
                float pulse = 0.5f + sin(GetTime() * 10) * 0.5f;
                Color auraColor = ColorAlpha(SKYBLUE, pulse * progress);

                // Anéis concêntricos
                for (int r = 1; r <= 3; r++) {
                    float radius = 50 + r * 20 * (1.0f - progress);
                    DrawCircleLines((int)center.x, (int)center.y, radius, auraColor);
                }

                // Texto flutuante
                const char* text = "ESCUDO ATIVO";
                int fontSize = 24;
                Vector2 textSize = MeasureTextEx(mainFont, text, fontSize, 0);
                DrawTextEx(mainFont, text,
                          (Vector2){center.x - textSize.x/2,
                                   center.y - 50 - (1.0f - progress) * 30},
                          fontSize, 0, auraColor);
            } else if (hitEffects[i].isStart) {
                // Animação de início (burning_start.png)
                int frame = (int)((1.0f - progress) * 4);
                frame = clamp(frame, 0, 3);
                Rectangle src = {frame * 24.0f, 0, 24.0f, 32.0f};
                Rectangle dest = {xPos, yPos, 96.0f, 54.0f};
                DrawTexturePro(burningStartTex, src, dest, (Vector2){0}, 0, WHITE);
            } else {
                // Animação de término (burning_end.png)
                int frame = (int)((1.0f - progress) * 5);
                frame = clamp(frame, 0, 4);
                Rectangle src = {frame * 24.0f, 0, 24.0f, 32.0f};
                Rectangle dest = {xPos, yPos, 120.0f, 54.0f};
                DrawTexturePro(burningEndTex, src, dest, (Vector2){0}, 0, WHITE);
            }
        }
    }
}

void DrawShieldIndicator(int shieldsAvailable, int screenWidth, int screenHeight, Font font) {
    // Posição base
    int baseX = screenWidth - 220;
    int baseY = screenHeight - 150;

    // Ícones
    for (int i = 0; i < 3; i++) {
        int cx = baseX + 10 + i * 50;
        int cy = baseY + 45;

        if (i < shieldsAvailable) {
            DrawCircle(cx, cy, 22, Fade(BLUE, 0.2f));     // Aura
            DrawCircle(cx, cy, 15, SKYBLUE);              // Corpo
            DrawCircleLines(cx, cy, 15, WHITE);           // Borda
        } else {
            DrawCircle(cx, cy, 15, Fade(BLUE, 0.1f));      // Vazio
            DrawCircleLines(cx, cy, 15, Fade(WHITE, 0.3f)); // Borda mais clara
        }
    }
}

void SpawnHitEffect(int lane) {
    for (int i = 0; i < MAX_HIT_EFFECTS; i++) {
        if (!hitEffects[i].active) {
            hitEffects[i].isForgiveness = false;
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

            blessingOptions[0] = (RockBlessing)1 + i*2;
            blessingOptions[1] = (RockBlessing)2 + i*2;

            blessingOptionsInitialized = true;
            break;
        }
    }
}

// Verifica se a música é a favorita do público no mapa atual
bool IsFavoriteSong(int songIndex, int mapLevel) {
    switch (mapLevel) {
    case 1: return songIndex == 1;
    case 2: return songIndex == 4;
    case 3: return songIndex == 8;
    default: return false;
    }
}

// Aplica os efeitos das bênçãos ativas
void ApplyBlessings(Player* player, GameStats* stats, float deltaTime) {
    for (int i = 0; i < player->blessings.count; i++) {
        switch (player->blessings.blessings[i]) {
        case BLESS_ROCK_METER: {
                // Resistência do Rock - Melhorado
                if (stats->rockMeter < 1.0f) {
                    stats->rockMeter += 0.06f * deltaTime;
                }
        } break;

        case BLESS_STAR_POWER: {
                // Explosão Estelar
                stats->starPower += 0.6f * deltaTime;
        } break;

        case BLESS_SCORE_BOOST: {
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
    // Encontra um slot de efeito vazio
    for (int i = 0; i < MAX_HIT_EFFECTS; i++) {
        if (!hitEffects[i].active) {
            hitEffects[i].lane = -1; // Efeito central, não associado a uma lane
            hitEffects[i].timer = 1.0f; // Duração maior para o efeito de escudo
            hitEffects[i].active = true;
            hitEffects[i].isForgiveness = false;
            hitEffects[i].isStart = false;
            break;
        }
    }
}

void SpawnForgivenessEffect(int lane, GameStats* stats) {
    for (int i = 0; i < MAX_HIT_EFFECTS; i++) {
        if (!hitEffects[i].active) {
            hitEffects[i].lane = lane;
            hitEffects[i].timer = FORGIVENESS_EFFECT_DURATION;
            hitEffects[i].active = true;
            hitEffects[i].isForgiveness = true;

            // Indica no status do jogo que o efeito está ativo
            stats->showForgivenessEffect = true;
            stats->forgivenessLane = lane;
            break;
        }
    }
}

bool ShouldIgnoreMiss(Player *player, GameStats* stats, int lane) {
    // Aura Inabalável
    if (HasBlessing(player, BLESS_FORGIVENESS)) {
        if (stats->forgivenessMisses < FORGIVENESS_CHARGES) {
            stats->forgivenessMisses++;
            SpawnForgivenessEffect(lane, stats);
            return true;
        }
    } else if (HasBlessing(player, BLESS_RHYTHM_SHIELD) && stats->rhythmShields > 0) {
        stats->rhythmShields--;
        SpawnShieldEffect();
        return true;
    }
    return false;
}

void ShowTempWarning(const char* message, float duration) {
    strncpy(tempWarning.message, message, sizeof(tempWarning.message) - 1);
    tempWarning.showTime = duration;
    tempWarning.timer = 0;
}

void GenerateGodModeNotes(Note* notes, int maxNotes, float currentTime, Music* gameMusic, GameStats* stats) {
  	if (!IsMusicStreamPlaying(*gameMusic)) return;
    // Padrões de riff pré-definidos para o modo Deus
	if (currentTime == 0) {
          lastRiffTime = 0.0f;
	}

    // Define o intervalo entre riffs baseado no combo atual
    float riffInterval;
    if (stats->combo >= GOD_MODE_COMBO_THRESHOLD) {
        riffInterval = 0.6f;
    } else { // Fase 1 - Normal
        riffInterval = 0.65f;
    }

    if (currentTime - lastRiffTime > riffInterval) {
        lastRiffTime = currentTime;

        // Escolhe um padrão de riff aleatório
        int riffPattern = GetRandomValue(0, 3);
        float baseTime = currentTime; // Começa 1 segundo depois

        // Define a probabilidade de notas especiais baseado no combo
        int specialNoteChance;
        if (stats->combo >= GOD_MODE_COMBO_THRESHOLD) { // Fase 2 - 60% chance
            specialNoteChance = 6;
        } else { // Fase 1 - 20% chance
            specialNoteChance = 8;
        }

        switch (riffPattern) {
            case 0: // Riff ascendente
                for (int i = 0; i < NUM_LANES; i++) {
                    int type = (GetRandomValue(0, 9) < specialNoteChance) ? 0 : GetRandomValue(1, 3);
                    AddSpecialNote(notes, maxNotes, i, baseTime + i*0.1f, type);

                    if (stats->combo >= GOD_MODE_COMBO_THRESHOLD && i == 4) {
                        AddSpecialNote(notes, maxNotes, 0, baseTime + i*0.1f, type);
                    }
                }
                break;

            case 1: // Riff descendente
                for (int i = NUM_LANES-1; i >= 0; i--) {
                    int type = (GetRandomValue(0, 9) < specialNoteChance) ? 0 : GetRandomValue(1, 3);
                    AddSpecialNote(notes, maxNotes, i, baseTime + (NUM_LANES-1-i)*0.1f, type);

                    if (stats->combo >= GOD_MODE_COMBO_THRESHOLD && i == 0) {
                        AddSpecialNote(notes, maxNotes, 4, baseTime + (NUM_LANES-1-i)*0.1f, type);
                    }
                }
                break;

            case 2: // Notas simultâneas
                for (int i = 0; i < NUM_LANES; i++) {
                    if (GetRandomValue(0, 1)) { // 50% chance de spawnar em cada lane
                        int type = (GetRandomValue(0, 9) < specialNoteChance) ? 0 : GetRandomValue(1, 3);
                        AddSpecialNote(notes, maxNotes, i, baseTime, type);
                        AddSpecialNote(notes, maxNotes, i, baseTime + 0.3f, type);
                    }
                }
                break;

            case 3: // Notas alternadas
                for (int i = 0; i < NUM_LANES; i += 2) {
                    int type = (GetRandomValue(0, 9) < specialNoteChance) ? 0 : GetRandomValue(1, 3);
                    AddSpecialNote(notes, maxNotes, i, baseTime + i*0.1f, type);

                    // Na fase 3, adiciona notas entre as alternadas
                    if (stats->combo >= GOD_MODE_COMBO_THRESHOLD && i+1 < NUM_LANES) {
                        AddSpecialNote(notes, maxNotes, i+1, baseTime + i*0.1f + 0.2f, type);
                    }
                }
                break;
        }
    }
}

void AddSpecialNote(Note* notes, int maxNotes, int lane, float spawnTime, int specialType) {
    for (int i = 0; i < maxNotes; i++) {
        if (!notes[i].active) {
          	notes[i] = (Note){0};
            notes[i].lane = lane;
            notes[i].hit = false;
            notes[i].spawnTime = spawnTime;
            notes[i].specialType = specialType;
            notes[i].specialTimer = 0.0f;
            notes[i].active = true;
            notes[i].rect = (Rectangle){
                HIGHWAY_LEFT + lane * LANE_WIDTH + (LANE_WIDTH - NOTE_WIDTH)/2,
                -NOTE_HEIGHT,
                NOTE_WIDTH,
                NOTE_HEIGHT
            };
            // Define cor base para todos os tipos de notas

            switch (lane) {
                case 0: notes[i].color = (Color){255, 50, 50, 255}; break;
                case 1: notes[i].color = (Color){255, 150, 50, 255}; break;
                case 2: notes[i].color = (Color){50, 255, 50, 255}; break;
                case 3: notes[i].color = (Color){50, 150, 255, 255}; break;
                case 4: notes[i].color = (Color){200, 50, 255, 255}; break;
            }
            // Se for nota especial, ajusta a cor
            if (specialType > 0) {
                switch (specialType) {
                    case SPECIAL_NOTE_FIRE:    notes[i].color = (Color){252, 140, 212, 255}; break;
                    case SPECIAL_NOTE_POISON:  notes[i].color = (Color){212, 252, 124, 255}; break;
                    case SPECIAL_NOTE_INVISIBLE: notes[i].color = (Color){228, 252, 252, 255}; break;
                }
            }

            break;
        }
    }
}

void ResetGodModeState(Note* notes, GameStats* stats, Music* gameMusic) {
    // Reseta todas as notas
    for (int i = 0; i < MAX_NOTES; i++) {
        notes[i].active = false;
    }

    // Reseta estatísticas do jogo
    memset(stats, 0, sizeof(GameStats));
    stats->multiplier = 1.0f;
    stats->multiplierLevel = 1;
    stats->rockMeter = 0.5f;
    stats->songFailed = false;
    stats->forgivenessMisses = 0;
    stats->perfectStreak = 0;
    stats->rhythmShields = 0;

    // Reseta variáveis do God Mode
    godModeActive = false;
    comboModeTimer = 0.0f;
    invisibleModeTimer = 0.0f;
    noteSpeedMultiplier = 1.0f;
    lastRiffTime = 0.0f;

    // Para e reseta a música
    StopMusicStream(*gameMusic);
    *gameMusic = LoadMusicStream("assets/musics/doom.mp3");
}

void InsertScore(const char* name, float time) {
    if (numScores < MAX_SCORES) {
        strcpy(topScores[numScores].name, name);
        topScores[numScores].time = time;
        numScores++;
    } else if (time < topScores[MAX_SCORES - 1].time) {
        // Substitui o pior tempo
        strcpy(topScores[MAX_SCORES - 1].name, name);
        topScores[MAX_SCORES - 1].time = time;
    } else {
        return; // tempo não é bom o suficiente
    }

    // Ordenar usando insertion sort
    for (int i = 1; i < numScores; i++) {
        ScoreEntry key = topScores[i];
        int j = i - 1;
        while (j >= 0 && topScores[j].time > key.time) {
            topScores[j + 1] = topScores[j];
            j--;
        }
        topScores[j + 1] = key;
    }
}

void DrawScoreboard(Font font, int x, int y) {
    for (int i = 0; i < numScores; i++) {
        DrawTextEx(font, TextFormat("%d. %s - %.2f segundos", i + 1, topScores[i].name, topScores[i].time),
                   (Vector2){x, y + i * 30}, 24, 1, WHITE);
    }
}

void SaveScoreboardToFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) return;

    for (int i = 0; i < numScores; i++) {
        fprintf(file, "%s %.2f\n", topScores[i].name, topScores[i].time);
    }

    fclose(file);
}

void LoadScoreboardFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return;

    numScores = 0;
    while (fscanf(file, "%s %f", topScores[numScores].name, &topScores[numScores].time) == 2) {
        numScores++;
        if (numScores >= MAX_SCORES) break;
    }

    fclose(file);
}
