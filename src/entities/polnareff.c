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
