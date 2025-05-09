#include "raylib.h"
#include "../include/player.h"
#include "../include/maps/mapa1.h"
#include "../include/utils/utils.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Jogo com Player e Polnareff");
    SetTargetFPS(60);

    if (!IsWindowFullscreen()) {
        ToggleFullscreen();
    }

    Player player;
    InitPlayer(&player);

    MapData map;
    InitMap(&map);

    while (!WindowShouldClose()) {
        UpdatePlayer(&player);
        UpdatePolnareff(&map.polnareff);

        BeginDrawing();
        DrawMap(&map);
        DrawPlayer(&player);

        // Debug info
        DrawText(TextFormat("Posição Player: (%.0f, %.0f)", player.position.x, player.position.y), 10, 10, 20, DARKGRAY);
        DrawText("Use as setas para mover", 10, 40, 20, DARKGRAY);
        DrawText(TextFormat("Frame Polnareff: %d/%d", map.polnareff.currentFrame, POLNAREFF_FRAMES), 10, 70, 20, DARKGRAY);
        EndDrawing();
    }

    UnloadTexture(player.spriteSheet);
    UnloadTexture(map.polnareff.spriteSheet);
    if (map.background.id != 0) UnloadTexture(map.background);
    CloseWindow();

    return 0;
}