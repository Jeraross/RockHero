//
// Created by jerin on 11/05/2025.
//

#include "chart.h"

Note Thunder[CHART_SIZE] = {
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

Note SweetChildOMine[CHART_SIZE] = {
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

Note TheTrooper[CHART_SIZE] = {
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

Note Livin_Prayer[CHART_SIZE] = {
        // Main pattern (single notes)
        {.lane = 1, .spawnTime = 7.430f},  // s
        {.lane = 2, .spawnTime = 7.889f},  // j
        {.lane = 1, .spawnTime = 8.371f},  // s
        {.lane = 0, .spawnTime = 8.810f},  // a
        {.lane = 1, .spawnTime = 9.281f},  // s
        {.lane = 2, .spawnTime = 9.777f},  // j
        {.lane = 1, .spawnTime = 10.249f}, // s
        {.lane = 0, .spawnTime = 10.744f}, // a
        {.lane = 1, .spawnTime = 11.261f}, // s
        {.lane = 2, .spawnTime = 11.751f}, // j
        {.lane = 1, .spawnTime = 12.252f}, // s
        {.lane = 0, .spawnTime = 12.727f}, // a
        {.lane = 1, .spawnTime = 13.183f}, // s
        {.lane = 2, .spawnTime = 13.732f}, // j
        {.lane = 1, .spawnTime = 14.211f}, // s
        {.lane = 0, .spawnTime = 14.664f}, // a
        {.lane = 1, .spawnTime = 15.167f}, // s
        {.lane = 2, .spawnTime = 15.660f}, // j
        {.lane = 1, .spawnTime = 16.170f}, // s
        {.lane = 0, .spawnTime = 16.630f}, // a
        {.lane = 1, .spawnTime = 17.162f}, // s
        {.lane = 2, .spawnTime = 17.662f}, // j
        {.lane = 1, .spawnTime = 18.151f}, // s
        {.lane = 0, .spawnTime = 18.604f}, // a
        {.lane = 1, .spawnTime = 19.115f}, // s
        {.lane = 2, .spawnTime = 19.613f}, // j
        {.lane = 1, .spawnTime = 20.141f}, // s
        {.lane = 0, .spawnTime = 20.597f}, // a
        {.lane = 1, .spawnTime = 21.127f}, // s
        {.lane = 2, .spawnTime = 21.656f}, // j
        {.lane = 1, .spawnTime = 22.164f}, // s
        {.lane = 0, .spawnTime = 22.564f}, // a
        {.lane = 1, .spawnTime = 23.053f}, // s
        {.lane = 2, .spawnTime = 23.556f}, // j
        {.lane = 1, .spawnTime = 24.095f}, // s
        {.lane = 0, .spawnTime = 24.566f}, // a
        {.lane = 1, .spawnTime = 25.048f}, // s
        {.lane = 2, .spawnTime = 25.537f}, // j
        {.lane = 1, .spawnTime = 26.061f}, // s
        {.lane = 0, .spawnTime = 26.475f}, // a
        {.lane = 1, .spawnTime = 26.985f}, // s
        {.lane = 2, .spawnTime = 27.503f}, // j
        {.lane = 1, .spawnTime = 27.956f}, // s
        {.lane = 0, .spawnTime = 28.438f}, // a
        {.lane = 1, .spawnTime = 28.978f}, // s
        {.lane = 2, .spawnTime = 29.469f}, // j
        {.lane = 1, .spawnTime = 29.942f}, // s
        {.lane = 0, .spawnTime = 30.403f}, // a
        {.lane = 1, .spawnTime = 30.866f}, // s
        {.lane = 2, .spawnTime = 31.406f}, // j
        {.lane = 1, .spawnTime = 31.924f}, // s
        {.lane = 0, .spawnTime = 32.391f}, // a
        {.lane = 1, .spawnTime = 32.896f}, // s
        {.lane = 2, .spawnTime = 33.419f}, // j
        {.lane = 1, .spawnTime = 33.852f}, // s
        {.lane = 0, .spawnTime = 34.354f}, // a
        {.lane = 1, .spawnTime = 34.880f}, // s
        {.lane = 2, .spawnTime = 35.349f}, // j
        {.lane = 1, .spawnTime = 35.827f}, // s
        {.lane = 0, .spawnTime = 36.305f}, // a
        {.lane = 1, .spawnTime = 36.811f}, // s
        {.lane = 2, .spawnTime = 37.303f}, // j
        {.lane = 1, .spawnTime = 37.803f}, // s
        {.lane = 0, .spawnTime = 38.266f}, // a
        {.lane = 1, .spawnTime = 38.797f}, // s

        // Simultaneous notes (interval <0.15s)
        {.lane = 2, .spawnTime = 39.704f}, // j
        {.lane = 1, .spawnTime = 39.704f}, // s
        {.lane = 2, .spawnTime = 41.280f}, // j
        {.lane = 4, .spawnTime = 41.280f}, // k
        {.lane = 2, .spawnTime = 43.314f}, // j

        // Main pattern continues
        {.lane = 1, .spawnTime = 43.758f}, // s
        {.lane = 0, .spawnTime = 44.186f}, // a
        {.lane = 1, .spawnTime = 44.716f}, // s
        {.lane = 2, .spawnTime = 45.165f}, // j
        {.lane = 1, .spawnTime = 45.669f}, // s
        {.lane = 0, .spawnTime = 46.150f}, // a
        {.lane = 1, .spawnTime = 46.668f}, // s
        {.lane = 2, .spawnTime = 47.175f}, // j
        {.lane = 1, .spawnTime = 47.664f}, // s
        {.lane = 0, .spawnTime = 48.123f}, // a
        {.lane = 1, .spawnTime = 48.654f}, // s
        {.lane = 2, .spawnTime = 49.133f}, // j
        {.lane = 1, .spawnTime = 49.593f}, // s
        {.lane = 0, .spawnTime = 50.069f}, // a
        {.lane = 1, .spawnTime = 50.626f}, // s
        {.lane = 2, .spawnTime = 51.091f}, // j
        {.lane = 1, .spawnTime = 51.563f}, // s
        {.lane = 0, .spawnTime = 52.043f}, // a
        {.lane = 1, .spawnTime = 52.588f}, // s
        {.lane = 2, .spawnTime = 53.071f}, // j
        {.lane = 1, .spawnTime = 53.583f}, // s
        {.lane = 0, .spawnTime = 54.052f}, // a
        {.lane = 1, .spawnTime = 54.561f}, // s

        // More simultaneous notes
        {.lane = 1, .spawnTime = 55.060f}, // s
        {.lane = 2, .spawnTime = 55.060f}, // j
        {.lane = 2, .spawnTime = 57.109f}, // j
        {.lane = 4, .spawnTime = 57.109f}, // k
        {.lane = 2, .spawnTime = 59.050f}, // j

        // Main pattern continues
        {.lane = 1, .spawnTime = 59.533f}, // s
        {.lane = 0, .spawnTime = 60.027f}, // a
        {.lane = 1, .spawnTime = 60.509f}, // s
        {.lane = 2, .spawnTime = 60.983f}, // j
        {.lane = 1, .spawnTime = 61.445f}, // s
        {.lane = 0, .spawnTime = 61.956f}, // a
        {.lane = 1, .spawnTime = 62.472f}, // s
        {.lane = 0, .spawnTime = 62.915f}, // a

        // Rapid simultaneous notes
        {.lane = 1, .spawnTime = 62.915f}, // s
        {.lane = 1, .spawnTime = 63.717f}, // s
        {.lane = 2, .spawnTime = 63.717f}, // j
        {.lane = 2, .spawnTime = 64.925f}, // j
        {.lane = 1, .spawnTime = 64.925f}, // s
        {.lane = 1, .spawnTime = 65.402f}, // s
        {.lane = 2, .spawnTime = 65.402f}, // j
        {.lane = 2, .spawnTime = 65.868f}, // j
        {.lane = 4, .spawnTime = 65.868f}, // k

        // Mixed pattern
        {.lane = 0, .spawnTime = 66.839f}, // a
        {.lane = 1, .spawnTime = 66.839f}, // s
        {.lane = 1, .spawnTime = 67.613f}, // s
        {.lane = 2, .spawnTime = 67.613f}, // j
        {.lane = 1, .spawnTime = 68.857f}, // s
        {.lane = 2, .spawnTime = 68.857f}, // j
        {.lane = 2, .spawnTime = 69.354f}, // j
        {.lane = 1, .spawnTime = 69.354f}, // s
        {.lane = 2, .spawnTime = 69.838f}, // j
        {.lane = 4, .spawnTime = 69.838f}, // k
        {.lane = 1, .spawnTime = 70.796f}, // s
        {.lane = 0, .spawnTime = 70.796f}, // a
        {.lane = 2, .spawnTime = 71.554f}, // j
        {.lane = 1, .spawnTime = 71.554f}, // s
        {.lane = 1, .spawnTime = 72.765f}, // s
        {.lane = 2, .spawnTime = 72.765f}, // j
        {.lane = 1, .spawnTime = 73.202f}, // s
        {.lane = 2, .spawnTime = 73.202f}, // j
        {.lane = 2, .spawnTime = 73.711f}, // j
        {.lane = 4, .spawnTime = 73.711f}, // k
        {.lane = 2, .spawnTime = 74.219f}, // j
        {.lane = 1, .spawnTime = 74.676f}, // s
        {.lane = 2, .spawnTime = 74.676f}, // j
        {.lane = 2, .spawnTime = 76.698f}, // j
        {.lane = 4, .spawnTime = 76.698f}, // k
        {.lane = 4, .spawnTime = 77.324f}, // k
        {.lane = 2, .spawnTime = 77.324f}, // j
        {.lane = 4, .spawnTime = 77.573f}, // k
        {.lane = 2, .spawnTime = 77.573f}, // j
        {.lane = 2, .spawnTime = 78.127f}, // j
        {.lane = 1, .spawnTime = 78.595f}, // s
        {.lane = 0, .spawnTime = 78.595f}, // a
        {.lane = 2, .spawnTime = 79.318f}, // j
        {.lane = 1, .spawnTime = 79.318f}, // s
        {.lane = 4, .spawnTime = 80.631f}, // k
        {.lane = 2, .spawnTime = 80.631f}, // j
        {.lane = 0, .spawnTime = 82.523f}, // a
        {.lane = 2, .spawnTime = 82.523f}, // j
        {.lane = 2, .spawnTime = 83.212f}, // j
        {.lane = 1, .spawnTime = 83.212f}, // s
        {.lane = 2, .spawnTime = 84.494f}, // j
        {.lane = 4, .spawnTime = 84.494f}, // k
        {.lane = 0, .spawnTime = 86.407f}, // a
        {.lane = 1, .spawnTime = 86.407f}, // s
        {.lane = 2, .spawnTime = 87.105f}, // j
        {.lane = 1, .spawnTime = 87.105f}, // s
        {.lane = 2, .spawnTime = 88.340f}, // j
        {.lane = 4, .spawnTime = 88.340f}, // k
        {.lane = 2, .spawnTime = 90.274f}, // j
        {.lane = 0, .spawnTime = 90.274f}, // a
        {.lane = 1, .spawnTime = 91.003f}, // s
        {.lane = 2, .spawnTime = 91.003f}, // j
        {.lane = 4, .spawnTime = 92.215f}, // k
        {.lane = 2, .spawnTime = 92.215f}, // j
        {.lane = 2, .spawnTime = 94.123f}, // j
        {.lane = -1}  // Terminator
};

Note BringMeToLife[CHART_SIZE] = {
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
Note KillerQueen[CHART_SIZE] = {
        // Initial pattern (adjusted times)
        {.lane = 1, .spawnTime = 3.223f},  // s (7.803 - 4.58)
        {.lane = 0, .spawnTime = 3.588f},  // a
        {.lane = 0, .spawnTime = 6.991f},  // a
        {.lane = 3, .spawnTime = 7.861f},  // k
        {.lane = 3, .spawnTime = 8.409f},  // k
        {.lane = 2, .spawnTime = 8.910f},  // j
        {.lane = 2, .spawnTime = 9.441f},  // j
        {.lane = 1, .spawnTime = 9.922f},  // s
        {.lane = 1, .spawnTime = 10.500f}, // s
        {.lane = 0, .spawnTime = 10.990f}, // a
        {.lane = 0, .spawnTime = 11.535f}, // a
        {.lane = 2, .spawnTime = 12.049f}, // j
        {.lane = 2, .spawnTime = 12.616f}, // j
        {.lane = 1, .spawnTime = 13.100f}, // s
        {.lane = 1, .spawnTime = 13.678f}, // s
        {.lane = 1, .spawnTime = 14.169f}, // s
        {.lane = 1, .spawnTime = 14.751f}, // s
        {.lane = 2, .spawnTime = 16.770f}, // j
        {.lane = 0, .spawnTime = 17.307f}, // a
        {.lane = 3, .spawnTime = 17.818f}, // k
        {.lane = 2, .spawnTime = 18.221f}, // j
        {.lane = 2, .spawnTime = 18.735f}, // j
        {.lane = 3, .spawnTime = 18.881f}, // k
        {.lane = 0, .spawnTime = 19.424f}, // a
        {.lane = 2, .spawnTime = 19.936f}, // j
        {.lane = 1, .spawnTime = 20.496f}, // s
        {.lane = 2, .spawnTime = 20.813f}, // j
        {.lane = 3, .spawnTime = 20.969f}, // k
        {.lane = 2, .spawnTime = 21.496f}, // j
        {.lane = 2, .spawnTime = 22.001f}, // j
        {.lane = 1, .spawnTime = 22.503f}, // s
        {.lane = 0, .spawnTime = 23.028f}, // a
        {.lane = 1, .spawnTime = 23.548f}, // s
        {.lane = 2, .spawnTime = 23.548f}, // j (simultaneous)
        {.lane = 3, .spawnTime = 24.650f}, // k
        {.lane = 1, .spawnTime = 24.650f}, // s (simultaneous)

        // Rapid fire section (simultaneous notes)
        {.lane = 2, .spawnTime = 25.668f}, // j
        {.lane = 3, .spawnTime = 25.668f}, // k
        {.lane = 2, .spawnTime = 26.170f}, // j
        {.lane = 3, .spawnTime = 26.170f}, // k
        {.lane = 1, .spawnTime = 26.626f}, // s
        {.lane = 3, .spawnTime = 26.626f}, // k
        {.lane = 1, .spawnTime = 27.182f}, // s
        {.lane = 3, .spawnTime = 27.182f}, // k
        {.lane = 3, .spawnTime = 27.716f}, // k
        {.lane = 2, .spawnTime = 27.716f}, // j
        {.lane = 3, .spawnTime = 28.221f}, // k
        {.lane = 2, .spawnTime = 28.221f}, // j
        {.lane = 1, .spawnTime = 28.745f}, // s
        {.lane = 2, .spawnTime = 28.745f}, // j
        {.lane = 3, .spawnTime = 29.166f}, // k
        {.lane = 1, .spawnTime = 29.166f}, // s
        {.lane = 1, .spawnTime = 29.745f}, // s
        {.lane = 2, .spawnTime = 29.745f}, // j
        {.lane = 2, .spawnTime = 30.246f}, // j
        {.lane = 1, .spawnTime = 30.246f}, // s
        {.lane = 2, .spawnTime = 30.778f}, // j
        {.lane = 1, .spawnTime = 30.778f}, // s
        {.lane = 3, .spawnTime = 31.271f}, // k
        {.lane = 1, .spawnTime = 31.271f}, // s
        {.lane = 2, .spawnTime = 32.098f}, // j
        {.lane = 0, .spawnTime = 32.098f}, // a

        // Continuing pattern...
        {.lane = 1, .spawnTime = 33.759f}, // s
        {.lane = 3, .spawnTime = 34.247f}, // k
        {.lane = 2, .spawnTime = 34.748f}, // j
        {.lane = 3, .spawnTime = 35.279f}, // k
        {.lane = 0, .spawnTime = 35.805f}, // a
        {.lane = 2, .spawnTime = 36.295f}, // j
        {.lane = 1, .spawnTime = 36.791f}, // s
        {.lane = 2, .spawnTime = 37.344f}, // j
        {.lane = 2, .spawnTime = 37.854f}, // j
        {.lane = 1, .spawnTime = 37.854f}, // s
        {.lane = 0, .spawnTime = 38.111f}, // a
        {.lane = 2, .spawnTime = 38.111f}, // j
        {.lane = 1, .spawnTime = 39.543f}, // s
        {.lane = 0, .spawnTime = 39.887f}, // a
        {.lane = 2, .spawnTime = 41.388f}, // j
        {.lane = 2, .spawnTime = 41.826f}, // j
        {.lane = 1, .spawnTime = 42.929f}, // s
        {.lane = 2, .spawnTime = 43.183f}, // j
        {.lane = 3, .spawnTime = 43.287f}, // k
        {.lane = 2, .spawnTime = 45.482f}, // j
        {.lane = 2, .spawnTime = 45.825f}, // j
        {.lane = 0, .spawnTime = 52.071f}, // a
        {.lane = 3, .spawnTime = 55.100f}, // k
        {.lane = 2, .spawnTime = 55.497f}, // j
        {.lane = 1, .spawnTime = 55.810f}, // s
        {.lane = 3, .spawnTime = 58.225f}, // k
        {.lane = 3, .spawnTime = 58.714f}, // k
        {.lane = 2, .spawnTime = 59.214f}, // j
        {.lane = 2, .spawnTime = 59.759f}, // j
        {.lane = 1, .spawnTime = 60.246f}, // s
        {.lane = 1, .spawnTime = 60.827f}, // s
        {.lane = 0, .spawnTime = 61.297f}, // a
        {.lane = 0, .spawnTime = 61.823f}, // a
        {.lane = 0, .spawnTime = 62.314f}, // a
        {.lane = 0, .spawnTime = 62.859f}, // a
        {.lane = 0, .spawnTime = 65.431f}, // a
        {.lane = 2, .spawnTime = 65.929f}, // j
        {.lane = 1, .spawnTime = 66.501f}, // s
        {.lane = 2, .spawnTime = 66.976f}, // j
        {.lane = 1, .spawnTime = 67.477f}, // s
        {.lane = 3, .spawnTime = 67.958f}, // k
        {.lane = 2, .spawnTime = 68.472f}, // j
        {.lane = 3, .spawnTime = 69.021f}, // k
        {.lane = 3, .spawnTime = 69.514f}, // k
        {.lane = 2, .spawnTime = 70.028f}, // j
        {.lane = 1, .spawnTime = 70.368f}, // s
        {.lane = 0, .spawnTime = 70.552f}, // a
        {.lane = 1, .spawnTime = 71.027f}, // s
        {.lane = 2, .spawnTime = 71.027f}, // j
        {.lane = 3, .spawnTime = 71.575f}, // k
        {.lane = 1, .spawnTime = 71.575f}, // s
        {.lane = 3, .spawnTime = 72.657f}, // k
        {.lane = 2, .spawnTime = 72.657f}, // j
        {.lane = 2, .spawnTime = 73.658f}, // j
        {.lane = 3, .spawnTime = 73.658f}, // k
        {.lane = 2, .spawnTime = 74.132f}, // j
        {.lane = 3, .spawnTime = 74.132f}, // k
        {.lane = 1, .spawnTime = 74.596f}, // s
        {.lane = 3, .spawnTime = 74.596f}, // k
        {.lane = 1, .spawnTime = 75.127f}, // s
        {.lane = 3, .spawnTime = 75.127f}, // k
        {.lane = 3, .spawnTime = 75.665f}, // k
        {.lane = 2, .spawnTime = 75.665f}, // j
        {.lane = 2, .spawnTime = 76.172f}, // j
        {.lane = 3, .spawnTime = 76.172f}, // k
        {.lane = 2, .spawnTime = 76.739f}, // j
        {.lane = 3, .spawnTime = 77.055f}, // k
        {.lane = 2, .spawnTime = 77.693f}, // j
        {.lane = 1, .spawnTime = 77.693f}, // s
        {.lane = 3, .spawnTime = 78.169f}, // k
        {.lane = 1, .spawnTime = 78.169f}, // s
        {.lane = 3, .spawnTime = 78.701f}, // k
        {.lane = 2, .spawnTime = 78.701f}, // j
        {.lane = 2, .spawnTime = 79.202f}, // j
        {.lane = 2, .spawnTime = 80.037f}, // j
        {.lane = 0, .spawnTime = 80.037f}, // a
        {.lane = 1, .spawnTime = 80.963f}, // s
        {.lane = 2, .spawnTime = 81.680f}, // j
        {.lane = 2, .spawnTime = 81.986f}, // j
        {.lane = 2, .spawnTime = 82.495f}, // j
        {.lane = 0, .spawnTime = 83.015f}, // a
        {.lane = 3, .spawnTime = 83.684f}, // k
        {.lane = 2, .spawnTime = 84.259f}, // j
        {.lane = 2, .spawnTime = 84.595f}, // j
        {.lane = 1, .spawnTime = 84.703f}, // s
        {.lane = 0, .spawnTime = 85.030f}, // a
        {.lane = 0, .spawnTime = 85.249f}, // a
        {.lane = 1, .spawnTime = 85.751f}, // s
        {.lane = 1, .spawnTime = 86.321f}, // s
        {.lane = 2, .spawnTime = 86.602f}, // j
        {.lane = 1, .spawnTime = 86.735f}, // s
        {.lane = 0, .spawnTime = 87.169f}, // a
        {.lane = 3, .spawnTime = 87.790f}, // k
        {.lane = 1, .spawnTime = 88.183f}, // s
        {.lane = 2, .spawnTime = 88.335f}, // j
        {.lane = 1, .spawnTime = 88.688f}, // s
        {.lane = 1, .spawnTime = 88.833f}, // s
        {.lane = 0, .spawnTime = 89.313f}, // a
        {.lane = 0, .spawnTime = 89.764f}, // a
        {.lane = 2, .spawnTime = 90.394f}, // j
        {.lane = 2, .spawnTime = 90.728f}, // j
        {.lane = 0, .spawnTime = 91.394f}, // a
        {.lane = 0, .spawnTime = 91.755f}, // a
        {.lane = 2, .spawnTime = 92.453f}, // j
        {.lane = 2, .spawnTime = 92.839f}, // j
        {.lane = 0, .spawnTime = 93.520f}, // a
        {.lane = 0, .spawnTime = 93.825f}, // a
        {.lane = 1, .spawnTime = 93.931f}, // s
        {.lane = 2, .spawnTime = 94.480f}, // j
        {.lane = 1, .spawnTime = 94.480f}, // s
        {.lane = 2, .spawnTime = 94.962f}, // j
        {.lane = 3, .spawnTime = 94.971f}, // k
        {.lane = 3, .spawnTime = 95.363f}, // k
        {.lane = 2, .spawnTime = 95.959f}, // j
        {.lane = 2, .spawnTime = 96.572f}, // j
        {.lane = 1, .spawnTime = 96.962f}, // s
        {.lane = 2, .spawnTime = 97.156f}, // j
        {.lane = 0, .spawnTime = 97.488f}, // a
        {.lane = 0, .spawnTime = 97.626f}, // a
        {.lane = 3, .spawnTime = 98.181f}, // k
        {.lane = 3, .spawnTime = 98.546f}, // k
        {.lane = 2, .spawnTime = 98.717f}, // j
        {.lane = 1, .spawnTime = 99.264f}, // s
        {.lane = 0, .spawnTime = 100.154f}, // a
        {.lane = 2, .spawnTime = 100.301f}, // j
        {.lane = 2, .spawnTime = 100.818f}, // j
        {.lane = 2, .spawnTime = 101.321f}, // j
        {.lane = 0, .spawnTime = 101.721f}, // a
        {.lane = 3, .spawnTime = 102.306f}, // k
        {.lane = 3, .spawnTime = 102.659f}, // k
        {.lane = 0, .spawnTime = 102.825f}, // a
        {.lane = 1, .spawnTime = 103.371f}, // s
        {.lane = 2, .spawnTime = 103.725f}, // j
        {.lane = 3, .spawnTime = 104.062f}, // k
        {.lane = 3, .spawnTime = 104.393f}, // k
        {.lane = 2, .spawnTime = 105.434f}, // j
        {.lane = 1, .spawnTime = 106.473f}, // s
        {.lane = 2, .spawnTime = 106.931f}, // j
        {.lane = 3, .spawnTime = 107.307f}, // k
        {.lane = 3, .spawnTime = 107.445f}, // k
        {.lane = 3, .spawnTime = 107.763f}, // k
        {.lane = 1, .spawnTime = 108.499f}, // s
        {.lane = 2, .spawnTime = 108.985f}, // j
        {.lane = 1, .spawnTime = 109.341f}, // s
        {.lane = 0, .spawnTime = 109.497f}, // a
        {.lane = 0, .spawnTime = 110.047f}, // a
        {.lane = 1, .spawnTime = 110.409f}, // s
        {.lane = 2, .spawnTime = 110.576f}, // j
        {.lane = 2, .spawnTime = 111.086f}, // j
        {.lane = 1, .spawnTime = 111.366f}, // s
        {.lane = 2, .spawnTime = 111.366f}, // j
        {.lane = -1}  // Terminator
};

Note EyeOfTheTiger[CHART_SIZE] = {
        {.lane = 2, .spawnTime = -0.756f},
        {.lane = 2, .spawnTime = -0.183f},
        {.lane = 2, .spawnTime = 0.394f},
        {.lane = 2, .spawnTime = 0.954f},
        {.lane = 2, .spawnTime = 1.506f},
        {.lane = 2, .spawnTime = 2.002f},
        {.lane = 2, .spawnTime = 2.555f},
        {.lane = 2, .spawnTime = 3.090f},
        {.lane = 2, .spawnTime = 3.629f},
        {.lane = 2, .spawnTime = 4.190f},
        {.lane = 2, .spawnTime = 4.757f},
        {.lane = 2, .spawnTime = 5.263f},
        {.lane = 2, .spawnTime = 5.836f},
        {.lane = 2, .spawnTime = 6.374f},
        {.lane = 2, .spawnTime = 6.929f},
        {.lane = 2, .spawnTime = 7.500f},
        {.lane = 2, .spawnTime = 8.095f},
        {.lane = 3, .spawnTime = 8.095f},  // Grouped with previous (0.01s difference)
        {.lane = 3, .spawnTime = 9.164f},
        {.lane = 2, .spawnTime = 9.164f},  // Grouped with previous (0.01s difference)
        {.lane = 2, .spawnTime = 9.589f},
        {.lane = 1, .spawnTime = 9.589f},  // Grouped with previous (0.01s difference)
        {.lane = 3, .spawnTime = 9.990f},
        {.lane = 2, .spawnTime = 9.990f},  // Grouped with previous (0.003s difference)
        {.lane = 2, .spawnTime = 11.410f},
        {.lane = 3, .spawnTime = 11.410f},  // Grouped with previous (0.004s difference)
        {.lane = 2, .spawnTime = 11.808f},
        {.lane = 1, .spawnTime = 11.808f},
        {.lane = 3, .spawnTime = 12.201f},
        {.lane = 2, .spawnTime = 12.201f},  // Grouped with previous (0.005s difference)
        {.lane = 3, .spawnTime = 13.560f},
        {.lane = 2, .spawnTime = 13.560f},  // Grouped with previous (0.003s difference)
        {.lane = 1, .spawnTime = 14.003f},
        {.lane = 1, .spawnTime = 14.401f},
        {.lane = 2, .spawnTime = 14.401f},  // Grouped with previous (0.007s difference)
        {.lane = 2, .spawnTime = 16.894f},
        {.lane = 3, .spawnTime = 16.894f},  // Grouped with previous (0.01s difference)
        {.lane = 2, .spawnTime = 17.965f},
        {.lane = 3, .spawnTime = 17.965f},  // Grouped with previous (0.003s difference)
        {.lane = 1, .spawnTime = 18.400f},
        {.lane = 2, .spawnTime = 18.400f},  // Grouped with previous (0.001s difference)
        {.lane = 2, .spawnTime = 18.819f},
        {.lane = 3, .spawnTime = 18.819f},  // Grouped with previous (0.009s difference)
        {.lane = 2, .spawnTime = 20.496f},
        {.lane = 3, .spawnTime = 20.496f},  // Grouped with previous (0.003s difference)
        {.lane = 2, .spawnTime = 20.893f},
        {.lane = 1, .spawnTime = 20.893f},
        {.lane = 2, .spawnTime = 21.303f},
        {.lane = 3, .spawnTime = 21.303f},  // Grouped with previous (0.01s difference)
        {.lane = 3, .spawnTime = 22.442f},
        {.lane = 2, .spawnTime = 22.442f},  // Grouped with previous (0.006s difference)
        {.lane = 1, .spawnTime = 22.863f},
        {.lane = 1, .spawnTime = 23.233f},
        {.lane = 2, .spawnTime = 23.233f},
        {.lane = 2, .spawnTime = 25.735f},
        {.lane = 3, .spawnTime = 25.735f},
        {.lane = 3, .spawnTime = 26.908f},
        {.lane = 2, .spawnTime = 27.273f},
        {.lane = 3, .spawnTime = 27.687f},
        {.lane = 3, .spawnTime = 29.127f},
        {.lane = 2, .spawnTime = 29.526f},
        {.lane = 3, .spawnTime = 29.898f},
        {.lane = 2, .spawnTime = 31.321f},
        {.lane = 3, .spawnTime = 31.321f},  // Grouped with previous (0.003s difference)
        {.lane = 1, .spawnTime = 31.716f},
        {.lane = 1, .spawnTime = 32.104f},
        {.lane = 2, .spawnTime = 32.104f},  // Grouped with previous (0.007s difference)
        {.lane = 2, .spawnTime = 34.594f},
        {.lane = 3, .spawnTime = 34.594f},  // Grouped with previous (0.01s difference)
        {.lane = 3, .spawnTime = 35.674f},
        {.lane = 2, .spawnTime = 36.094f},
        {.lane = 3, .spawnTime = 36.518f},
        {.lane = 3, .spawnTime = 37.928f},
        {.lane = 2, .spawnTime = 38.332f},
        {.lane = 3, .spawnTime = 38.733f},
        {.lane = 3, .spawnTime = 40.120f},
        {.lane = 2, .spawnTime = 40.120f},  // Grouped with previous (0.003s difference)
        {.lane = 1, .spawnTime = 40.581f},
        {.lane = 2, .spawnTime = 40.948f},
        {.lane = 1, .spawnTime = 40.948f},  // Grouped with previous (0.004s difference)
        {.lane = 3, .spawnTime = 43.444f},
        {.lane = 2, .spawnTime = 43.444f},  // Grouped with previous (0.003s difference)
        {.lane = 2, .spawnTime = 43.984f},
        {.lane = 2, .spawnTime = 44.485f},
        {.lane = 2, .spawnTime = 45.026f},
        {.lane = 2, .spawnTime = 45.599f},
        {.lane = 2, .spawnTime = 46.163f},
        {.lane = 2, .spawnTime = 46.753f},
        {.lane = 2, .spawnTime = 47.309f},
        {.lane = 2, .spawnTime = 47.881f},
        {.lane = 2, .spawnTime = 48.495f},
        {.lane = 2, .spawnTime = 48.960f},
        {.lane = 2, .spawnTime = 49.533f},
        {.lane = 2, .spawnTime = 50.068f},
        {.lane = 2, .spawnTime = 50.588f},
        {.lane = 2, .spawnTime = 51.158f},
        {.lane = 2, .spawnTime = 51.689f},
        {.lane = 2, .spawnTime = 52.243f},
        {.lane = 2, .spawnTime = 52.818f},
        {.lane = 2, .spawnTime = 53.334f},
        {.lane = 2, .spawnTime = 53.870f},
        {.lane = 2, .spawnTime = 54.450f},
        {.lane = 2, .spawnTime = 55.007f},
        {.lane = 2, .spawnTime = 55.519f},
        {.lane = 2, .spawnTime = 56.107f},
        {.lane = 2, .spawnTime = 56.625f},
        {.lane = 2, .spawnTime = 57.212f},
        {.lane = 2, .spawnTime = 57.743f},
        {.lane = 2, .spawnTime = 58.271f},
        {.lane = 2, .spawnTime = 58.837f},
        {.lane = 2, .spawnTime = 59.376f},
        {.lane = 2, .spawnTime = 59.917f},
        {.lane = 2, .spawnTime = 60.498f},
        {.lane = 2, .spawnTime = 61.021f},
        {.lane = 2, .spawnTime = 61.581f},
        {.lane = 2, .spawnTime = 62.120f},
        {.lane = 2, .spawnTime = 62.670f},
        {.lane = 2, .spawnTime = 63.265f},
        {.lane = 2, .spawnTime = 63.820f},
        {.lane = 2, .spawnTime = 64.356f},
        {.lane = 2, .spawnTime = 64.926f},
        {.lane = 2, .spawnTime = 65.490f},
        {.lane = 2, .spawnTime = 66.044f},
        {.lane = 2, .spawnTime = 66.582f},
        {.lane = 2, .spawnTime = 67.126f},
        {.lane = 2, .spawnTime = 67.655f},
        {.lane = 2, .spawnTime = 68.214f},
        {.lane = 2, .spawnTime = 68.819f},
        {.lane = 2, .spawnTime = 69.349f},
        {.lane = 2, .spawnTime = 69.888f},
        {.lane = 2, .spawnTime = 70.422f},
        {.lane = 2, .spawnTime = 70.986f},
        {.lane = 2, .spawnTime = 71.549f},
        {.lane = 2, .spawnTime = 72.069f},
        {.lane = 2, .spawnTime = 72.623f},
        {.lane = 2, .spawnTime = 73.183f},
        {.lane = 2, .spawnTime = 73.719f},
        {.lane = 2, .spawnTime = 74.284f},
        {.lane = 2, .spawnTime = 74.832f},
        {.lane = 2, .spawnTime = 75.385f},
        {.lane = 2, .spawnTime = 75.914f},
        {.lane = 2, .spawnTime = 76.499f},
        {.lane = 2, .spawnTime = 76.996f},
        {.lane = 2, .spawnTime = 77.607f},
        {.lane = 2, .spawnTime = 78.123f},
        {.lane = 2, .spawnTime = 78.677f},
        {.lane = 2, .spawnTime = 79.277f},
        {.lane = 2, .spawnTime = 79.807f},
        {.lane = 2, .spawnTime = 80.350f},
        {.lane = 2, .spawnTime = 80.965f},
        {.lane = 2, .spawnTime = 81.485f},
        {.lane = 2, .spawnTime = 82.073f},
        {.lane = 0, .spawnTime = 83.182f},
        {.lane = 1, .spawnTime = 83.182f},  // Grouped with previous (0.007s difference)
        {.lane = 3, .spawnTime = 85.396f},
        {.lane = 2, .spawnTime = 86.443f},
        {.lane = 1, .spawnTime = 87.611f},
        {.lane = 0, .spawnTime = 87.611f},  // Grouped with previous (0.003s difference)
        {.lane = 2, .spawnTime = 89.767f},
        {.lane = 1, .spawnTime = 90.354f},
        {.lane = 1, .spawnTime = 92.022f},
        {.lane = 0, .spawnTime = 92.022f},  // Grouped with previous (0.007s difference)
        {.lane = 3, .spawnTime = 94.214f},
        {.lane = 2, .spawnTime = 95.319f},
        {.lane = 1, .spawnTime = 96.410f},
        {.lane = 1, .spawnTime = 97.128f},
        {.lane = 2, .spawnTime = 97.486f},
        {.lane = 2, .spawnTime = 98.206f},
        {.lane = 3, .spawnTime = 98.621f},
        {.lane = 2, .spawnTime = 100.798f},
        {.lane = 2, .spawnTime = 101.305f},
        {.lane = 2, .spawnTime = 101.888f},
        {.lane = 2, .spawnTime = 102.442f},
        {.lane = 2, .spawnTime = 102.985f},
        {.lane = 2, .spawnTime = 103.578f},
        {.lane = 2, .spawnTime = 104.124f},
        {.lane = 2, .spawnTime = 104.700f},
        {.lane = 3, .spawnTime = 105.248f},
        {.lane = 3, .spawnTime = 108.722f},
        {.lane = 3, .spawnTime = 109.062f},
        {.lane = 2, .spawnTime = 109.669f},
        {.lane = 2, .spawnTime = 111.567f},
        {.lane = 1, .spawnTime = 111.893f},
        {.lane = 3, .spawnTime = 114.139f},
        {.lane = 3, .spawnTime = 115.261f},
        {.lane = 3, .spawnTime = 115.739f},
        {.lane = 3, .spawnTime = 116.253f},
        {.lane = 3, .spawnTime = 116.554f},
        {.lane = 2, .spawnTime = 118.537f},
        {.lane = 2, .spawnTime = 120.121f},
        {.lane = 1, .spawnTime = 120.755f},
        {.lane = 0, .spawnTime = 122.921f},
        {.lane = 1, .spawnTime = 122.921f},  // Grouped with previous (0.013s difference)
        {.lane = 3, .spawnTime = 125.160f},
        {.lane = 3, .spawnTime = 125.773f},
        {.lane = 2, .spawnTime = 126.047f},
        {.lane = 2, .spawnTime = 126.904f},
        {.lane = 0, .spawnTime = 127.285f},
        {.lane = 1, .spawnTime = 127.285f},  // Grouped with previous (0.003s difference)
        {.lane = 2, .spawnTime = 129.574f},
        {.lane = 1, .spawnTime = 130.121f},
        {.lane = 1, .spawnTime = 131.121f},
        {.lane = 0, .spawnTime = 131.768f},
        {.lane = 1, .spawnTime = 131.771f},  // Grouped with previous (0.003s difference)
        {.lane = 3, .spawnTime = 133.923f},
        {.lane = 2, .spawnTime = 135.034f},
        {.lane = 2, .spawnTime = 135.738f},
        {.lane = 1, .spawnTime = 136.140f},
        {.lane = 1, .spawnTime = 136.806f},
        {.lane = 2, .spawnTime = 137.218f},
        {.lane = 2, .spawnTime = 137.878f},
        {.lane = 3, .spawnTime = 138.287f},
        {.lane = 2, .spawnTime = 140.567f},
        {.lane = 2, .spawnTime = 141.108f},
        {.lane = 2, .spawnTime = 141.655f},
        {.lane = 2, .spawnTime = 142.256f},
        {.lane = 2, .spawnTime = 142.807f},
        {.lane = 2, .spawnTime = 143.362f},
        {.lane = 2, .spawnTime = 143.913f},
        {.lane = 2, .spawnTime = 144.478f},
        {.lane = 2, .spawnTime = 145.018f},
        {.lane = 2, .spawnTime = 145.559f},
        {.lane = 2, .spawnTime = 146.099f},
        {.lane = 2, .spawnTime = 146.636f},
        {.lane = 2, .spawnTime = 147.198f},

        // Terminator
        {.lane = -1}
};

Note Toxicity[CHART_SIZE] = {
        // First group (0.241f apart) - no changes
        {.lane = 0, .spawnTime = 1.975f},
        {.lane = 2, .spawnTime = 2.216f},
        {.lane = 0, .spawnTime = 2.502f},
        {.lane = 2, .spawnTime = 2.787f},
        {.lane = 0, .spawnTime = 3.031f},
        {.lane = 2, .spawnTime = 3.253f},
        {.lane = 0, .spawnTime = 3.569f},
        {.lane = 2, .spawnTime = 3.780f},
        {.lane = 0, .spawnTime = 4.043f},
        {.lane = 2, .spawnTime = 4.298f},
        {.lane = 0, .spawnTime = 4.560f},

        // Next group (0.236f apart) - no changes
        {.lane = 1, .spawnTime = 5.102f},
        {.lane = 3, .spawnTime = 5.338f},
        {.lane = 1, .spawnTime = 5.572f},
        {.lane = 3, .spawnTime = 5.838f},
        {.lane = 1, .spawnTime = 6.156f},
        {.lane = 3, .spawnTime = 6.386f},
        {.lane = 1, .spawnTime = 6.662f},
        {.lane = 3, .spawnTime = 6.923f},
        {.lane = 1, .spawnTime = 7.191f},
        {.lane = 3, .spawnTime = 7.439f},
        {.lane = 1, .spawnTime = 7.671f},

        // Next group - no changes
        {.lane = 0, .spawnTime = 8.268f},
        {.lane = 2, .spawnTime = 8.505f},
        {.lane = 0, .spawnTime = 8.760f},
        {.lane = 2, .spawnTime = 9.032f},
        {.lane = 0, .spawnTime = 9.250f},
        {.lane = 2, .spawnTime = 9.496f},
        {.lane = 3, .spawnTime = 9.746f},
        {.lane = 3, .spawnTime = 10.294f},
        {.lane = 2, .spawnTime = 10.516f},
        {.lane = 2, .spawnTime = 11.054f},
        {.lane = 1, .spawnTime = 11.286f},
        {.lane = 1, .spawnTime = 11.838f},
        {.lane = 4, .spawnTime = 12.023f},
        {.lane = 4, .spawnTime = 12.566f},
        {.lane = 3, .spawnTime = 12.794f},
        {.lane = 3, .spawnTime = 13.356f},
        {.lane = 2, .spawnTime = 13.552f},
        {.lane = 2, .spawnTime = 14.079f},

        // Close notes (0.013f apart) - made equal
        {.lane = 0, .spawnTime = 14.330f},
        {.lane = 1, .spawnTime = 14.330f},

        {.lane = 3, .spawnTime = 15.864f},
        {.lane = 2, .spawnTime = 16.057f},

        // Close notes (0.003f apart) - made equal
        {.lane = 0, .spawnTime = 16.343f},
        {.lane = 1, .spawnTime = 16.343f},

        // Close notes (0.010f apart) - made equal
        {.lane = 2, .spawnTime = 17.247f},
        {.lane = 4, .spawnTime = 17.247f},

        // Close notes (0.009f apart) - made equal
        {.lane = 4, .spawnTime = 18.059f},
        {.lane = 2, .spawnTime = 18.059f},

        // Close notes (0.013f apart) - made equal
        {.lane = 4, .spawnTime = 18.338f},
        {.lane = 2, .spawnTime = 18.338f},

        {.lane = 4, .spawnTime = 18.559f},
        {.lane = 2, .spawnTime = 18.559f},
        {.lane = 3, .spawnTime = 18.855f},

        // Close notes (0.022f apart) - made equal
        {.lane = 1, .spawnTime = 18.877f},
        {.lane = 1, .spawnTime = 18.877f},

        // Close notes (0.003f apart) - made equal
        {.lane = 1, .spawnTime = 19.231f},
        {.lane = 3, .spawnTime = 19.231f},

        // Close notes (0.012f apart) - made equal
        {.lane = 1, .spawnTime = 19.602f},
        {.lane = 3, .spawnTime = 19.602f},

        // Close notes (0.003f apart) - made equal
        {.lane = 1, .spawnTime = 19.873f},
        {.lane = 3, .spawnTime = 19.873f},

        // Close notes (0.012f apart) - made equal
        {.lane = 1, .spawnTime = 20.082f},
        {.lane = 3, .spawnTime = 20.082f},

        {.lane = 0, .spawnTime = 20.336f},
        {.lane = 3, .spawnTime = 21.842f},
        {.lane = 2, .spawnTime = 22.092f},
        {.lane = 0, .spawnTime = 22.341f},

        // Close notes (0.002f apart) - made equal
        {.lane = 1, .spawnTime = 22.341f},

        {.lane = 4, .spawnTime = 23.263f},

        // Close notes (0.007f apart) - made equal
        {.lane = 2, .spawnTime = 23.263f},

        {.lane = 4, .spawnTime = 24.007f},

        // Close notes (0.013f apart) - made equal
        {.lane = 2, .spawnTime = 24.007f},

        {.lane = 4, .spawnTime = 24.257f},

        // Close notes (0.012f apart) - made equal
        {.lane = 2, .spawnTime = 24.257f},

        {.lane = 2, .spawnTime = 24.498f},

        // Close notes (0.006f apart) - made equal
        {.lane = 4, .spawnTime = 24.498f},

        {.lane = 3, .spawnTime = 24.738f},

        // Close notes (0.017f apart) - made equal
        {.lane = 1, .spawnTime = 24.738f},

        {.lane = 3, .spawnTime = 25.520f},

        // Close notes (0.006f apart) - made equal
        {.lane = 1, .spawnTime = 25.520f},

        {.lane = 3, .spawnTime = 25.741f},

        // Close notes (0.008f apart) - made equal
        {.lane = 1, .spawnTime = 25.741f},

        {.lane = 3, .spawnTime = 25.983f},

        // Close notes (0.023f apart) - made equal
        {.lane = 1, .spawnTime = 25.983f},

        {.lane = 3, .spawnTime = 26.254f},
        {.lane = 2, .spawnTime = 26.507f},
        {.lane = 0, .spawnTime = 26.772f},
        {.lane = 3, .spawnTime = 27.009f},
        {.lane = 2, .spawnTime = 27.236f},
        {.lane = 0, .spawnTime = 27.542f},
        {.lane = 3, .spawnTime = 27.744f},
        {.lane = 2, .spawnTime = 27.976f},
        {.lane = 0, .spawnTime = 28.244f},
        {.lane = 3, .spawnTime = 28.454f},
        {.lane = 2, .spawnTime = 28.680f},
        {.lane = 0, .spawnTime = 28.901f},
        {.lane = 2, .spawnTime = 29.097f},

        // Close notes (0.012f apart) - made equal
        {.lane = 4, .spawnTime = 29.097f},

        {.lane = 4, .spawnTime = 29.852f},

        // Close notes (0.007f apart) - made equal
        {.lane = 2, .spawnTime = 29.852f},

        {.lane = 4, .spawnTime = 30.131f},

        // Close notes (0.016f apart) - made equal
        {.lane = 2, .spawnTime = 30.131f},

        {.lane = 2, .spawnTime = 30.366f},

        // Close notes (0.003f apart) - made equal
        {.lane = 4, .spawnTime = 30.366f},

        {.lane = 3, .spawnTime = 30.631f},

        // Close notes (0.036f apart) - made equal
        {.lane = 1, .spawnTime = 30.631f},

        {.lane = 3, .spawnTime = 31.417f},

        // Close notes (0.014f apart) - made equal
        {.lane = 1, .spawnTime = 31.417f},

        {.lane = 1, .spawnTime = 31.673f},

        // Close notes (0.007f apart) - made equal
        {.lane = 3, .spawnTime = 31.673f},

        {.lane = 3, .spawnTime = 31.902f},

        // Close notes (0.012f apart) - made equal
        {.lane = 1, .spawnTime = 31.902f},

        {.lane = 1, .spawnTime = 32.172f},

        // Close notes (0.002f apart) - made equal
        {.lane = 0, .spawnTime = 32.172f},

        {.lane = 3, .spawnTime = 33.615f},
        {.lane = 2, .spawnTime = 33.837f},
        {.lane = 0, .spawnTime = 34.149f},

        // Close notes (0.003f apart) - made equal
        {.lane = 1, .spawnTime = 34.149f},

        {.lane = 4, .spawnTime = 35.093f},

        // Close notes (0.004f apart) - made equal
        {.lane = 2, .spawnTime = 35.093f},

        {.lane = 4, .spawnTime = 35.833f},

        // Close notes (0.005f apart) - made equal
        {.lane = 2, .spawnTime = 35.833f},

        {.lane = 4, .spawnTime = 36.071f},

        // Close notes (0.004f apart) - made equal
        {.lane = 2, .spawnTime = 36.071f},

        {.lane = 2, .spawnTime = 36.286f},

        // Close notes (0.008f apart) - made equal
        {.lane = 4, .spawnTime = 36.286f},

        {.lane = 3, .spawnTime = 36.569f},

        // Close notes (0.021f apart) - made equal
        {.lane = 1, .spawnTime = 36.569f},

        {.lane = 1, .spawnTime = 36.943f},

        // Close notes (0.019f apart) - made equal
        {.lane = 3, .spawnTime = 36.943f},

        {.lane = 1, .spawnTime = 37.385f},

        // Close notes (0.009f apart) - made equal
        {.lane = 3, .spawnTime = 37.385f},

        {.lane = 1, .spawnTime = 37.585f},

        // Close notes (0.008f apart) - made equal
        {.lane = 3, .spawnTime = 37.585f},

        {.lane = 1, .spawnTime = 37.783f},

        // Close notes (0.010f apart) - made equal
        {.lane = 3, .spawnTime = 37.783f},

        {.lane = 0, .spawnTime = 38.123f},
        {.lane = 2, .spawnTime = 38.310f},
        {.lane = 0, .spawnTime = 38.611f},
        {.lane = 2, .spawnTime = 38.822f},
        {.lane = 0, .spawnTime = 39.142f},
        {.lane = 2, .spawnTime = 39.359f},
        {.lane = 0, .spawnTime = 39.608f},
        {.lane = 2, .spawnTime = 39.863f},
        {.lane = 0, .spawnTime = 40.106f},
        {.lane = 2, .spawnTime = 40.379f},
        {.lane = 0, .spawnTime = 40.587f},
        {.lane = 1, .spawnTime = 41.154f},
        {.lane = 3, .spawnTime = 41.416f},
        {.lane = 1, .spawnTime = 41.662f},
        {.lane = 3, .spawnTime = 41.888f},
        {.lane = 1, .spawnTime = 42.177f},
        {.lane = 3, .spawnTime = 42.420f},
        {.lane = 1, .spawnTime = 42.694f},
        {.lane = 3, .spawnTime = 42.948f},
        {.lane = 1, .spawnTime = 43.256f},
        {.lane = 3, .spawnTime = 43.485f},
        {.lane = 1, .spawnTime = 43.736f},
        {.lane = 0, .spawnTime = 44.297f},
        {.lane = 2, .spawnTime = 44.521f},
        {.lane = 0, .spawnTime = 44.805f},
        {.lane = 2, .spawnTime = 45.032f},
        {.lane = 0, .spawnTime = 45.308f},
        {.lane = 2, .spawnTime = 45.550f},
        {.lane = 3, .spawnTime = 45.833f},
        {.lane = 3, .spawnTime = 46.370f},
        {.lane = 2, .spawnTime = 46.613f},
        {.lane = 2, .spawnTime = 47.197f},
        {.lane = 1, .spawnTime = 47.413f},
        {.lane = 1, .spawnTime = 47.936f},
        {.lane = 4, .spawnTime = 48.163f},
        {.lane = 4, .spawnTime = 48.721f},
        {.lane = 3, .spawnTime = 48.976f},
        {.lane = 3, .spawnTime = 49.526f},
        {.lane = 2, .spawnTime = 49.768f},
        {.lane = 2, .spawnTime = 50.318f},
        {.lane = 0, .spawnTime = 50.588f},
        {.lane = 2, .spawnTime = 50.854f},
        {.lane = 0, .spawnTime = 51.109f},
        {.lane = 2, .spawnTime = 51.410f},
        {.lane = 0, .spawnTime = 51.680f},
        {.lane = 2, .spawnTime = 51.928f},
        {.lane = 0, .spawnTime = 52.171f},
        {.lane = 2, .spawnTime = 52.462f},
        {.lane = 0, .spawnTime = 52.688f},
        {.lane = 2, .spawnTime = 52.938f},
        {.lane = 0, .spawnTime = 53.161f},
        {.lane = 1, .spawnTime = 53.647f},
        {.lane = 3, .spawnTime = 53.912f},
        {.lane = 1, .spawnTime = 54.151f},
        {.lane = 4, .spawnTime = 54.425f},
        {.lane = 1, .spawnTime = 55.008f},
        {.lane = 4, .spawnTime = 55.178f},
        {.lane = 2, .spawnTime = 55.704f},
        {.lane = 3, .spawnTime = 55.940f},
        {.lane = 2, .spawnTime = 56.226f},
        {.lane = 1, .spawnTime = 56.462f},
        {.lane = 0, .spawnTime = 56.771f},
        {.lane = 2, .spawnTime = 56.996f},
        {.lane = 0, .spawnTime = 57.277f},
        {.lane = 2, .spawnTime = 57.541f},
        {.lane = 2, .spawnTime = 58.085f},
        {.lane = 3, .spawnTime = 58.322f},
        {.lane = 3, .spawnTime = 58.908f},
        {.lane = 2, .spawnTime = 59.109f},
        {.lane = 2, .spawnTime = 59.702f},
        {.lane = 1, .spawnTime = 59.900f},
        {.lane = 1, .spawnTime = 60.452f},
        {.lane = 4, .spawnTime = 60.674f},
        {.lane = 4, .spawnTime = 61.249f},
        {.lane = 3, .spawnTime = 61.457f},
        {.lane = 3, .spawnTime = 62.035f},
        {.lane = 2, .spawnTime = 62.264f},
        {.lane = 1, .spawnTime = 62.515f},
        {.lane = 2, .spawnTime = 62.799f},
        {.lane = 0, .spawnTime = 63.064f},
        {.lane = 0, .spawnTime = 63.422f},
        {.lane = 0, .spawnTime = 63.806f},
        {.lane = 0, .spawnTime = 64.099f},
        {.lane = 0, .spawnTime = 64.319f},
        {.lane = 0, .spawnTime = 64.592f},
        {.lane = 0, .spawnTime = 64.989f},
        {.lane = 0, .spawnTime = 65.432f},
        {.lane = 0, .spawnTime = 65.710f},
        {.lane = 0, .spawnTime = 65.940f},
        {.lane = 1, .spawnTime = 66.251f},
        {.lane = 1, .spawnTime = 66.652f},
        {.lane = 1, .spawnTime = 66.987f},
        {.lane = 1, .spawnTime = 67.279f},
        {.lane = 1, .spawnTime = 67.555f},
        {.lane = 1, .spawnTime = 67.852f},
        {.lane = 1, .spawnTime = 68.222f},
        {.lane = 1, .spawnTime = 68.652f},
        {.lane = 1, .spawnTime = 68.923f},
        {.lane = 1, .spawnTime = 69.132f},
        {.lane = 0, .spawnTime = 69.364f},
        {.lane = 0, .spawnTime = 69.784f},
        {.lane = 0, .spawnTime = 70.211f},
        {.lane = 0, .spawnTime = 70.501f},
        {.lane = 0, .spawnTime = 70.737f},
        {.lane = 0, .spawnTime = 70.992f},
        {.lane = 0, .spawnTime = 71.380f},
        {.lane = 0, .spawnTime = 71.794f},
        {.lane = 0, .spawnTime = 72.026f},
        {.lane = 0, .spawnTime = 72.278f},
        {.lane = 1, .spawnTime = 72.584f},
        {.lane = 1, .spawnTime = 72.977f},
        {.lane = 1, .spawnTime = 73.386f},
        {.lane = 1, .spawnTime = 73.609f},
        {.lane = 1, .spawnTime = 73.830f},
        {.lane = 1, .spawnTime = 74.115f},
        {.lane = 1, .spawnTime = 74.530f},
        {.lane = 1, .spawnTime = 74.932f},
        {.lane = 1, .spawnTime = 75.181f},
        {.lane = 1, .spawnTime = 75.385f},

        // Close notes (0.008f apart) - made equal
        {.lane = 0, .spawnTime = 75.629f},
        {.lane = 1, .spawnTime = 75.629f},

        {.lane = 3, .spawnTime = 77.151f},
        {.lane = 2, .spawnTime = 77.408f},
        {.lane = 0, .spawnTime = 77.643f},

        // Close notes (0.010f apart) - made equal
        {.lane = 1, .spawnTime = 77.643f},

        {.lane = 2, .spawnTime = 78.601f},

        // Close notes (0.005f apart) - made equal
        {.lane = 4, .spawnTime = 78.601f},

        {.lane = 2, .spawnTime = 79.310f},

        // Close notes (0.007f apart) - made equal
        {.lane = 4, .spawnTime = 79.310f},

        {.lane = 2, .spawnTime = 79.607f},

        // Close notes (0.002f apart) - made equal
        {.lane = 4, .spawnTime = 79.607f},

        {.lane = 4, .spawnTime = 79.837f},

        // Close notes (0.012f apart) - made equal
        {.lane = 2, .spawnTime = 79.837f},

        {.lane = 3, .spawnTime = 80.138f},

        // Close notes (0.024f apart) - made equal
        {.lane = 1, .spawnTime = 80.138f},

        {.lane = 3, .spawnTime = 80.540f},

        // Close notes (0.003f apart) - made equal
        {.lane = 1, .spawnTime = 80.540f},

        {.lane = 1, .spawnTime = 80.923f},

        // Close notes (0.009f apart) - made equal
        {.lane = 3, .spawnTime = 80.923f},

        {.lane = 1, .spawnTime = 81.128f},

        // Close notes (0.033f apart) - made equal
        {.lane = 3, .spawnTime = 81.128f},

        {.lane = 1, .spawnTime = 81.363f},

        // Close notes (0.000f apart) - made equal
        {.lane = 3, .spawnTime = 81.363f},

        {.lane = 0, .spawnTime = 81.618f},

        // Close notes (0.003f apart) - made equal
        {.lane = 1, .spawnTime = 81.618f},

        {.lane = 3, .spawnTime = 83.202f},
        {.lane = 2, .spawnTime = 83.418f},
        {.lane = 0, .spawnTime = 83.661f},

        // Close notes (0.016f apart) - made equal
        {.lane = 1, .spawnTime = 83.661f},

        {.lane = 2, .spawnTime = 84.610f},

        // Close notes (0.004f apart) - made equal
        {.lane = 4, .spawnTime = 84.610f},

        {.lane = 4, .spawnTime = 85.331f},

        // Close notes (0.005f apart) - made equal
        {.lane = 2, .spawnTime = 85.331f},

        {.lane = 2, .spawnTime = 85.602f},

        // Close notes (0.012f apart) - made equal
        {.lane = 4, .spawnTime = 85.602f},

        {.lane = 4, .spawnTime = 85.855f},

        // Close notes (0.003f apart) - made equal
        {.lane = 2, .spawnTime = 85.855f},

        {.lane = 3, .spawnTime = 86.166f},

        // Close notes (0.022f apart) - made equal
        {.lane = 1, .spawnTime = 86.166f},

        {.lane = 1, .spawnTime = 86.834f},

        // Close notes (0.002f apart) - made equal
        {.lane = 3, .spawnTime = 86.834f},

        {.lane = 3, .spawnTime = 87.379f},

        // Close notes (0.009f apart) - made equal
        {.lane = 1, .spawnTime = 87.379f},

        {.lane = 3, .spawnTime = 87.635f},
        {.lane = 2, .spawnTime = 87.889f},
        {.lane = 0, .spawnTime = 88.158f},
        {.lane = 3, .spawnTime = 88.396f},
        {.lane = 2, .spawnTime = 88.640f},
        {.lane = 0, .spawnTime = 88.906f},
        {.lane = 3, .spawnTime = 89.107f},
        {.lane = 2, .spawnTime = 89.345f},
        {.lane = 0, .spawnTime = 89.631f},
        {.lane = 3, .spawnTime = 89.859f},
        {.lane = 2, .spawnTime = 90.071f},
        {.lane = 0, .spawnTime = 90.362f},

        // Close notes (0.002f apart) - made equal
        {.lane = 4, .spawnTime = 90.362f},
        {.lane = 2, .spawnTime = 90.362f},

        {.lane = 2, .spawnTime = 91.270f},

        // Close notes (0.000f apart) - made equal
        {.lane = 4, .spawnTime = 91.270f},

        {.lane = 4, .spawnTime = 91.527f},

        // Close notes (0.003f apart) - made equal
        {.lane = 2, .spawnTime = 91.527f},

        {.lane = 4, .spawnTime = 91.765f},

        // Close notes (0.006f apart) - made equal
        {.lane = 2, .spawnTime = 91.765f},

        {.lane = 3, .spawnTime = 92.092f},

        // Close notes (0.027f apart) - made equal
        {.lane = 1, .spawnTime = 92.092f},

        {.lane = 3, .spawnTime = 92.834f},

        // Close notes (0.013f apart) - made equal
        {.lane = 1, .spawnTime = 92.834f},

        {.lane = 3, .spawnTime = 93.114f},

        // Close notes (0.024f apart) - made equal
        {.lane = 1, .spawnTime = 93.114f},

        {.lane = 3, .spawnTime = 93.324f},

        // Close notes (0.024f apart) - made equal
        {.lane = 1, .spawnTime = 93.324f},

        {.lane = 0, .spawnTime = 93.611f},

        // Close notes (0.000f apart) - made equal
        {.lane = 1, .spawnTime = 93.611f},

        {.lane = 3, .spawnTime = 95.154f},
        {.lane = 2, .spawnTime = 95.353f},
        {.lane = 0, .spawnTime = 95.643f},

        // Close notes (0.007f apart) - made equal
        {.lane = 1, .spawnTime = 95.643f},

        {.lane = 2, .spawnTime = 96.607f},

        // Close notes (0.013f apart) - made equal
        {.lane = 4, .spawnTime = 96.607f},

        {.lane = 2, .spawnTime = 97.321f},

        // Close notes (0.011f apart) - made equal
        {.lane = 4, .spawnTime = 97.321f},

        {.lane = 2, .spawnTime = 97.577f},

        // Close notes (0.017f apart) - made equal
        {.lane = 4, .spawnTime = 97.577f},

        {.lane = 4, .spawnTime = 97.817f},

        // Close notes (0.006f apart) - made equal
        {.lane = 2, .spawnTime = 97.817f},

        {.lane = 3, .spawnTime = 98.110f},

        // Close notes (0.022f apart) - made equal
        {.lane = 1, .spawnTime = 98.110f},

        {.lane = 3, .spawnTime = 98.861f},

        // Close notes (0.026f apart) - made equal
        {.lane = 1, .spawnTime = 98.861f},

        {.lane = 3, .spawnTime = 99.142f},

        // Close notes (0.003f apart) - made equal
        {.lane = 1, .spawnTime = 99.142f},

        {.lane = 3, .spawnTime = 99.360f},

        // Close notes (0.004f apart) - made equal
        {.lane = 1, .spawnTime = 99.360f},

        {.lane = 0, .spawnTime = 99.686f},
        {.lane = 2, .spawnTime = 99.938f},
        {.lane = 0, .spawnTime = 100.244f},
        {.lane = 2, .spawnTime = 100.533f},
        {.lane = 0, .spawnTime = 100.767f},
        {.lane = 2, .spawnTime = 101.053f},
        {.lane = 0, .spawnTime = 101.282f},
        {.lane = 2, .spawnTime = 101.584f},
        {.lane = 0, .spawnTime = 101.833f},
        {.lane = 2, .spawnTime = 102.077f},
        {.lane = 0, .spawnTime = 102.342f},
        {.lane = 1, .spawnTime = 102.808f},
        {.lane = 3, .spawnTime = 103.075f},
        {.lane = 1, .spawnTime = 103.364f},
        {.lane = 3, .spawnTime = 103.632f},
        {.lane = 1, .spawnTime = 103.898f},
        {.lane = 3, .spawnTime = 104.157f},
        {.lane = 1, .spawnTime = 104.430f},
        {.lane = 3, .spawnTime = 104.632f},
        {.lane = 1, .spawnTime = 104.921f},
        {.lane = 3, .spawnTime = 105.203f},
        {.lane = 1, .spawnTime = 105.434f},
        {.lane = 0, .spawnTime = 105.996f},
        {.lane = 2, .spawnTime = 106.206f},
        {.lane = 0, .spawnTime = 106.506f},
        {.lane = 2, .spawnTime = 106.757f},
        {.lane = 0, .spawnTime = 107.029f},
        {.lane = 2, .spawnTime = 107.275f},
        {.lane = 3, .spawnTime = 107.536f},
        {.lane = 3, .spawnTime = 108.076f},
        {.lane = 2, .spawnTime = 108.329f},
        {.lane = 2, .spawnTime = 108.874f},
        {.lane = 1, .spawnTime = 109.121f},
        {.lane = 1, .spawnTime = 109.688f},
        {.lane = 4, .spawnTime = 109.916f},
        {.lane = 4, .spawnTime = 110.456f},
        {.lane = 3, .spawnTime = 110.708f},
        {.lane = 3, .spawnTime = 111.287f},
        {.lane = 2, .spawnTime = 111.550f},
        {.lane = 1, .spawnTime = 111.808f},
        {.lane = 2, .spawnTime = 112.088f},
        {.lane = 0, .spawnTime = 112.368f},
        {.lane = 2, .spawnTime = 112.636f},
        {.lane = 0, .spawnTime = 112.926f},
        {.lane = 2, .spawnTime = 113.177f},
        {.lane = 0, .spawnTime = 113.406f},
        {.lane = 2, .spawnTime = 113.680f},
        {.lane = 3, .spawnTime = 113.932f},
        {.lane = 3, .spawnTime = 114.432f},
        {.lane = 2, .spawnTime = 114.675f},
        {.lane = 2, .spawnTime = 115.235f},
        {.lane = 1, .spawnTime = 115.518f},
        {.lane = 1, .spawnTime = 116.066f},
        {.lane = 3, .spawnTime = 116.295f},
        {.lane = 1, .spawnTime = 116.810f},
        {.lane = 4, .spawnTime = 117.065f},
        {.lane = 2, .spawnTime = 117.602f},
        {.lane = 3, .spawnTime = 117.846f},
        {.lane = 2, .spawnTime = 118.112f},
        {.lane = 1, .spawnTime = 118.378f},
        {.lane = 0, .spawnTime = 118.649f},
        {.lane = 2, .spawnTime = 118.951f},
        {.lane = 0, .spawnTime = 119.234f},
        {.lane = 2, .spawnTime = 119.495f},
        {.lane = 0, .spawnTime = 119.732f},
        {.lane = 2, .spawnTime = 119.945f},
        {.lane = 3, .spawnTime = 120.249f},
        {.lane = 3, .spawnTime = 120.732f},
        {.lane = 2, .spawnTime = 121.021f},
        {.lane = 2, .spawnTime = 121.594f},
        {.lane = 1, .spawnTime = 121.815f},
        {.lane = 1, .spawnTime = 122.373f},
        {.lane = 4, .spawnTime = 122.586f},
        {.lane = 4, .spawnTime = 123.165f},
        {.lane = 3, .spawnTime = 123.389f},
        {.lane = 3, .spawnTime = 123.978f},
        {.lane = 2, .spawnTime = 124.232f},
        {.lane = 1, .spawnTime = 124.481f},
        {.lane = 2, .spawnTime = 124.738f},
        {.lane = 0, .spawnTime = 125.008f},
        {.lane = 0, .spawnTime = 125.413f},
        {.lane = 0, .spawnTime = 125.793f},
        {.lane = 0, .spawnTime = 126.043f},
        {.lane = 0, .spawnTime = 126.291f},
        {.lane = 0, .spawnTime = 126.578f},
        {.lane = 0, .spawnTime = 126.977f},
        {.lane = 0, .spawnTime = 127.428f},
        {.lane = 0, .spawnTime = 127.674f},
        {.lane = 0, .spawnTime = 127.915f},
        {.lane = 1, .spawnTime = 128.202f},
        {.lane = 1, .spawnTime = 128.618f},
        {.lane = 1, .spawnTime = 129.075f},
        {.lane = 1, .spawnTime = 129.251f},
        {.lane = 1, .spawnTime = 129.510f},
        {.lane = 1, .spawnTime = 129.801f},
        {.lane = 1, .spawnTime = 130.217f},
        {.lane = 1, .spawnTime = 130.642f},
        {.lane = 1, .spawnTime = 130.906f},
        {.lane = 1, .spawnTime = 131.146f},
        {.lane = 0, .spawnTime = 131.400f},
        {.lane = 0, .spawnTime = 131.834f},
        {.lane = 0, .spawnTime = 132.222f},
        {.lane = 0, .spawnTime = 132.501f},
        {.lane = 0, .spawnTime = 132.718f},
        {.lane = 0, .spawnTime = 132.967f},
        {.lane = 0, .spawnTime = 133.349f},
        {.lane = 0, .spawnTime = 133.756f},
        {.lane = 0, .spawnTime = 134.003f},
        {.lane = 0, .spawnTime = 134.241f},
        {.lane = 1, .spawnTime = 134.563f},
        {.lane = 1, .spawnTime = 134.979f},
        {.lane = 1, .spawnTime = 135.382f},
        {.lane = 1, .spawnTime = 135.598f},
        {.lane = 1, .spawnTime = 135.839f},
        {.lane = 1, .spawnTime = 136.137f},
        {.lane = 1, .spawnTime = 136.503f},
        {.lane = 1, .spawnTime = 136.899f},
        {.lane = 1, .spawnTime = 137.129f},
        {.lane = 1, .spawnTime = 137.346f},
        {.lane = 0, .spawnTime = 137.661f},
        {.lane = 1, .spawnTime = 137.661f},
        {.lane = 3, .spawnTime = 139.203f},
        {.lane = 2, .spawnTime = 139.447f},
        {.lane = 0, .spawnTime = 139.717f},
        {.lane = 1, .spawnTime = 139.717f},
        {.lane = 2, .spawnTime = 140.588f},
        {.lane = 4, .spawnTime = 140.588f},
        {.lane = 4, .spawnTime = 141.337f},
        {.lane = 2, .spawnTime = 141.337f},
        {.lane = 4, .spawnTime = 141.626f},
        {.lane = 2, .spawnTime = 141.626f},
        {.lane = 4, .spawnTime = 141.868f},
        {.lane = 2, .spawnTime = 141.868f},
        {.lane = 3, .spawnTime = 142.147f},
        {.lane = 1, .spawnTime = 142.147f},
        {.lane = 3, .spawnTime = 142.911f},
        {.lane = 1, .spawnTime = 142.911f},
        {.lane = 3, .spawnTime = 143.222f},
        {.lane = 1, .spawnTime = 143.222f},
        {.lane = 1, .spawnTime = 143.411f},
        {.lane = 3, .spawnTime = 143.411f},
        {.lane = 0, .spawnTime = 143.653f},
        {.lane = 1, .spawnTime = 143.653f},
        {.lane = 3, .spawnTime = 145.245f},
        {.lane = 2, .spawnTime = 145.483f},
        {.lane = 1, .spawnTime = 145.777f},
        {.lane = 0, .spawnTime = 145.777f},
        {.lane = 2, .spawnTime = 146.634f},
        {.lane = 4, .spawnTime = 146.634f},
        {.lane = 4, .spawnTime = 147.406f},
        {.lane = 2, .spawnTime = 147.406f},
        {.lane = 2, .spawnTime = 147.682f},
        {.lane = 4, .spawnTime = 147.682f},
        {.lane = 4, .spawnTime = 147.926f},
        {.lane = 2, .spawnTime = 147.926f},
        {.lane = 3, .spawnTime = 148.235f},
        {.lane = 1, .spawnTime = 148.235f},
        {.lane = 3, .spawnTime = 148.969f},
        {.lane = 1, .spawnTime = 148.969f},
        {.lane = 1, .spawnTime = 149.203f},
        {.lane = 3, .spawnTime = 149.241f},
        {.lane = 3, .spawnTime = 149.455f},
        {.lane = 1, .spawnTime = 149.455f},
        {.lane = 3, .spawnTime = 149.690f},
        {.lane = 2, .spawnTime = 149.947f},
        {.lane = 0, .spawnTime = 150.207f},
        {.lane = 3, .spawnTime = 150.443f},
        {.lane = 2, .spawnTime = 150.692f},
        {.lane = 0, .spawnTime = 150.972f},
        {.lane = 3, .spawnTime = 151.203f},
        {.lane = 2, .spawnTime = 151.429f},
        {.lane = 0, .spawnTime = 151.688f},
        {.lane = 3, .spawnTime = 151.883f},
        {.lane = 2, .spawnTime = 152.109f},
        {.lane = 0, .spawnTime = 152.362f},
        {.lane = 4, .spawnTime = 152.586f},
        {.lane = 2, .spawnTime = 152.586f},
        {.lane = 2, .spawnTime = 153.377f},
        {.lane = 4, .spawnTime = 153.377f},
        {.lane = 4, .spawnTime = 153.635f},
        {.lane = 2, .spawnTime = 153.635f},
        {.lane = 4, .spawnTime = 153.883f},
        {.lane = 2, .spawnTime = 153.883f},
        {.lane = 3, .spawnTime = 154.182f},
        {.lane = 1, .spawnTime = 154.182f},
        {.lane = 3, .spawnTime = 154.913f},
        {.lane = 1, .spawnTime = 154.913f},
        {.lane = 3, .spawnTime = 155.204f},
        {.lane = 1, .spawnTime = 155.204f},
        {.lane = 3, .spawnTime = 155.416f},
        {.lane = 1, .spawnTime = 155.416f},
        {.lane = 0, .spawnTime = 155.669f},
        {.lane = 1, .spawnTime = 155.669f},
        {.lane = 3, .spawnTime = 157.156f},
        {.lane = 2, .spawnTime = 157.392f},
        {.lane = 0, .spawnTime = 157.654f},
        {.lane = 1, .spawnTime = 157.653f},
        {.lane = 2, .spawnTime = 158.604f},
        {.lane = 4, .spawnTime = 158.604f},
        {.lane = 4, .spawnTime = 159.314f},
        {.lane = 2, .spawnTime = 159.314f},
        {.lane = 2, .spawnTime = 159.584f},
        {.lane = 4, .spawnTime = 159.584f},
        {.lane = 4, .spawnTime = 159.820f},
        {.lane = 2, .spawnTime = 159.820f},
        {.lane = 3, .spawnTime = 160.146f},
        {.lane = 1, .spawnTime = 160.146f},
        {.lane = 3, .spawnTime = 160.522f},
        {.lane = 1, .spawnTime = 160.532f},
        {.lane = 3, .spawnTime = 160.882f},
        {.lane = 1, .spawnTime = 160.882f},
        {.lane = 1, .spawnTime = 161.174f},
        {.lane = 3, .spawnTime = 161.174f},
        {.lane = 3, .spawnTime = 161.386f},
        {.lane = 1, .spawnTime = 161.415f},
        {.lane = 2, .spawnTime = 161.650f},
        {.lane = 2, .spawnTime = 161.992f},
        {.lane = 4, .spawnTime = 162.314f},
        {.lane = 3, .spawnTime = 162.686f},
        {.lane = 2, .spawnTime = 163.060f},
        {.lane = 2, .spawnTime = 163.356f},
        {.lane = 4, .spawnTime = 163.707f},
        {.lane = 3, .spawnTime = 164.045f},
        {.lane = 2, .spawnTime = 164.437f},
        {.lane = 2, .spawnTime = 164.770f},
        {.lane = 4, .spawnTime = 165.099f},
        {.lane = 3, .spawnTime = 165.485f},
        {.lane = 2, .spawnTime = 165.843f},
        {.lane = 2, .spawnTime = 166.138f},
        {.lane = 4, .spawnTime = 166.528f},
        {.lane = 3, .spawnTime = 166.943f},

        {.lane = -1}
};

Note Sandman[CHART_SIZE] = {
        {.lane = 0, .spawnTime = 1.471f},
        {.lane = 3, .spawnTime = 1.933f},
        {.lane = 4, .spawnTime = 2.177f},
        {.lane = 2, .spawnTime = 2.431f},
        {.lane = 1, .spawnTime = 2.648f},
        {.lane = 3, .spawnTime = 3.165f},
        {.lane = 0, .spawnTime = 3.418f},
        {.lane = 3, .spawnTime = 3.901f},
        {.lane = 4, .spawnTime = 4.141f},
        {.lane = 2, .spawnTime = 4.435f},
        {.lane = 1, .spawnTime = 4.684f},
        {.lane = 3, .spawnTime = 5.191f},
        {.lane = 0, .spawnTime = 5.467f},
        {.lane = 3, .spawnTime = 5.972f},
        {.lane = 4, .spawnTime = 6.203f},
        {.lane = 2, .spawnTime = 6.480f},
        {.lane = 1, .spawnTime = 6.742f},
        {.lane = 3, .spawnTime = 7.199f},
        {.lane = 0, .spawnTime = 7.464f},
        {.lane = 3, .spawnTime = 7.949f},
        {.lane = 4, .spawnTime = 8.182f},
        {.lane = 2, .spawnTime = 8.460f},
        {.lane = 1, .spawnTime = 8.731f},
        {.lane = 3, .spawnTime = 9.218f},
        {.lane = 0, .spawnTime = 9.445f},
        {.lane = 3, .spawnTime = 9.899f},
        {.lane = 4, .spawnTime = 10.148f},
        {.lane = 2, .spawnTime = 10.427f},
        {.lane = 1, .spawnTime = 10.699f},
        {.lane = 3, .spawnTime = 11.157f},
        {.lane = 0, .spawnTime = 11.429f},
        {.lane = 3, .spawnTime = 11.929f},
        {.lane = 4, .spawnTime = 12.169f},
        {.lane = 2, .spawnTime = 12.451f},
        {.lane = 1, .spawnTime = 12.700f},
        {.lane = 3, .spawnTime = 13.179f},
        {.lane = 0, .spawnTime = 13.428f},
        {.lane = 3, .spawnTime = 13.927f},
        {.lane = 4, .spawnTime = 14.181f},
        {.lane = 2, .spawnTime = 14.459f},
        {.lane = 1, .spawnTime = 14.703f},
        {.lane = 3, .spawnTime = 15.202f},
        {.lane = 0, .spawnTime = 15.422f},
        {.lane = 3, .spawnTime = 15.892f},
        {.lane = 4, .spawnTime = 16.152f},
        {.lane = 2, .spawnTime = 16.422f},
        {.lane = 1, .spawnTime = 16.695f},
        {.lane = 3, .spawnTime = 17.163f},
        {.lane = 0, .spawnTime = 17.426f},
        {.lane = 3, .spawnTime = 17.900f},
        {.lane = 4, .spawnTime = 18.154f},
        {.lane = 2, .spawnTime = 18.414f},
        {.lane = 1, .spawnTime = 18.696f},
        {.lane = 3, .spawnTime = 19.169f},
        {.lane = 0, .spawnTime = 19.390f},
        {.lane = 3, .spawnTime = 19.855f},
        {.lane = 4, .spawnTime = 20.075f},
        {.lane = 2, .spawnTime = 20.323f},
        {.lane = 1, .spawnTime = 20.617f},
        {.lane = 3, .spawnTime = 21.094f},
        {.lane = 0, .spawnTime = 21.326f},
        {.lane = 3, .spawnTime = 21.805f},
        {.lane = 4, .spawnTime = 22.036f},
        {.lane = 2, .spawnTime = 22.298f},
        {.lane = 1, .spawnTime = 22.553f},
        {.lane = 3, .spawnTime = 23.014f},
        {.lane = 0, .spawnTime = 23.272f},
        {.lane = 3, .spawnTime = 23.730f},
        {.lane = 4, .spawnTime = 23.975f},
        {.lane = 2, .spawnTime = 24.247f},
        {.lane = 1, .spawnTime = 24.528f},
        {.lane = 3, .spawnTime = 24.978f},
        {.lane = 2, .spawnTime = 25.217f},
        {.lane = 0, .spawnTime = 25.217f},
        {.lane = 0, .spawnTime = 25.676f},
        {.lane = 0, .spawnTime = 25.952f},
        {.lane = 0, .spawnTime = 26.205f},
        {.lane = 0, .spawnTime = 26.440f},
        {.lane = 0, .spawnTime = 26.688f},
        {.lane = 0, .spawnTime = 26.913f},
        {.lane = 3, .spawnTime = 27.146f},
        {.lane = 4, .spawnTime = 27.236f},
        {.lane = 0, .spawnTime = 27.445f},
        {.lane = 0, .spawnTime = 27.712f},
        {.lane = 0, .spawnTime = 27.945f},
        {.lane = 0, .spawnTime = 28.200f},
        {.lane = 0, .spawnTime = 28.444f},
        {.lane = 0, .spawnTime = 28.725f},
        {.lane = 0, .spawnTime = 28.919f},
        {.lane = 3, .spawnTime = 29.110f},
        {.lane = 4, .spawnTime = 29.166f},
        {.lane = 0, .spawnTime = 29.403f},
        {.lane = 0, .spawnTime = 29.689f},
        {.lane = 0, .spawnTime = 29.899f},
        {.lane = 0, .spawnTime = 30.133f},
        {.lane = 0, .spawnTime = 30.383f},
        {.lane = 0, .spawnTime = 30.604f},
        {.lane = 0, .spawnTime = 30.845f},
        {.lane = 3, .spawnTime = 31.063f},
        {.lane = 4, .spawnTime = 31.117f},
        {.lane = 0, .spawnTime = 31.350f},
        {.lane = 0, .spawnTime = 31.621f},
        {.lane = 0, .spawnTime = 31.847f},
        {.lane = 0, .spawnTime = 32.093f},
        {.lane = 0, .spawnTime = 32.349f},
        {.lane = 0, .spawnTime = 32.577f},
        {.lane = 0, .spawnTime = 32.802f},
        {.lane = 3, .spawnTime = 33.045f},
        {.lane = 4, .spawnTime = 33.093f},
        {.lane = 0, .spawnTime = 33.325f},
        {.lane = 0, .spawnTime = 33.531f},
        {.lane = 3, .spawnTime = 33.763f},
        {.lane = 4, .spawnTime = 33.780f},
        {.lane = 3, .spawnTime = 34.059f},
        {.lane = 2, .spawnTime = 34.059f},
        {.lane = 0, .spawnTime = 34.295f},
        {.lane = 1, .spawnTime = 34.979f},
        {.lane = 2, .spawnTime = 34.979f},
        {.lane = 0, .spawnTime = 35.352f},
        {.lane = 3, .spawnTime = 35.698f},
        {.lane = 4, .spawnTime = 35.765f},
        {.lane = 2, .spawnTime = 35.979f},
        {.lane = 0, .spawnTime = 36.188f},
        {.lane = 0, .spawnTime = 36.470f},
        {.lane = 0, .spawnTime = 36.704f},
        {.lane = 2, .spawnTime = 36.951f},
        {.lane = 1, .spawnTime = 36.951f},
        {.lane = 0, .spawnTime = 37.220f},
        {.lane = 0, .spawnTime = 37.396f},
        {.lane = 3, .spawnTime = 37.634f},
        {.lane = 4, .spawnTime = 37.710f},
        {.lane = 2, .spawnTime = 37.956f},
        {.lane = 0, .spawnTime = 38.167f},
        {.lane = 0, .spawnTime = 38.443f},
        {.lane = 0, .spawnTime = 38.648f},
        {.lane = 1, .spawnTime = 38.905f},
        {.lane = 2, .spawnTime = 38.905f},
        {.lane = 0, .spawnTime = 39.160f},
        {.lane = 0, .spawnTime = 39.359f},
        {.lane = 3, .spawnTime = 39.566f},
        {.lane = 4, .spawnTime = 39.637f},
        {.lane = 2, .spawnTime = 39.911f},
        {.lane = 0, .spawnTime = 40.115f},
        {.lane = 0, .spawnTime = 40.405f},
        {.lane = 0, .spawnTime = 40.610f},
        {.lane = 1, .spawnTime = 40.890f},
        {.lane = 2, .spawnTime = 40.890f},
        {.lane = 0, .spawnTime = 41.140f},
        {.lane = 0, .spawnTime = 41.337f},
        {.lane = 3, .spawnTime = 41.552f},
        {.lane = 4, .spawnTime = 41.610f},
        {.lane = 2, .spawnTime = 41.866f},
        {.lane = 1, .spawnTime = 42.057f},
        {.lane = 0, .spawnTime = 42.311f},
        {.lane = 0, .spawnTime = 42.547f},
        {.lane = 1, .spawnTime = 42.820f},
        {.lane = 2, .spawnTime = 42.820f},
        {.lane = 0, .spawnTime = 43.083f},
        {.lane = 0, .spawnTime = 43.298f},
        {.lane = 3, .spawnTime = 43.514f},
        {.lane = 4, .spawnTime = 43.592f},
        {.lane = 2, .spawnTime = 43.823f},
        {.lane = 1, .spawnTime = 44.006f},
        {.lane = 0, .spawnTime = 44.299f},
        {.lane = 0, .spawnTime = 44.518f},
        {.lane = 1, .spawnTime = 44.788f},
        {.lane = 2, .spawnTime = 44.788f},
        {.lane = 0, .spawnTime = 45.018f},
        {.lane = 0, .spawnTime = 45.226f},
        {.lane = 3, .spawnTime = 45.429f},
        {.lane = 4, .spawnTime = 45.502f},
        {.lane = 2, .spawnTime = 45.775f},
        {.lane = 1, .spawnTime = 45.987f},
        {.lane = 0, .spawnTime = 46.192f},
        {.lane = 0, .spawnTime = 46.429f},
        {.lane = 1, .spawnTime = 46.727f},
        {.lane = 2, .spawnTime = 46.727f},
        {.lane = 0, .spawnTime = 46.976f},
        {.lane = 0, .spawnTime = 47.173f},
        {.lane = 3, .spawnTime = 47.406f},
        {.lane = 4, .spawnTime = 47.470f},
        {.lane = 2, .spawnTime = 47.742f},
        {.lane = 1, .spawnTime = 47.959f},
        {.lane = 0, .spawnTime = 48.216f},
        {.lane = 0, .spawnTime = 48.454f},
        {.lane = 1, .spawnTime = 48.730f},
        {.lane = 2, .spawnTime = 48.730f},
        {.lane = 0, .spawnTime = 48.993f},
        {.lane = 0, .spawnTime = 49.185f},
        {.lane = 3, .spawnTime = 49.418f},
        {.lane = 4, .spawnTime = 49.486f},
        {.lane = 2, .spawnTime = 49.725f},
        {.lane = 1, .spawnTime = 49.930f},
        {.lane = 0, .spawnTime = 50.185f},
        {.lane = 0, .spawnTime = 50.437f},
        {.lane = 2, .spawnTime = 50.689f},
        {.lane = 1, .spawnTime = 50.689f},
        {.lane = 0, .spawnTime = 50.961f},
        {.lane = 0, .spawnTime = 51.156f},
        {.lane = 3, .spawnTime = 51.333f},
        {.lane = 4, .spawnTime = 51.436f},
        {.lane = 2, .spawnTime = 51.639f},
        {.lane = 1, .spawnTime = 51.843f},
        {.lane = 0, .spawnTime = 52.096f},
        {.lane = 0, .spawnTime = 52.368f},
        {.lane = 1, .spawnTime = 52.617f},
        {.lane = 2, .spawnTime = 52.617f},
        {.lane = 0, .spawnTime = 52.885f},
        {.lane = 0, .spawnTime = 53.073f},
        {.lane = 3, .spawnTime = 53.295f},
        {.lane = 4, .spawnTime = 53.377f},
        {.lane = 2, .spawnTime = 53.624f},
        {.lane = 1, .spawnTime = 53.815f},
        {.lane = 0, .spawnTime = 54.092f},
        {.lane = 0, .spawnTime = 54.327f},
        {.lane = 1, .spawnTime = 54.602f},
        {.lane = 2, .spawnTime = 54.602f},
        {.lane = 0, .spawnTime = 54.852f},
        {.lane = 0, .spawnTime = 55.030f},
        {.lane = 3, .spawnTime = 55.244f},
        {.lane = 4, .spawnTime = 55.322f},
        {.lane = 2, .spawnTime = 55.560f},
        {.lane = 1, .spawnTime = 55.724f},
        {.lane = 0, .spawnTime = 55.935f},
        {.lane = 0, .spawnTime = 56.193f},
        {.lane = 2, .spawnTime = 56.529f},
        {.lane = 0, .spawnTime = 56.529f},
        {.lane = 0, .spawnTime = 56.998f},
        {.lane = 3, .spawnTime = 57.230f},
        {.lane = 4, .spawnTime = 57.282f},
        {.lane = 2, .spawnTime = 57.536f},
        {.lane = 1, .spawnTime = 57.771f},
        {.lane = 0, .spawnTime = 58.231f},
        {.lane = 2, .spawnTime = 58.498f},
        {.lane = 0, .spawnTime = 58.498f},
        {.lane = 0, .spawnTime = 58.940f},
        {.lane = 3, .spawnTime = 59.162f},
        {.lane = 4, .spawnTime = 59.249f},
        {.lane = 2, .spawnTime = 59.449f},
        {.lane = 1, .spawnTime = 59.701f},
        {.lane = 0, .spawnTime = 60.153f},
        {.lane = 2, .spawnTime = 60.425f},
        {.lane = 0, .spawnTime = 60.425f},
        {.lane = 0, .spawnTime = 60.851f},
        {.lane = 3, .spawnTime = 61.096f},
        {.lane = 4, .spawnTime = 61.139f},
        {.lane = 2, .spawnTime = 61.426f},
        {.lane = 1, .spawnTime = 61.620f},
        {.lane = 0, .spawnTime = 62.053f},
        {.lane = 3, .spawnTime = 62.300f},
        {.lane = 2, .spawnTime = 62.300f},
        {.lane = 0, .spawnTime = 62.795f},
        {.lane = 2, .spawnTime = 62.795f},
        {.lane = 1, .spawnTime = 63.024f},
        {.lane = 2, .spawnTime = 63.024f},
        {.lane = 0, .spawnTime = 63.275f},
        {.lane = 2, .spawnTime = 63.275f},
        {.lane = 1, .spawnTime = 63.491f},
        {.lane = 2, .spawnTime = 63.491f},
        {.lane = 3, .spawnTime = 63.761f},
        {.lane = 2, .spawnTime = 63.761f},
        {.lane = 1, .spawnTime = 64.055f},
        {.lane = 2, .spawnTime = 64.265f},
        {.lane = 0, .spawnTime = 64.265f},
        {.lane = 0, .spawnTime = 64.811f},
        {.lane = 3, .spawnTime = 64.909f},
        {.lane = 4, .spawnTime = 64.983f},
        {.lane = 2, .spawnTime = 65.228f},
        {.lane = 1, .spawnTime = 65.463f},
        {.lane = 0, .spawnTime = 65.920f},
        {.lane = 0, .spawnTime = 66.214f},
        {.lane = 2, .spawnTime = 66.214f},
        {.lane = 0, .spawnTime = 66.649f},
        {.lane = 3, .spawnTime = 66.821f},
        {.lane = 4, .spawnTime = 66.881f},
        {.lane = 2, .spawnTime = 67.169f},
        {.lane = 1, .spawnTime = 67.383f},
        {.lane = 0, .spawnTime = 67.846f},
        {.lane = 2, .spawnTime = 68.119f},
        {.lane = 0, .spawnTime = 68.119f},
        {.lane = 0, .spawnTime = 68.550f},
        {.lane = 3, .spawnTime = 68.756f},
        {.lane = 4, .spawnTime = 68.815f},
        {.lane = 2, .spawnTime = 69.091f},
        {.lane = 1, .spawnTime = 69.295f},
        {.lane = 0, .spawnTime = 69.725f},
        {.lane = 2, .spawnTime = 69.989f},
        {.lane = 3, .spawnTime = 69.989f},
        {.lane = 0, .spawnTime = 70.448f},
        {.lane = 2, .spawnTime = 70.448f},
        {.lane = 1, .spawnTime = 70.690f},
        {.lane = 2, .spawnTime = 70.690f},
        {.lane = 0, .spawnTime = 70.936f},
        {.lane = 2, .spawnTime = 71.936f},
        {.lane = 1, .spawnTime = 71.173f},
        {.lane = 2, .spawnTime = 71.173f},
        {.lane = 2, .spawnTime = 71.469f},
        {.lane = 3, .spawnTime = 71.469f},
        {.lane = 1, .spawnTime = 71.740f},
        {.lane = 2, .spawnTime = 71.740f},
        {.lane = 0, .spawnTime = 71.991f},
        {.lane = 2, .spawnTime = 72.991f},
        {.lane = 0, .spawnTime = 72.561f},
        {.lane = 0, .spawnTime = 72.794f},
        {.lane = 0, .spawnTime = 73.037f},
        {.lane = 0, .spawnTime = 73.263f},
        {.lane = 0, .spawnTime = 73.493f},
        {.lane = 0, .spawnTime = 73.684f},
        {.lane = 2, .spawnTime = 73.909f},
        {.lane = 1, .spawnTime = 73.909f},
        {.lane = 0, .spawnTime = 74.147f},
        {.lane = 0, .spawnTime = 74.416f},
        {.lane = 0, .spawnTime = 74.673f},
        {.lane = 0, .spawnTime = 74.901f},
        {.lane = 0, .spawnTime = 75.149f},
        {.lane = 0, .spawnTime = 75.372f},
        {.lane = 0, .spawnTime = 75.605f},
        {.lane = 1, .spawnTime = 75.828f},
        {.lane = 2, .spawnTime = 75.828f},
        {.lane = 0, .spawnTime = 76.054f},
        {.lane = 0, .spawnTime = 76.327f},
        {.lane = 0, .spawnTime = 76.570f},
        {.lane = 0, .spawnTime = 76.825f},
        {.lane = 0, .spawnTime = 77.057f},
        {.lane = 0, .spawnTime = 77.292f},
        {.lane = 0, .spawnTime = 77.507f},
        {.lane = 2, .spawnTime = 77.756f},
        {.lane = 3, .spawnTime = 77.756f},
        {.lane = 0, .spawnTime = 78.185f},
        {.lane = 2, .spawnTime = 78.185f},
        {.lane = 1, .spawnTime = 78.409f},
        {.lane = 2, .spawnTime = 78.409f},
        {.lane = 0, .spawnTime = 78.613f},
        {.lane = 2, .spawnTime = 78.613f},
        {.lane = 1, .spawnTime = 78.871f},
        {.lane = 2, .spawnTime = 78.871f},
        {.lane = 2, .spawnTime = 79.155f},
        {.lane = 3, .spawnTime = 79.155f},
        {.lane = 2, .spawnTime = 79.400f},
        {.lane = 1, .spawnTime = 79.400f},
        {.lane = 2, .spawnTime = 79.625f},
        {.lane = 0, .spawnTime = 79.625f},
        {.lane = 0, .spawnTime = 80.104f},
        {.lane = 0, .spawnTime = 80.378f},
        {.lane = 0, .spawnTime = 80.639f},
        {.lane = 0, .spawnTime = 80.919f},
        {.lane = 0, .spawnTime = 81.137f},
        {.lane = 0, .spawnTime = 81.343f},
        {.lane = 2, .spawnTime = 81.597f},
        {.lane = 1, .spawnTime = 81.597f},
        {.lane = 0, .spawnTime = 81.845f},
        {.lane = 0, .spawnTime = 82.114f},
        {.lane = 0, .spawnTime = 82.372f},
        {.lane = 0, .spawnTime = 82.595f},
        {.lane = 0, .spawnTime = 82.838f},
        {.lane = 0, .spawnTime = 83.069f},
        {.lane = 0, .spawnTime = 83.263f},
        {.lane = 2, .spawnTime = 83.543f},
        {.lane = 1, .spawnTime = 83.543f},
        {.lane = 0, .spawnTime = 83.769f},
        {.lane = 0, .spawnTime = 84.041f},
        {.lane = 0, .spawnTime = 84.272f},
        {.lane = 0, .spawnTime = 84.507f},
        {.lane = 0, .spawnTime = 84.778f},
        {.lane = 0, .spawnTime = 85.015f},
        {.lane = 0, .spawnTime = 85.221f},
        {.lane = 3, .spawnTime = 85.483f},
        {.lane = 2, .spawnTime = 85.483f},
        {.lane = 0, .spawnTime = 85.891f},
        {.lane = 2, .spawnTime = 85.891f},
        {.lane = 1, .spawnTime = 86.108f},
        {.lane = 2, .spawnTime = 86.108f},
        {.lane = 0, .spawnTime = 86.335f},
        {.lane = 2, .spawnTime = 86.335f},
        {.lane = 1, .spawnTime = 86.569f},
        {.lane = 2, .spawnTime = 86.569f},
        {.lane = 2, .spawnTime = 86.875f},
        {.lane = 3, .spawnTime = 86.875f},
        {.lane = 3, .spawnTime = 87.167f},
        {.lane = 1, .spawnTime = 87.167f},
        {.lane = 1, .spawnTime = 87.444f},
        {.lane = 3, .spawnTime = 87.444f},
        {.lane = 3, .spawnTime = 87.925f},
        {.lane = 4, .spawnTime = 88.120f},
        {.lane = 3, .spawnTime = 88.339f},
        {.lane = 2, .spawnTime = 88.553f},
        {.lane = 3, .spawnTime = 89.019f},
        {.lane = 1, .spawnTime = 89.299f},
        {.lane = 3, .spawnTime = 89.735f},
        {.lane = 4, .spawnTime = 89.990f},
        {.lane = 3, .spawnTime = 90.240f},
        {.lane = 2, .spawnTime = 90.509f},
        {.lane = 3, .spawnTime = 91.002f},
        {.lane = 1, .spawnTime = 91.273f},
        {.lane = 3, .spawnTime = 91.700f},
        {.lane = 4, .spawnTime = 91.934f},
        {.lane = 3, .spawnTime = 92.164f},
        {.lane = 2, .spawnTime = 92.442f},
        {.lane = 3, .spawnTime = 92.920f},
        {.lane = 1, .spawnTime = 93.158f},
        {.lane = 3, .spawnTime = 93.620f},
        {.lane = 4, .spawnTime = 93.859f},
        {.lane = 3, .spawnTime = 94.095f},
        {.lane = 2, .spawnTime = 94.363f},
        {.lane = 3, .spawnTime = 94.824f},
        {.lane = 1, .spawnTime = 95.270f},
        {.lane = 3, .spawnTime = 95.270f},
        {.lane = 4, .spawnTime = 95.983f},
        {.lane = 3, .spawnTime = 95.983f},
        {.lane = 3, .spawnTime = 96.215f},
        {.lane = 1, .spawnTime = 96.992f},
        {.lane = 3, .spawnTime = 96.992f},
        {.lane = 4, .spawnTime = 97.942f},
        {.lane = 3, .spawnTime = 97.942f},
        {.lane = 3, .spawnTime = 98.179f},
        {.lane = 2, .spawnTime = 98.179f},
        {.lane = 1, .spawnTime = 98.933f},
        {.lane = 3, .spawnTime = 98.933f},
        {.lane = 4, .spawnTime = 99.889f},
        {.lane = 3, .spawnTime = 99.889f},
        {.lane = 3, .spawnTime = 100.117f},
        {.lane = 2, .spawnTime = 100.117f},
        {.lane = 0, .spawnTime = 100.856f},
        {.lane = 2, .spawnTime = 100.856f},
        {.lane = 0, .spawnTime = 101.353f},
        {.lane = 2, .spawnTime = 101.593f},
        {.lane = 0, .spawnTime = 101.823f},
        {.lane = 3, .spawnTime = 102.067f},
        {.lane = 0, .spawnTime = 102.305f},
        {.lane = 4, .spawnTime = 102.515f},
        {.lane = 2, .spawnTime = 102.750f},
        {.lane = 3, .spawnTime = 103.010f},
        {.lane = 1, .spawnTime = 103.010f},
        {.lane = 4, .spawnTime = 103.672f},
        {.lane = 3, .spawnTime = 103.672f},
        {.lane = 2, .spawnTime = 103.894f},
        {.lane = 0, .spawnTime = 104.652f},
        {.lane = 2, .spawnTime = 104.652f},
        {.lane = 0, .spawnTime = 105.181f},
        {.lane = 1, .spawnTime = 105.418f},
        {.lane = 0, .spawnTime = 105.647f},
        {.lane = 2, .spawnTime = 105.883f},
        {.lane = 0, .spawnTime = 106.140f},
        {.lane = 3, .spawnTime = 106.380f},
        {.lane = 0, .spawnTime = 106.553f},
        {.lane = 3, .spawnTime = 106.853f},
        {.lane = 2, .spawnTime = 106.853f},
        {.lane = 0, .spawnTime = 106.926f},
        {.lane = 2, .spawnTime = 107.093f},
        {.lane = 1, .spawnTime = 107.093f},
        {.lane = 2, .spawnTime = 107.331f},
        {.lane = 0, .spawnTime = 107.331f},
        {.lane = 2, .spawnTime = 107.680f},
        {.lane = 1, .spawnTime = 107.680f},
        {.lane = 2, .spawnTime = 108.021f},
        {.lane = 3, .spawnTime = 108.021f},
        {.lane = 2, .spawnTime = 108.228f},
        {.lane = 3, .spawnTime = 108.228f},
        {.lane = 2, .spawnTime = 108.541f},
        {.lane = 0, .spawnTime = 108.541f},
        {.lane = 0, .spawnTime = 109.059f},
        {.lane = 3, .spawnTime = 109.236f},
        {.lane = 4, .spawnTime = 109.396f},
        {.lane = 2, .spawnTime = 109.603f},
        {.lane = 1, .spawnTime = 109.808f},
        {.lane = 0, .spawnTime = 110.276f},
        {.lane = 2, .spawnTime = 110.555f},
        {.lane = 0, .spawnTime = 110.555f},
        {.lane = 0, .spawnTime = 110.967f},
        {.lane = 3, .spawnTime = 111.202f},
        {.lane = 4, .spawnTime = 111.279f},
        {.lane = 2, .spawnTime = 111.549f},
        {.lane = 1, .spawnTime = 111.702f},
        {.lane = 0, .spawnTime = 112.256f},
        {.lane = 2, .spawnTime = 112.491f},
        {.lane = 0, .spawnTime = 112.491f},
        {.lane = 3, .spawnTime = 113.120f},
        {.lane = 4, .spawnTime = 113.179f},
        {.lane = 2, .spawnTime = 113.433f},
        {.lane = 1, .spawnTime = 113.614f},
        {.lane = 0, .spawnTime = 114.070f},
        {.lane = 2, .spawnTime = 114.346f},
        {.lane = 3, .spawnTime = 114.346f},
        {.lane = 0, .spawnTime = 114.777f},
        {.lane = 2, .spawnTime = 114.777f},
        {.lane = 1, .spawnTime = 115.029f},
        {.lane = 2, .spawnTime = 115.029f},
        {.lane = 0, .spawnTime = 115.239f},
        {.lane = 2, .spawnTime = 115.239f},
        {.lane = 1, .spawnTime = 115.469f},
        {.lane = 2, .spawnTime = 115.469f},
        {.lane = 3, .spawnTime = 115.767f},
        {.lane = 2, .spawnTime = 115.994f},
        {.lane = 1, .spawnTime = 115.994f},
        {.lane = 2, .spawnTime = 116.292f},
        {.lane = 0, .spawnTime = 116.292f},
        {.lane = 0, .spawnTime = 116.763f},
        {.lane = 3, .spawnTime = 116.982f},
        {.lane = 4, .spawnTime = 117.049f},
        {.lane = 2, .spawnTime = 117.298f},
        {.lane = 1, .spawnTime = 117.497f},
        {.lane = 0, .spawnTime = 117.923f},
        {.lane = 2, .spawnTime = 118.273f},
        {.lane = 0, .spawnTime = 118.273f},
        {.lane = 0, .spawnTime = 118.720f},
        {.lane = 3, .spawnTime = 118.911f},
        {.lane = 4, .spawnTime = 118.953f},
        {.lane = 2, .spawnTime = 119.235f},
        {.lane = 1, .spawnTime = 119.440f},
        {.lane = 0, .spawnTime = 119.867f},
        {.lane = 2, .spawnTime = 120.107f},
        {.lane = 3, .spawnTime = 120.107f},
        {.lane = 1, .spawnTime = 120.596f},
        {.lane = 3, .spawnTime = 120.854f},
        {.lane = 4, .spawnTime = 121.079f},
        {.lane = 4, .spawnTime = 121.290f},
        {.lane = 3, .spawnTime = 121.453f},
        {.lane = 2, .spawnTime = 121.568f},
        {.lane = 3, .spawnTime = 121.861f},
        {.lane = 3, .spawnTime = 122.120f},
        {.lane = 4, .spawnTime = 122.120f},
        {.lane = 2, .spawnTime = 122.120f},
        {.lane = 2, .spawnTime = 124.034f},
        {.lane = 3, .spawnTime = 124.034f},

        {.lane = -1}
};

Note TeenSpirit[CHART_SIZE] = {
        {.lane = 0, .spawnTime = 1.177f},
        {.lane = 1, .spawnTime = 1.177f},
        {.lane = 1, .spawnTime = 1.756f},
        {.lane = 0, .spawnTime = 1.756f},
        {.lane = 1, .spawnTime = 2.558f},
        {.lane = 2, .spawnTime = 2.558f},
        {.lane = 1, .spawnTime = 2.859f},
        {.lane = 2, .spawnTime = 2.859f},
        {.lane = 0, .spawnTime = 3.365f},
        {.lane = 2, .spawnTime = 3.365f},
        {.lane = 1, .spawnTime = 3.918f},
        {.lane = 2, .spawnTime = 3.918f},
        {.lane = 1, .spawnTime = 4.788f},
        {.lane = 3, .spawnTime = 4.788f},
        {.lane = 3, .spawnTime = 5.042f},
        {.lane = 1, .spawnTime = 5.042f},
        {.lane = 0, .spawnTime = 5.582f},
        {.lane = 1, .spawnTime = 5.582f},
        {.lane = 0, .spawnTime = 6.096f},
        {.lane = 1, .spawnTime = 6.096f},
        {.lane = 2, .spawnTime = 6.968f},
        {.lane = 1, .spawnTime = 6.968f},
        {.lane = 2, .spawnTime = 7.224f},
        {.lane = 1, .spawnTime = 7.224f},
        {.lane = 2, .spawnTime = 7.772f},
        {.lane = 0, .spawnTime = 7.772f},
        {.lane = 0, .spawnTime = 8.283f},
        {.lane = 2, .spawnTime = 8.283f},
        {.lane = 3, .spawnTime = 9.084f},
        {.lane = 1, .spawnTime = 9.084f},
        {.lane = 3, .spawnTime = 9.353f},
        {.lane = 1, .spawnTime = 9.353f},
        {.lane = 1, .spawnTime = 9.899f},
        {.lane = 0, .spawnTime = 9.899f},
        {.lane = 1, .spawnTime = 10.372f},
        {.lane = 0, .spawnTime = 10.372f},
        {.lane = 1, .spawnTime = 11.189f},
        {.lane = 2, .spawnTime = 11.189f},
        {.lane = 1, .spawnTime = 11.392f},
        {.lane = 2, .spawnTime = 11.392f},
        {.lane = 0, .spawnTime = 11.916f},
        {.lane = 2, .spawnTime = 11.916f},
        {.lane = 0, .spawnTime = 12.455f},
        {.lane = 2, .spawnTime = 12.455f},
        {.lane = 1, .spawnTime = 13.211f},
        {.lane = 3, .spawnTime = 13.211f},
        {.lane = 3, .spawnTime = 13.460f},
        {.lane = 1, .spawnTime = 13.460f},
        {.lane = 0, .spawnTime = 13.975f},
        {.lane = 1, .spawnTime = 13.975f},
        {.lane = 1, .spawnTime = 14.473f},
        {.lane = 0, .spawnTime = 14.473f},
        {.lane = 2, .spawnTime = 15.213f},
        {.lane = 1, .spawnTime = 15.213f},
        {.lane = 1, .spawnTime = 15.459f},
        {.lane = 2, .spawnTime = 15.459f},
        {.lane = 2, .spawnTime = 16.028f},
        {.lane = 0, .spawnTime = 16.028f},
        {.lane = 0, .spawnTime = 16.508f},
        {.lane = 2, .spawnTime = 16.508f},
        {.lane = 1, .spawnTime = 17.264f},
        {.lane = 3, .spawnTime = 17.264f},
        {.lane = 1, .spawnTime = 17.493f},
        {.lane = 3, .spawnTime = 17.493f},
        {.lane = 1, .spawnTime = 18.046f},
        {.lane = 0, .spawnTime = 18.046f},
        {.lane = 1, .spawnTime = 18.514f},
        {.lane = 0, .spawnTime = 18.514f},
        {.lane = 1, .spawnTime = 19.364f},
        {.lane = 2, .spawnTime = 19.364f},
        {.lane = 1, .spawnTime = 19.595f},
        {.lane = 2, .spawnTime = 19.595f},
        {.lane = 0, .spawnTime = 20.101f},
        {.lane = 2, .spawnTime = 20.101f},
        {.lane = 0, .spawnTime = 20.578f},
        {.lane = 2, .spawnTime = 20.578f},
        {.lane = 3, .spawnTime = 21.372f},
        {.lane = 1, .spawnTime = 21.372f},
        {.lane = 1, .spawnTime = 21.623f},
        {.lane = 3, .spawnTime = 21.623f},
        {.lane = 0, .spawnTime = 22.133f},
        {.lane = 1, .spawnTime = 22.133f},
        {.lane = 0, .spawnTime = 22.556f},
        {.lane = 1, .spawnTime = 22.556f},
        {.lane = 1, .spawnTime = 23.409f},
        {.lane = 2, .spawnTime = 23.409f},
        {.lane = 1, .spawnTime = 23.644f},
        {.lane = 2, .spawnTime = 23.644f},
        {.lane = 1, .spawnTime = 24.251f},
        {.lane = 0, .spawnTime = 24.251f},
        {.lane = 0, .spawnTime = 24.642f},
        {.lane = 2, .spawnTime = 24.642f},
        {.lane = 1, .spawnTime = 25.417f},
        {.lane = 3, .spawnTime = 25.417f},
        {.lane = 1, .spawnTime = 25.643f},
        {.lane = 3, .spawnTime = 25.643f},
        {.lane = 2, .spawnTime = 26.689f},
        {.lane = 3, .spawnTime = 26.941f},
        {.lane = 2, .spawnTime = 30.832f},
        {.lane = 3, .spawnTime = 31.130f},
        {.lane = 2, .spawnTime = 35.048f},
        {.lane = 3, .spawnTime = 35.297f},
        {.lane = 3, .spawnTime = 35.905f},
        {.lane = 3, .spawnTime = 36.443f},
        {.lane = 3, .spawnTime = 37.011f},
        {.lane = 3, .spawnTime = 37.419f},
        {.lane = 2, .spawnTime = 39.181f},
        {.lane = 3, .spawnTime = 39.483f},
        {.lane = 3, .spawnTime = 40.111f},
        {.lane = 3, .spawnTime = 40.687f},
        {.lane = 3, .spawnTime = 41.214f},
        {.lane = 3, .spawnTime = 41.677f},
        {.lane = 2, .spawnTime = 43.084f},
        {.lane = 3, .spawnTime = 43.438f},
        {.lane = 3, .spawnTime = 44.063f},
        {.lane = 3, .spawnTime = 44.596f},
        {.lane = 3, .spawnTime = 45.087f},
        {.lane = 3, .spawnTime = 45.574f},
        {.lane = 2, .spawnTime = 47.289f},
        {.lane = 3, .spawnTime = 47.537f},
        {.lane = 3, .spawnTime = 48.103f},
        {.lane = 3, .spawnTime = 48.633f},
        {.lane = 3, .spawnTime = 49.110f},
        {.lane = 3, .spawnTime = 49.531f},
        {.lane = 2, .spawnTime = 50.909f},
        {.lane = 3, .spawnTime = 51.432f},
        {.lane = 2, .spawnTime = 51.942f},
        {.lane = 3, .spawnTime = 52.482f},
        {.lane = 2, .spawnTime = 52.986f},
        {.lane = 3, .spawnTime = 53.542f},
        {.lane = 2, .spawnTime = 54.066f},
        {.lane = 3, .spawnTime = 54.548f},
        {.lane = 2, .spawnTime = 55.080f},
        {.lane = 3, .spawnTime = 55.627f},
        {.lane = 2, .spawnTime = 56.128f},
        {.lane = 3, .spawnTime = 56.639f},
        {.lane = 2, .spawnTime = 57.220f},
        {.lane = 3, .spawnTime = 57.696f},
        {.lane = 2, .spawnTime = 58.243f},
        {.lane = 3, .spawnTime = 58.724f},
        {.lane = 2, .spawnTime = 59.224f},
        {.lane = 3, .spawnTime = 59.728f},
        {.lane = 2, .spawnTime = 60.233f},
        {.lane = 3, .spawnTime = 60.759f},
        {.lane = 2, .spawnTime = 61.245f},
        {.lane = 3, .spawnTime = 61.738f},
        {.lane = 2, .spawnTime = 62.304f},
        {.lane = 3, .spawnTime = 62.801f},
        {.lane = 2, .spawnTime = 63.316f},
        {.lane = 3, .spawnTime = 63.811f},
        {.lane = 2, .spawnTime = 64.327f},
        {.lane = 3, .spawnTime = 64.822f},
        {.lane = 2, .spawnTime = 65.345f},
        {.lane = 0, .spawnTime = 65.867f},
        {.lane = 3, .spawnTime = 66.382f},
        {.lane = 0, .spawnTime = 66.852f},
        {.lane = 1, .spawnTime = 67.386f},
        {.lane = 0, .spawnTime = 67.386f},
        {.lane = 0, .spawnTime = 67.872f},
        {.lane = 1, .spawnTime = 67.872f},
        {.lane = 2, .spawnTime = 68.636f},
        {.lane = 1, .spawnTime = 68.636f},
        {.lane = 1, .spawnTime = 68.856f},
        {.lane = 2, .spawnTime = 68.856f},
        {.lane = 0, .spawnTime = 69.394f},
        {.lane = 2, .spawnTime = 69.394f},
        {.lane = 2, .spawnTime = 69.893f},
        {.lane = 0, .spawnTime = 69.893f},
        {.lane = 3, .spawnTime = 70.697f},
        {.lane = 1, .spawnTime = 70.697f},
        {.lane = 1, .spawnTime = 70.914f},
        {.lane = 3, .spawnTime = 70.914f},
        {.lane = 1, .spawnTime = 71.455f},
        {.lane = 0, .spawnTime = 71.455f},
        {.lane = 1, .spawnTime = 71.956f},
        {.lane = 0, .spawnTime = 71.956f},
        {.lane = 2, .spawnTime = 72.800f},
        {.lane = 1, .spawnTime = 72.800f},
        {.lane = 1, .spawnTime = 73.003f},
        {.lane = 2, .spawnTime = 73.003f},
        {.lane = 2, .spawnTime = 73.539f},
        {.lane = 0, .spawnTime = 73.539f},
        {.lane = 2, .spawnTime = 74.019f},
        {.lane = 0, .spawnTime = 74.019f},
        {.lane = 1, .spawnTime = 74.776f},
        {.lane = 3, .spawnTime = 74.776f},
        {.lane = 1, .spawnTime = 75.004f},
        {.lane = 3, .spawnTime = 75.004f},
        {.lane = 1, .spawnTime = 75.556f},
        {.lane = 0, .spawnTime = 75.556f},
        {.lane = 1, .spawnTime = 76.044f},
        {.lane = 0, .spawnTime = 76.044f},
        {.lane = 1, .spawnTime = 76.858f},
        {.lane = 2, .spawnTime = 76.858f},
        {.lane = 1, .spawnTime = 77.068f},
        {.lane = 2, .spawnTime = 77.068f},
        {.lane = 2, .spawnTime = 77.621f},
        {.lane = 0, .spawnTime = 77.621f},
        {.lane = 2, .spawnTime = 78.104f},
        {.lane = 0, .spawnTime = 78.104f},
        {.lane = 3, .spawnTime = 78.908f},
        {.lane = 1, .spawnTime = 78.908f},
        {.lane = 1, .spawnTime = 79.145f},
        {.lane = 3, .spawnTime = 79.145f},
        {.lane = 0, .spawnTime = 79.666f},
        {.lane = 1, .spawnTime = 79.666f},
        {.lane = 1, .spawnTime = 80.138f},
        {.lane = 0, .spawnTime = 80.138f},
        {.lane = 2, .spawnTime = 80.954f},
        {.lane = 1, .spawnTime = 80.954f},
        {.lane = 1, .spawnTime = 81.174f},
        {.lane = 2, .spawnTime = 81.174f},
        {.lane = 2, .spawnTime = 81.701f},
        {.lane = 0, .spawnTime = 81.701f},
        {.lane = 0, .spawnTime = 82.210f},
        {.lane = 2, .spawnTime = 82.210f},
        {.lane = 3, .spawnTime = 83.050f},
        {.lane = 1, .spawnTime = 83.050f},
        {.lane = 1, .spawnTime = 83.256f},
        {.lane = 3, .spawnTime = 83.256f},
        {.lane = 1, .spawnTime = 83.792f},
        {.lane = 0, .spawnTime = 83.792f},
        {.lane = 0, .spawnTime = 84.244f},
        {.lane = 1, .spawnTime = 84.244f},
        {.lane = 2, .spawnTime = 85.041f},
        {.lane = 1, .spawnTime = 85.041f},
        {.lane = 2, .spawnTime = 85.261f},
        {.lane = 1, .spawnTime = 85.261f},
        {.lane = 0, .spawnTime = 85.809f},
        {.lane = 2, .spawnTime = 85.809f},
        {.lane = 2, .spawnTime = 86.260f},
        {.lane = 0, .spawnTime = 86.260f},
        {.lane = 3, .spawnTime = 87.095f},
        {.lane = 1, .spawnTime = 87.095f},
        {.lane = 1, .spawnTime = 87.277f},
        {.lane = 3, .spawnTime = 87.277f},
        {.lane = 0, .spawnTime = 87.812f},
        {.lane = 1, .spawnTime = 87.812f},
        {.lane = 1, .spawnTime = 88.287f},
        {.lane = 0, .spawnTime = 88.287f},
        {.lane = 2, .spawnTime = 89.123f},
        {.lane = 1, .spawnTime = 89.123f},
        {.lane = 2, .spawnTime = 89.351f},
        {.lane = 1, .spawnTime = 89.351f},
        {.lane = 0, .spawnTime = 89.879f},
        {.lane = 2, .spawnTime = 89.879f},
        {.lane = 2, .spawnTime = 90.376f},
        {.lane = 0, .spawnTime = 90.376f},
        {.lane = 3, .spawnTime = 91.172f},
        {.lane = 1, .spawnTime = 91.172f},
        {.lane = 1, .spawnTime = 91.377f},
        {.lane = 3, .spawnTime = 91.377f},
        {.lane = 0, .spawnTime = 91.927f},
        {.lane = 1, .spawnTime = 91.927f},
        {.lane = 0, .spawnTime = 92.459f},
        {.lane = 1, .spawnTime = 92.936f},
        {.lane = 2, .spawnTime = 92.936f},
        {.lane = 3, .spawnTime = 93.506f},
        {.lane = 0, .spawnTime = 94.004f},
        {.lane = 1, .spawnTime = 94.004f},
        {.lane = 0, .spawnTime = 94.547f},
        {.lane = 1, .spawnTime = 95.061f},
        {.lane = 2, .spawnTime = 95.061f},
        {.lane = 0, .spawnTime = 95.555f},
        {.lane = 2, .spawnTime = 95.555f},
        {.lane = 1, .spawnTime = 96.073f},
        {.lane = 0, .spawnTime = 96.073f},
        {.lane = 0, .spawnTime = 96.588f},
        {.lane = 2, .spawnTime = 97.076f},
        {.lane = 1, .spawnTime = 97.076f},
        {.lane = 3, .spawnTime = 97.616f},
        {.lane = 0, .spawnTime = 98.134f},
        {.lane = 1, .spawnTime = 98.134f},
        {.lane = 0, .spawnTime = 98.644f},
        {.lane = 1, .spawnTime = 99.115f},
        {.lane = 2, .spawnTime = 99.115f},
        {.lane = 0, .spawnTime = 99.626f},
        {.lane = 2, .spawnTime = 99.626f},
        {.lane = 2, .spawnTime = 100.657f},
        {.lane = 3, .spawnTime = 100.950f},

        {.lane = -1}
};

Note CarryOn[CHART_SIZE] = {
        {.lane = 1, .spawnTime = 14.571f},
        {.lane = 1, .spawnTime = 14.869f},
        {.lane = 1, .spawnTime = 15.124f},
        {.lane = 2, .spawnTime = 15.401f},
        {.lane = 1, .spawnTime = 16.078f},
        {.lane = 1, .spawnTime = 16.375f},
        {.lane = 1, .spawnTime = 16.593f},
        {.lane = 3, .spawnTime = 16.861f},
        {.lane = 2, .spawnTime = 17.578f},
        {.lane = 3, .spawnTime = 17.818f},
        {.lane = 2, .spawnTime = 18.046f},
        {.lane = 2, .spawnTime = 18.539f},
        {.lane = 1, .spawnTime = 18.764f},
        {.lane = 2, .spawnTime = 19.440f},
        {.lane = 0, .spawnTime = 19.698f},
        {.lane = 1, .spawnTime = 20.456f},
        {.lane = 1, .spawnTime = 20.728f},
        {.lane = 1, .spawnTime = 20.953f},
        {.lane = 2, .spawnTime = 21.187f},
        {.lane = 1, .spawnTime = 21.840f},
        {.lane = 1, .spawnTime = 22.124f},
        {.lane = 1, .spawnTime = 22.388f},
        {.lane = 3, .spawnTime = 22.632f},
        {.lane = 2, .spawnTime = 23.342f},
        {.lane = 3, .spawnTime = 23.589f},
        {.lane = 2, .spawnTime = 23.820f},
        {.lane = 2, .spawnTime = 24.315f},
        {.lane = 1, .spawnTime = 24.571f},
        {.lane = 2, .spawnTime = 25.219f},
        {.lane = 0, .spawnTime = 25.474f},
        {.lane = 0, .spawnTime = 26.215f},
        {.lane = 0, .spawnTime = 26.457f},
        {.lane = 2, .spawnTime = 27.641f},
        {.lane = 2, .spawnTime = 27.991f},
        {.lane = 1, .spawnTime = 29.099f},
        {.lane = 2, .spawnTime = 29.575f},
        {.lane = 0, .spawnTime = 30.007f},
        {.lane = 0, .spawnTime = 30.327f},
        {.lane = 3, .spawnTime = 31.389f},
        {.lane = 2, .spawnTime = 31.671f},
        {.lane = 1, .spawnTime = 32.804f},
        {.lane = 2, .spawnTime = 33.287f},
        {.lane = 0, .spawnTime = 33.725f},
        {.lane = 0, .spawnTime = 34.022f},
        {.lane = 2, .spawnTime = 35.174f},
        {.lane = 2, .spawnTime = 35.500f},
        {.lane = 1, .spawnTime = 36.494f},
        {.lane = 2, .spawnTime = 36.934f},
        {.lane = 0, .spawnTime = 37.416f},
        {.lane = 0, .spawnTime = 37.713f},
        {.lane = 3, .spawnTime = 38.824f},
        {.lane = 2, .spawnTime = 39.094f},
        {.lane = 1, .spawnTime = 40.181f},
        {.lane = 2, .spawnTime = 40.666f},
        {.lane = 2, .spawnTime = 41.166f},
        {.lane = 3, .spawnTime = 42.103f},
        {.lane = 2, .spawnTime = 42.362f},
        {.lane = 2, .spawnTime = 43.056f},
        {.lane = 1, .spawnTime = 43.551f},
        {.lane = 1, .spawnTime = 43.769f},
        {.lane = 1, .spawnTime = 44.735f},
        {.lane = 2, .spawnTime = 45.064f},
        {.lane = 2, .spawnTime = 45.315f},
        {.lane = 2, .spawnTime = 45.563f},
        {.lane = 2, .spawnTime = 45.821f},
        {.lane = 2, .spawnTime = 46.067f},
        {.lane = 2, .spawnTime = 46.294f},
        {.lane = 3, .spawnTime = 46.507f},
        {.lane = 2, .spawnTime = 47.390f},
        {.lane = 3, .spawnTime = 47.728f},
        {.lane = 3, .spawnTime = 48.123f},
        {.lane = 3, .spawnTime = 48.507f},
        {.lane = 3, .spawnTime = 48.876f},
        {.lane = 2, .spawnTime = 49.314f},
        {.lane = 1, .spawnTime = 49.683f},
        {.lane = 1, .spawnTime = 50.238f},
        {.lane = 2, .spawnTime = 50.574f},
        {.lane = 2, .spawnTime = 50.833f},
        {.lane = 1, .spawnTime = 51.148f},
        {.lane = 0, .spawnTime = 51.542f},
        {.lane = 0, .spawnTime = 52.638f},
        {.lane = 0, .spawnTime = 52.909f},
        {.lane = 3, .spawnTime = 54.145f},
        {.lane = 3, .spawnTime = 54.445f},
        {.lane = 0, .spawnTime = 56.453f},
        {.lane = 0, .spawnTime = 56.747f},
        {.lane = 3, .spawnTime = 57.911f},
        {.lane = 3, .spawnTime = 58.208f},
        {.lane = 1, .spawnTime = 60.187f},
        {.lane = 0, .spawnTime = 60.530f},
        {.lane = 1, .spawnTime = 60.806f},
        {.lane = 2, .spawnTime = 61.116f},
        {.lane = 1, .spawnTime = 61.424f},
        {.lane = 2, .spawnTime = 61.716f},
        {.lane = 3, .spawnTime = 61.970f},
        {.lane = 3, .spawnTime = 74.565f},
        {.lane = 1, .spawnTime = 75.043f},
        {.lane = 2, .spawnTime = 75.532f},
        {.lane = 0, .spawnTime = 76.002f},
        {.lane = 0, .spawnTime = 76.504f},
        {.lane = 1, .spawnTime = 77.067f},
        {.lane = 3, .spawnTime = 77.569f},
        {.lane = 2, .spawnTime = 78.055f},
        {.lane = 3, .spawnTime = 78.585f},
        {.lane = 1, .spawnTime = 79.063f},
        {.lane = 2, .spawnTime = 79.539f},
        {.lane = 0, .spawnTime = 80.024f},
        {.lane = 0, .spawnTime = 80.522f},
        {.lane = 1, .spawnTime = 81.042f},
        {.lane = 3, .spawnTime = 81.509f},
        {.lane = 2, .spawnTime = 82.228f},
        {.lane = 2, .spawnTime = 82.456f},
        {.lane = 1, .spawnTime = 82.962f},
        {.lane = 2, .spawnTime = 83.281f},
        {.lane = 2, .spawnTime = 83.491f},
        {.lane = 0, .spawnTime = 83.962f},
        {.lane = 2, .spawnTime = 84.242f},
        {.lane = 2, .spawnTime = 84.469f},
        {.lane = 1, .spawnTime = 84.868f},
        {.lane = 2, .spawnTime = 85.158f},
        {.lane = 2, .spawnTime = 85.374f},
        {.lane = 0, .spawnTime = 85.791f},
        {.lane = 2, .spawnTime = 86.094f},
        {.lane = 2, .spawnTime = 86.319f},
        {.lane = 1, .spawnTime = 86.769f},
        {.lane = 2, .spawnTime = 87.040f},
        {.lane = 2, .spawnTime = 87.242f},
        {.lane = 0, .spawnTime = 87.689f},
        {.lane = 2, .spawnTime = 87.976f},
        {.lane = 2, .spawnTime = 88.188f},
        {.lane = 1, .spawnTime = 88.631f},
        {.lane = 2, .spawnTime = 88.873f},
        {.lane = 2, .spawnTime = 89.087f},
        {.lane = 0, .spawnTime = 89.510f},
        {.lane = 3, .spawnTime = 90.005f},
        {.lane = 1, .spawnTime = 90.514f},
        {.lane = 2, .spawnTime = 90.973f},
        {.lane = 0, .spawnTime = 91.462f},
        {.lane = 0, .spawnTime = 91.940f},
        {.lane = 1, .spawnTime = 92.404f},
        {.lane = 2, .spawnTime = 92.897f},
        {.lane = 3, .spawnTime = 93.363f},
        {.lane = 3, .spawnTime = 93.839f},
        {.lane = 1, .spawnTime = 94.287f},
        {.lane = 2, .spawnTime = 94.756f},
        {.lane = 0, .spawnTime = 95.215f},
        {.lane = 0, .spawnTime = 95.734f},
        {.lane = 2, .spawnTime = 95.746f},
        {.lane = 2, .spawnTime = 95.981f},
        {.lane = 0, .spawnTime = 95.991f},
        {.lane = 0, .spawnTime = 96.218f},
        {.lane = 2, .spawnTime = 96.228f},
        {.lane = 0, .spawnTime = 96.419f},
        {.lane = 2, .spawnTime = 96.461f},
        {.lane = 0, .spawnTime = 96.645f},
        {.lane = 2, .spawnTime = 96.667f},
        {.lane = 1, .spawnTime = 97.569f},
        {.lane = 3, .spawnTime = 98.075f},
        {.lane = 2, .spawnTime = 98.488f},
        {.lane = 3, .spawnTime = 98.957f},
        {.lane = 1, .spawnTime = 99.432f},
        {.lane = 2, .spawnTime = 99.959f},
        {.lane = 0, .spawnTime = 100.387f},
        {.lane = 2, .spawnTime = 100.935f},
        {.lane = 1, .spawnTime = 101.373f},
        {.lane = 3, .spawnTime = 101.817f},
        {.lane = 2, .spawnTime = 102.278f},
        {.lane = 3, .spawnTime = 102.760f},
        {.lane = 1, .spawnTime = 103.205f},
        {.lane = 2, .spawnTime = 103.693f},
        {.lane = 2, .spawnTime = 104.144f},
        {.lane = 2, .spawnTime = 104.597f},
        {.lane = 1, .spawnTime = 105.076f},
        {.lane = 3, .spawnTime = 105.534f},
        {.lane = 2, .spawnTime = 106.022f},
        {.lane = 3, .spawnTime = 106.489f},
        {.lane = 1, .spawnTime = 106.971f},
        {.lane = 2, .spawnTime = 107.427f},
        {.lane = 0, .spawnTime = 107.886f},
        {.lane = 2, .spawnTime = 108.386f},
        {.lane = 0, .spawnTime = 108.857f},
        {.lane = 2, .spawnTime = 108.857f},
        {.lane = 1, .spawnTime = 110.763f},
        {.lane = 1, .spawnTime = 111.005f},
        {.lane = 1, .spawnTime = 111.237f},
        {.lane = 2, .spawnTime = 111.506f},
        {.lane = 1, .spawnTime = 112.156f},
        {.lane = 1, .spawnTime = 112.421f},
        {.lane = 1, .spawnTime = 112.676f},
        {.lane = 3, .spawnTime = 112.890f},
        {.lane = 2, .spawnTime = 113.577f},
        {.lane = 3, .spawnTime = 113.843f},
        {.lane = 2, .spawnTime = 114.085f},
        {.lane = 2, .spawnTime = 114.551f},
        {.lane = 1, .spawnTime = 114.781f},
        {.lane = 2, .spawnTime = 115.508f},
        {.lane = 0, .spawnTime = 115.731f},
        {.lane = 1, .spawnTime = 116.464f},
        {.lane = 1, .spawnTime = 116.708f},
        {.lane = 1, .spawnTime = 116.943f},
        {.lane = 2, .spawnTime = 117.189f},
        {.lane = 1, .spawnTime = 117.908f},
        {.lane = 1, .spawnTime = 118.191f},
        {.lane = 1, .spawnTime = 118.400f},
        {.lane = 3, .spawnTime = 118.641f},
        {.lane = 2, .spawnTime = 119.341f},
        {.lane = 3, .spawnTime = 119.601f},
        {.lane = 2, .spawnTime = 119.827f},
        {.lane = 2, .spawnTime = 120.328f},
        {.lane = 1, .spawnTime = 120.558f},
        {.lane = 2, .spawnTime = 121.252f},
        {.lane = 0, .spawnTime = 121.468f},
        {.lane = 2, .spawnTime = 122.246f},

        {.lane = -1}
};