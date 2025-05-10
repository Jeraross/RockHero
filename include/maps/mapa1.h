#ifndef MAPA1_H
#define MAPA1_H

#include "mapa.h"  // Inclui a definição de MapData

// Funções específicas para o mapa 1
void InitMap(MapData *map);
void UpdateMap(MapData *map, Player *player);
void DrawMap(MapData *map, Player *player);

#endif
