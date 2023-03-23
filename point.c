#include <stdio.h>
#include <stdlib.h>

#include "point.h"

Point* create_point(int x, int y)
{
    Point *p = malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}

void display_point(Point *p)
{
    printf("Point: (%d, %d)", p->x, p->y);
}

void destroy_point(Point *p)
{
    free(p);
}
