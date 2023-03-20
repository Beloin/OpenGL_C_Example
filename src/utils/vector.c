//
// Created by beloin on 19/03/23.
//

#include "vector.h"
#include <math.h>

const float h = ((float) 3 / 2) * DEFAULT_CENTER_DIST;

float normalize(float value, int min, int max);

Vector2 CreateVector(float x, float y) {
    return (Vector2) {x, y};
}

TriangleVector2 CreateTriangle(Vector2 *point, int height, int width) {
    // TODO: Problem while normalizing:
    //  To solve it: Create a simple example and calculate it manually.
    //  Test with R = 50
    //  Height = 75
    //  Central Point = (400, 400)
    //  Upper Point =  (400, 450)
    //  Left Point =  (356.7, 375)
    //  Right Point =  (443.3, 375)
    //  Normalized:
    //  Upper Point =  (0, 0.125)
    //  Left Point =  (-0.108, -0.0625)
    //  Right Point =  (0.108, -0.0625)


    // Normalize between -1 and 1:
    // Working with the triangle height

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

void GenerateFloatArray(TriangleVector2 *triangle, float output[9]) {
    output[0] = triangle->left.x;
    output[1] = triangle->left.y;
    output[2] = 0;

    output[3] = triangle->left.x;
    output[4] = triangle->right.y;
    output[5] = 0;

    output[6] = triangle->upper.x;
    output[7] = triangle->upper.y;
    output[8] = 0;
}
