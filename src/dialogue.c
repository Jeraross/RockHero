#include "../include/dialogue.h"
#include <string.h>

void DrawWrappedText(const char *text, int x, int y, int maxWidth, int fontSize, Color color) {
    int lineHeight = fontSize + 5;
    int offsetY = 0;

    const char *start = text;

    while (*start) {
        int length = 0;
        int lastSpace = -1;
        char buffer[512];

        while (start[length] && length < (int)(sizeof(buffer) - 1)) {
            if (start[length] == ' ') lastSpace = length;

            buffer[length] = start[length];
            buffer[length + 1] = '\0';

            if (MeasureText(buffer, fontSize) > maxWidth) break;
            length++;
        }

        if (MeasureText(buffer, fontSize) > maxWidth && lastSpace != -1) {
            length = lastSpace;
        }

        strncpy(buffer, start, length);
        buffer[length] = '\0';

        DrawText(buffer, x, y + offsetY, fontSize, color);
        offsetY += lineHeight;

        start += length;
        while (*start == ' ') start++;  // pula espaços extras
    }
}

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

    const int boxWidth = 750;
    const int boxHeight = 180;
    const int boxX = (1920 - boxWidth) / 2;
    const int boxY = 1080 - boxHeight - 50;
    const int textX = boxX + 20;
    const int textY = boxY + 40;

    DrawRectangle(boxX, boxY, boxWidth, boxHeight, Fade(BLACK, 0.8f));
    DrawRectangleLines(boxX, boxY, boxWidth, boxHeight, WHITE);

    char displayedText[256] = {0};
    strncpy(displayedText, dialogue->text, dialogue->currentChar);
    displayedText[dialogue->currentChar] = '\0';
    DrawWrappedText(displayedText, textX, textY, boxWidth - 40, 20, WHITE);

    if (dialogue->isFinished) {
        DrawText("Press ENTER to continue...",
                 boxX + boxWidth - 200,
                 boxY + boxHeight - 20,
                 15, YELLOW);
    }
}
