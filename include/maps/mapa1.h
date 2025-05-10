#ifndef MAPA1_H
#define MAPA1_H

#include "../../include_raylib/raylib.h"
#include "../entities/polnareff.h"
#include "../dialogue.h"
#include "../entities/player.h"  // <--- Necessário para Player

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
