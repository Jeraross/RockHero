#include "raylib.h"
#include <stdio.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

// Configurações do Player
#define NUM_FRAMES 13
#define PLAYER_SPEED 8.0f
#define ANIMATION_SPEED 8
#define FRAME_WIDTH 80
#define FRAME_HEIGHT 123
#define FRAME_SPACING 227
#define START_OFFSET_X 20
#define PLAYER_SCALE 2.0f

// Configurações do Polnareff
#define POLNAREFF_FRAMES 7
#define POLNAREFF_ANIM_SPEED 8
#define POLNAREFF_FRAME_WIDTH 191
#define POLNAREFF_FRAME_HEIGHT 155
#define POLNAREFF_FRAME_DISTANCE 185
#define POLNAREFF_SCALE 2.0f

// Área da estrada (limites verticais)
#define ROAD_TOP 720
#define ROAD_BOTTOM 1080

typedef enum {
    STATE_IDLE,
    STATE_WALK
} PlayerState;

typedef struct {
    Texture2D spriteSheet;
    Vector2 position;
    int currentFrame;
    int frameCounter;
    bool facingRight;
    PlayerState state;
} Player;

typedef struct {
    Texture2D spriteSheet;
    Vector2 position;
    int currentFrame;
    int frameCounter;
    float scale;
} Polnareff;

float clamp(float value, float min, float max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Jogo com Player e Polnareff");
    SetTargetFPS(60);

    if (!IsWindowFullscreen()) {
        ToggleFullscreen();
    }

    // Carrega os recursos
    Texture2D background = LoadTexture("assets/Free-Pixel-Art-Street-2D-Backgrounds/PNG/City2/Bright/City2.png");
    if (background.id == 0) {
        TraceLog(LOG_WARNING, "Background não carregado, usando cor sólida");
    }

    // Inicializa o Player
    Player player = {0};
    player.position = (Vector2){SCREEN_WIDTH / 2.0f, (ROAD_TOP + ROAD_BOTTOM) / 2.0f};
    player.facingRight = true;
    player.currentFrame = 0;
    player.frameCounter = 0;
    player.state = STATE_IDLE;

    Image temp = LoadImage("assets/move (2).png");
    Color green = (Color){0, 255, 0, 255};
    ImageColorReplace(&temp, green, BLANK);
    player.spriteSheet = LoadTextureFromImage(temp);
    UnloadImage(temp);

    if (player.spriteSheet.id == 0) {
        TraceLog(LOG_ERROR, "Falha ao carregar o spritesheet do player.");
        CloseWindow();
        return -1;
    }

    // Inicializa o Polnareff
    Polnareff polnareff = {0};
    polnareff.spriteSheet = LoadTexture("assets/polnareff.png");
    polnareff.position = (Vector2){SCREEN_WIDTH * 0.75f, (ROAD_BOTTOM - 200) - POLNAREFF_FRAME_HEIGHT * POLNAREFF_SCALE};
    polnareff.currentFrame = 1; // Começa no frame 1 para pular o primeiro
    polnareff.frameCounter = 0;
    polnareff.scale = POLNAREFF_SCALE;

    if (polnareff.spriteSheet.id == 0) {
        TraceLog(LOG_ERROR, "Falha ao carregar a spritesheet do Polnareff!");
        CloseWindow();
        return -1;
    }

    while (!WindowShouldClose())
    {
        // Atualiza o Player
        Vector2 movement = {0};
        if (IsKeyDown(KEY_RIGHT)) {
            movement.x = 1;
            player.facingRight = false;
        }
        if (IsKeyDown(KEY_LEFT)) {
            movement.x = -1;
            player.facingRight = true;
        }
        if (IsKeyDown(KEY_UP)) movement.y = -1;
        if (IsKeyDown(KEY_DOWN)) movement.y = 1;

        // Normalizar diagonal
        if (movement.x != 0 && movement.y != 0) {
            movement.x *= 0.7071f;
            movement.y *= 0.7071f;
        }

        player.position.x += movement.x * PLAYER_SPEED;
        player.position.y += movement.y * PLAYER_SPEED;

        // Limita o movimento
        player.position.x = clamp(player.position.x, 0, SCREEN_WIDTH - FRAME_WIDTH * PLAYER_SCALE);
        player.position.y = clamp(player.position.y, ROAD_TOP, ROAD_BOTTOM - FRAME_HEIGHT * PLAYER_SCALE);

        // Atualiza animação do Player
        bool isMoving = (movement.x != 0 || movement.y != 0);
        player.state = isMoving ? STATE_WALK : STATE_IDLE;

        switch (player.state) {
            case STATE_IDLE:
                player.currentFrame = 0;
                break;
            case STATE_WALK:
                player.frameCounter++;
                if (player.frameCounter >= (60 / ANIMATION_SPEED)) {
                    player.frameCounter = 0;
                    player.currentFrame++;
                    if (player.currentFrame < 1 || player.currentFrame > 12)
                        player.currentFrame = 1;
                }
                break;
        }

        // Atualiza animação do Polnareff
        polnareff.frameCounter++;
        if (polnareff.frameCounter >= (60 / POLNAREFF_ANIM_SPEED)) {
            polnareff.frameCounter = 0;
            polnareff.currentFrame++;

            if (polnareff.currentFrame >= POLNAREFF_FRAMES)
                polnareff.currentFrame = 1; // Volta para o frame 1 (ignorando o 0)
        }

        // Desenho
        BeginDrawing();

        // Desenha o background
        if (background.id != 0) {
            DrawTexture(background, 0, 0, WHITE);
        } else {
            ClearBackground(RAYWHITE);
        }

        // Desenha o Polnareff (primeiro para ficar atrás se necessário)
        Rectangle polnareffSource = {
                polnareff.currentFrame * POLNAREFF_FRAME_DISTANCE,
                0,
                POLNAREFF_FRAME_WIDTH,
                POLNAREFF_FRAME_HEIGHT
        };

        Rectangle polnareffDest = {
                polnareff.position.x,
                polnareff.position.y,
                POLNAREFF_FRAME_WIDTH * polnareff.scale,
                POLNAREFF_FRAME_HEIGHT * polnareff.scale
        };

        DrawTexturePro(polnareff.spriteSheet, polnareffSource, polnareffDest, (Vector2){0, 0}, 0.0f, WHITE);

        // Desenha o Player
        Rectangle playerSource = {
                START_OFFSET_X + player.currentFrame * FRAME_SPACING,
                0,
                player.facingRight ? FRAME_WIDTH : -FRAME_WIDTH,
                FRAME_HEIGHT
        };

        Rectangle playerDest = {
                player.position.x,
                player.position.y,
                FRAME_WIDTH * PLAYER_SCALE,
                FRAME_HEIGHT * PLAYER_SCALE
        };

        DrawTexturePro(player.spriteSheet, playerSource, playerDest, (Vector2){0, 0}, 0.0f, WHITE);

        // Debug info
        DrawText(TextFormat("Posição Player: (%.0f, %.0f)", player.position.x, player.position.y), 10, 10, 20, DARKGRAY);
        DrawText("Use as setas para mover", 10, 40, 20, DARKGRAY);
        DrawText(TextFormat("Frame Polnareff: %d/%d", polnareff.currentFrame, POLNAREFF_FRAMES), 10, 70, 20, DARKGRAY);

        EndDrawing();
    }

    // Descarrega texturas
    if (background.id != 0) UnloadTexture(background);
    UnloadTexture(player.spriteSheet);
    UnloadTexture(polnareff.spriteSheet);
    CloseWindow();

    return 0;
}