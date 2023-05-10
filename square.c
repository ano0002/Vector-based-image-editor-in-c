#include <stdio.h>
#include <stdlib.h>

#include "square.h"

Square *create_square(int x, int y, int length)
{
    Square *sq = (Square *) malloc(sizeof(Square)); // allocate memory for the square
    sq->origin = create_point(x, y); // create the point and assign it to the square
    sq->length = length; // set the length
    return sq; // return the square
}

void print_square(Square *square)
{
    printf("Square: [Point: (%d, %d) - length = %d]", square->origin->x, square->origin->y, square->length);
}

void destroy_square(Square *square)
{
    // destroy the point and free the memory allocated for the square
    destroy_point(square->origin); 
    free(square);
}