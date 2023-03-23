#ifndef POINT_H
#define POINT_H

typedef struct {
    int x;
    int y;
} Point;

Point* Create_Point(int x, int y);
void Draw_Point(Point *p);


#endif 