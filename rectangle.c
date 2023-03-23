#include <stdio.h>
#include <stdlib.h>

#include "rectangle.h"

#include "point.h"

Rectangle* create_rectangle(int x, int y, int width, int height)
{
    Rectangle *l = malloc(sizeof(Rectangle));
    l->point = create_point(x, y);
    l->width = width;
    l->height = height;
    return l;
}

void print_rectangle(Rectangle *l)
{
    printf("Rectangle: [");
    print_point(l->point);
    printf(" - width: %d, height: %d", l->width, l->height);
    printf("]");
}

void destroy_rectangle(Rectangle *l)
{
    destroy_point(l->point);
    free(l);
}