#include <stdio.h>
#include <stdlib.h>

#include "square.h"

Square *create_square(int x, int y, int length)
{
    Square *sq = (Square *) malloc(sizeof(Square));
    sq->origin = create_point(x, y);
    sq->length = length;
    return sq;
}

void print_square(Square *square)
{
    printf("Square: [Point: (%d, %d) - length = %d]", square->origin->x, square->origin->y, square->length);
}

void destroy_square(Square *square)
{
    destroy_point(square->origin);
    free(square);
}