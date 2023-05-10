#include <stdio.h>
#include <stdlib.h>

#include "rectangle.h"

#include "point.h"

Rectangle* create_rectangle(int x, int y, int width, int height)
{
    Rectangle *l = malloc(sizeof(Rectangle)); // allocate memory for the rectangle
    l->point = create_point(x, y); // create the point and assign it to the rectangle
    l->width = width; // set the width
    l->height = height; // set the height
    return l; // return the rectangle
}

void print_rectangle(Rectangle *l)
{
    // print the point and the width and height
    printf("Rectangle: ["); 
    print_point(l->point);
    printf(" - width: %d, height: %d", l->width, l->height);
    printf("]");
}

void destroy_rectangle(Rectangle *l)
{
    // destroy the point and free the memory allocated for the rectangle
    destroy_point(l->point);
    free(l);
}