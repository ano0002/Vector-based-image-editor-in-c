#include <stdio.h>
#include <stdlib.h>

#include "square.h"

Square *create_square(int x, int y, int length)
{
    Square *sq = (Square *) malloc(sizeof(Square));
    sq->center = create_point(x, y);
    sq->length = length;
    return sq;
}

void print_square(Square *square)
{
    printf("Square: [Point: (%d, %d) - length = %d]", square->center->x, square->center->y, square->length);
}

void destroy_square(Square *square)
{
    destroy_point(square->center);
    free(square);
}