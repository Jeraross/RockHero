#ifndef UTILS_H
#define UTILS_H

#include "../../include_raylib/raylib.h"

static inline float clamp(float value, float min, float max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

#endif