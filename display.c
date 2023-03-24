#include <stdio.h>

#include "display.h"


void display(Shape ** L, int SIZE) {
    char M[5][5];
    for(int i=0; i<5; i++)  for(int j=0; j<5; j++)  M[i][j] = 'O';
    char symbol = 'w';



    for (int i=0; i<SIZE; i++) {
        Shape *shape = L[i];

        if (shape->shape_type == POINT) {
            Point *p = (Point *) shape->ptrShape;
            M[p->y][p->x] = symbol;
        }

        else if (shape->shape_type == LINE) {}
        
        else if (shape->shape_type == CIRCLE) {}
        
        else if (shape->shape_type == RECTANGLE) {}
        
        else if (shape->shape_type == SQUARE) {}
        
        else if (shape->shape_type == POLYGON) {}
    }

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) printf("%c", M[i][j]);
        printf("\n");
    }
}




