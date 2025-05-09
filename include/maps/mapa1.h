#ifndef MAPA1_H
#define MAPA1_H

#include "../../include_raylib/raylib.h"
#include "../entities/polnareff.h"

typedef struct {
    Texture2D background;
    Polnareff polnareff;
} MapData;

void InitMap(MapData *map);
void UpdatePolnareff(Polnareff *polnareff);
void DrawMap(MapData *map);

#endif
