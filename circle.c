#include <stdio.h>
#include <stdlib.h>

#include "circle.h"


Circle* create_circle(int x, int y, int radius){
    Circle *circle = malloc(sizeof(Circle)); // allocate memory for the circle
    circle->center = create_point(x, y); // create the center point
    circle->radius = radius; // set the radius
    return circle; // return the circle
}

void print_circle(Circle *circle){
    printf("Circle: [" );
    print_point(circle->center); // print the center point
    printf(" - radius = %d]", circle->radius); // print the radius
}

void destroy_circle(Circle *circle){
    destroy_point(circle->center); // destroy the center point
    free(circle); // free the memory allocated for the circle
}
