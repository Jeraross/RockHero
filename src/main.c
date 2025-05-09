#include "raylib.h"
#include "raymath.h"
#include "../include/entities/player.h"
#include "../include/maps/mapa1.h"
#include "../include/utils/utils.h"
#include <string.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

// Estrutura para controle de diálogo
typedef struct {
    char text[256];
    int currentChar;
    float timer;
    bool isActive;
    bool isFinished;
    Sound typeSound;
} DialogueSystem;

void InitDialogue(DialogueSystem *dialogue, const char *text, Sound sound) {
    strncpy(dialogue->text, text, sizeof(dialogue->text));
    dialogue->currentChar = 0;
    dialogue->timer = 0;
    dialogue->isActive = false;
    dialogue->isFinished = false;
    dialogue->typeSound = sound;
}

void UpdateDialogue(DialogueSystem *dialogue) {
    if (!dialogue->isActive || dialogue->isFinished) return;

    dialogue->timer += GetFrameTime();
    const float charSpeed = 0.05f; // Velocidade entre caracteres

    if (dialogue->timer >= charSpeed) {
        dialogue->timer = 0;
        dialogue->currentChar++;

        // Toca som apenas para caracteres visíveis (não espaços)
        if (dialogue->currentChar < (int)strlen(dialogue->text) &&
            dialogue->text[dialogue->currentChar-1] != ' ') {
            PlaySound(dialogue->typeSound);
        }

        if (dialogue->currentChar >= (int)strlen(dialogue->text)) {
            dialogue->isFinished = true;
        }
    }
}

void DrawDialogue(DialogueSystem *dialogue) {
    if (!dialogue->isActive) return;

    const int boxWidth = 600;
    const int boxHeight = 120;
    const int boxX = (SCREEN_WIDTH - boxWidth) / 2;
    const int boxY = SCREEN_HEIGHT - boxHeight - 50;
    const int textX = boxX + 20;
    const int textY = boxY + 40;

    // Fundo da caixa de diálogo
    DrawRectangle(boxX, boxY, boxWidth, boxHeight, Fade(BLACK, 0.8f));
    DrawRectangleLines(boxX, boxY, boxWidth, boxHeight, WHITE);

    // Texto com efeito de digitação
    char displayedText[256] = {0};
    strncpy(displayedText, dialogue->text, dialogue->currentChar);
    DrawText(displayedText, textX, textY, 20, WHITE);

    // Indicador para continuar
    if (dialogue->isFinished) {
        DrawText("Press ENTER to continue...",
                 boxX + boxWidth - 200,
                 boxY + boxHeight - 20,
                 15, YELLOW);
    }
}

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Jogo com Player e Polnareff");
    SetTargetFPS(60);

    if (!IsWindowFullscreen()) {
        ToggleFullscreen();
    }

    // Inicialização
    Player player;
    InitPlayer(&player);
    player.frozen = false; // Garante que começa não congelado

    MapData map;
    InitMap(&map);

    // Sistema de diálogo
    DialogueSystem dialogue;
    Sound typeSound = LoadSound("assets/sounds/type_sound.wav");
    InitDialogue(&dialogue, "Olá Joseph! Você parece mais novo...", typeSound);

    while (!WindowShouldClose()) {
        // Atualização
        UpdatePlayer(&player);
        UpdatePolnareff(&map.polnareff);
        UpdateDialogue(&dialogue);

        // Verifica distância para interação
        float distance = Vector2Distance(player.position, map.polnareff.position);
        bool showPrompt = distance < 200.0f;

        // Lógica de interação
        if (showPrompt && IsKeyPressed(KEY_P) && !dialogue.isActive) {
            dialogue.isActive = true;
            player.frozen = true; // Congela o player
        }

        // Finaliza diálogo
        if (dialogue.isActive && dialogue.isFinished && IsKeyPressed(KEY_ENTER)) {
            dialogue.isActive = false;
            player.frozen = false; // Libera o player
        }

        // Desenho
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawMap(&map);
        DrawPlayer(&player);

        // Mostra prompt de interação
        if (showPrompt && !dialogue.isActive) {
            DrawText("PRESS P!",
                     map.polnareff.position.x + 55,
                     map.polnareff.position.y + 30,
                     20, YELLOW);
        }

        // Desenha diálogo se ativo
        DrawDialogue(&dialogue);

        // Debug info
        DrawText(TextFormat("Posição Player: (%.0f, %.0f)", player.position.x, player.position.y),
                 10, 10, 20, DARKGRAY);
        DrawText("Use as setas para mover", 10, 40, 20, DARKGRAY);
        EndDrawing();
    }

    // Limpeza
    UnloadTexture(player.spriteSheet);
    UnloadTexture(map.polnareff.spriteSheet);
    if (map.background.id != 0) UnloadTexture(map.background);
    UnloadSound(typeSound);
    CloseWindow();

    return 0;
}