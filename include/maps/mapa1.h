#ifndef MAPA1_H
#define MAPA1_H

#include "../../include_raylib/raylib.h"

#define POLNAREFF_FRAMES 7
#define POLNAREFF_ANIM_SPEED 8
#define POLNAREFF_FRAME_WIDTH 191
#define POLNAREFF_FRAME_HEIGHT 155
#define POLNAREFF_FRAME_DISTANCE 185
#define POLNAREFF_SCALE 2.0f

typedef struct {
    Texture2D spriteSheet;
    Vector2 position;
    int currentFrame;
    int frameCounter;
    float scale;
} Polnareff;

typedef struct {
    Texture2D background;
    Polnareff polnareff;
} MapData;

void InitMap(MapData *map);
void UpdatePolnareff(Polnareff *polnareff);
void DrawMap(MapData *map);

#endif