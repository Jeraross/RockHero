#include "../../include/entities/npc.h"

void InitNpc(Npc *npc, Vector2 position, const char *spritePath,
             int frameCount, int animSpeed, int frameWidth,
             int frameHeight, int frameDistance, float scale) {
    npc->spriteSheet = LoadTexture(spritePath);
    npc->position = position;
    npc->currentFrame = 1;
    npc->frameCounter = 0;
    npc->scale = scale;

    npc->frameCount = frameCount;
    npc->animSpeed = animSpeed;
    npc->frameWidth = frameWidth;
    npc->frameHeight = frameHeight;
    npc->frameDistance = frameDistance;
}

void UpdateNpc(Npc *npc) {
    npc->frameCounter++;
    if (npc->frameCounter >= (60 / npc->animSpeed)) {
        npc->frameCounter = 1;
        npc->currentFrame++;
        if (npc->currentFrame >= npc->frameCount) {
            npc->currentFrame = 1;
        }
    }
}

void UnloadNpc(Npc *npc) {
    if (npc->spriteSheet.id != 0) {
        UnloadTexture(npc->spriteSheet);
    }
}
