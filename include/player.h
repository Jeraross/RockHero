#ifndef PLAYER_H
#define PLAYER_H

#include "../include_raylib/raylib.h"

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

typedef struct {
    Texture2D spriteSheet;
    Vector2 position;
    int currentFrame;
    int frameCounter;
    bool facingRight;
    PlayerState state;
} Player;

void InitPlayer(Player *player);
void UpdatePlayer(Player *player);
void DrawPlayer(Player *player);

#endif