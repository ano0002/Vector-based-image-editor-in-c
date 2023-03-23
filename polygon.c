#include <stdio.h>
#include <stdlib.h>
#include <math.h>

# define M_PI 3.14159265358979323846  

#include "polygon.h"
#include "point.h"

Polygon *create_polygon(Point **points, int n){
    Polygon *polygon = malloc(sizeof(Polygon));
    if (n%2){
        printf("Error: n must be even");
        return NULL;
    }
    polygon->n = n;
    polygon->points = malloc(n*sizeof(Point*));
    for (int i = 0; i < n; i++){
        polygon->points[i] = points[i];
    }
    return polygon;
}

void destroy_polygon(Polygon * polygon){
    for (int i = 0; i < polygon->n; i++){
        destroy_point(polygon->points[i]);
    }
    free(polygon->points);
    free(polygon);
}

void print_polygon(Polygon * polygon){
    printf("Polygon: n=%d, points=[", polygon->n);
    for (int i = 0; i < polygon->n; i++){
        printf("(%d,%d)", polygon->points[i]->x, polygon->points[i]->y);
        if (i != polygon->n-1){
            printf(", ");
        }
    }
    printf("]");
}