//
// Created by jerin on 11/05/2025.
//

#ifndef CHART_H
#define CHART_H

#include "raylib.h"

#define CHART_SIZE 500

typedef struct {
    Rectangle rect;
    int lane;
    bool active;
    Color color;
    float spawnTime;
    bool hit;
    int specialType; // 0 = normal, 1 = fogo roxo, 2 = fogo verde, 3 = fogo branco
    float specialTimer; // Para animações especiais
} Note;

extern Note thunderChart[CHART_SIZE];
extern Note SweetChildOMine[CHART_SIZE];
extern Note TheTrooper[CHART_SIZE];
extern Note Livin_Prayer[CHART_SIZE];
extern Note BringMeToLife[CHART_SIZE];
extern Note KillerQueen[CHART_SIZE];

#endif //CHART_H