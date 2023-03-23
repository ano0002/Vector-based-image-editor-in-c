#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

typedef struct {
    Point *point;
    int width;
    int height;
} Rectangle;


Rectangle* create_rectangle(int x, int y, int width, int height);
void print_rectangle(Rectangle *rect);
void destroy_rectangle(Rectangle *rect);

#endif