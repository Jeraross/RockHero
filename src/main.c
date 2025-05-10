#include "raylib.h"
#include "../include/entities/player.h"
#include "../include/maps/mapa1.h"
#include "../include/utils/utils.h"
#include "gemini.h"
#include <string.h>
#include "../include/utils/constants.h"

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Jogo com Player e Polnareff");
    SetTargetFPS(60);

    if (!IsWindowFullscreen()) {
        ToggleFullscreen();
    }

    Player player;
    InitPlayer(&player);
    player.frozen = false;

    MapData map;
    InitMap(&map);


    while (!WindowShouldClose()) {
        UpdateMap(&map, &player);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawMap(&map, &player);
        DrawPlayer(&player);

        DrawText(TextFormat("Posição Player: (%.0f, %.0f)", player.position.x, player.position.y),
                 10, 10, 20, DARKGRAY);
        DrawText("Use as setas para mover", 10, 40, 20, DARKGRAY);
        EndDrawing();
    }

    UnloadTexture(player.spriteSheet);
    UnloadTexture(map.polnareff.spriteSheet);
    if (map.background.id != 0) UnloadTexture(map.background);
    UnloadSound(map.typeSound);
    CloseWindow();

    return 0;
}

