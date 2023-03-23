#include <stdio.h>
#include <stdlib.h>

#include "shapes.h"

#include "point.h"
#include "line.h"
#include "circle.h"


int id = 0;

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
    free(shape);
}

int get_next_id(){
    id ++;
    return id;
}

