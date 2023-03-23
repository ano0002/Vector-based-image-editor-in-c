#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

typedef struct {
    Point *center;
    int radius;
} Circle;

Circle* create_circle(int x, int y, int radius);
void print_circle(Circle *circle);
void destroy_circle(Circle *circle);
#endif