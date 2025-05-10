#ifndef AVDOL_H
#define AVDOL_H

#include "../../include_raylib/raylib.h"

#define AVDOL_FRAMES 7
#define AVDOL_ANIM_SPEED 8
#define AVDOL_FRAME_WIDTH 164
#define AVDOL_FRAME_HEIGHT 124
#define AVDOL_FRAME_DISTANCE 240
#define AVDOL_SCALE 2.0f

typedef struct {
    Texture2D spriteSheet;
    Vector2 position;
    int currentFrame;
    int frameCounter;
    float scale;
} Avdol;

void InitAvdol(Avdol *avdol, Vector2 position);
void UnloadAvdol(Avdol *avdol);
void UpdateAvdol(Avdol *avdol); // ← Adicionada esta linha

#endif
