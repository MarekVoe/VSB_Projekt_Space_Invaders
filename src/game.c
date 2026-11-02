#include "../include/game.h"

bool sdl_init(Game* game) {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "SDL nelze inicializovat! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    game->window = SDL_CreateWindow(
        "Space Invaders 2.0",
        100,
        100,
        1280,
        720,
        SDL_WINDOW_SHOWN
    );

    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (game->renderer == NULL) {
        SDL_DestroyWindow(game->window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    if (game->window == NULL) {
        fprintf(stderr, "SDL_CreateWindow Error: %s", SDL_GetError());
        return false;
    }
    return true;
}

void loop(Game* game) {
    player_init(&game->player, game->renderer,  375.0f, 500.0f);

    while(game->running) {
        while(SDL_PollEvent(&game->event)) {
            if (game->event.type == SDL_QUIT) {
                game->running = false;
            }
        }
        player_update(&game->player);
        SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
        SDL_RenderClear(game->renderer);
        player_render(&game->player, game->renderer);
        SDL_RenderPresent(game->renderer);
    }
    player_destroy(&game->player);
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}