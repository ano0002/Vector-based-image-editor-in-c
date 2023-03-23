#ifndef POLYGON_H
#define POLYGON_H

#include "point.h"

typedef struct polygon {
    int n;
    Point ** points; // tableau 1D dynamique de Point*
}Polygon;

Polygon *create_polygon(Point **points, int n);
void destroy_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);


#endif 