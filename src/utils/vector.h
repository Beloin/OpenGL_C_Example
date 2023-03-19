//
// Created by beloin on 19/03/23.
//

#ifndef OPENGL_C_VECTOR_H
#define OPENGL_C_VECTOR_H

#define DEFAULT_CENTER_DIST 5.0f

typedef struct {
    float x;
    float y;
} Vector2;

// For now everyone will be a equilateral triangle.
typedef struct {
    Vector2 center;

    float centerDistance; // if: r = 2/3 * h. So h = 3/2*r

    // Upper Point:
    // X = X
    // Y = Y + 2/3 * h
    Vector2 upper;
    // Left point:
    // X = X - sqrt(3) * h / 3
    // Y = Y - 1/3 *h
    Vector2 left;
    // Right point:
    // X = X + sqrt(3) * h / 3
    // Y = Y - 1/3 *h
    Vector2 right;
} TriangleVector2;

Vector2 createVector(float x, float y);

TriangleVector2 createTriangle(Vector2 *point, int height, int width);


#endif //OPENGL_C_VECTOR_H
