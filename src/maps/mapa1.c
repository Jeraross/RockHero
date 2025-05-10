#include "../../include/maps/mapa1.h"
#include "../../include/entities/polnareff.h"
#include "../../include/utils/utils.h"
#include <string.h>
#include "../../lib_raylib/raymath.h"
#include "../gemini.h"
#include "../../include/utils/constants.h"
#include "../../include/entities/player.h"

// src/maps/mapa1.c
void InitMap(MapData *map) {
    map->background = LoadTexture("assets/maps/PNG/City2/Bright/City2.png");

    Vector2 polnareffPos = {
            GetScreenWidth() * 0.75f,
            (1080 - 200) - POLNAREFF_FRAME_HEIGHT * POLNAREFF_SCALE
    };

    InitPolnareff(&map->polnareff, polnareffPos);

    // Removido map->playerFrozen

    map->typingQuestion = false;
    map->waitingResponse = false;
    map->showingAnswer = false;
    map->inputText[0] = '\0';
    map->respostaIA[0] = '\0';
    map->typeSound = LoadSound("assets/sounds/type_sound.wav");

    InitDialogue(&map->dialogue, "", map->typeSound);
}

void UpdateMap(MapData *map, Player *player) {
    // Agora o controle do congelamento do jogador é feito diretamente com player->frozen
    if (!player->frozen) {
        UpdatePlayer(player); // O jogador só pode se mover se não estiver congelado
    }

    UpdatePolnareff(&map->polnareff);
    UpdateDialogue(&map->dialogue);

    float distance = Vector2Distance(player->position, map->polnareff.position);
    bool showPrompt = distance < 200.0f;

    if (showPrompt && IsKeyPressed(KEY_P) && !map->dialogue.isActive && !map->typingQuestion && !map->waitingResponse && !map->showingAnswer) {
        map->typingQuestion = true;
        player->frozen = true; // Congela o jogador quando ele começa a digitar
        map->inputText[0] = '\0';
    }

    if (map->typingQuestion) {
        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= 32) && (key <= 125) && strlen(map->inputText) < MAX_INPUT - 1) {
                int len = strlen(map->inputText);
                map->inputText[len] = (char)key;
                map->inputText[len + 1] = '\0';
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE) && strlen(map->inputText) > 0) {
            map->inputText[strlen(map->inputText) - 1] = '\0';
        }

        if (IsKeyPressed(KEY_ENTER)) {
            map->typingQuestion = false;
            map->waitingResponse = true;
        }
    }

    if (map->waitingResponse) {
        respt(map->inputText, map->respostaIA);
        InitDialogue(&map->dialogue, map->respostaIA, map->typeSound);
        map->dialogue.isActive = true;
        map->waitingResponse = false;
        map->showingAnswer = true;
    }

    if (map->dialogue.isActive && map->dialogue.isFinished && IsKeyPressed(KEY_ENTER)) {
        map->dialogue.isActive = false;
        if (map->showingAnswer) {
            map->showingAnswer = false;
            player->frozen = false; // Descongela o jogador após a resposta ser mostrada
        }
    }
}

void DrawMap(MapData *map, Player *player) {
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

    float distance = Vector2Distance(map->polnareff.position, player->position);
    if (distance < 200.0f && !map->dialogue.isActive && !map->typingQuestion) {
        DrawText("PRESS P!", map->polnareff.position.x + 55, map->polnareff.position.y + 30, 20, YELLOW);
    }

    if (map->typingQuestion) {
        DrawRectangle(460, SCREEN_HEIGHT - 160, 1000, 80, Fade(BLACK, 0.8f));
        DrawRectangleLines(460, SCREEN_HEIGHT - 160, 1000, 80, WHITE);
        DrawText("Digite sua pergunta:", 480, SCREEN_HEIGHT - 150, 20, YELLOW);
        DrawText(map->inputText, 480, SCREEN_HEIGHT - 120, 20, WHITE);
    }

    DrawDialogue(&map->dialogue);
}
