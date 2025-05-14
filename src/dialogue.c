#include "../include/dialogue.h"
#include <string.h>
#include <stdio.h> // Para printf (debug)

void DrawWrappedText(const char *text, int x, int y, int maxWidth, int fontSize, Color color) {
    int lineHeight = fontSize + 5;
    int offsetY = 0;
    const char *start = text;

    // Margem de segurança para evitar que o texto encoste nas bordas
    int effectiveMaxWidth = maxWidth - 10;

    while (*start) {
        int length = 0;
        int lastSpace = -1;
        char buffer[1024] = {0};
        int currentWidth = 0;

        while (start[length] && length < (int)(sizeof(buffer) - 1)) {
            // Copia o caractere atual para o buffer
            buffer[length] = start[length];
            buffer[length + 1] = '\0';

            // Mede a largura do texto acumulado
            currentWidth = MeasureText(buffer, fontSize);

            // Verifica se ultrapassou a largura máxima
            if (currentWidth > effectiveMaxWidth) {
                if (lastSpace != -1) {
                    // Quebra no último espaço encontrado
                    length = lastSpace;
                }
                break;
            }

            // Atualiza o último espaço encontrado
            if (start[length] == ' ') {
                lastSpace = length;
            }

            length++;
        }

        // Desenha a linha atual
        if (length > 0) {
            strncpy(buffer, start, length);
            buffer[length] = '\0';
            DrawText(buffer, x, y + offsetY, fontSize, color);
            offsetY += lineHeight;
        }

        // Avança para o próximo caractere após a quebra
        start += length;

        // Pula espaços no início da próxima linha
        while (*start == ' ') start++;
    }
}

void InitDialogue(DialogueSystem *dialogue, const char *text, Sound sound) {
    strncpy(dialogue->text, text, sizeof(dialogue->text));
    dialogue->text[sizeof(dialogue->text) - 1] = '\0'; // Garante terminação nula
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

        if (dialogue->currentChar < (int)strlen(dialogue->text)) {
            // Toca som apenas para caracteres visíveis (não espaços)
            if (dialogue->text[dialogue->currentChar - 1] != ' ') {
                PlaySound(dialogue->typeSound);
            }
        }

        if (dialogue->currentChar >= (int)strlen(dialogue->text)) {
            dialogue->isFinished = true;
        }
    }
}

void DrawDialogue(DialogueSystem *dialogue) {
    if (!dialogue->isActive) return;

    // Dimensões da caixa de diálogo
    const int boxWidth = 1100;
    const int boxHeight = 175;
    const int boxX = (GetScreenWidth() - boxWidth) / 2;  // Centraliza horizontalmente
    const int boxY = GetScreenHeight() - boxHeight - 50; // Posiciona na parte inferior
    const int textX = boxX + 20;
    const int textY = boxY + 40;
    const int textWidth = boxWidth - 40;

    // Desenha a caixa de diálogo
    DrawRectangle(boxX, boxY, boxWidth, boxHeight, Fade(BLACK, 0.8f));
    DrawRectangleLines(boxX, boxY, boxWidth, boxHeight, WHITE);

    char displayedText[1024] = {0};
    int byteIndex = 0;
    int charCount = 0;

    while (dialogue->text[byteIndex] != '\0') {
        unsigned char c = (unsigned char)dialogue->text[byteIndex];
        int charSize = 1;

        if (c >= 0xF0) charSize = 4;
        else if (c >= 0xE0) charSize = 3;
        else if (c >= 0xC0) charSize = 2;

        if (charCount + 1 > dialogue->currentChar) break;

        for (int i = 0; i < charSize; i++) {
            displayedText[byteIndex + i] = dialogue->text[byteIndex + i];
        }

        byteIndex += charSize;
        charCount++;
    }
    displayedText[byteIndex] = '\0';


    // Desenha o texto com quebra de linha
    DrawWrappedText(displayedText, textX, textY, textWidth, 20, WHITE);

    // Mostra instrução para continuar quando o texto terminar
    if (dialogue->isFinished) {
        const char *continueText = "Press ENTER to continue...";
        int textWidth = MeasureText(continueText, 15);
        DrawText(continueText,
                 boxX + boxWidth - textWidth - 20, // Alinha à direita com margem
                 boxY + boxHeight - 30,
                 15, YELLOW);
    }
}