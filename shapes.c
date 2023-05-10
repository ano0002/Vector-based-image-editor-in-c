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
    Shape *shp = (Shape *) malloc(sizeof(Shape)); // allocate memory for the shape
    shp->ptrShape = NULL; // set the pointer to the shape to NULL
    shp->id = get_next_id();  // set the id
    shp->shape_type = shape_type; // set the shape type
    return shp; // return the shape
}

Shape *create_point_shape(int px, int py)
{
    Shape *shp = create_empty_shape(POINT); // create an empty shape
    Point *p = create_point(px, py); // create a point
    shp->ptrShape = p; // set the pointer to the shape to the point
    return shp; // return the shape
}

Shape *create_line_shape(int px1, int py1, int px2, int py2)
{
    Shape *shp = create_empty_shape(LINE); // create an empty shape
    Line *p = create_line(px1,py1,px2,py2); // create a line
    shp->ptrShape = p; // set the pointer to the shape to the line
    return shp; // return the shape
}

Shape *create_circle_shape(int px, int py, int radius){
    Shape *shp = create_empty_shape(CIRCLE); // create an empty shape
    Circle *p = create_circle(px,py,radius); // create a circle
    shp->ptrShape = p; // set the pointer to the shape to the circle
    return shp; // return the shape
}

Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape *shp = create_empty_shape(RECTANGLE); // create an empty shape
    Rectangle *p = create_rectangle(px,py,width,height); // create a rectangle
    shp->ptrShape = p; // set the pointer to the shape to the rectangle
    return shp; // return the shape
}

Shape *create_square_shape(int px, int py, int side){
    Shape *shp = create_empty_shape(SQUARE); // create an empty shape
    Square *p = create_square(px,py,side); // create a square
    shp->ptrShape = p; // set the pointer to the shape to the square
    return shp; // return the shape
}

Shape *create_polygon_shape(Point **points, int n){
    Shape *shp = create_empty_shape(POLYGON); // create an empty shape
    Polygon *p = create_polygon(points,n); // create a polygon
    shp->ptrShape = p; // set the pointer to the shape to the polygon
    return shp; // return the shape
}

void print_shape(Shape *shape){

    // print the id

    printf("ID : %d, ",shape->id);

    // print the shape depending on the shape type

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

    // delete the shape depending on the shape type
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
    // increment the global id and return it
    global_id ++;
    return global_id;
}

