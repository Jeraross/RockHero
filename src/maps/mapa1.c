#include "../../include/maps/mapa1.h"
#include "../../include/maps/mapa2.h"
#include "../../include/utils/utils.h"
#include "../../lib_raylib/raymath.h"
#include "../../include/utils/constants.h"
#include "../../include/entities/npc.h"
#include "../gemini.h"
#include <string.h>
#include <stdio.h>

void InitMap1(MapData *map) {
    map->background = LoadTexture("assets/maps/PNG/City2/Bright/City2.png");

    Vector2 npcPos = {
            1400,
            (1080 - 200) - 150 * 2.0f  // altura do sprite * escala
    };

    InitNpc(&map->npc, npcPos, "assets/sprites/polnareff.png",
            7, 8, 191, 155, 185, 2.0f);

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

void UpdateMap1(MapData *map, Player *player) {
    if (!player->frozen) {
        UpdatePlayer(player);
    }

    UpdateNpc(&map->npc);
    UpdateDialogue(&map->dialogue);

    float distance = Vector2Distance(player->position, map->npc.position);
    bool showPrompt = distance < 200.0f;

    // Se o jogador apertar 'P' e estiver perto de Polnareff, permite que ele comece a digitar a pergunta
    if (showPrompt && IsKeyPressed(KEY_P) && !map->dialogue.isActive && !map->typingQuestion && !map->waitingResponse && !map->showingAnswer) {
        map->typingQuestion = true;
        player->frozen = true;
        map->inputText[0] = '\0'; // Limpa a pergunta anterior
    }

    // Lógica para digitar a pergunta
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

        // Quando pressionar Enter, o NPC vai responder à pergunta
        if (IsKeyPressed(KEY_ENTER)) {
            map->typingQuestion = false;
            map->waitingResponse = true;
        }
    }

    // Quando o NPC estiver esperando a resposta, ele processa a pergunta
    if (map->waitingResponse) {

        char promptFinal[1024];
        snprintf(promptFinal, sizeof(promptFinal),
                 "Você é um cara chamado Polnareff, um ex-guitarrista francês aposentado. Você é bem-humorado, sarcástico e exagerado. "
                 "O jogador está tentando se tornar uma estrela do rock e a fama dele atualmente é %d (de 0 a 100). "
                 "Quanto maior a fama, mais você o admira e bajula; quanto menor, mais debochado e desdenhoso você se torna. "
                 "Você sabe uma informação importante: a melhor música para tocar nesta cidade é 'Thunderstruck', da banda AC/DC. "
                 "Mas você nunca deve revelar isso diretamente. Dê dicas de forma criativa, com piadas, trocadilhos, etc. "
                 "Responda como Polnareff: Sua resposta deve ter no máximo 300 caracteres. Nunca ultrapasse esse limite.\n\nJogador: \"%s\"",
                 player->fama, map->inputText
        );


        // Envia esse prompt para a IA
        respt(promptFinal, map->respostaIA);

        // Adiciona prefixo para indicar que é fala do NPC
        char respostaFinal[1024];
        snprintf(respostaFinal, sizeof(respostaFinal), "Polnareff: %s", map->respostaIA);

        InitDialogue(&map->dialogue, respostaFinal, map->typeSound);
        map->dialogue.isActive = true;
        map->waitingResponse = false;
        map->showingAnswer = true;
    }

    // Quando a resposta é exibida, o jogador pode continuar a conversa
    if (map->dialogue.isActive && map->dialogue.isFinished && IsKeyPressed(KEY_ENTER)) {
        map->dialogue.isActive = false;
        if (map->showingAnswer) {
            map->showingAnswer = false;
            player->frozen = false;
        }
    }
}



void DrawMap1(MapData *map, Player *player) {
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
            DrawRectangle(550, SCREEN_HEIGHT - 160, 650, 120, Fade(BLACK, 0.8f));
            DrawRectangleLines(550, SCREEN_HEIGHT - 160, 650, 120, WHITE);
            DrawText("Pergunte algo ao NPC:", 570, SCREEN_HEIGHT - 150, 20, YELLOW);
            DrawText(map->inputText, 570, SCREEN_HEIGHT - 120, 20, WHITE);
        }


    float distance2 = fabs(SCREEN_WIDTH - (player->position.x + FRAME_WIDTH * PLAYER_SCALE));
    float time = GetTime();
    float offset = sinf(time * 4.0f) * 10.0f;

    if (player->fama >= 40) {
        DrawTextureEx(map->seta, (Vector2){SCREEN_WIDTH - 250 + offset, 650}, 0.0f, 0.5f, WHITE);
    }

    if (distance2 < 200.0f) {
        DrawTextureEx(map->seta, (Vector2){SCREEN_WIDTH - 250 + offset, 650}, 0.0f, 0.5f, WHITE);
        DrawTextEx(
                GetFontDefault(),
                "PRESS G!",
                (Vector2){SCREEN_WIDTH - 195 + offset - 20, 710},  // posição (ajuste -20 se centralizar)
                20.0f,  // tamanho da fonte
                2.0f,   // espaçamento
                WHITE   // cor
        );
    }


    float distance3 = fabs(790 - (player->position.x + FRAME_WIDTH * PLAYER_SCALE));
    if (distance3 < 150.0f) {
        float scale = 0.25f;

        DrawTexturePro(
                map->seta,
                (Rectangle){0, 0, map->seta.width, map->seta.height},
                (Rectangle){
                        735,
                        790 + offset,
                        map->seta.width * scale,
                        map->seta.height * scale
                },
                (Vector2){
                        (map->seta.width * scale) / 2,
                        (map->seta.height * scale) / 2
                },
                270.0f,
                WHITE
        );

        const char* letra = "M";
        int fontSize = 20;
        Vector2 textSize = MeasureTextEx(map->font, letra, fontSize, 2.0f);

        Vector2 textPos = {
                736 - textSize.x / 2,
                (790 + offset) - textSize.y / 2
        };

        DrawTextEx(map->font, letra, textPos, fontSize, 2.0f, WHITE);
    }



}
