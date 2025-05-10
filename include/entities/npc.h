#ifndef NPC_H
#define NPC_H

#include "../../include_raylib/raylib.h"

typedef struct {
    Texture2D spriteSheet;
    Vector2 position;
    int currentFrame;
    int frameCounter;
    float scale;

    int frameCount;
    int animSpeed;
    int frameWidth;
    int frameHeight;
    int frameDistance;
} Npc;

void InitNpc(Npc *npc, Vector2 position, const char *spritePath,
             int frameCount, int animSpeed, int frameWidth,
             int frameHeight, int frameDistance, float scale);

void UpdateNpc(Npc *npc);
void UnloadNpc(Npc *npc);

#endif
