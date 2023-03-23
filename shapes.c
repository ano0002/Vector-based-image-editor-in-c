#include <stdio.h>
#include <stdlib.h>

#include "shapes.h"

#include "point.h"
#include "line.h"

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

Shape *create_line_shape(int px1, int py1, int px2, int py2)
{
    Shape *shp = create_empty_shape(LINE);
    Line *p = create_line(px1,py1,px2,py2);
    shp->ptrShape = p;
    return shp;
}

void display_shape(Shape *shape){
    if (shape->shape_type == POINT)
    {
        display_point(shape->ptrShape);
    }
    else if (shape->shape_type == LINE)
    {
        display_line(shape->ptrShape);
    }
    
}

int main(void){
    Shape *point = create_point_shape(2,2);
    display_shape(point);
    destroy_point(point->ptrShape);
    printf("\n");

    Shape *line = create_line_shape(1,1,6,5);
    display_shape(line);
    destroy_line(line->ptrShape);

}
