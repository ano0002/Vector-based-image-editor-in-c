#ifndef SQUARE_H
#define SQUARE_H

#include "point.h"

typedef struct {
    Point *origin;
    int length;
} Square;

Square* create_square(int x, int y, int length);
void print_square(Square *square);
void destroy_square(Square *square);
#endif
