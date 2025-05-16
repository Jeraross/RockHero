#ifndef PLAYER_H
#define PLAYER_H

#include "../../include_raylib/raylib.h"

#define NUM_FRAMES 13
#define PLAYER_SPEED 8.0f
#define ANIMATION_SPEED 8
#define FRAME_WIDTH 80
#define FRAME_HEIGHT 123
#define FRAME_SPACING 227
#define START_OFFSET_X 20
#define PLAYER_SCALE 2.0f

typedef enum {
    STATE_IDLE,
    STATE_WALK
} PlayerState;

// Tipos de bênçãos
typedef enum {
    BLESS_NONE,
    BLESS_ROCK_METER,    // Rock meter desce mais devagar
    BLESS_SCORE_BOOST,   // Multiplicador de pontuação
    BLESS_FORGIVENESS,   // Menos penalidade por erros
    BLESS_RHYTHM_SHIELD, // Escudo
    BLESS_COMBO,         // Combos maiores dão mais pontos
    BLESS_STAR_POWER     // Star power recarrega mais rápido
} RockBlessing;

// Estrutura para armazenar as bênçãos ativas
typedef struct {
    RockBlessing blessings[3]; // Máximo de 3 bênçãos (25%, 50%, 75%)
    int count;
} PlayerBlessings;

typedef struct {
    Texture2D spriteSheet;
    Vector2 position;
    int currentFrame;
    int frameCounter;
    bool facingRight;
    PlayerState state;
    bool frozen;
    int fama;
    PlayerBlessings blessings;
} Player;

void InitPlayer(Player *player);
void UpdatePlayer(Player *player);
void DrawPlayer(Player *player);

#endif