//
// Created by beloin on 19/03/23.
//

#include "vector.h"
#include <math.h>

float normalize(float value, int min, int max);

Vector2 createVector(float x, float y) {
    return (Vector2) {x, y};
}

TriangleVector2 createTriangle(Vector2 *point, int height, int width) {
    // Normalize between -1 and 1:

    // Working with the triangle height
    const float h = ((float) 3 / 2) * DEFAULT_CENTER_DIST;

    float upperX = point->x;
    float upperY = point->y + ((float) 2 / 3) * h;

    float leftX = point->x - (float) sqrt(3) * h / 3;
    float leftY = point->y - ((float) 1 / 3) * h;

    float rightX = point->x + (float) sqrt(3) * h / 3;

    float normalizedUpperX = normalize(upperX, 0, width);
    float normalizedUpperY = normalize(upperY, 0, height);
    Vector2 normalizedUpperVector = {normalizedUpperX, normalizedUpperY};

    float normalizedLeftX = normalize(leftX, 0, height);
    float normalizedLeftY = normalize(leftY, 0, width);
    Vector2 normalizedLeftVector = {normalizedLeftX, normalizedLeftY};

    float normalizedRightX = normalize(rightX, 0, width);
    Vector2 normalizedRightVector = {normalizedRightX, normalizedLeftY};

    TriangleVector2 norm = (TriangleVector2) {*point, DEFAULT_CENTER_DIST,
                                              normalizedUpperVector, normalizedLeftVector,
                                              normalizedRightVector};

    return norm;
}

float normalize(float value, int min, int max) {
    // Zi = 2 * ((Xi -Xmin) / (Xmax -Xmin)) - 1
    float p1 = value - (float) min;
    float p2 = (float) (max - min);

    float zi = (2 * (p1 / p2)) - 1;
    return zi;
}
