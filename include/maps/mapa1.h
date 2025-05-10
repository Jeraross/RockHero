#ifndef MAPA1_H
#define MAPA1_H

#include "mapa.h"  // Inclui a definição de MapData
#include "../entities/npc.h"

// Funções específicas para o mapa 1
void InitMap1(MapData *map);
void UpdateMap1(MapData *map, Player *player);
void DrawMap1(MapData *map, Player *player);

#endif
