#include "../../include/maps/mapa3.h"
#include "../../include/utils/utils.h"
#include "../../lib_raylib/raymath.h"
#include "../../include/utils/constants.h"
#include "../../include/entities/npc.h"
#include "../gemini.h"
#include <string.h>
#include <stdio.h>

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
    map->keyPrompt = LoadTexture("assets/sprites/individual sprites/keyboard/P.png");
    map->exclamation = LoadTexture("assets/sprites/exclamation.png");
}

void UpdateMap3(MapData *map, Player *player) {
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

        if (player->fama > 65){
            snprintf(promptFinal, sizeof(promptFinal),
                     "Você é Jotaro, um cara reservado, sério e direto. Ex-roqueiro que viu o auge e a queda da fama. Você raramente sorri, fala pouco e não suporta bajulação. "
                     "O jogador quer ser um astro do rock. A fama dele é %d. Se for alta (>80), você o reconhece com relutância. Se for média (65-80), responde friamente. "
                     "Você sabe algo importante: a música ideal nesta cidade é 'Thunderstruck', da banda AC/DC. "
                     "Mas nunca diga isso diretamente. Dê dicas de forma criativa. "
                     "Responda como Jotaro: firme, lacônico, ríspido. No máximo 300 caracteres. Nunca ultrapasse esse limite.\n\nJogador: \"%s\"",
                     player->fama, map->inputText
            );

        } else{
            snprintf(promptFinal, sizeof(promptFinal),
                     "Você é Jotaro, um cara frio e direto. Ex-roqueiro calejado. O jogador tem fama %d, e isso não impressiona você. "
                     "Ele tentará fazer uma pergunta. "
                     "Se a fama do jogador for 50 ou menos, você evita conversa, responde com desinteresse ou o ignora completamente. "
                     "Nada de dicas, nada de paciência. Responda como Jotaro: curto, seco, sem enrolação. No máximo 300 caracteres. Nunca ultrapasse esse limite.\n\nJogador: \"%s\"",
                     player->fama, map->inputText
            );

        }


        // Envia esse prompt para a IA
        respt(promptFinal, map->respostaIA);

        // Adiciona prefixo para indicar que é fala do NPC
        char respostaFinal[1024];
        snprintf(respostaFinal, sizeof(respostaFinal), "Jotaro: %s", map->respostaIA);

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
                        map->npc.position.x + 15,
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
        DrawRectangle(460, SCREEN_HEIGHT - 160, 650, 120, Fade(BLACK, 0.8f));
        DrawRectangleLines(460, SCREEN_HEIGHT - 160, 650, 120, WHITE);
        DrawText("Digite sua pergunta:", 480, SCREEN_HEIGHT - 150, 20, YELLOW);
        DrawText(map->inputText, 480, SCREEN_HEIGHT - 120, 20, WHITE);
    }

    DrawDialogue(&map->dialogue);

    float time = GetTime();
    float offset = sinf(time * 4.0f) * 10.0f;  // 4.0f = velocidade, 10.0f = quanto mexe

    //Desenha a seta para orientar o jogador para qual fase deve ir
    if (player->fama < 60){
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
    }

    //Desenha a seta para orientar o jogador à mudar de mapa
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
                GetFontDefault(),
                "PRESS X!",
                (Vector2){130 + offset - 20, 725},  // ajuste posição conforme necessário
                20.0f,
                2.0f,
                WHITE
        );
    }

    //Desenha a seta para o jogador entrar no café para tocar a musica
    float distance3 = fabs(590 - (player->position.x + FRAME_WIDTH * PLAYER_SCALE));
    if (distance3 < 150.0f){
        float scale = 0.25f;
        DrawTexturePro(
                map->seta,
                (Rectangle){0, 0, map->seta.width, map->seta.height},
                (Rectangle){
                        485,
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
        const char* letra = "O";
        int fontSize = 20;
        Vector2 textSize = MeasureTextEx(GetFontDefault(), letra, fontSize, 2.0f);

        Vector2 textPos = {
                486 - textSize.x / 2,
                (790 + offset) - textSize.y / 2
        };

        DrawTextEx(GetFontDefault(), letra, textPos, fontSize, 2.0f, WHITE);
    }

    //Desenha a exclamação caso o NPC possa dar a dica
    if (player->fama >= 70){
        float exclamationOffset = sinf(GetTime() * 4.0f) * 5.0f;
        float scaleExclamation = 0.25f;
        DrawTextureEx(
                map->exclamation,
                (Vector2){
                        map->npc.position.x - 25 + (map->npc.frameWidth * map->npc.scale) / 2 - (map->exclamation.width * scaleExclamation) / 2,
                        map->npc.position.y + 10 - (map->exclamation.height * scaleExclamation) - 20 + exclamationOffset
                },
                0.0f,
                scaleExclamation,
                WHITE
        );
    }

}
