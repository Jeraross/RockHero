#include "../include/dialogue.h"
#include <string.h>

void DrawWrappedText(const char *text, int x, int y, int maxWidth, int fontSize, Color color) {
    int lineHeight = fontSize + 5;
    int offsetY = 0;

    const char *start = text;

    while (*start) {  // Removi a verificação de maxHeight
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
        while (*start == ' ') start++;
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

    const int boxWidth = 1100;
    const int boxHeight = 175;
    const int boxX = (1920 - boxWidth) / 2;
    const int boxY = 1080 - boxHeight - 50;
    const int textX = boxX + 20;
    const int textY = boxY + 40;

    DrawRectangle(boxX, boxY, boxWidth, boxHeight, Fade(BLACK, 0.8f));
    DrawRectangleLines(boxX, boxY, boxWidth, boxHeight, WHITE);

    // Buffer grande para texto exibido gradualmente
    char displayedText[1024] = {0};

    // Copia apenas caracteres completos em UTF-8
    int byteIndex = 0;
    int charCount = 0;

    while (dialogue->text[byteIndex] != '\0' && charCount < dialogue->currentChar) {
        unsigned char c = (unsigned char)dialogue->text[byteIndex];
        int charSize = 1;

        if (c >= 0xF0) charSize = 4;       // 4-byte UTF-8
        else if (c >= 0xE0) charSize = 3;  // 3-byte UTF-8
        else if (c >= 0xC0) charSize = 2;  // 2-byte UTF-8

        for (int i = 0; i < charSize; i++) {
            displayedText[byteIndex + i] = dialogue->text[byteIndex + i];
        }

        byteIndex += charSize;
        charCount++;
    }

    displayedText[byteIndex] = '\0';  // Finaliza a string corretamente

    DrawWrappedText(displayedText, textX, textY, boxWidth - 40, 20, WHITE);

    if (dialogue->isFinished) {
        DrawText("Press ENTER to continue...",
                 boxX + boxWidth - 200,
                 boxY + boxHeight - 20,
                 15, YELLOW);
    }
}


