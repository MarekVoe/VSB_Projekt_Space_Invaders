#ifndef PLAYER_HEADER_H
#define PLAYER_HEADER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/utils.h"
#include "../include/vector2d.h"

// ------------ TODO: Implement own Vector2D data type, instead of two float variables for coordinates ------------

typedef struct {
    Vector2D position;
    Vector2D size;
    Vector2D cursor;
    float speed;
    float angle;
    SDL_Texture* texture;
} Player;

void player_init(Player* player, SDL_Renderer* renderer, const float start_x, const float start_y);
void player_update(Player* player);
void player_render(Player* player, SDL_Renderer* renderer);
void player_destroy(Player* player);

#endif