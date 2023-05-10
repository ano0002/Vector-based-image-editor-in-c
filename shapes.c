#include <stdio.h>
#include <stdlib.h>

#include "shapes.h"

#include "point.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include "polygon.h"

unsigned int global_id = 0;

Shape *create_empty_shape(SHAPE_TYPE shape_type)
{
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = get_next_id();
    shp->shape_type = shape_type;
    return shp;
}

Shape *create_point_shape(int px, int py)
{
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2)
{
    Shape *shp = create_empty_shape(LINE);
    Line *p = create_line(px1,py1,px2,py2);
    shp->ptrShape = p;
    return shp;
}

Shape *create_circle_shape(int px, int py, int radius){
    Shape *shp = create_empty_shape(CIRCLE);
    Circle *p = create_circle(px,py,radius);
    shp->ptrShape = p;
    return shp;
}

Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape *shp = create_empty_shape(RECTANGLE);
    Rectangle *p = create_rectangle(px,py,width,height);
    shp->ptrShape = p;
    return shp;
}

Shape *create_square_shape(int px, int py, int side){
    Shape *shp = create_empty_shape(SQUARE);
    Square *p = create_square(px,py,side);
    shp->ptrShape = p;
    return shp;
}

Shape *create_polygon_shape(Point **points, int n){
    Shape *shp = create_empty_shape(POLYGON);
    Polygon *p = create_polygon(points,n);
    shp->ptrShape = p;
    return shp;
}

void print_shape(Shape *shape){

    printf("ID : %d, ",shape->id);

    if (shape->shape_type == POINT)
    {
        print_point(shape->ptrShape);
    }
    else if (shape->shape_type == LINE)
    {
        print_line(shape->ptrShape);
    }
    else if (shape->shape_type == CIRCLE)
    {
        print_circle(shape->ptrShape);
    }
    else if (shape->shape_type == RECTANGLE)
    {
        print_rectangle(shape->ptrShape);
    }
    else if (shape->shape_type == SQUARE)
    {
        print_square(shape->ptrShape);
    }
    else if (shape->shape_type == POLYGON)
    {
        print_polygon(shape->ptrShape);
    }
    printf("\n");
    
}

void delete_shape(Shape *shape){
    if (shape->shape_type == POINT)
    {
        destroy_point(shape->ptrShape);
    }
    else if (shape->shape_type == LINE)
    {
        destroy_line(shape->ptrShape);
    }
    else if (shape->shape_type == CIRCLE)
    {
        destroy_circle(shape->ptrShape);
    }
    else if (shape->shape_type == RECTANGLE)
    {
        destroy_rectangle(shape->ptrShape);
    }
    else if (shape->shape_type == SQUARE)
    {
        destroy_square(shape->ptrShape);
    }
    else if (shape->shape_type == POLYGON)
    {
        destroy_polygon(shape->ptrShape);
    }
    free(shape);
}

int get_next_id(){
    global_id ++;
    return global_id;
}

