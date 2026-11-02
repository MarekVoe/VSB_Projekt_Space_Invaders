#ifndef BULLET_HEADER_H
#define BULLET_HEADER_H
#include <stdbool.h>
#include "../include/Vector2D.h"

typedef struct {
    Vector2D position;
    Vector2D velocity;
    Vector2D size;
    bool active;
    int damage;
} Projectile;

#endif