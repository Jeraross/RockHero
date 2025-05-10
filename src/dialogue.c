#include "../include/dialogue.h"
#include <string.h>

void InitDialogue(DialogueSystem *dialogue, const char *text, Sound sound) {
    strncpy(dialogue->text, text, sizeof(dialogue->text));
    dialogue->currentChar = 0;
    dialogue->timer = 0;
    dialogue->isActive = false;
    dialogue->isFinished = false;
    dialogue->typeSound = sound;
}

void UpdateDialogue(DialogueSystem *dialogue) {
    if (!dialogue->isActive || dialogue->isFinished) return;

    dialogue->timer += GetFrameTime();
    const float charSpeed = 0.05f;

    if (dialogue->timer >= charSpeed) {
        dialogue->timer = 0;
        dialogue->currentChar++;

        if (dialogue->currentChar < (int)strlen(dialogue->text) &&
            dialogue->text[dialogue->currentChar - 1] != ' ') {
            PlaySound(dialogue->typeSound);
        }

        if (dialogue->currentChar >= (int)strlen(dialogue->text)) {
            dialogue->isFinished = true;
        }
    }
}

void DrawDialogue(DialogueSystem *dialogue) {
    if (!dialogue->isActive) return;

    const int boxWidth = 600;
    const int boxHeight = 120;
    const int boxX = (1920 - boxWidth) / 2;
    const int boxY = 1080 - boxHeight - 50;
    const int textX = boxX + 20;
    const int textY = boxY + 40;

    DrawRectangle(boxX, boxY, boxWidth, boxHeight, Fade(BLACK, 0.8f));
    DrawRectangleLines(boxX, boxY, boxWidth, boxHeight, WHITE);

    char displayedText[256] = {0};
    strncpy(displayedText, dialogue->text, dialogue->currentChar);
    DrawText(displayedText, textX, textY, 20, WHITE);

    if (dialogue->isFinished) {
        DrawText("Press ENTER to continue...",
                 boxX + boxWidth - 200,
                 boxY + boxHeight - 20,
                 15, YELLOW);
    }
}
