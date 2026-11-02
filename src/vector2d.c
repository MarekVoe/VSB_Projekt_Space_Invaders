#include "../include/vector2d.h"

Vector2D look_at_vector(Vector2D* vec1, Vector2D* vec2) {
    Vector2D resultVector = {0.0f, 0.0f};
    resultVector.x = vec2->x - vec1->x;
    resultVector.y = vec2->y - vec1->y;
    return resultVector;
}

float calculateAngle(Vector2D* vector) {
    float resultAngle = atan2(vector->y, vector->x);
    resultAngle *= (180 / PI);
    return resultAngle;
}