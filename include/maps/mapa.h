#ifndef MAPA_H
#define MAPA_H

#include "../../include_raylib/raylib.h"
#include "../dialogue.h"
#include "../entities/player.h"
#include "../entities/npc.h"  // Adiciona o novo NPC genérico

typedef struct {
    Texture2D background;
    Npc npc;

    bool typingQuestion;
    bool waitingResponse;
    bool showingAnswer;

    char inputText[256];
    char respostaIA[1024];

    DialogueSystem dialogue;
    Sound typeSound;
} MapData;

void InitMap(MapData *map);
void UpdateMap(MapData *map, Player *player);
void DrawMap(MapData *map, Player *player);

#endif
