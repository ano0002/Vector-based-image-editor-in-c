#include <stdio.h>
#include <stdlib.h>

#include "point.h"

Point* create_point(int x, int y)
{
    Point *p = malloc(sizeof(Point)); // allocate memory for the point
    p->x = x; // set the x coordinate
    p->y = y; // set the y coordinate
    return p; // return the point
}

void print_point(Point *p)
{
    printf("Point: (%d, %d)", p->x, p->y);
}

void destroy_point(Point *p)
{
    free(p);// free the memory allocated for the point
}
