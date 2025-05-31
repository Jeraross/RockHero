#include "../../include/entities/player.h"
#include "../../include_raylib/raylib.h"
#include "../../include/utils/utils.h"

void InitPlayer(Player *player) {
    player->position = (Vector2){GetScreenWidth() / 2.0f, (720 + 1080) / 2.0f};
    player->facingRight = true;
    player->currentFrame = 0;
    player->frameCounter = 0;
    player->state = STATE_IDLE;

    Image temp = LoadImage("assets/sprites/move.png");
    Color green = (Color){0, 255, 0, 255};
    ImageColorReplace(&temp, green, BLANK);
    player->spriteSheet = LoadTextureFromImage(temp);
    UnloadImage(temp);
}

void UpdatePlayer(Player *player) {
    if (player->frozen) {
        player->state = STATE_IDLE; // Força estado idle
        return;
    }
    Vector2 movement = {0};
    if (IsKeyDown(KEY_RIGHT) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) {
        movement.x = 1;
        player->facingRight = false;
    }
    if (IsKeyDown(KEY_LEFT) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {
        movement.x = -1;
        player->facingRight = true;
    }
    if (IsKeyDown(KEY_UP) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP)) movement.y = -1;
    if (IsKeyDown(KEY_DOWN) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) movement.y = 1;

    if (movement.x != 0 && movement.y != 0) {
        movement.x *= 0.7071f;
        movement.y *= 0.7071f;
    }

    player->position.x += movement.x * PLAYER_SPEED;
    player->position.y += movement.y * PLAYER_SPEED;

    player->position.x = clamp(player->position.x, 0, GetScreenWidth() - FRAME_WIDTH * PLAYER_SCALE);
    player->position.y = clamp(player->position.y, 720, 1080 - FRAME_HEIGHT * PLAYER_SCALE);

    bool isMoving = (movement.x != 0 || movement.y != 0);
    player->state = isMoving ? STATE_WALK : STATE_IDLE;

    switch (player->state) {
        case STATE_IDLE:
            player->currentFrame = 0;
            break;
        case STATE_WALK:
            player->frameCounter++;
            if (player->frameCounter >= (60 / ANIMATION_SPEED)) {
                player->frameCounter = 0;
                player->currentFrame++;
                if (player->currentFrame < 1 || player->currentFrame > 12)
                    player->currentFrame = 1;
            }
            break;
    }
}

void DrawPlayer(Player *player) {
    Rectangle playerSource = {
            START_OFFSET_X + player->currentFrame * FRAME_SPACING,
            0,
            player->facingRight ? FRAME_WIDTH : -FRAME_WIDTH,
            FRAME_HEIGHT
    };

    Rectangle playerDest = {
            player->position.x,
            player->position.y,
            FRAME_WIDTH * PLAYER_SCALE,
            FRAME_HEIGHT * PLAYER_SCALE
    };

    DrawTexturePro(player->spriteSheet, playerSource, playerDest, (Vector2){0, 0}, 0.0f, WHITE);
}