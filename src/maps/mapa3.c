#include "../../include/maps/mapa3.h"
#include "../../include/utils/utils.h"
#include "../../lib_raylib/raymath.h"
#include "../../include/utils/constants.h"
#include "../../include/entities/npc.h"
#include "../gemini.h"
#include <string.h>

void InitMap3(MapData *map) {
    map->background = LoadTexture("assets/maps/PNG/City4/Bright/City4.png");

    Vector2 npcPos = {
            1190,
            (1080 - 200) - 130 * 2.0f  // altura do sprite * escala
    };

    InitNpc(&map->npc, npcPos, "assets/sprites/jotaro.png",
            4, 7, 112, 129, 153, 2.0f);

    map->typingQuestion = false;
    map->waitingResponse = false;
    map->showingAnswer = false;
    map->inputText[0] = '\0';
    map->respostaIA[0] = '\0';
    map->typeSound = LoadSound("assets/sounds/type_sound.wav");

    InitDialogue(&map->dialogue, "", map->typeSound);
    map->seta = LoadTexture("assets/sprites/seta.png");
    map->font = LoadFont("assets/font/Vampire Wars.ttf");

}

void UpdateMap3(MapData *map, Player *player) {
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

void DrawMap3(MapData *map, Player *player) {
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
    if (distance < 200.0f && !map->dialogue.isActive && !map->typingQuestion) {
        DrawText("PRESS P!", map->npc.position.x - 70, map->npc.position.y + 30, 20, GREEN);
    }

    if (map->typingQuestion) {
        DrawRectangle(460, SCREEN_HEIGHT - 160, 1000, 80, Fade(BLACK, 0.8f));
        DrawRectangleLines(460, SCREEN_HEIGHT - 160, 1000, 80, WHITE);
        DrawText("Digite sua pergunta:", 480, SCREEN_HEIGHT - 150, 20, YELLOW);
        DrawText(map->inputText, 480, SCREEN_HEIGHT - 120, 20, WHITE);
    }

    DrawDialogue(&map->dialogue);

    float time = GetTime();
    float offset = sinf(time * 4.0f) * 10.0f;  // 4.0f = velocidade, 10.0f = quanto mexe
    if (player->position.x < 20) {
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
