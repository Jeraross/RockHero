#include "../../include/maps/mapa1.h"
#include "../../include/entities/polnareff.h"
#include "../../include/utils/utils.h"

void InitMap(MapData *map) {
    map->background = LoadTexture("assets/maps/PNG/City2/Bright/City2.png");

    Vector2 polnareffPos = {
            GetScreenWidth() * 0.75f,
            (1080 - 200) - POLNAREFF_FRAME_HEIGHT * POLNAREFF_SCALE
    };

    InitPolnareff(&map->polnareff, polnareffPos);
}

void UpdatePolnareff(Polnareff *polnareff) {
    polnareff->frameCounter++;
    if (polnareff->frameCounter >= (60 / POLNAREFF_ANIM_SPEED)) {
        polnareff->frameCounter = 0;
        polnareff->currentFrame++;

        if (polnareff->currentFrame >= POLNAREFF_FRAMES)
            polnareff->currentFrame = 1;
    }
}

void DrawMap(MapData *map) {
    if (map->background.id != 0) {
        DrawTexture(map->background, 0, 0, WHITE);
    } else {
        ClearBackground(RAYWHITE);
    }

    Rectangle polnareffSource = {
            map->polnareff.currentFrame * POLNAREFF_FRAME_DISTANCE,
            0,
            POLNAREFF_FRAME_WIDTH,
            POLNAREFF_FRAME_HEIGHT
    };

    Rectangle polnareffDest = {
            map->polnareff.position.x,
            map->polnareff.position.y,
            POLNAREFF_FRAME_WIDTH * map->polnareff.scale,
            POLNAREFF_FRAME_HEIGHT * map->polnareff.scale
    };

    DrawTexturePro(map->polnareff.spriteSheet, polnareffSource, polnareffDest, (Vector2){0, 0}, 0.0f, WHITE);
}
