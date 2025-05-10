#include "raylib.h"
#include "../include/entities/player.h"
#include "../include/maps/mapa1.h"
#include "../include/maps/mapa2.h"
#include "../include/utils/utils.h"
#include "gemini.h"
#include <string.h>
#include "../include/utils/constants.h"

typedef enum { MAPA1, MAPA2 } CurrentMap; // Enum para controlar o mapa atual

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Jogo com Player e Polnareff");
    SetTargetFPS(60);

    if (!IsWindowFullscreen()) {
        ToggleFullscreen();
    }

    Player player;
    InitPlayer(&player);
    player.frozen = false;

    MapData map1;
    InitMap(&map1);  // Mapa 1 carregado inicialmente

    MapData map2;
    InitMap2(&map2); // Mapa 2 carregado, mas não usado ainda

    CurrentMap currentMap = MAPA1; // Começa com o mapa 1

    while (!WindowShouldClose()) {
        // Verifica se a tecla "G" foi pressionada para alternar o mapa
        if (IsKeyPressed(KEY_G)) {
            if (currentMap == MAPA1) {
                currentMap = MAPA2;
            } else {
                currentMap = MAPA1;
            }
        }

        // Atualiza o mapa atual
        if (currentMap == MAPA1) {
            UpdateMap(&map1, &player);  // Atualiza o mapa 1
        } else {
            UpdateMap2(&map2, &player); // Atualiza o mapa 2
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Desenha o mapa atual
        if (currentMap == MAPA1) {
            DrawMap(&map1, &player);  // Desenha o mapa 1
        } else {
            DrawMap2(&map2, &player); // Desenha o mapa 2
        }

        // Desenha o player
        DrawPlayer(&player);

        // Informação de posição
        DrawText(TextFormat("Posição Player: (%.0f, %.0f)", player.position.x, player.position.y),
                 10, 10, 20, DARKGRAY);
        DrawText("Use as setas para mover", 10, 40, 20, DARKGRAY);

        // Texto informativo sobre o mapa atual
        if (currentMap == MAPA1) {
            DrawText("Mapa 1 Carregado", 10, 70, 20, GREEN);
        } else {
            DrawText("Mapa 2 Carregado", 10, 70, 20, GREEN);
        }

        EndDrawing();
    }

    // Limpeza dos recursos
    UnloadTexture(player.spriteSheet);
    if (currentMap == MAPA1) {
        UnloadTexture(map1.polnareff.spriteSheet);
        if (map1.background.id != 0) UnloadTexture(map1.background);
        UnloadSound(map1.typeSound);
    } else {
        UnloadTexture(map2.polnareff.spriteSheet);
        if (map2.background.id != 0) UnloadTexture(map2.background);
        UnloadSound(map2.typeSound);
    }

    CloseWindow();

    return 0;
}