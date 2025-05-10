#ifndef MAPA_H
#define MAPA_H

#include "../../include_raylib/raylib.h"
#include "../entities/polnareff.h"
#include "../dialogue.h"
#include "../entities/player.h"  // Necessário para o Player

typedef struct {
    Texture2D background;
    Polnareff polnareff;
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
