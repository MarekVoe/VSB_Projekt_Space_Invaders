#ifndef PLAYER_HEADER_H
#define PLAYER_HEADER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct {
    float x;
    float y;
    int width;
    int height;
    float speed;
    SDL_Texture* texture;
} Player;

void player_init(Player* player, SDL_Renderer* renderer, const float start_x, const float start_y);
void player_update(Player* player);
void player_render(Player* player, SDL_Renderer* renderer);
void player_destroy(Player* player);

#endif