#ifndef DIALOGUE_H
#define DIALOGUE_H

#include "../include_raylib/raylib.h"

#define MAX_INPUT 256
#define MAX_RESPOSTA 1024

typedef struct {
    char text[256];
    int currentChar;
    float timer;
    bool isActive;
    bool isFinished;
    Sound typeSound;
} DialogueSystem;

void InitDialogue(DialogueSystem *dialogue, const char *text, Sound sound);
void UpdateDialogue(DialogueSystem *dialogue);
void DrawDialogue(DialogueSystem *dialogue);

#endif
