#include "raylib.h"
#include "raymath.h"
#include "../include/entities/player.h"
#include "../include/maps/mapa1.h"
#include "../include/utils/utils.h"
#include "gemini.h"
#include <string.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define MAX_INPUT 256
#define MAX_RESPOSTA 1024

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
    const float charSpeed = 0.05f;

    if (dialogue->timer >= charSpeed) {
        dialogue->timer = 0;
        dialogue->currentChar++;

        if (dialogue->currentChar < (int)strlen(dialogue->text) &&
            dialogue->text[dialogue->currentChar - 1] != ' ') {
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

    DrawRectangle(boxX, boxY, boxWidth, boxHeight, Fade(BLACK, 0.8f));
    DrawRectangleLines(boxX, boxY, boxWidth, boxHeight, WHITE);

    char displayedText[256] = {0};
    strncpy(displayedText, dialogue->text, dialogue->currentChar);
    DrawText(displayedText, textX, textY, 20, WHITE);

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

    Player player;
    InitPlayer(&player);
    player.frozen = false;

    MapData map;
    InitMap(&map);

    DialogueSystem dialogue;
    Sound typeSound = LoadSound("assets/sounds/type_sound.wav");

    char inputText[MAX_INPUT] = "";
    char respostaIA[MAX_RESPOSTA] = "";
    bool typingQuestion = false;
    bool waitingResponse = false;
    bool showingAnswer = false;

    while (!WindowShouldClose()) {
        if (!player.frozen) {
            UpdatePlayer(&player);
        }
        UpdatePolnareff(&map.polnareff);
        UpdateDialogue(&dialogue);

        float distance = Vector2Distance(player.position, map.polnareff.position);
        bool showPrompt = distance < 200.0f;

        if (showPrompt && IsKeyPressed(KEY_P) && !dialogue.isActive && !typingQuestion && !waitingResponse && !showingAnswer) {
            typingQuestion = true;
            player.frozen = true;
            inputText[0] = '\0';
        }

        if (typingQuestion) {
            int key = GetCharPressed();
            while (key > 0) {
                if ((key >= 32) && (key <= 125) && strlen(inputText) < MAX_INPUT - 1) {
                    int len = strlen(inputText);
                    inputText[len] = (char)key;
                    inputText[len + 1] = '\0';
                }
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE) && strlen(inputText) > 0) {
                inputText[strlen(inputText) - 1] = '\0';
            }

            if (IsKeyPressed(KEY_ENTER)) {
                typingQuestion = false;
                waitingResponse = true;
            }
        }

        if (waitingResponse) {
            respt(inputText, respostaIA);
            InitDialogue(&dialogue, respostaIA, typeSound);
            dialogue.isActive = true;
            waitingResponse = false;
            showingAnswer = true;
        }

        if (dialogue.isActive && dialogue.isFinished && IsKeyPressed(KEY_ENTER)) {
            dialogue.isActive = false;
            if (showingAnswer) {
                showingAnswer = false;
                player.frozen = false;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawMap(&map);
        DrawPlayer(&player);

        if (showPrompt && !dialogue.isActive && !typingQuestion) {
            DrawText("PRESS P!",
                     map.polnareff.position.x + 55,
                     map.polnareff.position.y + 30,
                     20, YELLOW);
        }

        if (typingQuestion) {
            DrawRectangle(460, SCREEN_HEIGHT - 160, 1000, 80, Fade(BLACK, 0.8f));
            DrawRectangleLines(460, SCREEN_HEIGHT - 160, 1000, 80, WHITE);
            DrawText("Digite sua pergunta:", 480, SCREEN_HEIGHT - 150, 20, YELLOW);
            DrawText(inputText, 480, SCREEN_HEIGHT - 120, 20, WHITE);
        }

        DrawDialogue(&dialogue);

        DrawText(TextFormat("Posição Player: (%.0f, %.0f)", player.position.x, player.position.y),
                 10, 10, 20, DARKGRAY);
        DrawText("Use as setas para mover", 10, 40, 20, DARKGRAY);
        EndDrawing();
    }

    UnloadTexture(player.spriteSheet);
    UnloadTexture(map.polnareff.spriteSheet);
    if (map.background.id != 0) UnloadTexture(map.background);
    UnloadSound(typeSound);
    CloseWindow();

    return 0;
}
