#include "../include/player.h"

void player_init(Player* player, SDL_Renderer* renderer, const float start_x, const float start_y) {
    player->x = start_x;
    player->y = start_y;
    player->width = 64;
    player->height = 64;
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

    if (keyState[SDL_SCANCODE_LEFT] || keyState[SDL_SCANCODE_A]) {
        player->x -= player->speed;
    }
    if (keyState[SDL_SCANCODE_RIGHT] || keyState[SDL_SCANCODE_D]) {
        player->x += player->speed;
    }

    if (keyState[SDL_SCANCODE_UP] || keyState[SDL_SCANCODE_W]) {
        player->y -= player->speed;
    }

    if (keyState[SDL_SCANCODE_DOWN] || keyState[SDL_SCANCODE_S]) {
        player->y += player->speed;
    }
}

void player_render(Player* player, SDL_Renderer* renderer) {
    SDL_Rect dest = {
        (int)player->x,
        (int)player->y,
        player->width,
        player->height
    };

    if (player->texture != NULL) {
        SDL_RenderCopy(renderer, player->texture, NULL, &dest);
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