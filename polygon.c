#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "polygon.h"
#include "point.h"

Polygon *create_polygon(Point **points, int n){
    Polygon *polygon = malloc(sizeof(Polygon)); // allocate memory for the polygon
    /* Removed because it is not necessary
    if (n%2){
        printf("Error: n must be even");
        return NULL;
    }
    */
    polygon->n = n; // set the number of points
    polygon->points = malloc(n*sizeof(Point*)); // allocate memory for the points
    for (int i = 0; i < n; i++){
        polygon->points[i] = points[i]; // set the points
    }
    return polygon; // return the polygon
}

void destroy_polygon(Polygon * polygon){
    for (int i = 0; i < polygon->n; i++){ 
        destroy_point(polygon->points[i]); // destroy the points
    }
    free(polygon->points); // free the memory allocated for the points
    free(polygon); // free the memory allocated for the polygon
}

void print_polygon(Polygon * polygon){
    printf("Polygon: n=%d, points=[", polygon->n); // print the number of points
    for (int i = 0; i < polygon->n; i++){ //for each point
        printf("(%d,%d)", polygon->points[i]->x, polygon->points[i]->y); // print the point
        if (i != polygon->n-1){
            printf(", ");
        }
    }
    printf("]");
}