//
// Created by jerin on 11/05/2025.
//

#include "chart.h"

Note thunderChart[THUNDER_CHART_SIZE] = {
    // Opening riff (16th notes at ~130 BPM)
    {.lane = 0, .spawnTime = 1.0f},
    {.lane = 2, .spawnTime = 1.15f},
    {.lane = 1, .spawnTime = 1.3f},
    {.lane = 3, .spawnTime = 1.45f},

    {.lane = 0, .spawnTime = 2.0f},
    {.lane = 2, .spawnTime = 2.15f},
    {.lane = 1, .spawnTime = 2.3f},
    {.lane = 3, .spawnTime = 2.45f},

    // Repeat with variation
    {.lane = 0, .spawnTime = 3.0f},
    {.lane = 2, .spawnTime = 3.15f},
    {.lane = 1, .spawnTime = 3.3f},
    {.lane = 3, .spawnTime = 3.45f},

    {.lane = 0, .spawnTime = 4.0f},
    {.lane = 1, .spawnTime = 4.15f},
    {.lane = 2, .spawnTime = 4.3f},
    {.lane = 3, .spawnTime = 4.45f},
    {.lane = 0, .spawnTime = 5.0f},
    {.lane = 2, .spawnTime = 5.15f},
    {.lane = 1, .spawnTime = 5.3f},
    {.lane = 3, .spawnTime = 5.45f},

    {.lane = 0, .spawnTime = 6.0f},
    {.lane = 2, .spawnTime = 6.15f},
    {.lane = 1, .spawnTime = 6.3f},
    {.lane = 3, .spawnTime = 6.45f},

    {.lane = 0, .spawnTime = 7.0f},
    {.lane = 1, .spawnTime = 7.15f},
    {.lane = 2, .spawnTime = 7.3f},
    {.lane = 3, .spawnTime = 7.45f},

    {.lane = 0, .spawnTime = 8.0f},
    {.lane = 2, .spawnTime = 8.15f},
    {.lane = 1, .spawnTime = 8.3f},
    {.lane = 3, .spawnTime = 8.45f},

    // Pequena quebra para preparação do verso
    {.lane = 1, .spawnTime = 9.0f},
    {.lane = 1, .spawnTime = 9.3f},
    {.lane = 2, .spawnTime = 9.6f},

    // Refrão forte (acordes simultâneos)
    {.lane = 0, .spawnTime = 10.0f},
    {.lane = 1, .spawnTime = 10.0f},
    {.lane = 2, .spawnTime = 10.5f},
    {.lane = 3, .spawnTime = 10.5f},

    {.lane = 0, .spawnTime = 11.0f},
    {.lane = 1, .spawnTime = 11.0f},
    {.lane = 2, .spawnTime = 11.5f},
    {.lane = 3, .spawnTime = 11.5f},

    {.lane = 1, .spawnTime = 12.0f},
    {.lane = 3, .spawnTime = 12.15f},
    {.lane = 2, .spawnTime = 12.3f},
    {.lane = 0, .spawnTime = 12.45f},

    // Riff retorna (com nova combinação)
    {.lane = 0, .spawnTime = 13.0f},
    {.lane = 2, .spawnTime = 13.15f},
    {.lane = 1, .spawnTime = 13.3f},
    {.lane = 3, .spawnTime = 13.45f},

    {.lane = 0, .spawnTime = 14.0f},
    {.lane = 1, .spawnTime = 14.15f},
    {.lane = 2, .spawnTime = 14.3f},
    {.lane = 3, .spawnTime = 14.45f},

    // Transição
    {.lane = 1, .spawnTime = 15.0f},
    {.lane = 1, .spawnTime = 15.2f},
    {.lane = 1, .spawnTime = 15.4f},

    // Solo de guitarra – notas rápidas
    {.lane = 2, .spawnTime = 16.0f},
    {.lane = 2, .spawnTime = 16.1f},
    {.lane = 3, .spawnTime = 16.2f},
    {.lane = 1, .spawnTime = 16.3f},
    {.lane = 2, .spawnTime = 16.4f},
    {.lane = 3, .spawnTime = 16.5f},
    {.lane = 0, .spawnTime = 16.6f},
    {.lane = 1, .spawnTime = 16.7f},

    // Riff volta com intensidade
    {.lane = 0, .spawnTime = 20.0f},
    {.lane = 2, .spawnTime = 20.15f},
    {.lane = 1, .spawnTime = 20.3f},
    {.lane = 3, .spawnTime = 20.45f},

    // Continuação do chart após o .spawnTime = 20.45f
    {.lane = 0, .spawnTime = 20.6f},
    {.lane = 1, .spawnTime = 20.75f},
    {.lane = 2, .spawnTime = 20.9f},
    {.lane = 3, .spawnTime = 21.05f},

    {.lane = 1, .spawnTime = 21.2f},
    {.lane = 0, .spawnTime = 21.35f},
    {.lane = 2, .spawnTime = 21.5f},
    {.lane = 3, .spawnTime = 21.65f},

    {.lane = 0, .spawnTime = 21.8f},
    {.lane = 2, .spawnTime = 21.95f},
    {.lane = 1, .spawnTime = 22.1f},
    {.lane = 3, .spawnTime = 22.25f},

    {.lane = 0, .spawnTime = 22.4f},
    {.lane = 1, .spawnTime = 22.55f},
    {.lane = 2, .spawnTime = 22.7f},
    {.lane = 3, .spawnTime = 22.85f},

    // Mini pausa rítmica
    {.lane = 1, .spawnTime = 23.5f},
    {.lane = 2, .spawnTime = 23.7f},
    {.lane = 1, .spawnTime = 23.9f},

    // Acordes simultâneos
    {.lane = 0, .spawnTime = 24.5f},
    {.lane = 1, .spawnTime = 24.5f},
    {.lane = 2, .spawnTime = 25.0f},
    {.lane = 3, .spawnTime = 25.0f},

    {.lane = 0, .spawnTime = 25.5f},
    {.lane = 1, .spawnTime = 25.5f},
    {.lane = 2, .spawnTime = 26.0f},
    {.lane = 3, .spawnTime = 26.0f},

    // Novo riff (mais rápido)
    {.lane = 2, .spawnTime = 27.0f},
    {.lane = 3, .spawnTime = 27.1f},
    {.lane = 2, .spawnTime = 27.2f},
    {.lane = 3, .spawnTime = 27.3f},
    {.lane = 2, .spawnTime = 27.4f},
    {.lane = 3, .spawnTime = 27.5f},
    {.lane = 1, .spawnTime = 27.6f},
    {.lane = 0, .spawnTime = 27.7f},

    {.lane = 1, .spawnTime = 28.0f},
    {.lane = 2, .spawnTime = 28.15f},
    {.lane = 3, .spawnTime = 28.3f},
    {.lane = 0, .spawnTime = 28.45f},

    {.lane = 0, .spawnTime = 29.0f},
    {.lane = 1, .spawnTime = 29.15f},
    {.lane = 2, .spawnTime = 29.3f},
    {.lane = 3, .spawnTime = 29.45f},

    // Destaque no refrão com quebra de padrão
    {.lane = 0, .spawnTime = 30.0f},
    {.lane = 1, .spawnTime = 30.0f},
    {.lane = 2, .spawnTime = 30.25f},
    {.lane = 3, .spawnTime = 30.25f},

    {.lane = 0, .spawnTime = 30.5f},
    {.lane = 2, .spawnTime = 30.65f},
    {.lane = 1, .spawnTime = 30.8f},
    {.lane = 3, .spawnTime = 30.95f},

    {.lane = 0, .spawnTime = 31.1f},
    {.lane = 1, .spawnTime = 31.25f},
    {.lane = 2, .spawnTime = 31.4f},
    {.lane = 3, .spawnTime = 31.55f},

    // Solo – aumento de densidade
    {.lane = 1, .spawnTime = 32.0f},
    {.lane = 2, .spawnTime = 32.1f},
    {.lane = 1, .spawnTime = 32.2f},
    {.lane = 2, .spawnTime = 32.3f},
    {.lane = 3, .spawnTime = 32.4f},
    {.lane = 0, .spawnTime = 32.5f},
    {.lane = 3, .spawnTime = 32.6f},
    {.lane = 1, .spawnTime = 32.7f},

    // Clímax e retorno do riff
    {.lane = 0, .spawnTime = 33.0f},
    {.lane = 2, .spawnTime = 33.15f},
    {.lane = 1, .spawnTime = 33.3f},
    {.lane = 3, .spawnTime = 33.45f},

    {.lane = 0, .spawnTime = 34.0f},
    {.lane = 1, .spawnTime = 34.15f},
    {.lane = 2, .spawnTime = 34.3f},
    {.lane = 3, .spawnTime = 34.45f},

    // Adiciona groove
    {.lane = 1, .spawnTime = 35.0f},
    {.lane = 3, .spawnTime = 35.15f},
    {.lane = 1, .spawnTime = 35.3f},
    {.lane = 0, .spawnTime = 35.45f},

    // Trecho mais "calmo"
    {.lane = 2, .spawnTime = 36.0f},
    {.lane = 3, .spawnTime = 36.3f},
    {.lane = 1, .spawnTime = 36.6f},
    {.lane = 0, .spawnTime = 36.9f},

    // Reentrada no solo com velocidade
    {.lane = 0, .spawnTime = 37.0f},
    {.lane = 1, .spawnTime = 37.1f},
    {.lane = 2, .spawnTime = 37.2f},
    {.lane = 3, .spawnTime = 37.3f},
    {.lane = 0, .spawnTime = 37.4f},
    {.lane = 1, .spawnTime = 37.5f},
    {.lane = 2, .spawnTime = 37.6f},
    {.lane = 3, .spawnTime = 37.7f},

    // Seção final do bloco (até ~50s)
    {.lane = 0, .spawnTime = 39.0f},
    {.lane = 2, .spawnTime = 39.15f},
    {.lane = 1, .spawnTime = 39.3f},
    {.lane = 3, .spawnTime = 39.45f},

    {.lane = 0, .spawnTime = 40.0f},
    {.lane = 2, .spawnTime = 40.15f},
    {.lane = 1, .spawnTime = 40.3f},
    {.lane = 3, .spawnTime = 40.45f},

    // Sobe tensão até 50s
    {.lane = 0, .spawnTime = 42.0f},
    {.lane = 1, .spawnTime = 42.15f},
    {.lane = 2, .spawnTime = 42.3f},
    {.lane = 3, .spawnTime = 42.45f},

    {.lane = 0, .spawnTime = 43.0f},
    {.lane = 1, .spawnTime = 43.15f},
    {.lane = 2, .spawnTime = 43.3f},
    {.lane = 3, .spawnTime = 43.45f},

    {.lane = 0, .spawnTime = 45.0f},
    {.lane = 1, .spawnTime = 45.1f},
    {.lane = 2, .spawnTime = 45.2f},
    {.lane = 3, .spawnTime = 45.3f},

    {.lane = 0, .spawnTime = 47.0f},
    {.lane = 1, .spawnTime = 47.15f},
    {.lane = 2, .spawnTime = 47.3f},
    {.lane = 3, .spawnTime = 47.45f},

    {.lane = 1, .spawnTime = 49.0f},
    {.lane = 2, .spawnTime = 49.15f},
    {.lane = 3, .spawnTime = 49.3f},
    {.lane = 0, .spawnTime = 49.45f},

    {.lane = 0, .spawnTime = 50.0f},
    {.lane = 1, .spawnTime = 50.15f},
    {.lane = 2, .spawnTime = 50.3f},
    {.lane = 3, .spawnTime = 50.45f},

    {.lane = 0, .spawnTime = 51.0f},
    {.lane = 2, .spawnTime = 51.15f},
    {.lane = 1, .spawnTime = 51.3f},
    {.lane = 3, .spawnTime = 51.45f},

    {.lane = 0, .spawnTime = 52.0f},
    {.lane = 1, .spawnTime = 52.1f},
    {.lane = 2, .spawnTime = 52.2f},
    {.lane = 3, .spawnTime = 52.3f},

    {.lane = 0, .spawnTime = 52.4f},
    {.lane = 1, .spawnTime = 52.5f},
    {.lane = 2, .spawnTime = 52.6f},
    {.lane = 3, .spawnTime = 52.7f},

    // Entra novo trecho com groove
    {.lane = 1, .spawnTime = 53.0f},
    {.lane = 3, .spawnTime = 53.2f},
    {.lane = 0, .spawnTime = 53.4f},
    {.lane = 2, .spawnTime = 53.6f},

    // Notas pontuais
    {.lane = 0, .spawnTime = 54.0f},
    {.lane = 3, .spawnTime = 54.5f},
    {.lane = 1, .spawnTime = 55.0f},
    {.lane = 2, .spawnTime = 55.5f},

    // Mini solo
    {.lane = 0, .spawnTime = 56.0f},
    {.lane = 1, .spawnTime = 56.1f},
    {.lane = 2, .spawnTime = 56.2f},
    {.lane = 3, .spawnTime = 56.3f},
    {.lane = 2, .spawnTime = 56.5f},
    {.lane = 3, .spawnTime = 56.7f},
    {.lane = 1, .spawnTime = 56.9f},

    // Retorno ao riff
    {.lane = 0, .spawnTime = 57.5f},
    {.lane = 1, .spawnTime = 57.65f},
    {.lane = 2, .spawnTime = 57.8f},
    {.lane = 3, .spawnTime = 57.95f},

    {.lane = 1, .spawnTime = 58.1f},
    {.lane = 2, .spawnTime = 58.25f},
    {.lane = 3, .spawnTime = 58.4f},
    {.lane = 0, .spawnTime = 58.55f},

    // Alternância rápida
    {.lane = 0, .spawnTime = 59.0f},
    {.lane = 1, .spawnTime = 59.1f},
    {.lane = 2, .spawnTime = 59.2f},
    {.lane = 3, .spawnTime = 59.3f},
    {.lane = 1, .spawnTime = 59.4f},
    {.lane = 2, .spawnTime = 59.5f},
    {.lane = 0, .spawnTime = 59.6f},
    {.lane = 3, .spawnTime = 59.7f},

    // Parte com variação melódica
    {.lane = 1, .spawnTime = 60.2f},
    {.lane = 2, .spawnTime = 60.4f},
    {.lane = 3, .spawnTime = 60.6f},
    {.lane = 0, .spawnTime = 60.8f},

    {.lane = 2, .spawnTime = 61.0f},
    {.lane = 3, .spawnTime = 61.15f},
    {.lane = 2, .spawnTime = 61.3f},
    {.lane = 3, .spawnTime = 61.45f},

    {.lane = 0, .spawnTime = 62.0f},
    {.lane = 1, .spawnTime = 62.15f},
    {.lane = 2, .spawnTime = 62.3f},
    {.lane = 3, .spawnTime = 62.45f},

    // Pausa dramática
    {.lane = 2, .spawnTime = 63.0f},
    {.lane = 3, .spawnTime = 63.5f},
    {.lane = 1, .spawnTime = 64.0f},
    {.lane = 0, .spawnTime = 64.5f},

    // Acordes de impacto
    {.lane = 0, .spawnTime = 65.0f},
    {.lane = 1, .spawnTime = 65.0f},
    {.lane = 2, .spawnTime = 65.25f},
    {.lane = 3, .spawnTime = 65.25f},

    {.lane = 0, .spawnTime = 65.5f},
    {.lane = 1, .spawnTime = 65.5f},
    {.lane = 2, .spawnTime = 65.75f},
    {.lane = 3, .spawnTime = 65.75f},

    // Clímax da seção
    {.lane = 0, .spawnTime = 66.0f},
    {.lane = 1, .spawnTime = 66.1f},
    {.lane = 2, .spawnTime = 66.2f},
    {.lane = 3, .spawnTime = 66.3f},
    {.lane = 1, .spawnTime = 66.4f},
    {.lane = 2, .spawnTime = 66.5f},
    {.lane = 0, .spawnTime = 66.6f},
    {.lane = 3, .spawnTime = 66.7f},

    // Sustenta intensidade
    {.lane = 1, .spawnTime = 67.2f},
    {.lane = 2, .spawnTime = 67.35f},
    {.lane = 3, .spawnTime = 67.5f},
    {.lane = 0, .spawnTime = 67.65f},

    {.lane = 2, .spawnTime = 68.0f},
    {.lane = 3, .spawnTime = 68.2f},
    {.lane = 1, .spawnTime = 68.4f},
    {.lane = 0, .spawnTime = 68.6f},

    // Refrão instrumental
    {.lane = 0, .spawnTime = 69.0f},
    {.lane = 1, .spawnTime = 69.0f},
    {.lane = 2, .spawnTime = 69.3f},
    {.lane = 3, .spawnTime = 69.3f},

    {.lane = 0, .spawnTime = 70.0f},
    {.lane = 2, .spawnTime = 70.2f},
    {.lane = 1, .spawnTime = 70.4f},
    {.lane = 3, .spawnTime = 70.6f},

    // Parte final do trecho (construção para os 80s)
    {.lane = 1, .spawnTime = 71.0f},
    {.lane = 2, .spawnTime = 71.15f},
    {.lane = 3, .spawnTime = 71.3f},
    {.lane = 0, .spawnTime = 71.45f},

    {.lane = 1, .spawnTime = 72.0f},
    {.lane = 2, .spawnTime = 72.1f},
    {.lane = 3, .spawnTime = 72.2f},
    {.lane = 0, .spawnTime = 72.3f},

    {.lane = 2, .spawnTime = 73.0f},
    {.lane = 3, .spawnTime = 73.15f},
    {.lane = 1, .spawnTime = 73.3f},
    {.lane = 0, .spawnTime = 73.45f},

    // Última sequência do trecho
    {.lane = 0, .spawnTime = 74.0f},
    {.lane = 1, .spawnTime = 74.1f},
    {.lane = 2, .spawnTime = 74.2f},
    {.lane = 3, .spawnTime = 74.3f},

    {.lane = 1, .spawnTime = 75.0f},
    {.lane = 3, .spawnTime = 75.25f},
    {.lane = 0, .spawnTime = 75.5f},
    {.lane = 2, .spawnTime = 75.75f},

    {.lane = 1, .spawnTime = 76.0f},
    {.lane = 2, .spawnTime = 76.15f},
    {.lane = 3, .spawnTime = 76.3f},
    {.lane = 0, .spawnTime = 76.45f},

    {.lane = 0, .spawnTime = 77.0f},
    {.lane = 1, .spawnTime = 77.2f},
    {.lane = 2, .spawnTime = 77.4f},
    {.lane = 3, .spawnTime = 77.6f},

    {.lane = 1, .spawnTime = 78.0f},
    {.lane = 2, .spawnTime = 78.1f},
    {.lane = 3, .spawnTime = 78.2f},
    {.lane = 0, .spawnTime = 78.3f},

    {.lane = 2, .spawnTime = 79.0f},
    {.lane = 3, .spawnTime = 79.2f},
    {.lane = 1, .spawnTime = 79.4f},
    {.lane = 0, .spawnTime = 79.6f},

    {.lane = -1} // Terminador
};