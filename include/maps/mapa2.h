#ifndef MAPA2_H
#define MAPA2_H

#include "mapa.h"
#include "../entities/npc.h"

void InitMap2(MapData *map);
void UpdateMap2(MapData *map, Player *player);
void DrawMap2(MapData *map, Player *player);

#endif
