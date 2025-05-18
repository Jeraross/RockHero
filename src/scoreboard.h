//
// Created by jpamo on 18/05/2025.
//

#ifndef ROCKHEROM_SCOREBOARD_H
#define ROCKHEROM_SCOREBOARD_H

#define MAX_NAME_LENGTH 20
#define MAX_SCORES 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    float time;  // tempo em segundos
} ScoreEntry;


#endif //ROCKHEROM_SCOREBOARD_H
