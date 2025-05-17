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

Note SweetChildOMine[THUNDER_CHART_SIZE] = {
        {.lane = 1, .spawnTime = 0.212f},
        {.lane = 2, .spawnTime = 0.763f},
        {.lane = 0, .spawnTime = 1.262f},
        {.lane = 3, .spawnTime = 1.664f},
        {.lane = 1, .spawnTime = 2.157f},
        {.lane = 2, .spawnTime = 2.613f},
        {.lane = 3, .spawnTime = 3.040f},
        {.lane = 0, .spawnTime = 3.277f},
        {.lane = 2, .spawnTime = 3.517f},
        {.lane = 1, .spawnTime = 4.015f},
        {.lane = 3, .spawnTime = 4.492f},
        {.lane = 0, .spawnTime = 4.957f},
        {.lane = 2, .spawnTime = 5.181f},
        {.lane = 1, .spawnTime = 5.408f},
        {.lane = 3, .spawnTime = 5.897f},
        {.lane = 0, .spawnTime = 6.354f},
        {.lane = 2, .spawnTime = 6.844f},
        {.lane = 1, .spawnTime = 7.068f},
        {.lane = 3, .spawnTime = 7.272f},
        {.lane = 0, .spawnTime = 7.754f},
        {.lane = 2, .spawnTime = 8.240f},
        {.lane = 1, .spawnTime = 8.734f},
        {.lane = 3, .spawnTime = 8.943f},
        {.lane = 0, .spawnTime = 9.153f},
        {.lane = 2, .spawnTime = 9.651f},
        {.lane = 1, .spawnTime = 10.117f},
        {.lane = 3, .spawnTime = 10.609f},
        {.lane = 0, .spawnTime = 10.828f},
        {.lane = 2, .spawnTime = 11.061f},
        {.lane = 1, .spawnTime = 11.572f},
        {.lane = 3, .spawnTime = 12.049f},
        {.lane = 0, .spawnTime = 12.518f},
        {.lane = 2, .spawnTime = 12.742f},
        {.lane = 1, .spawnTime = 12.983f},
        {.lane = 3, .spawnTime = 13.487f},
        {.lane = 0, .spawnTime = 13.942f},
        {.lane = 2, .spawnTime = 14.419f},
        {.lane = 1, .spawnTime = 14.636f},
        {.lane = 3, .spawnTime = 14.858f},
        {.lane = 0, .spawnTime = 15.331f},
        {.lane = 2, .spawnTime = 15.834f},
        {.lane = 1, .spawnTime = 16.301f},
        {.lane = 3, .spawnTime = 16.541f},
        {.lane = 0, .spawnTime = 16.759f},
        {.lane = 2, .spawnTime = 17.236f},
        {.lane = 1, .spawnTime = 17.708f},
        {.lane = 3, .spawnTime = 18.151f},
        {.lane = 0, .spawnTime = 18.390f},
        {.lane = 2, .spawnTime = 18.627f},
        {.lane = 1, .spawnTime = 19.115f},
        {.lane = 3, .spawnTime = 19.601f},
        {.lane = 0, .spawnTime = 20.058f},
        {.lane = 2, .spawnTime = 20.307f},
        {.lane = 1, .spawnTime = 20.532f},
        {.lane = 3, .spawnTime = 21.041f},
        {.lane = 0, .spawnTime = 21.533f},
        {.lane = 2, .spawnTime = 21.964f},
        {.lane = 1, .spawnTime = 22.197f},
        {.lane = 3, .spawnTime = 22.414f},
        {.lane = 0, .spawnTime = 22.886f},
        {.lane = 2, .spawnTime = 23.406f},
        {.lane = 1, .spawnTime = 23.892f},
        {.lane = 3, .spawnTime = 24.110f},
        {.lane = 0, .spawnTime = 24.347f},
        {.lane = 2, .spawnTime = 24.805f},
        {.lane = 1, .spawnTime = 25.307f},
        {.lane = 3, .spawnTime = 25.825f},
        {.lane = 0, .spawnTime = 26.021f},
        {.lane = 2, .spawnTime = 26.230f},
        {.lane = 1, .spawnTime = 26.730f},
        {.lane = 3, .spawnTime = 27.167f},
        {.lane = 0, .spawnTime = 27.668f},
        {.lane = 2, .spawnTime = 27.898f},
        {.lane = 1, .spawnTime = 28.123f},
        {.lane = 3, .spawnTime = 28.618f},
        {.lane = 0, .spawnTime = 29.120f},
        {.lane = 2, .spawnTime = 29.578f},
        {.lane = 1, .spawnTime = 29.808f},
        {.lane = 3, .spawnTime = 30.041f},
        {.lane = 0, .spawnTime = 30.536f},
        {.lane = 2, .spawnTime = 31.002f},
        {.lane = 1, .spawnTime = 31.505f},
        {.lane = 3, .spawnTime = 31.729f},
        {.lane = 0, .spawnTime = 31.984f},
        {.lane = 2, .spawnTime = 32.434f},
        {.lane = 1, .spawnTime = 32.952f},
        {.lane = 3, .spawnTime = 33.409f},
        {.lane = 0, .spawnTime = 33.638f},
        {.lane = 2, .spawnTime = 33.865f},
        {.lane = 1, .spawnTime = 34.306f},
        {.lane = 3, .spawnTime = 34.862f},
        {.lane = 0, .spawnTime = 35.317f},
        {.lane = 2, .spawnTime = 35.560f},
        {.lane = 1, .spawnTime = 35.786f},
        {.lane = 3, .spawnTime = 36.315f},
        {.lane = 0, .spawnTime = 36.747f},
        {.lane = 2, .spawnTime = 37.230f},
        {.lane = 1, .spawnTime = 37.486f},
        {.lane = 3, .spawnTime = 37.701f},
        {.lane = 0, .spawnTime = 38.205f},
        {.lane = 2, .spawnTime = 38.690f},
        {.lane = 1, .spawnTime = 39.173f},
        {.lane = 3, .spawnTime = 39.412f},
        {.lane = 0, .spawnTime = 39.635f},
        {.lane = 2, .spawnTime = 40.093f},
        {.lane = 1, .spawnTime = 40.589f},
        {.lane = 3, .spawnTime = 41.046f},
        {.lane = 0, .spawnTime = 41.547f},
        {.lane = 2, .spawnTime = 42.049f},
        {.lane = 1, .spawnTime = 42.489f},
        {.lane = 3, .spawnTime = 42.995f},
        {.lane = 0, .spawnTime = 43.468f},
        {.lane = 2, .spawnTime = 43.931f},
        {.lane = 1, .spawnTime = 44.423f},
        {.lane = 3, .spawnTime = 44.945f},
        {.lane = 0, .spawnTime = 48.093f},
        {.lane = 2, .spawnTime = 48.351f},
        {.lane = 1, .spawnTime = 48.704f},
        {.lane = 3, .spawnTime = 49.546f},
        {.lane = 0, .spawnTime = 50.798f},
        {.lane = 2, .spawnTime = 51.066f},
        {.lane = 1, .spawnTime = 51.480f},
        {.lane = 3, .spawnTime = 52.511f},
        {.lane = 0, .spawnTime = 54.396f},
        {.lane = 2, .spawnTime = 54.805f},
        {.lane = 1, .spawnTime = 55.224f},
        {.lane = 3, .spawnTime = 55.760f},
        {.lane = 0, .spawnTime = 56.193f},
        {.lane = 2, .spawnTime = 58.398f},
        {.lane = 1, .spawnTime = 58.612f},
        {.lane = 3, .spawnTime = 58.885f},
        {.lane = 0, .spawnTime = 59.070f},
        {.lane = 2, .spawnTime = 59.316f},
        {.lane = 1, .spawnTime = 59.577f},
        {.lane = 3, .spawnTime = 59.819f},
        {.lane = 0, .spawnTime = 60.086f},
        {.lane = 2, .spawnTime = 62.226f},
        {.lane = 1, .spawnTime = 62.427f},
        {.lane = 3, .spawnTime = 62.721f},
        {.lane = 0, .spawnTime = 63.155f},
        {.lane = 2, .spawnTime = 63.373f},
        {.lane = 1, .spawnTime = 63.945f},
        {.lane = 3, .spawnTime = 65.797f},
        {.lane = 0, .spawnTime = 66.011f},
        {.lane = 2, .spawnTime = 66.541f},
        {.lane = 1, .spawnTime = 67.038f},
        {.lane = 3, .spawnTime = 67.237f},
        {.lane = 0, .spawnTime = 67.703f},
        {.lane = 2, .spawnTime = 69.583f},
        {.lane = 1, .spawnTime = 70.307f},
        {.lane = 3, .spawnTime = 70.510f},
        {.lane = 0, .spawnTime = 70.724f},
        {.lane = 2, .spawnTime = 70.958f},
        {.lane = 1, .spawnTime = 71.212f},
        {.lane = 3, .spawnTime = 72.236f},
        {.lane = 0, .spawnTime = 73.587f},
        {.lane = 2, .spawnTime = 73.793f},
        {.lane = 1, .spawnTime = 74.063f},
        {.lane = 3, .spawnTime = 74.508f},
        {.lane = 0, .spawnTime = 74.727f},
        {.lane = 2, .spawnTime = 75.206f},
        {.lane = 1, .spawnTime = 75.428f},
        {.lane = 3, .spawnTime = 75.686f},
        {.lane = 0, .spawnTime = 76.175f},
        {.lane = 2, .spawnTime = 76.666f},
        {.lane = 1, .spawnTime = 77.148f},
        {.lane = 3, .spawnTime = 77.370f},
        {.lane = 0, .spawnTime = 77.602f},
        {.lane = 2, .spawnTime = 78.061f},
        {.lane = 1, .spawnTime = 78.563f},
        {.lane = 3, .spawnTime = 79.045f},
        {.lane = 0, .spawnTime = 79.275f},
        {.lane = 2, .spawnTime = 79.490f},
        {.lane = 1, .spawnTime = 79.967f},
        {.lane = 3, .spawnTime = 80.509f},
        {.lane = 0, .spawnTime = 80.982f},
        {.lane = 2, .spawnTime = 81.211f},
        {.lane = 1, .spawnTime = 81.433f},
        {.lane = 3, .spawnTime = 81.928f},
        {.lane = 0, .spawnTime = 82.420f},
        {.lane = 2, .spawnTime = 82.894f},
        {.lane = 1, .spawnTime = 83.101f},
        {.lane = 3, .spawnTime = 83.346f},
        {.lane = 0, .spawnTime = 83.875f},
        {.lane = 2, .spawnTime = 84.371f},
        {.lane = 1, .spawnTime = 84.828f},
        {.lane = 3, .spawnTime = 85.049f},
        {.lane = 0, .spawnTime = 85.288f},
        {.lane = 2, .spawnTime = 85.752f},
        {.lane = 1, .spawnTime = 86.214f},
        {.lane = 3, .spawnTime = 86.688f},
        {.lane = 0, .spawnTime = 86.904f},
        {.lane = 2, .spawnTime = 87.172f},
        {.lane = 1, .spawnTime = 87.422f},

        // Terminator
        {.lane = -1}
};

Note TheTrooper[THUNDER_CHART_SIZE] = {
        {.lane = 2, .spawnTime = 2.089f},
        {.lane = 4, .spawnTime = 2.274f},
        {.lane = 1, .spawnTime = 2.450f},
        {.lane = 3, .spawnTime = 2.623f},
        {.lane = 0, .spawnTime = 3.004f},
        {.lane = 2, .spawnTime = 3.215f},
        {.lane = 4, .spawnTime = 3.620f},
        {.lane = 1, .spawnTime = 3.813f},
        {.lane = 3, .spawnTime = 4.008f},
        {.lane = 0, .spawnTime = 4.401f},
        {.lane = 2, .spawnTime = 4.598f},
        {.lane = 4, .spawnTime = 4.778f},
        {.lane = 1, .spawnTime = 5.175f},
        {.lane = 3, .spawnTime = 5.375f},
        {.lane = 0, .spawnTime = 5.549f},
        {.lane = 2, .spawnTime = 5.746f},
        {.lane = 4, .spawnTime = 6.111f},
        {.lane = 1, .spawnTime = 6.356f},
        {.lane = 3, .spawnTime = 6.489f},
        {.lane = 0, .spawnTime = 6.577f},
        {.lane = 2, .spawnTime = 6.819f},
        {.lane = 4, .spawnTime = 6.981f},
        {.lane = 1, .spawnTime = 7.135f},
        {.lane = 3, .spawnTime = 7.237f},
        {.lane = 0, .spawnTime = 7.562f},
        {.lane = 2, .spawnTime = 7.756f},
        {.lane = 4, .spawnTime = 7.926f},
        {.lane = 1, .spawnTime = 8.079f},
        {.lane = 3, .spawnTime = 8.302f},
        {.lane = 0, .spawnTime = 8.484f},
        {.lane = 2, .spawnTime = 8.656f},
        {.lane = 4, .spawnTime = 8.830f},
        {.lane = 1, .spawnTime = 9.182f},
        {.lane = 3, .spawnTime = 9.374f},
        {.lane = 0, .spawnTime = 9.486f},
        {.lane = 2, .spawnTime = 9.585f},
        {.lane = 4, .spawnTime = 9.826f},
        {.lane = 1, .spawnTime = 9.996f},
        {.lane = 3, .spawnTime = 10.172f},
        {.lane = 0, .spawnTime = 10.273f},
        {.lane = 2, .spawnTime = 10.379f},
        {.lane = 4, .spawnTime = 10.629f},
        {.lane = 1, .spawnTime = 10.804f},
        {.lane = 3, .spawnTime = 10.969f},
        {.lane = 0, .spawnTime = 11.063f},
        {.lane = 2, .spawnTime = 11.152f},
        {.lane = 4, .spawnTime = 11.369f},
        {.lane = 1, .spawnTime = 11.543f},
        {.lane = 3, .spawnTime = 11.727f},
        {.lane = 0, .spawnTime = 11.896f},
        {.lane = 2, .spawnTime = 12.184f},
        {.lane = 4, .spawnTime = 12.352f},
        {.lane = 1, .spawnTime = 12.458f},
        {.lane = 3, .spawnTime = 12.547f},
        {.lane = 0, .spawnTime = 12.834f},
        {.lane = 2, .spawnTime = 13.017f},
        {.lane = 4, .spawnTime = 13.185f},
        {.lane = 1, .spawnTime = 13.580f},
        {.lane = 3, .spawnTime = 13.756f},
        {.lane = 0, .spawnTime = 13.942f},
        {.lane = 2, .spawnTime = 14.325f},
        {.lane = 4, .spawnTime = 14.497f},
        {.lane = 1, .spawnTime = 14.685f},
        {.lane = 3, .spawnTime = 14.867f},
        {.lane = 0, .spawnTime = 15.239f},
        {.lane = 2, .spawnTime = 15.421f},
        {.lane = 4, .spawnTime = 15.802f},
        {.lane = 1, .spawnTime = 16.006f},
        {.lane = 3, .spawnTime = 16.198f},
        {.lane = 0, .spawnTime = 16.606f},
        {.lane = 2, .spawnTime = 16.804f},
        {.lane = 4, .spawnTime = 17.005f},
        {.lane = 1, .spawnTime = 17.361f},
        {.lane = 3, .spawnTime = 17.541f},
        {.lane = 0, .spawnTime = 17.733f},
        {.lane = 2, .spawnTime = 17.913f},
        {.lane = 4, .spawnTime = 18.257f},
        {.lane = 1, .spawnTime = 18.449f},
        {.lane = 3, .spawnTime = 18.805f},
        {.lane = 0, .spawnTime = 19.005f},
        {.lane = 2, .spawnTime = 19.223f},
        {.lane = 4, .spawnTime = 19.605f},
        {.lane = 1, .spawnTime = 19.786f},
        {.lane = 3, .spawnTime = 19.982f},
        {.lane = 0, .spawnTime = 20.371f},
        {.lane = 2, .spawnTime = 20.546f},
        {.lane = 4, .spawnTime = 20.740f},
        {.lane = 1, .spawnTime = 20.925f},
        {.lane = 3, .spawnTime = 21.284f},
        {.lane = 0, .spawnTime = 21.482f},
        {.lane = 2, .spawnTime = 21.843f},
        {.lane = 4, .spawnTime = 22.024f},
        {.lane = 1, .spawnTime = 22.230f},
        {.lane = 3, .spawnTime = 22.617f},
        {.lane = 0, .spawnTime = 22.803f},
        {.lane = 2, .spawnTime = 23.004f},
        {.lane = 4, .spawnTime = 23.391f},
        {.lane = 1, .spawnTime = 23.572f},
        {.lane = 3, .spawnTime = 23.753f},
        {.lane = 0, .spawnTime = 23.938f},
        {.lane = 2, .spawnTime = 24.271f},
        {.lane = 4, .spawnTime = 24.439f},
        {.lane = 1, .spawnTime = 24.847f},
        {.lane = 3, .spawnTime = 25.061f},
        {.lane = 0, .spawnTime = 25.243f},
        {.lane = 2, .spawnTime = 25.624f},
        {.lane = 4, .spawnTime = 25.804f},
        {.lane = 1, .spawnTime = 25.982f},
        {.lane = 3, .spawnTime = 26.353f},
        {.lane = 0, .spawnTime = 26.536f},
        {.lane = 2, .spawnTime = 26.725f},
        {.lane = 4, .spawnTime = 26.910f},
        {.lane = 1, .spawnTime = 27.252f},
        {.lane = 3, .spawnTime = 27.443f},
        {.lane = 0, .spawnTime = 27.828f},
        {.lane = 2, .spawnTime = 28.016f},
        {.lane = 4, .spawnTime = 28.215f},
        {.lane = 1, .spawnTime = 28.598f},
        {.lane = 3, .spawnTime = 28.789f},
        {.lane = 0, .spawnTime = 28.988f},
        {.lane = 2, .spawnTime = 29.363f},
        {.lane = 4, .spawnTime = 29.555f},
        {.lane = 1, .spawnTime = 29.739f},
        {.lane = 3, .spawnTime = 29.928f},
        {.lane = 0, .spawnTime = 30.275f},
        {.lane = 2, .spawnTime = 30.472f},
        {.lane = 4, .spawnTime = 30.841f},
        {.lane = 1, .spawnTime = 31.017f},
        {.lane = 3, .spawnTime = 31.249f},
        {.lane = 0, .spawnTime = 31.634f},
        {.lane = 2, .spawnTime = 31.839f},
        {.lane = 4, .spawnTime = 32.052f},
        {.lane = 1, .spawnTime = 32.379f},
        {.lane = 3, .spawnTime = 32.569f},
        {.lane = 0, .spawnTime = 32.760f},
        {.lane = 2, .spawnTime = 32.949f},
        {.lane = 4, .spawnTime = 33.283f},
        {.lane = 1, .spawnTime = 33.473f},
        {.lane = 3, .spawnTime = 33.819f},
        {.lane = 0, .spawnTime = 34.010f},
        {.lane = 2, .spawnTime = 34.228f},
        {.lane = 4, .spawnTime = 34.618f},
        {.lane = 1, .spawnTime = 34.801f},
        {.lane = 3, .spawnTime = 35.006f},
        {.lane = 0, .spawnTime = 35.355f},
        {.lane = 2, .spawnTime = 35.552f},
        {.lane = 4, .spawnTime = 35.735f},
        {.lane = 1, .spawnTime = 35.905f},
        {.lane = 3, .spawnTime = 38.344f},
        {.lane = 0, .spawnTime = 38.511f},
        {.lane = 2, .spawnTime = 38.705f},
        {.lane = 4, .spawnTime = 38.901f},
        {.lane = 1, .spawnTime = 41.344f},
        {.lane = 3, .spawnTime = 41.532f},
        {.lane = 0, .spawnTime = 41.709f},
        {.lane = 2, .spawnTime = 41.911f},
        {.lane = 4, .spawnTime = 44.451f},
        {.lane = 1, .spawnTime = 44.623f},
        {.lane = 3, .spawnTime = 44.810f},
        {.lane = 0, .spawnTime = 44.992f},
        {.lane = 2, .spawnTime = 47.521f},
        {.lane = 4, .spawnTime = 47.705f},
        {.lane = 1, .spawnTime = 47.858f},
        {.lane = 3, .spawnTime = 48.018f},
        {.lane = 0, .spawnTime = 48.415f},
        {.lane = 2, .spawnTime = 48.596f},
        {.lane = 4, .spawnTime = 48.941f},
        {.lane = 1, .spawnTime = 49.220f},
        {.lane = 3, .spawnTime = 49.637f},
        {.lane = 0, .spawnTime = 50.034f},
        {.lane = 2, .spawnTime = 50.402f},
        {.lane = 4, .spawnTime = 50.592f},
        {.lane = 1, .spawnTime = 50.768f},
        {.lane = 3, .spawnTime = 50.973f},
        {.lane = 0, .spawnTime = 51.416f},
        {.lane = 2, .spawnTime = 51.608f},
        {.lane = 4, .spawnTime = 51.690f},
        {.lane = 1, .spawnTime = 51.803f},
        {.lane = 3, .spawnTime = 52.009f},
        {.lane = 0, .spawnTime = 52.177f},
        {.lane = 2, .spawnTime = 52.352f},
        {.lane = 4, .spawnTime = 52.440f},
        {.lane = 1, .spawnTime = 52.543f},
        {.lane = 3, .spawnTime = 52.751f},
        {.lane = 0, .spawnTime = 52.939f},
        {.lane = 2, .spawnTime = 53.119f},
        {.lane = 4, .spawnTime = 53.203f},
        {.lane = 1, .spawnTime = 53.295f},
        {.lane = 3, .spawnTime = 53.507f},
        {.lane = 0, .spawnTime = 53.688f},
        {.lane = 2, .spawnTime = 53.862f},
        {.lane = 4, .spawnTime = 54.046f},
        {.lane = 1, .spawnTime = 54.407f},
        {.lane = 3, .spawnTime = 54.578f},
        {.lane = 0, .spawnTime = 54.958f},
        {.lane = 2, .spawnTime = 55.127f},
        {.lane = 4, .spawnTime = 55.320f},
        {.lane = 1, .spawnTime = 55.736f},
        {.lane = 3, .spawnTime = 55.915f},
        {.lane = 0, .spawnTime = 56.105f},
        {.lane = 2, .spawnTime = 56.482f},
        {.lane = 4, .spawnTime = 56.672f},
        {.lane = 1, .spawnTime = 56.860f},
        {.lane = 3, .spawnTime = 57.039f},
        {.lane = 0, .spawnTime = 57.403f},
        {.lane = 2, .spawnTime = 57.583f},
        {.lane = 4, .spawnTime = 57.963f},
        {.lane = 1, .spawnTime = 58.149f},
        {.lane = 3, .spawnTime = 58.336f},
        {.lane = 0, .spawnTime = 58.718f},
        {.lane = 2, .spawnTime = 58.907f},
        {.lane = 4, .spawnTime = 59.081f},
        {.lane = 1, .spawnTime = 59.458f},
        {.lane = 3, .spawnTime = 59.621f},
        {.lane = 0, .spawnTime = 59.818f},
        {.lane = 2, .spawnTime = 60.008f},
        {.lane = 4, .spawnTime = 60.388f},
        {.lane = 1, .spawnTime = 60.563f},
        {.lane = 3, .spawnTime = 60.939f},
        {.lane = 0, .spawnTime = 61.340f},
        {.lane = 2, .spawnTime = 61.722f},
        {.lane = 4, .spawnTime = 62.105f},
        {.lane = 1, .spawnTime = 62.433f},
        {.lane = 3, .spawnTime = 62.615f},
        {.lane = 0, .spawnTime = 62.802f},
        {.lane = 2, .spawnTime = 63.001f},
        {.lane = 4, .spawnTime = 63.422f},
        {.lane = 1, .spawnTime = 63.574f},
        {.lane = 3, .spawnTime = 63.947f},
        {.lane = 0, .spawnTime = 64.132f},
        {.lane = 2, .spawnTime = 64.321f},
        {.lane = 4, .spawnTime = 64.713f},
        {.lane = 1, .spawnTime = 64.888f},
        {.lane = 3, .spawnTime = 65.076f},
        {.lane = 0, .spawnTime = 65.426f},
        {.lane = 2, .spawnTime = 65.606f},
        {.lane = 4, .spawnTime = 65.774f},
        {.lane = 1, .spawnTime = 65.963f},
        {.lane = 3, .spawnTime = 66.481f},
        {.lane = 0, .spawnTime = 66.908f},
        {.lane = 2, .spawnTime = 67.319f},
        {.lane = 4, .spawnTime = 67.702f},
        {.lane = 1, .spawnTime = 68.038f},
        {.lane = 3, .spawnTime = 68.428f},
        {.lane = 0, .spawnTime = 68.600f},
        {.lane = 2, .spawnTime = 68.793f},
        {.lane = 4, .spawnTime = 68.976f},
        {.lane = 1, .spawnTime = 69.484f},
        {.lane = 3, .spawnTime = 69.649f},
        {.lane = 0, .spawnTime = 69.948f},
        {.lane = 2, .spawnTime = 70.313f},
        {.lane = 4, .spawnTime = 70.684f},
        {.lane = 1, .spawnTime = 71.029f},
        {.lane = 3, .spawnTime = 71.368f},
        {.lane = 0, .spawnTime = 71.548f},
        {.lane = 2, .spawnTime = 71.749f},
        {.lane = 4, .spawnTime = 71.937f},
        {.lane = 1, .spawnTime = 72.301f},
        {.lane = 3, .spawnTime = 72.476f},
        {.lane = 0, .spawnTime = 72.880f},
        {.lane = 2, .spawnTime = 73.042f},
        {.lane = 4, .spawnTime = 73.223f},
        {.lane = 1, .spawnTime = 73.626f},
        {.lane = 3, .spawnTime = 73.794f},
        {.lane = 0, .spawnTime = 73.983f},
        {.lane = 2, .spawnTime = 74.374f},
        {.lane = 4, .spawnTime = 74.553f},
        {.lane = 1, .spawnTime = 74.730f},
        {.lane = 3, .spawnTime = 74.901f},
        {.lane = 0, .spawnTime = 75.314f},
        {.lane = 2, .spawnTime = 75.495f},
        {.lane = 4, .spawnTime = 75.844f},
        {.lane = 1, .spawnTime = 76.022f},
        {.lane = 3, .spawnTime = 76.256f},
        {.lane = 0, .spawnTime = 76.654f},
        {.lane = 2, .spawnTime = 76.848f},
        {.lane = 4, .spawnTime = 77.049f},
        {.lane = 1, .spawnTime = 77.385f},
        {.lane = 3, .spawnTime = 77.571f},
        {.lane = 0, .spawnTime = 77.757f},
        {.lane = 2, .spawnTime = 77.951f},
        {.lane = 4, .spawnTime = 78.307f},
        {.lane = 1, .spawnTime = 78.502f},
        {.lane = 3, .spawnTime = 78.851f},
        {.lane = 0, .spawnTime = 79.045f},
        {.lane = 2, .spawnTime = 79.256f},
        {.lane = 4, .spawnTime = 79.649f},
        {.lane = 1, .spawnTime = 79.855f},
        {.lane = 3, .spawnTime = 80.064f},
        {.lane = 0, .spawnTime = 80.413f},
        {.lane = 2, .spawnTime = 80.589f},
        {.lane = 4, .spawnTime = 80.778f},
        {.lane = 1, .spawnTime = 80.983f},
        {.lane = 3, .spawnTime = 81.312f},
        {.lane = 0, .spawnTime = 81.495f},
        {.lane = 2, .spawnTime = 81.855f},
        {.lane = 4, .spawnTime = 82.034f},
        {.lane = 1, .spawnTime = 82.256f},
        {.lane = 3, .spawnTime = 82.639f},
        {.lane = 0, .spawnTime = 82.825f},
        {.lane = 2, .spawnTime = 83.038f},
        {.lane = 4, .spawnTime = 83.394f},
        {.lane = 1, .spawnTime = 83.572f},
        {.lane = 3, .spawnTime = 83.762f},
        {.lane = 0, .spawnTime = 83.958f},
        {.lane = 2, .spawnTime = 84.381f},
        {.lane = 4, .spawnTime = 84.563f},
        {.lane = 1, .spawnTime = 84.905f},
        {.lane = 3, .spawnTime = 85.078f},
        {.lane = 0, .spawnTime = 85.284f},
        {.lane = 2, .spawnTime = 85.659f},
        {.lane = 4, .spawnTime = 85.819f},
        {.lane = 1, .spawnTime = 86.024f},
        {.lane = 3, .spawnTime = 86.369f},
        {.lane = 0, .spawnTime = 86.541f},
        {.lane = 2, .spawnTime = 86.734f},
        {.lane = 4, .spawnTime = 86.922f},
        {.lane = 1, .spawnTime = 87.294f},
        {.lane = 3, .spawnTime = 87.483f},
        {.lane = 0, .spawnTime = 87.855f},
        {.lane = 2, .spawnTime = 88.038f},
        {.lane = 4, .spawnTime = 88.241f},
        {.lane = 1, .spawnTime = 88.642f},
        {.lane = 3, .spawnTime = 88.836f},
        {.lane = 0, .spawnTime = 89.039f},
        {.lane = 2, .spawnTime = 89.364f},
        {.lane = 4, .spawnTime = 89.529f},
        {.lane = 1, .spawnTime = 89.695f},
        {.lane = 3, .spawnTime = 89.902f},
        {.lane = 0, .spawnTime = 90.275f},
        {.lane = 2, .spawnTime = 90.472f},
        {.lane = 4, .spawnTime = 90.806f},
        {.lane = 1, .spawnTime = 90.980f},
        {.lane = 3, .spawnTime = 91.197f},
        {.lane = 0, .spawnTime = 91.575f},
        {.lane = 2, .spawnTime = 91.767f},
        {.lane = 4, .spawnTime = 91.964f},
        {.lane = 1, .spawnTime = 92.324f},
        {.lane = 3, .spawnTime = 92.508f},
        {.lane = 0, .spawnTime = 92.674f},
        {.lane = 2, .spawnTime = 92.853f},
        {.lane = 4, .spawnTime = 93.205f},
        {.lane = 1, .spawnTime = 93.384f},
        {.lane = 3, .spawnTime = 93.749f},
        {.lane = 0, .spawnTime = 93.914f},
        {.lane = 2, .spawnTime = 94.138f},
        {.lane = 4, .spawnTime = 94.575f},
        {.lane = 1, .spawnTime = 94.722f},
        {.lane = 3, .spawnTime = 94.913f},
        {.lane = 0, .spawnTime = 95.258f},
        {.lane = 2, .spawnTime = 95.395f},
        {.lane = 4, .spawnTime = 95.597f},
        {.lane = 1, .spawnTime = 95.799f},
        {.lane = -1, .spawnTime = 97.839790f}

};

Note Livin_Prayer[THUNDER_CHART_SIZE] = {
        // Main pattern (single notes)
        {.lane = 1, .spawnTime = 24.710f},  // s
        {.lane = 2, .spawnTime = 25.169f},  // j
        {.lane = 1, .spawnTime = 25.651f},  // s
        {.lane = 0, .spawnTime = 26.090f},  // a
        {.lane = 1, .spawnTime = 26.561f},  // s
        {.lane = 2, .spawnTime = 27.057f},  // j
        {.lane = 1, .spawnTime = 27.529f},  // s
        {.lane = 0, .spawnTime = 28.024f},  // a
        {.lane = 1, .spawnTime = 28.541f},  // s
        {.lane = 2, .spawnTime = 29.031f},  // j
        {.lane = 1, .spawnTime = 29.532f},  // s
        {.lane = 0, .spawnTime = 30.007f},  // a
        {.lane = 1, .spawnTime = 30.463f},  // s
        {.lane = 2, .spawnTime = 31.012f},  // j
        {.lane = 1, .spawnTime = 31.491f},  // s
        {.lane = 0, .spawnTime = 31.944f},  // a
        {.lane = 1, .spawnTime = 32.447f},  // s
        {.lane = 2, .spawnTime = 32.940f},  // j
        {.lane = 1, .spawnTime = 33.450f},  // s
        {.lane = 0, .spawnTime = 33.910f},  // a
        {.lane = 1, .spawnTime = 34.442f},  // s
        {.lane = 2, .spawnTime = 34.942f},  // j
        {.lane = 1, .spawnTime = 35.431f},  // s
        {.lane = 0, .spawnTime = 35.884f},  // a
        {.lane = 1, .spawnTime = 36.395f},  // s
        {.lane = 2, .spawnTime = 36.893f},  // j
        {.lane = 1, .spawnTime = 37.421f},  // s
        {.lane = 0, .spawnTime = 37.877f},  // a
        {.lane = 1, .spawnTime = 38.407f},  // s
        {.lane = 2, .spawnTime = 38.936f},  // j
        {.lane = 1, .spawnTime = 39.444f},  // s
        {.lane = 0, .spawnTime = 39.844f},  // a
        {.lane = 1, .spawnTime = 40.333f},  // s
        {.lane = 2, .spawnTime = 40.836f},  // j
        {.lane = 1, .spawnTime = 41.375f},  // s
        {.lane = 0, .spawnTime = 41.846f},  // a
        {.lane = 1, .spawnTime = 42.328f},  // s
        {.lane = 2, .spawnTime = 42.817f},  // j
        {.lane = 1, .spawnTime = 43.341f},  // s
        {.lane = 0, .spawnTime = 43.755f},  // a
        {.lane = 1, .spawnTime = 44.265f},  // s
        {.lane = 2, .spawnTime = 44.783f},  // j
        {.lane = 1, .spawnTime = 45.236f},  // s
        {.lane = 0, .spawnTime = 45.718f},  // a
        {.lane = 1, .spawnTime = 46.258f},  // s
        {.lane = 2, .spawnTime = 46.749f},  // j
        {.lane = 1, .spawnTime = 47.222f},  // s
        {.lane = 0, .spawnTime = 47.683f},  // a
        {.lane = 1, .spawnTime = 48.146f},  // s
        {.lane = 2, .spawnTime = 48.686f},  // j
        {.lane = 1, .spawnTime = 49.204f},  // s
        {.lane = 0, .spawnTime = 49.671f},  // a
        {.lane = 1, .spawnTime = 50.176f},  // s
        {.lane = 2, .spawnTime = 50.699f},  // j
        {.lane = 1, .spawnTime = 51.132f},  // s
        {.lane = 0, .spawnTime = 51.634f},  // a
        {.lane = 1, .spawnTime = 52.160f},  // s
        {.lane = 2, .spawnTime = 52.629f},  // j
        {.lane = 1, .spawnTime = 53.107f},  // s
        {.lane = 0, .spawnTime = 53.585f},  // a
        {.lane = 1, .spawnTime = 54.091f},  // s
        {.lane = 2, .spawnTime = 54.583f},  // j
        {.lane = 1, .spawnTime = 55.083f},  // s
        {.lane = 0, .spawnTime = 55.546f},  // a
        {.lane = 1, .spawnTime = 56.077f},  // s

        // Simultaneous notes (interval <0.15s)
        {.lane = 2, .spawnTime = 56.984f},  // j
        {.lane = 1, .spawnTime = 56.984f},  // s
        {.lane = 2, .spawnTime = 58.560f},  // j
        {.lane = 4, .spawnTime = 58.560f},  // k
        {.lane = 2, .spawnTime = 60.594f},  // j

        // Main pattern continues
        {.lane = 1, .spawnTime = 61.038f},  // s
        {.lane = 0, .spawnTime = 61.466f},  // a
        {.lane = 1, .spawnTime = 61.996f},  // s
        {.lane = 2, .spawnTime = 62.445f},  // j
        {.lane = 1, .spawnTime = 62.949f},  // s
        {.lane = 0, .spawnTime = 63.430f},  // a
        {.lane = 1, .spawnTime = 63.948f},  // s
        {.lane = 2, .spawnTime = 64.455f},  // j
        {.lane = 1, .spawnTime = 64.944f},  // s
        {.lane = 0, .spawnTime = 65.403f},  // a
        {.lane = 1, .spawnTime = 65.934f},  // s
        {.lane = 2, .spawnTime = 66.413f},  // j
        {.lane = 1, .spawnTime = 66.873f},  // s
        {.lane = 0, .spawnTime = 67.349f},  // a
        {.lane = 1, .spawnTime = 67.906f},  // s
        {.lane = 2, .spawnTime = 68.371f},  // j
        {.lane = 1, .spawnTime = 68.843f},  // s
        {.lane = 0, .spawnTime = 69.323f},  // a
        {.lane = 1, .spawnTime = 69.868f},  // s
        {.lane = 2, .spawnTime = 70.351f},  // j
        {.lane = 1, .spawnTime = 70.863f},  // s
        {.lane = 0, .spawnTime = 71.332f},  // a
        {.lane = 1, .spawnTime = 71.841f},  // s

        // More simultaneous notes
        {.lane = 1, .spawnTime = 72.340f},  // s
        {.lane = 2, .spawnTime = 72.340f},  // j
        {.lane = 2, .spawnTime = 74.389f},  // j
        {.lane = 4, .spawnTime = 74.389f},  // k
        {.lane = 2, .spawnTime = 76.330f},  // j

        // Main pattern continues
        {.lane = 1, .spawnTime = 76.813f},  // s
        {.lane = 0, .spawnTime = 77.307f},  // a
        {.lane = 1, .spawnTime = 77.789f},  // s
        {.lane = 2, .spawnTime = 78.263f},  // j
        {.lane = 1, .spawnTime = 78.725f},  // s
        {.lane = 0, .spawnTime = 79.236f},  // a
        {.lane = 1, .spawnTime = 79.752f},  // s
        {.lane = 0, .spawnTime = 80.179f},  // a

        // Rapid simultaneous notes
        {.lane = 1, .spawnTime = 80.195f},  // s
        {.lane = 1, .spawnTime = 80.997f},  // s
        {.lane = 2, .spawnTime = 80.997f},  // j
        {.lane = 2, .spawnTime = 82.205f},  // j
        {.lane = 1, .spawnTime = 82.205f},  // s
        {.lane = 1, .spawnTime = 82.682f},  // s
        {.lane = 2, .spawnTime = 82.682f},  // j
        {.lane = 2, .spawnTime = 83.148f},  // j
        {.lane = 4, .spawnTime = 83.148f},  // k

        // Mixed pattern
        {.lane = 0, .spawnTime = 84.119f},  // a
        {.lane = 1, .spawnTime = 84.119f},  // s
        {.lane = 1, .spawnTime = 84.893f},  // s
        {.lane = 2, .spawnTime = 84.893f},  // j
        {.lane = 1, .spawnTime = 86.137f},  // s
        {.lane = 2, .spawnTime = 86.137f},  // j
        {.lane = 2, .spawnTime = 86.634f},  // j
        {.lane = 1, .spawnTime = 86.634f},  // s
        {.lane = 2, .spawnTime = 87.118f},  // j
        {.lane = 4, .spawnTime = 87.118f},  // k
        {.lane = 1, .spawnTime = 88.076f},  // s
        {.lane = 0, .spawnTime = 88.076f},  // a
        {.lane = 2, .spawnTime = 88.834f},  // j
        {.lane = 1, .spawnTime = 88.834f},  // s
        {.lane = 1, .spawnTime = 90.045f},  // s
        {.lane = 2, .spawnTime = 90.045f},  // j
        {.lane = 1, .spawnTime = 90.482f},  // s
        {.lane = 2, .spawnTime = 90.482f},  // j
        {.lane = 2, .spawnTime = 90.991f},  // j
        {.lane = 4, .spawnTime = 90.991f},  // k
        {.lane = 2, .spawnTime = 91.499f},  // j
        {.lane = 1, .spawnTime = 91.956f},  // s
        {.lane = 2, .spawnTime = 91.956f},  // j
        {.lane = 2, .spawnTime = 93.978f},  // j
        {.lane = 4, .spawnTime = 93.978f},  // k
        {.lane = 4, .spawnTime = 94.604f},  // k
        {.lane = 2, .spawnTime = 94.604f},  // j
        {.lane = 4, .spawnTime = 94.853f},  // k
        {.lane = 2, .spawnTime = 94.853f},  // j
        {.lane = 2, .spawnTime = 95.407f},  // j
        {.lane = 1, .spawnTime = 95.875f},  // s
        {.lane = 0, .spawnTime = 95.875f},  // a
        {.lane = 2, .spawnTime = 96.598f},  // j
        {.lane = 1, .spawnTime = 96.598f},  // s
        {.lane = 4, .spawnTime = 97.911f},  // k
        {.lane = 2, .spawnTime = 97.911f},  // j
        {.lane = 0, .spawnTime = 99.803f},  // a
        {.lane = 2, .spawnTime = 99.803f},  // j
        {.lane = 2, .spawnTime = 100.492f}, // j
        {.lane = 1, .spawnTime = 100.492f}, // s
        {.lane = 2, .spawnTime = 101.774f}, // j
        {.lane = 4, .spawnTime = 101.774f}, // k
        {.lane = 0, .spawnTime = 103.687f}, // a
        {.lane = 1, .spawnTime = 103.687f}, // s
        {.lane = 2, .spawnTime = 104.385f}, // j
        {.lane = 1, .spawnTime = 104.385f}, // s
        {.lane = 2, .spawnTime = 105.620f}, // j
        {.lane = 4, .spawnTime = 105.620f}, // k
        {.lane = 2, .spawnTime = 107.554f}, // j
        {.lane = 0, .spawnTime = 107.554f}, // a
        {.lane = 1, .spawnTime = 108.283f}, // s
        {.lane = 2, .spawnTime = 108.283f}, // j
        {.lane = 4, .spawnTime = 109.495f}, // k
        {.lane = 2, .spawnTime = 109.495f}, // j
        {.lane = 2, .spawnTime = 111.403f}, // j
        {.lane = 1, .spawnTime = 111.916f}, // s
        {.lane = -1}  // Terminator
};

Note BringMeToLife[THUNDER_CHART_SIZE] = {
        // Initial pattern
        {.lane = 0, .spawnTime = 2.574f},  // a
        {.lane = 2, .spawnTime = 2.891f},  // j
        {.lane = 1, .spawnTime = 3.523f},  // s
        {.lane = 2, .spawnTime = 3.839f},  // j
        {.lane = 2, .spawnTime = 4.808f},  // j
        {.lane = 3, .spawnTime = 5.693f},  // k
        {.lane = 1, .spawnTime = 6.649f},  // s
        {.lane = 0, .spawnTime = 7.232f},  // a
        {.lane = 0, .spawnTime = 7.579f},  // a
        {.lane = 2, .spawnTime = 7.955f},  // j
        {.lane = 1, .spawnTime = 8.566f},  // s
        {.lane = 2, .spawnTime = 8.883f},  // j
        {.lane = 2, .spawnTime = 9.884f},  // j
        {.lane = 3, .spawnTime = 10.875f}, // k
        {.lane = 1, .spawnTime = 11.774f}, // s
        {.lane = 0, .spawnTime = 12.356f}, // a
        {.lane = 0, .spawnTime = 12.647f}, // a
        {.lane = 2, .spawnTime = 12.946f}, // j
        {.lane = 1, .spawnTime = 13.642f}, // s
        {.lane = 2, .spawnTime = 13.953f}, // j
        {.lane = 2, .spawnTime = 14.953f}, // j
        {.lane = 3, .spawnTime = 15.884f}, // k
        {.lane = 1, .spawnTime = 16.804f}, // s
        {.lane = 0, .spawnTime = 17.419f}, // a
        {.lane = 0, .spawnTime = 17.672f}, // a
        {.lane = 2, .spawnTime = 18.049f}, // j
        {.lane = 1, .spawnTime = 18.683f}, // s
        {.lane = 2, .spawnTime = 18.990f}, // j
        {.lane = 2, .spawnTime = 19.954f}, // j
        {.lane = 3, .spawnTime = 20.903f}, // k
        {.lane = 1, .spawnTime = 21.848f}, // s
        {.lane = 0, .spawnTime = 22.486f}, // a
        {.lane = 0, .spawnTime = 22.726f}, // a
        {.lane = 2, .spawnTime = 23.077f}, // j
        {.lane = 1, .spawnTime = 23.732f}, // s
        {.lane = 2, .spawnTime = 24.021f}, // j
        {.lane = 2, .spawnTime = 24.992f}, // j
        {.lane = 3, .spawnTime = 25.968f}, // k
        {.lane = 1, .spawnTime = 26.905f}, // s
        {.lane = 0, .spawnTime = 27.451f}, // a
        {.lane = 0, .spawnTime = 27.711f}, // a
        {.lane = 2, .spawnTime = 28.094f}, // j
        {.lane = 1, .spawnTime = 28.744f}, // s
        {.lane = 2, .spawnTime = 29.058f}, // j
        {.lane = 3, .spawnTime = 30.060f}, // k
        {.lane = 0, .spawnTime = 31.004f}, // a
        {.lane = 1, .spawnTime = 31.004f}, // s (simultaneous with a)

        // Rapid fire section (simultaneous notes)
        {.lane = 0, .spawnTime = 33.215f}, // a
        {.lane = 1, .spawnTime = 33.215f}, // s
        {.lane = 0, .spawnTime = 33.700f}, // a
        {.lane = 1, .spawnTime = 33.700f}, // s
        {.lane = 1, .spawnTime = 34.152f}, // s
        {.lane = 0, .spawnTime = 34.152f}, // a
        {.lane = 0, .spawnTime = 34.613f}, // a
        {.lane = 1, .spawnTime = 34.613f}, // s
        {.lane = 0, .spawnTime = 34.747f}, // a
        {.lane = 1, .spawnTime = 34.747f}, // s
        {.lane = 0, .spawnTime = 35.893f}, // a
        {.lane = 1, .spawnTime = 35.893f}, // s
        {.lane = 0, .spawnTime = 36.342f}, // a
        {.lane = 1, .spawnTime = 36.342f}, // s
        {.lane = 0, .spawnTime = 36.878f}, // a
        {.lane = 1, .spawnTime = 36.878f}, // s
        {.lane = 0, .spawnTime = 37.413f}, // a
        {.lane = 1, .spawnTime = 37.413f}, // s
        {.lane = 0, .spawnTime = 37.660f}, // a
        {.lane = 3, .spawnTime = 37.851f}, // k
        {.lane = 1, .spawnTime = 38.228f}, // s
        {.lane = 0, .spawnTime = 38.868f}, // a
        {.lane = 2, .spawnTime = 38.868f}, // j
        {.lane = 2, .spawnTime = 39.351f}, // j
        {.lane = 0, .spawnTime = 39.351f}, // a
        {.lane = 2, .spawnTime = 39.706f}, // j
        {.lane = 0, .spawnTime = 39.706f}, // a
        {.lane = 2, .spawnTime = 39.840f}, // j
        {.lane = 0, .spawnTime = 39.840f}, // a
        {.lane = 0, .spawnTime = 40.985f}, // a
        {.lane = 2, .spawnTime = 40.985f}, // j
        {.lane = 0, .spawnTime = 41.451f}, // a
        {.lane = 2, .spawnTime = 41.451f}, // j
        {.lane = 2, .spawnTime = 41.934f}, // j
        {.lane = 0, .spawnTime = 41.934f}, // a
        {.lane = 0, .spawnTime = 42.416f}, // a
        {.lane = 2, .spawnTime = 42.416f}, // j
        {.lane = 0, .spawnTime = 42.756f}, // a
        {.lane = 2, .spawnTime = 43.053f}, // j
        {.lane = 0, .spawnTime = 43.347f}, // a
        {.lane = 1, .spawnTime = 43.347f}, // s
        {.lane = 0, .spawnTime = 43.825f}, // a
        {.lane = 1, .spawnTime = 43.825f}, // s
        {.lane = 1, .spawnTime = 44.338f}, // s
        {.lane = 0, .spawnTime = 44.338f}, // a
        {.lane = 1, .spawnTime = 44.812f}, // s
        {.lane = 0, .spawnTime = 44.812f}, // a
        {.lane = 0, .spawnTime = 44.934f}, // a
        {.lane = 1, .spawnTime = 44.934f}, // s
        {.lane = 0, .spawnTime = 46.001f}, // a
        {.lane = 1, .spawnTime = 46.001f}, // s
        {.lane = 0, .spawnTime = 46.490f}, // a
        {.lane = 1, .spawnTime = 46.490f}, // s
        {.lane = 0, .spawnTime = 46.992f}, // a
        {.lane = 1, .spawnTime = 46.992f}, // s
        {.lane = 0, .spawnTime = 47.494f}, // a
        {.lane = 1, .spawnTime = 47.494f}, // s
        {.lane = 0, .spawnTime = 47.843f}, // a
        {.lane = 3, .spawnTime = 48.078f}, // k
        {.lane = 2, .spawnTime = 48.376f}, // j
        {.lane = 0, .spawnTime = 48.376f}, // a
        {.lane = 2, .spawnTime = 48.850f}, // j
        {.lane = 0, .spawnTime = 48.850f}, // a
        {.lane = 2, .spawnTime = 49.319f}, // j
        {.lane = 0, .spawnTime = 49.319f}, // a
        {.lane = 0, .spawnTime = 49.781f}, // a
        {.lane = 2, .spawnTime = 49.781f}, // j
        {.lane = 2, .spawnTime = 49.918f}, // j
        {.lane = 0, .spawnTime = 49.918f}, // a
        {.lane = 0, .spawnTime = 51.023f}, // a
        {.lane = 2, .spawnTime = 51.023f}, // j
        {.lane = 2, .spawnTime = 51.553f}, // j
        {.lane = 0, .spawnTime = 51.553f}, // a
        {.lane = 2, .spawnTime = 52.043f}, // j
        {.lane = 0, .spawnTime = 52.043f}, // a
        {.lane = 2, .spawnTime = 52.540f}, // j
        {.lane = 0, .spawnTime = 52.540f}, // a
        {.lane = 0, .spawnTime = 52.905f}, // a
        {.lane = 2, .spawnTime = 53.186f}, // j

        // Continuing pattern...
        {.lane = 0, .spawnTime = 54.722f}, // a
        {.lane = 1, .spawnTime = 54.722f}, // s
        {.lane = 0, .spawnTime = 55.264f}, // a
        {.lane = 1, .spawnTime = 55.264f}, // s
        {.lane = 0, .spawnTime = 55.795f}, // a
        {.lane = 1, .spawnTime = 55.795f}, // s
        {.lane = 1, .spawnTime = 56.279f}, // s
        {.lane = 0, .spawnTime = 56.279f}, // a
        {.lane = 1, .spawnTime = 56.668f}, // s
        {.lane = 0, .spawnTime = 56.668f}, // a
        {.lane = 0, .spawnTime = 56.975f}, // a
        {.lane = 1, .spawnTime = 56.975f}, // s
        {.lane = 2, .spawnTime = 57.328f}, // j
        {.lane = 1, .spawnTime = 57.328f}, // s
        {.lane = 1, .spawnTime = 57.953f}, // s
        {.lane = 2, .spawnTime = 57.953f}, // j
        {.lane = 2, .spawnTime = 58.441f}, // j
        {.lane = 1, .spawnTime = 58.441f}, // s
        {.lane = 2, .spawnTime = 58.880f}, // j
        {.lane = 1, .spawnTime = 58.880f}, // s
        {.lane = 2, .spawnTime = 59.205f}, // j
        {.lane = 1, .spawnTime = 59.205f}, // s
        {.lane = 0, .spawnTime = 59.473f}, // a
        {.lane = 3, .spawnTime = 59.820f}, // k
        {.lane = 3, .spawnTime = 60.427f}, // k
        {.lane = 3, .spawnTime = 60.945f}, // k
        {.lane = 3, .spawnTime = 61.399f}, // k
        {.lane = 3, .spawnTime = 61.703f}, // k
        {.lane = 0, .spawnTime = 61.996f}, // a
        {.lane = 1, .spawnTime = 62.354f}, // s
        {.lane = 2, .spawnTime = 63.001f}, // j
        {.lane = 0, .spawnTime = 63.596f}, // a
        {.lane = 2, .spawnTime = 64.262f}, // j
        {.lane = 1, .spawnTime = 64.920f}, // s
        {.lane = 0, .spawnTime = 64.920f}, // a

        // Continuing with the same pattern...
        {.lane = 0, .spawnTime = 65.446f}, // a
        {.lane = 1, .spawnTime = 65.446f}, // s
        {.lane = 0, .spawnTime = 65.962f}, // a
        {.lane = 1, .spawnTime = 65.962f}, // s
        {.lane = 0, .spawnTime = 66.473f}, // a
        {.lane = 1, .spawnTime = 66.473f}, // s
        {.lane = 0, .spawnTime = 66.844f}, // a
        {.lane = 1, .spawnTime = 66.844f}, // s
        {.lane = 0, .spawnTime = 67.121f}, // a
        {.lane = 1, .spawnTime = 67.121f}, // s
        {.lane = 2, .spawnTime = 67.446f}, // j
        {.lane = 1, .spawnTime = 67.446f}, // s
        {.lane = 2, .spawnTime = 67.999f}, // j
        {.lane = 1, .spawnTime = 67.999f}, // s
        {.lane = 2, .spawnTime = 68.494f}, // j
        {.lane = 1, .spawnTime = 68.494f}, // s
        {.lane = 1, .spawnTime = 68.953f}, // s
        {.lane = 2, .spawnTime = 68.953f}, // j
        {.lane = 1, .spawnTime = 69.301f}, // s
        {.lane = 2, .spawnTime = 69.301f}, // j
        {.lane = 0, .spawnTime = 69.646f}, // a
        {.lane = 3, .spawnTime = 69.899f}, // k
        {.lane = 3, .spawnTime = 70.495f}, // k
        {.lane = 3, .spawnTime = 70.950f}, // k
        {.lane = 3, .spawnTime = 71.414f}, // k
        {.lane = 3, .spawnTime = 71.750f}, // k
        {.lane = 0, .spawnTime = 71.993f}, // a
        {.lane = 0, .spawnTime = 72.398f}, // a
        {.lane = 1, .spawnTime = 72.398f}, // s
        {.lane = 0, .spawnTime = 73.031f}, // a
        {.lane = 1, .spawnTime = 73.031f}, // s
        {.lane = 0, .spawnTime = 73.658f}, // a
        {.lane = 1, .spawnTime = 73.658f}, // s
        {.lane = 0, .spawnTime = 74.051f}, // a
        {.lane = 1, .spawnTime = 74.051f}, // s
        {.lane = 2, .spawnTime = 74.350f}, // j
        {.lane = 0, .spawnTime = 74.857f}, // a
        {.lane = 1, .spawnTime = 74.857f}, // s
        {.lane = 0, .spawnTime = 75.375f}, // a
        {.lane = 1, .spawnTime = 75.375f}, // s
        {.lane = 0, .spawnTime = 75.897f}, // a
        {.lane = 1, .spawnTime = 75.897f}, // s
        {.lane = 0, .spawnTime = 76.361f}, // a
        {.lane = 1, .spawnTime = 76.361f}, // s
        {.lane = 1, .spawnTime = 76.511f}, // s
        {.lane = 0, .spawnTime = 76.511f}, // a
        {.lane = 0, .spawnTime = 76.831f}, // a
        {.lane = 2, .spawnTime = 77.118f}, // j
        {.lane = 0, .spawnTime = 77.437f}, // a
        {.lane = 1, .spawnTime = 77.437f}, // s
        {.lane = 0, .spawnTime = 77.927f}, // a
        {.lane = 1, .spawnTime = 77.927f}, // s
        {.lane = 1, .spawnTime = 78.425f}, // s
        {.lane = 0, .spawnTime = 78.425f}, // a
        {.lane = 0, .spawnTime = 78.893f}, // a
        {.lane = 1, .spawnTime = 78.893f}, // s
        {.lane = 1, .spawnTime = 79.324f}, // s
        {.lane = 0, .spawnTime = 79.324f}, // a
        {.lane = 0, .spawnTime = 79.653f}, // a
        {.lane = 0, .spawnTime = 79.792f}, // a
        {.lane = 0, .spawnTime = 80.056f}, // a
        {.lane = 1, .spawnTime = 80.056f}, // s
        {.lane = 0, .spawnTime = 80.629f}, // a
        {.lane = 1, .spawnTime = 80.629f}, // s
        {.lane = 0, .spawnTime = 81.139f}, // a
        {.lane = 1, .spawnTime = 81.139f}, // s
        {.lane = 0, .spawnTime = 81.588f}, // a
        {.lane = 1, .spawnTime = 81.588f}, // s
        {.lane = 0, .spawnTime = 81.961f}, // a
        {.lane = 3, .spawnTime = 82.235f}, // k
        {.lane = 2, .spawnTime = 82.531f}, // j
        {.lane = 0, .spawnTime = 82.531f}, // a
        {.lane = 2, .spawnTime = 82.994f}, // j
        {.lane = 0, .spawnTime = 82.994f}, // a
        {.lane = 0, .spawnTime = 83.475f}, // a
        {.lane = 2, .spawnTime = 83.475f}, // j
        {.lane = 2, .spawnTime = 83.985f}, // j
        {.lane = 0, .spawnTime = 83.985f}, // a
        {.lane = 0, .spawnTime = 84.441f}, // a
        {.lane = 2, .spawnTime = 84.441f}, // j
        {.lane = 0, .spawnTime = 84.742f}, // a
        {.lane = 0, .spawnTime = 84.859f}, // a
        {.lane = 2, .spawnTime = 85.136f}, // j
        {.lane = 0, .spawnTime = 85.136f}, // a
        {.lane = 0, .spawnTime = 85.642f}, // a
        {.lane = 2, .spawnTime = 85.642f}, // j
        {.lane = 2, .spawnTime = 86.117f}, // j
        {.lane = 0, .spawnTime = 86.117f}, // a
        {.lane = 2, .spawnTime = 86.621f}, // j
        {.lane = 0, .spawnTime = 86.621f}, // a
        {.lane = 0, .spawnTime = 87.017f}, // a
        {.lane = 2, .spawnTime = 87.275f}, // j
        {.lane = 0, .spawnTime = 87.551f}, // a
        {.lane = 1, .spawnTime = 87.551f}, // s
        {.lane = 0, .spawnTime = 88.020f}, // a
        {.lane = 1, .spawnTime = 88.020f}, // s
        {.lane = 0, .spawnTime = 88.525f}, // a
        {.lane = 1, .spawnTime = 88.525f}, // s
        {.lane = 0, .spawnTime = 88.981f}, // a
        {.lane = 1, .spawnTime = 88.981f}, // s
        {.lane = 0, .spawnTime = 89.419f}, // a
        {.lane = 1, .spawnTime = 89.419f}, // s
        {.lane = 0, .spawnTime = 89.707f}, // a
        {.lane = 0, .spawnTime = 89.832f}, // a
        {.lane = 0, .spawnTime = 90.227f}, // a
        {.lane = 1, .spawnTime = 90.227f}, // s
        {.lane = 0, .spawnTime = 90.706f}, // a
        {.lane = 1, .spawnTime = 90.706f}, // s
        {.lane = 0, .spawnTime = 91.192f}, // a
        {.lane = 1, .spawnTime = 91.192f}, // s
        {.lane = 0, .spawnTime = 91.662f}, // a
        {.lane = 1, .spawnTime = 91.662f}, // s
        {.lane = 0, .spawnTime = 92.036f}, // a
        {.lane = 3, .spawnTime = 92.212f}, // k
        {.lane = 0, .spawnTime = 92.530f}, // a
        {.lane = 2, .spawnTime = 92.530f}, // j
        {.lane = 0, .spawnTime = 93.027f}, // a
        {.lane = 2, .spawnTime = 93.027f}, // j
        {.lane = 0, .spawnTime = 93.528f}, // a
        {.lane = 2, .spawnTime = 93.528f}, // j
        {.lane = 0, .spawnTime = 94.022f}, // a
        {.lane = 2, .spawnTime = 94.022f}, // j
        {.lane = 0, .spawnTime = 94.498f}, // a
        {.lane = 2, .spawnTime = 94.498f}, // j
        {.lane = 0, .spawnTime = 94.865f}, // a
        {.lane = 0, .spawnTime = 95.007f}, // a
        {.lane = 2, .spawnTime = 95.283f}, // j
        {.lane = 0, .spawnTime = 95.283f}, // a
        {.lane = 2, .spawnTime = 95.755f}, // j
        {.lane = 0, .spawnTime = 95.755f}, // a
        {.lane = 0, .spawnTime = 96.240f}, // a
        {.lane = 2, .spawnTime = 96.240f}, // j
        {.lane = 0, .spawnTime = 96.723f}, // a
        {.lane = 2, .spawnTime = 96.723f}, // j
        {.lane = 0, .spawnTime = 97.053f}, // a
        {.lane = 2, .spawnTime = 97.327f}, // j

        // Final section
        {.lane = 0, .spawnTime = 100.201f}, // a
        {.lane = 1, .spawnTime = 100.201f}, // s
        {.lane = 0, .spawnTime = 100.767f}, // a
        {.lane = 1, .spawnTime = 100.767f}, // s
        {.lane = 0, .spawnTime = 101.291f}, // a
        {.lane = 1, .spawnTime = 101.291f}, // s
        {.lane = 0, .spawnTime = 101.742f}, // a
        {.lane = 1, .spawnTime = 101.742f}, // s
        {.lane = 0, .spawnTime = 102.150f}, // a
        {.lane = 1, .spawnTime = 102.150f}, // s
        {.lane = 0, .spawnTime = 102.411f}, // a
        {.lane = 1, .spawnTime = 102.411f}, // s
        {.lane = 2, .spawnTime = 102.805f}, // j
        {.lane = 1, .spawnTime = 102.805f}, // s
        {.lane = 2, .spawnTime = 103.353f}, // j
        {.lane = 1, .spawnTime = 103.353f}, // s
        {.lane = 2, .spawnTime = 103.860f}, // j
        {.lane = 1, .spawnTime = 103.860f}, // s
        {.lane = 2, .spawnTime = 104.285f}, // j
        {.lane = 1, .spawnTime = 104.285f}, // s
        {.lane = 1, .spawnTime = 104.645f}, // s
        {.lane = 2, .spawnTime = 104.645f}, // j
        {.lane = 0, .spawnTime = 104.986f}, // a
        {.lane = 3, .spawnTime = 105.236f}, // k
        {.lane = 3, .spawnTime = 105.857f}, // k
        {.lane = 3, .spawnTime = 106.396f}, // k
        {.lane = 3, .spawnTime = 106.842f}, // k
        {.lane = 3, .spawnTime = 107.168f}, // k
        {.lane = 0, .spawnTime = 107.332f}, // a
        {.lane = 0, .spawnTime = 107.866f}, // a
        {.lane = 1, .spawnTime = 107.866f}, // s
        {.lane = 2, .spawnTime = 108.479f}, // j
        {.lane = 0, .spawnTime = 109.059f}, // a
        {.lane = 1, .spawnTime = 109.059f}, // s
        {.lane = 0, .spawnTime = 109.356f}, // a
        {.lane = 1, .spawnTime = 109.356f}, // s
        {.lane = 2, .spawnTime = 109.705f}, // j
        {.lane = 1, .spawnTime = 109.994f}, // s
        {.lane = 0, .spawnTime = 110.372f}, // a
        {.lane = 1, .spawnTime = 110.372f}, // s
        {.lane = 0, .spawnTime = 110.893f}, // a
        {.lane = 1, .spawnTime = 110.893f}, // s
        {.lane = 0, .spawnTime = 111.417f}, // a
        {.lane = 1, .spawnTime = 111.417f}, // s
        {.lane = 0, .spawnTime = 111.875f}, // a
        {.lane = 1, .spawnTime = 111.875f}, // s
        {.lane = 0, .spawnTime = 112.249f}, // a
        {.lane = 1, .spawnTime = 112.249f}, // s
        {.lane = 0, .spawnTime = 112.513f}, // a
        {.lane = 1, .spawnTime = 112.513f}, // s
        {.lane = 2, .spawnTime = 112.852f}, // j
        {.lane = 1, .spawnTime = 112.852f}, // s
        {.lane = 2, .spawnTime = 113.414f}, // j
        {.lane = 1, .spawnTime = 113.414f}, // s
        {.lane = 1, .spawnTime = 113.929f}, // s
        {.lane = 2, .spawnTime = 113.929f}, // j
        {.lane = 2, .spawnTime = 114.373f}, // j
        {.lane = 1, .spawnTime = 114.373f}, // s
        {.lane = 1, .spawnTime = 114.696f}, // s
        {.lane = 2, .spawnTime = 114.696f}, // j
        {.lane = 0, .spawnTime = 114.934f}, // a
        {.lane = 3, .spawnTime = 115.419f}, // k
        {.lane = 3, .spawnTime = 115.971f}, // k
        {.lane = 3, .spawnTime = 116.407f}, // k
        {.lane = 3, .spawnTime = 116.871f}, // k
        {.lane = 3, .spawnTime = 117.278f}, // k
        {.lane = 0, .spawnTime = 117.551f}, // a
        {.lane = 0, .spawnTime = 117.907f}, // a
        {.lane = 1, .spawnTime = 117.907f}, // s
        {.lane = 0, .spawnTime = 118.528f}, // a
        {.lane = 1, .spawnTime = 118.528f}, // s
        {.lane = 0, .spawnTime = 119.098f}, // a
        {.lane = 0, .spawnTime = 119.577f}, // a
        {.lane = 0, .spawnTime = 119.814f}, // a
        {.lane = 0, .spawnTime = 120.110f}, // a
        {.lane = 2, .spawnTime = 120.414f}, // j
        {.lane = 1, .spawnTime = 121.095f}, // s
        {.lane = 2, .spawnTime = 121.095f}, // j
        {.lane = 0, .spawnTime = 122.242f}, // a
        {.lane = 0, .spawnTime = 122.366f}, // a
        {.lane = 3, .spawnTime = 122.934f}, // k
        {.lane = 2, .spawnTime = 122.934f}, // j
        {.lane = 2, .spawnTime = 123.590f}, // j
        {.lane = 3, .spawnTime = 123.590f}, // k
        {.lane = 0, .spawnTime = 124.789f}, // a
        {.lane = 0, .spawnTime = 124.927f}, // a
        {.lane = 0, .spawnTime = 125.501f}, // a
        {.lane = 0, .spawnTime = 125.981f}, // a
        {.lane = 0, .spawnTime = 126.438f}, // a
        {.lane = 0, .spawnTime = 126.929f}, // a
        {.lane = 0, .spawnTime = 127.387f}, // a
        {.lane = 0, .spawnTime = 127.724f}, // a
        {.lane = 0, .spawnTime = 127.844f}, // a
        {.lane = 0, .spawnTime = 128.072f}, // a
        {.lane = 0, .spawnTime = 128.550f}, // a
        {.lane = 0, .spawnTime = 129.043f}, // a
        {.lane = 0, .spawnTime = 129.543f}, // a
        {.lane = 0, .spawnTime = 129.953f}, // a
        {.lane = 3, .spawnTime = 130.191f}, // k
        {.lane = 2, .spawnTime = 130.550f}, // j
        {.lane = 1, .spawnTime = 130.550f}, // s
        {.lane = 2, .spawnTime = 131.177f}, // j
        {.lane = 0, .spawnTime = 132.429f}, // a
        {.lane = 0, .spawnTime = 132.569f}, // a
        {.lane = 2, .spawnTime = 133.134f}, // j
        {.lane = 3, .spawnTime = 133.134f}, // k
        {.lane = 2, .spawnTime = 133.751f}, // j
        {.lane = 3, .spawnTime = 133.751f}, // k
        {.lane = 0, .spawnTime = 134.928f}, // a
        {.lane = 0, .spawnTime = 135.069f}, // a
        {.lane = 0, .spawnTime = 135.563f}, // a
        {.lane = 0, .spawnTime = 136.112f}, // a
        {.lane = 0, .spawnTime = 136.596f}, // a
        {.lane = -1}
};

Note KillerQueen[THUNDER_CHART_SIZE] = {
        // Initial pattern
        {.lane = 1, .spawnTime = 7.803f},  // s
        {.lane = 0, .spawnTime = 8.168f},  // a
        {.lane = 0, .spawnTime = 11.571f}, // a
        {.lane = 4, .spawnTime = 12.441f}, // k
        {.lane = 4, .spawnTime = 12.989f}, // k
        {.lane = 2, .spawnTime = 13.490f}, // j
        {.lane = 2, .spawnTime = 14.021f}, // j
        {.lane = 1, .spawnTime = 14.502f}, // s
        {.lane = 1, .spawnTime = 15.080f}, // s
        {.lane = 0, .spawnTime = 15.570f}, // a
        {.lane = 0, .spawnTime = 16.115f}, // a
        {.lane = 2, .spawnTime = 16.629f}, // j
        {.lane = 2, .spawnTime = 17.196f}, // j
        {.lane = 1, .spawnTime = 17.680f}, // s
        {.lane = 1, .spawnTime = 18.258f}, // s
        {.lane = 1, .spawnTime = 18.749f}, // s
        {.lane = 1, .spawnTime = 19.331f}, // s
        {.lane = 2, .spawnTime = 21.350f}, // j
        {.lane = 0, .spawnTime = 21.887f}, // a
        {.lane = 4, .spawnTime = 22.398f}, // k
        {.lane = 2, .spawnTime = 22.801f}, // j
        {.lane = 2, .spawnTime = 23.315f}, // j
        {.lane = 4, .spawnTime = 23.461f}, // k
        {.lane = 0, .spawnTime = 24.004f}, // a
        {.lane = 2, .spawnTime = 24.516f}, // j
        {.lane = 1, .spawnTime = 25.076f}, // s
        {.lane = 2, .spawnTime = 25.393f}, // j
        {.lane = 4, .spawnTime = 25.549f}, // k
        {.lane = 2, .spawnTime = 26.076f}, // j
        {.lane = 2, .spawnTime = 26.581f}, // j
        {.lane = 1, .spawnTime = 27.083f}, // s
        {.lane = 0, .spawnTime = 27.608f}, // a
        {.lane = 1, .spawnTime = 28.128f}, // s
        {.lane = 2, .spawnTime = 28.128f}, // j (simultaneous with s)
        {.lane = 4, .spawnTime = 29.230f}, // k
        {.lane = 1, .spawnTime = 29.230f}, // s (simultaneous with k)

        // Rapid fire section (simultaneous notes)
        {.lane = 2, .spawnTime = 30.248f}, // j
        {.lane = 4, .spawnTime = 30.248f}, // k
        {.lane = 2, .spawnTime = 30.750f}, // j
        {.lane = 4, .spawnTime = 30.750f}, // k
        {.lane = 1, .spawnTime = 31.206f}, // s
        {.lane = 4, .spawnTime = 31.206f}, // k
        {.lane = 1, .spawnTime = 31.762f}, // s
        {.lane = 4, .spawnTime = 31.762f}, // k
        {.lane = 4, .spawnTime = 32.296f}, // k
        {.lane = 2, .spawnTime = 32.296f}, // j
        {.lane = 4, .spawnTime = 32.801f}, // k
        {.lane = 2, .spawnTime = 32.801f}, // j
        {.lane = 1, .spawnTime = 33.325f}, // s
        {.lane = 2, .spawnTime = 33.325f}, // j
        {.lane = 4, .spawnTime = 33.746f}, // k
        {.lane = 1, .spawnTime = 33.746f}, // s
        {.lane = 1, .spawnTime = 34.325f}, // s
        {.lane = 2, .spawnTime = 34.325f}, // j
        {.lane = 2, .spawnTime = 34.826f}, // j
        {.lane = 1, .spawnTime = 34.826f}, // s
        {.lane = 2, .spawnTime = 35.358f}, // j
        {.lane = 1, .spawnTime = 35.358f}, // s
        {.lane = 4, .spawnTime = 35.851f}, // k
        {.lane = 1, .spawnTime = 35.851f}, // s
        {.lane = 2, .spawnTime = 36.678f}, // j
        {.lane = 0, .spawnTime = 36.678f}, // a

        // Continuing pattern...
        {.lane = 1, .spawnTime = 38.339f}, // s
        {.lane = 4, .spawnTime = 38.827f}, // k
        {.lane = 2, .spawnTime = 39.328f}, // j
        {.lane = 4, .spawnTime = 39.859f}, // k
        {.lane = 0, .spawnTime = 40.385f}, // a
        {.lane = 2, .spawnTime = 40.875f}, // j
        {.lane = 1, .spawnTime = 41.371f}, // s
        {.lane = 2, .spawnTime = 41.924f}, // j
        {.lane = 2, .spawnTime = 42.434f}, // j
        {.lane = 1, .spawnTime = 42.434f}, // s
        {.lane = 0, .spawnTime = 42.691f}, // a
        {.lane = 2, .spawnTime = 42.691f}, // j
        {.lane = 1, .spawnTime = 44.123f}, // s
        {.lane = 0, .spawnTime = 44.467f}, // a
        {.lane = 2, .spawnTime = 45.968f}, // j
        {.lane = 2, .spawnTime = 46.406f}, // j
        {.lane = 1, .spawnTime = 47.509f}, // s
        {.lane = 2, .spawnTime = 47.763f}, // j
        {.lane = 4, .spawnTime = 47.867f}, // k
        {.lane = 2, .spawnTime = 50.062f}, // j
        {.lane = 2, .spawnTime = 50.405f}, // j
        {.lane = 0, .spawnTime = 56.651f}, // a
        {.lane = 4, .spawnTime = 59.680f}, // k
        {.lane = 2, .spawnTime = 60.077f}, // j
        {.lane = 1, .spawnTime = 60.390f}, // s
        {.lane = 4, .spawnTime = 62.805f}, // k
        {.lane = 4, .spawnTime = 63.294f}, // k
        {.lane = 2, .spawnTime = 63.794f}, // j
        {.lane = 2, .spawnTime = 64.339f}, // j
        {.lane = 1, .spawnTime = 64.826f}, // s
        {.lane = 1, .spawnTime = 65.407f}, // s
        {.lane = 0, .spawnTime = 65.877f}, // a
        {.lane = 0, .spawnTime = 66.403f}, // a
        {.lane = 0, .spawnTime = 66.894f}, // a
        {.lane = 0, .spawnTime = 67.439f}, // a
        {.lane = 0, .spawnTime = 70.011f}, // a
        {.lane = 2, .spawnTime = 70.509f}, // j
        {.lane = 1, .spawnTime = 71.081f}, // s
        {.lane = 2, .spawnTime = 71.556f}, // j
        {.lane = 1, .spawnTime = 72.057f}, // s
        {.lane = 4, .spawnTime = 72.538f}, // k
        {.lane = 2, .spawnTime = 73.052f}, // j
        {.lane = 4, .spawnTime = 73.601f}, // k
        {.lane = 4, .spawnTime = 74.094f}, // k
        {.lane = 2, .spawnTime = 74.608f}, // j
        {.lane = 1, .spawnTime = 74.948f}, // s
        {.lane = 0, .spawnTime = 75.132f}, // a
        {.lane = 1, .spawnTime = 75.607f}, // s
        {.lane = 2, .spawnTime = 75.607f}, // j
        {.lane = 4, .spawnTime = 76.155f}, // k
        {.lane = 1, .spawnTime = 76.155f}, // s
        {.lane = 4, .spawnTime = 77.237f}, // k
        {.lane = 2, .spawnTime = 77.237f}, // j
        {.lane = 2, .spawnTime = 78.238f}, // j
        {.lane = 4, .spawnTime = 78.238f}, // k
        {.lane = 2, .spawnTime = 78.712f}, // j
        {.lane = 4, .spawnTime = 78.712f}, // k
        {.lane = 1, .spawnTime = 79.176f}, // s
        {.lane = 4, .spawnTime = 79.176f}, // k
        {.lane = 1, .spawnTime = 79.707f}, // s
        {.lane = 4, .spawnTime = 79.707f}, // k
        {.lane = 4, .spawnTime = 80.245f}, // k
        {.lane = 2, .spawnTime = 80.245f}, // j
        {.lane = 2, .spawnTime = 80.752f}, // j
        {.lane = 4, .spawnTime = 80.752f}, // k
        {.lane = 2, .spawnTime = 81.319f}, // j
        {.lane = 4, .spawnTime = 81.635f}, // k
        {.lane = 2, .spawnTime = 82.273f}, // j
        {.lane = 1, .spawnTime = 82.273f}, // s
        {.lane = 4, .spawnTime = 82.749f}, // k
        {.lane = 1, .spawnTime = 82.749f}, // s
        {.lane = 4, .spawnTime = 83.281f}, // k
        {.lane = 2, .spawnTime = 83.281f}, // j
        {.lane = 2, .spawnTime = 83.782f}, // j
        {.lane = 2, .spawnTime = 84.617f}, // j
        {.lane = 0, .spawnTime = 84.617f}, // a
        {.lane = 1, .spawnTime = 85.543f}, // s
        {.lane = 2, .spawnTime = 86.260f}, // j
        {.lane = 2, .spawnTime = 86.566f}, // j
        {.lane = 2, .spawnTime = 87.075f}, // j
        {.lane = 0, .spawnTime = 87.595f}, // a
        {.lane = 4, .spawnTime = 88.264f}, // k
        {.lane = 2, .spawnTime = 88.839f}, // j
        {.lane = 2, .spawnTime = 89.175f}, // j
        {.lane = 1, .spawnTime = 89.283f}, // s
        {.lane = 0, .spawnTime = 89.610f}, // a
        {.lane = 0, .spawnTime = 89.829f}, // a
        {.lane = 1, .spawnTime = 90.331f}, // s
        {.lane = 1, .spawnTime = 90.901f}, // s
        {.lane = 2, .spawnTime = 91.182f}, // j
        {.lane = 1, .spawnTime = 91.315f}, // s
        {.lane = 0, .spawnTime = 91.749f}, // a
        {.lane = 4, .spawnTime = 92.370f}, // k
        {.lane = 1, .spawnTime = 92.763f}, // s
        {.lane = 2, .spawnTime = 92.915f}, // j
        {.lane = 1, .spawnTime = 93.268f}, // s
        {.lane = 1, .spawnTime = 93.413f}, // s
        {.lane = 0, .spawnTime = 93.893f}, // a
        {.lane = 0, .spawnTime = 94.344f}, // a
        {.lane = 2, .spawnTime = 94.974f}, // j
        {.lane = 2, .spawnTime = 95.308f}, // j
        {.lane = 0, .spawnTime = 95.974f}, // a
        {.lane = 0, .spawnTime = 96.335f}, // a
        {.lane = 2, .spawnTime = 97.033f}, // j
        {.lane = 2, .spawnTime = 97.419f}, // j
        {.lane = 0, .spawnTime = 98.100f}, // a
        {.lane = 0, .spawnTime = 98.405f}, // a
        {.lane = 1, .spawnTime = 98.511f}, // s
        {.lane = 2, .spawnTime = 99.060f}, // j
        {.lane = 1, .spawnTime = 99.060f}, // s
        {.lane = 2, .spawnTime = 99.542f}, // j
        {.lane = 4, .spawnTime = 99.551f}, // k
        {.lane = 4, .spawnTime = 99.943f}, // k
        {.lane = 2, .spawnTime = 100.539f}, // j
        {.lane = 2, .spawnTime = 101.152f}, // j
        {.lane = 1, .spawnTime = 101.542f}, // s
        {.lane = 2, .spawnTime = 101.736f}, // j
        {.lane = 0, .spawnTime = 102.068f}, // a
        {.lane = 0, .spawnTime = 102.206f}, // a
        {.lane = 4, .spawnTime = 102.761f}, // k
        {.lane = 4, .spawnTime = 103.126f}, // k
        {.lane = 2, .spawnTime = 103.297f}, // j
        {.lane = 1, .spawnTime = 103.844f}, // s
        {.lane = 0, .spawnTime = 104.734f}, // a
        {.lane = 2, .spawnTime = 104.881f}, // j
        {.lane = 2, .spawnTime = 105.398f}, // j
        {.lane = 2, .spawnTime = 105.901f}, // j
        {.lane = 0, .spawnTime = 106.301f}, // a
        {.lane = 4, .spawnTime = 106.886f}, // k
        {.lane = 4, .spawnTime = 107.239f}, // k
        {.lane = 0, .spawnTime = 107.405f}, // a
        {.lane = 1, .spawnTime = 107.951f}, // s
        {.lane = 2, .spawnTime = 108.305f}, // j
        {.lane = 4, .spawnTime = 108.642f}, // k
        {.lane = 4, .spawnTime = 108.973f}, // k
        {.lane = 2, .spawnTime = 110.014f}, // j
        {.lane = 1, .spawnTime = 111.053f}, // s
        {.lane = 2, .spawnTime = 111.511f}, // j
        {.lane = 4, .spawnTime = 111.887f}, // k
        {.lane = 4, .spawnTime = 112.025f}, // k
        {.lane = 4, .spawnTime = 112.343f}, // k
        {.lane = 1, .spawnTime = 113.079f}, // s
        {.lane = 2, .spawnTime = 113.565f}, // j
        {.lane = 1, .spawnTime = 113.921f}, // s
        {.lane = 0, .spawnTime = 114.077f}, // a
        {.lane = 0, .spawnTime = 114.627f}, // a
        {.lane = 1, .spawnTime = 114.989f}, // s
        {.lane = 2, .spawnTime = 115.156f}, // j
        {.lane = 2, .spawnTime = 115.665f}, // j
        {.lane = 1, .spawnTime = 115.946f}, // s
        {.lane = 2, .spawnTime = 115.946f}, // j
        {.lane = 1, .spawnTime = 118.014f}, // s
        {.lane = 2, .spawnTime = 118.014f}, // j
        {.lane = 2, .spawnTime = 118.473f}, // j
        {.lane = 1, .spawnTime = 118.628f}, // s
        {.lane = 2, .spawnTime = 118.628f}, // j
        {.lane = -1}  // Terminator
};