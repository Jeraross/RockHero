#include "../../include/entities/polnareff.h"

void InitPolnareff(Polnareff *polnareff, Vector2 position) {
    polnareff->spriteSheet = LoadTexture("assets/sprites/polnareff.png");
    polnareff->position = position;
    polnareff->currentFrame = 1;
    polnareff->frameCounter = 0;
    polnareff->scale = POLNAREFF_SCALE;
}

void UnloadPolnareff(Polnareff *polnareff) {
    if (polnareff->spriteSheet.id != 0) {
        UnloadTexture(polnareff->spriteSheet);
    }
}

void UpdatePolnareff(Polnareff *polnareff) {
    polnareff->frameCounter++;

    if (polnareff->frameCounter >= (60 / POLNAREFF_ANIM_SPEED)) {
        polnareff->frameCounter = 1;
        polnareff->currentFrame++;

        if (polnareff->currentFrame >= POLNAREFF_FRAMES) {
            polnareff->currentFrame = 1;
        }
    }
}

