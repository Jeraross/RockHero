//
// Created by jerin on 11/05/2025.
//

#ifndef CHART_H
#define CHART_H

#include "raylib.h"

#define SKYFALL_CHART_SIZE 23

typedef struct {
    Rectangle rect;
    int lane;
    bool active;
    Color color;
    float spawnTime;
    bool hit;
} Note;

extern Note skyfallChart[SKYFALL_CHART_SIZE];

#endif //CHART_H