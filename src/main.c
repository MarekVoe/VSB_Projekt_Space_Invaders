#include <stdio.h>
#include "../include/game.h"

Game game;

int main() {
    game.running = true;
    if (sdl_init(&game)) {
        loop(&game);
    } else {
        printf("Hru se nepodarilo spustit \n");
        return 1;
        }
    return 0;
}