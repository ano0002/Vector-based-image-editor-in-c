#include <stdio.h>
#include <stdlib.h>

#include "shapes.h"

#include "point.h"

Shape *create_empty_shape(SHAPE_TYPE shape_type)
{
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = 1; // plus tard on appelera get_next_id();
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

void display_shape(Shape *shape){
    if (shape->shape_type == POINT)
    {
        display_point(shape->ptrShape);
    }
    
}

int main(void){
    Shape *point = create_point_shape(2,2);
    display_shape(point);
    destroy_point(point->ptrShape);
}
