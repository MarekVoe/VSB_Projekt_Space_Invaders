#ifndef GAME_HEADER_H
#define GAME_HEADER_H
#define DEBUG true
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../include/player.h"

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running;
    SDL_Event event;
    Player player;
} Game;

bool sdl_init(Game* game);
void loop(Game* game);

#endif