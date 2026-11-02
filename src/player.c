#include "../include/player.h"

void player_init(Player* player, SDL_Renderer* renderer, const float start_x, const float start_y) {
    player->position.x = start_x;
    player->position.y = start_y;
    player->size.x = 64;
    player->size.y = 64;
    player->speed = 5.0f;
    player->texture = NULL;

    SDL_Surface* surface = IMG_Load("assets/images/T_PlayerShip.png");
    if (surface == NULL) {
        fprintf(stderr, "Nepodarilo se nacist texturu lodi, IMG_Error: %s", IMG_GetError());
    } else {
        player->texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
}

void player_update(Player* player){
    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    // SDL_GetMouseState takes only (int variables)
    int mouseX = 0;
    int mouseY = 0;

    // Getting cursor position -> for player rotation
    SDL_GetMouseState(&mouseX, &mouseY);
    player->cursor.x = (float) mouseX;
    player->cursor.y = (float) mouseY;

    // Calculating player texture center for the rotation
    Vector2D centerPos = {
        player->position.x + (player->size.x / 2.0f),
        player->position.y + (player->size.y / 2.0f)
    };

    Vector2D mousePos = { player->cursor.x, player->cursor.y };
    Vector2D direction = look_at_vector(&centerPos, &mousePos);
    player->angle = calculateAngle(&direction) + 90.0f;

    if (keyState[SDL_SCANCODE_LEFT] || keyState[SDL_SCANCODE_A]) {
        player->position.x -= player->speed;
    }
    if (keyState[SDL_SCANCODE_RIGHT] || keyState[SDL_SCANCODE_D]) {
        player->position.x += player->speed;
    }

    if (keyState[SDL_SCANCODE_UP] || keyState[SDL_SCANCODE_W]) {
        player->position.y -= player->speed;
    }

    if (keyState[SDL_SCANCODE_DOWN] || keyState[SDL_SCANCODE_S]) {
        player->position.y += player->speed;
    }
}

void player_render(Player* player, SDL_Renderer* renderer) {
    SDL_Rect dest = {
        (int)player->position.x,
        (int)player->position.y,
        player->size.x,
        player->size.y
    };

    if (player->texture != NULL) {
        // I Had to rotate the .png texture 90 degrees to the right in order to work
        SDL_RenderCopyEx(renderer, player->texture, NULL, &dest, player->angle, NULL, SDL_FLIP_NONE);
    } else {
       SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
       SDL_RenderFillRect(renderer, &dest);
    }
}

void player_destroy(Player* player) {
    if (player->texture != NULL) {
        SDL_DestroyTexture(player->texture);
        player->texture = NULL;
    }
}