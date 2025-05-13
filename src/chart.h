//
// Created by jerin on 11/05/2025.
//

#ifndef CHART_H
#define CHART_H

#include "raylib.h"

#define THUNDER_CHART_SIZE 500

typedef struct {
    Rectangle rect;
    int lane;
    bool active;
    Color color;
    float spawnTime;
    bool hit;
} Note;

extern Note thunderChart[THUNDER_CHART_SIZE];

#endif //CHART_H