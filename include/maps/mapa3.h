#ifndef MAPA3_H
#define MAPA3_H

#include "mapa.h"
#include "../entities/npc.h"

void InitMap3(MapData *map);
void UpdateMap3(MapData *map, Player *player);
void DrawMap3(MapData *map, Player *player);

#endif
