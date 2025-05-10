#include "../../include/entities/avdol.h"

void InitAvdol(Avdol *avdol, Vector2 position) {
    avdol->spriteSheet = LoadTexture("assets/sprites/avdol (1).png");  // Supondo que você tenha a sprite do Avdol.
    avdol->position = position;
    avdol->currentFrame = 1;
    avdol->frameCounter = 0;
    avdol->scale = AVDOL_SCALE;
}

void UnloadAvdol(Avdol *avdol) {
    if (avdol->spriteSheet.id != 0) {
        UnloadTexture(avdol->spriteSheet);
    }
}

void UpdateAvdol(Avdol *avdol) {
    avdol->frameCounter++;

    if (avdol->frameCounter >= (60 / AVDOL_ANIM_SPEED)) {
        avdol->frameCounter = 1;
        avdol->currentFrame++;

        if (avdol->currentFrame >= AVDOL_FRAMES) {
            avdol->currentFrame = 1;
        }
    }
}
