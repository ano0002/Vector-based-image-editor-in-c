#ifndef SHAPES_H
#define SHAPES_H

#include "point.h"

typedef enum { POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON} SHAPE_TYPE;


typedef struct {
    int id;
    SHAPE_TYPE shape_type;
    void *ptrShape;
} Shape;

Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_circle_shape(int px, int py, int radius);
Shape *create_polygon_shape(Point **points, int n);
void delete_shape(Shape *shape);
void print_shape(Shape * shape);

int get_next_id();


#endif