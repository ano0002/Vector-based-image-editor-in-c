#ifndef SHAPES_H
#define SHAPES_H

typedef enum { POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON} SHAPE_TYPE;


typedef struct {
    void* shape;
    SHAPE_TYPE type;
} Shape;

Shape* Create_Empty_shape();


#endif