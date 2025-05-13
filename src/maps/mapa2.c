#include "../../include/maps/mapa2.h"
#include "../../include/utils/utils.h"
#include "../../lib_raylib/raymath.h"
#include "../../include/utils/constants.h"
#include "../../include/entities/npc.h"
#include "../gemini.h"
#include <string.h>

void InitMap2(MapData *map) {
    map->background = LoadTexture("assets/maps/PNG/City3/Bright/City3.png");

    Vector2 npcPos = {
            660,
            (1080 - 200) - 130 * 2.0f  // altura do sprite * escala
    };

    InitNpc(&map->npc, npcPos, "assets/sprites/avdol.png",
            7, 5, -164, 124, 213, 2.0f);

    map->typingQuestion = false;
    map->waitingResponse = false;
    map->showingAnswer = false;
    map->inputText[0] = '\0';
    map->respostaIA[0] = '\0';
    map->typeSound = LoadSound("assets/sounds/type_sound.wav");

    InitDialogue(&map->dialogue, "", map->typeSound);
    map->seta = LoadTexture("assets/sprites/seta.png");
    map->font = LoadFont("assets/font/Vampire Wars.ttf");
    map->keyPrompt = LoadTexture("assets/sprites/individual sprites/keyboard/P.png");
}

void UpdateMap2(MapData *map, Player *player) {
    if (!player->frozen) {
        UpdatePlayer(player);
    }

    UpdateNpc(&map->npc);
    UpdateDialogue(&map->dialogue);

    float distance = Vector2Distance(player->position, map->npc.position);
    bool showPrompt = distance < 200.0f;

    if (showPrompt && IsKeyPressed(KEY_P) && !map->dialogue.isActive && !map->typingQuestion && !map->waitingResponse && !map->showingAnswer) {
        map->typingQuestion = true;
        player->frozen = true;
        map->inputText[0] = '\0';
    }

    if (map->typingQuestion) {
        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= 32) && (key <= 125) && strlen(map->inputText) < 255) {
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
            player->frozen = false;
        }
    }
}

void DrawMap2(MapData *map, Player *player) {
    DrawTexture(map->background, 0, 0, WHITE);

    Rectangle src = {
            map->npc.currentFrame * map->npc.frameDistance,
            0,
            map->npc.frameWidth,
            map->npc.frameHeight
    };

    Rectangle dst = {
            map->npc.position.x,
            map->npc.position.y,
            map->npc.frameWidth * map->npc.scale,
            map->npc.frameHeight * map->npc.scale
    };

    DrawTexturePro(map->npc.spriteSheet, src, dst, (Vector2){0, 0}, 0.0f, WHITE);

    float distance = Vector2Distance(map->npc.position, player->position);

    // Efeito de pulsação da tecla
    static float pulseScale = 1.0f;
    static float pulseDirection = 1.0f;
    float pulseSpeed = 0.01f; // Controle de velocidade da pulsação

    pulseScale += pulseSpeed * pulseDirection;  // Modifica a escala para o efeito
    if (pulseScale >= 1.2f) pulseDirection = -1.0f; // Quando chega no limite superior, inverte a direção
    if (pulseScale <= 0.8f) pulseDirection = 1.0f; // Quando chega no limite inferior, inverte a direção

    if (distance < 200.0f && !map->dialogue.isActive && !map->typingQuestion) {
        // Desenha a tecla "P" com efeito de pulsação
        DrawTexturePro(
                map->keyPrompt,
                (Rectangle){0, 0, map->keyPrompt.width, map->keyPrompt.height},
                (Rectangle){
                        map->npc.position.x + 75,
                        map->npc.position.y + 30,
                        map->keyPrompt.width * pulseScale, // Aplica a escala pulsante
                        map->keyPrompt.height * pulseScale // Aplica a escala pulsante
                },
                (Vector2){(map->keyPrompt.width * pulseScale) / 2, (map->keyPrompt.height * pulseScale) / 2}, // Origem
                0.0f, // Sem rotação
                WHITE
        );
    }

    if (map->typingQuestion) {
        DrawRectangle(460, SCREEN_HEIGHT - 160, 1000, 80, Fade(BLACK, 0.8f));
        DrawRectangleLines(460, SCREEN_HEIGHT - 160, 1000, 80, WHITE);
        DrawText("Digite sua pergunta:", 480, SCREEN_HEIGHT - 150, 20, YELLOW);
        DrawText(map->inputText, 480, SCREEN_HEIGHT - 120, 20, WHITE);
    }

    DrawDialogue(&map->dialogue);

    float distance2 = fabs(SCREEN_WIDTH - (player->position.x + FRAME_WIDTH * PLAYER_SCALE));

    float time = GetTime();
    float offset = sinf(time * 4.0f) * 10.0f;
    if (distance2 < 200.0f) {
        DrawTextureEx(map->seta, (Vector2){SCREEN_WIDTH - 250 + offset, 650}, 0.0f, 0.5f, WHITE);
        DrawTextEx(
                map->font,
                "PRESS G!",
                (Vector2){SCREEN_WIDTH - 195 + offset - 20, 710},
                20.0f,
                2.0f,
                WHITE
        );
    }
    else if (player->position.x < 20) {
        float scale = 0.5f;

        DrawTexturePro(
                map->seta,
                (Rectangle){0, 0, map->seta.width, map->seta.height},
                (Rectangle){
                        150 + offset,
                        740,
                        map->seta.width * scale,
                        map->seta.height * scale
                },
                (Vector2){
                        (map->seta.width * scale) / 2,
                        (map->seta.height * scale) / 2
                },
                180.0f,
                WHITE
        );

        // Texto acima da seta da esquerda
        DrawTextEx(
                map->font,
                "PRESS G!",
                (Vector2){140 + offset - 20, 725},  // ajuste posição conforme necessário
                20.0f,
                2.0f,
                WHITE
        );
    }



}
