#include <stdio.h>
#include <stdlib.h>

#include "circle.h"


Circle* create_circle(int x, int y, int radius){
    Circle *circle = malloc(sizeof(Circle));
    circle->center = create_point(x, y);
    circle->radius = radius;
    return circle;
}

void print_circle(Circle *circle){
    printf("Circle: center = [" );
    print_point(circle->center);
    printf("], radius = %d", circle->radius);
}

void destroy_circle(Circle *circle){
    destroy_point(circle->center);
    free(circle);
}
