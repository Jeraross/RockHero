#include "../../include/maps/mapa2.h"
#include "../../include/utils/utils.h"
#include "../../lib_raylib/raymath.h"
#include "../../include/utils/constants.h"
#include "../../include/entities/npc.h"
#include "../gemini.h"
#include <string.h>
#include <stdio.h>

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
    map->exclamation = LoadTexture("assets/sprites/exclamation.png");
}
void UpdateMap2(MapData *map, Player *player) {
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

        if (player->fama > 45){
            snprintf(promptFinal, sizeof(promptFinal),
                     "Você é Avdol, um ex-produtor musical egípcio, sério e místico. Você fala como um sábio e valoriza autenticidade e alma musical. "
                     "A fama do jogador é %d. Se for alta (>60), trate-o com respeito. Se for média (45–60), seja neutro, porém cordial. "
                     "Você sabe uma informação importante: a melhor música para tocar nesta cidade é 'Sweet Child O Mine', do Guns N' Roses. "
                     "Mas nunca diga isso diretamente. Use metáforas, pistas filosóficas ou referências sutis como 'doçura', 'infância', etc. "
                     "Fale como Avdol. Sua resposta deve ter no máximo 300 caracteres. Nunca ultrapasse esse limite.\n\nJogador: \"%s\"",
                     player->fama, map->inputText
            );
        }
        else{
            snprintf(promptFinal, sizeof(promptFinal),
                     "Você é Avdol, um ex-produtor musical egípcio. Você fala como um sábio e valoriza autenticidade e alma musical. Um jogador de fama %d se aproxima. "
                     "Você não desperdiça palavras com quem não demonstrou alma musical. "
                     "Se a fama do jogador for menos que 45, ignore-o ou recuse-se a interagir. "
                     "Responda com silêncio, desdém ou frases curtas que encerram a conversa. "
                     "Fale como Avdol. Sua resposta deve ter no máximo 300 caracteres. Nunca ultrapasse esse limite.\n\nJogador: \"%s\"",
                     player->fama, map->inputText
            );

        }


        // Envia esse prompt para a IA
        respt(promptFinal, map->respostaIA);

        // Adiciona prefixo para indicar que é fala do NPC
        char respostaFinal[1024];
        snprintf(respostaFinal, sizeof(respostaFinal), "Avdol: %s", map->respostaIA);

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
        DrawRectangle(1000, SCREEN_HEIGHT - 160, 650, 120, Fade(BLACK, 0.8f));
        DrawRectangleLines(1000, SCREEN_HEIGHT - 160, 650, 120, WHITE);
        DrawText("Digite sua pergunta:", 1020, SCREEN_HEIGHT - 150, 20, YELLOW);
        DrawText(map->inputText, 1020, SCREEN_HEIGHT - 120, 20, WHITE);
    }

    DrawDialogue(&map->dialogue);

    float distance2 = fabs(SCREEN_WIDTH - (player->position.x + FRAME_WIDTH * PLAYER_SCALE));

    float time = GetTime();
    float offset = sinf(time * 4.0f) * 10.0f;

    //Desenha a seta para orientar o jogador para qual fase deve ir
    if (player->fama >= 70){
        DrawTextureEx(map->seta, (Vector2){SCREEN_WIDTH - 250 + offset, 650}, 0.0f, 0.5f, WHITE);
    }

    else if (player->fama < 30){
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

    if (distance2 < 200.0f) {
        DrawTextureEx(map->seta, (Vector2){SCREEN_WIDTH - 250 + offset, 650}, 0.0f, 0.5f, WHITE);
        DrawTextEx(
                GetFontDefault(),
                "PRESS G!",
                (Vector2){SCREEN_WIDTH - 195 + offset - 20, 710},
                20.0f,
                2.0f,
                WHITE
        );
    }

        //Desenha a seta para orientar o jogador à mudar de mapa
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
                GetFontDefault(),
                "PRESS G!",
                (Vector2){130 + offset - 20, 725},  // ajuste posição conforme necessário
                20.0f,
                2.0f,
                WHITE
        );
    }

    //Desenha a seta para o jogador entrar no cinema para tocar a musica
    float distance3 = fabs(1550 - (player->position.x + FRAME_WIDTH * PLAYER_SCALE));
    if (distance3 < 150.0f){
        float scale = 0.25f;
        DrawTexturePro(
                map->seta,
                (Rectangle){0, 0, map->seta.width, map->seta.height},
                (Rectangle){
                        1545,
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
                1546 - textSize.x / 2,
                (790 + offset) - textSize.y / 2
        };

        DrawTextEx(map->font, letra, textPos, fontSize, 2.0f, WHITE);
    }

    //Desenha a exclamação caso o NPC possa dar a dica
    if (player->fama >= 40){
        float exclamationOffset = sinf(GetTime() * 4.0f) * 5.0f;
        float scaleExclamation = 0.25f;
        DrawTextureEx(
                map->exclamation,
                (Vector2){
                        map->npc.position.x + 330 + (map->npc.frameWidth * map->npc.scale) / 2 - (map->exclamation.width * scaleExclamation) / 2,
                        map->npc.position.y + 5 - (map->exclamation.height * scaleExclamation) - 20 + exclamationOffset
                },
                0.0f,
                scaleExclamation,
                WHITE
        );
    }

}
