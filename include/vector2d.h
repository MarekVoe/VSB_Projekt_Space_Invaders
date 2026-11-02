#ifndef VECTOR2D_HEADER_H
#define VECTOR2D_HEADER_H
#define PI 3.14159265358979323846
#include <math.h>

typedef struct {
    float x;
    float y;
} Vector2D;

Vector2D look_at_vector(Vector2D* vec1, Vector2D* vec2);
float calculateAngle(Vector2D* vector);

#endif