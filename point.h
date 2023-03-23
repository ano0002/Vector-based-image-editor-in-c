#ifndef POINT_H
#define POINT_H

typedef struct {
    int x;
    int y;
} Point;

Point* create_point(int x, int y);
void print_point(Point *p);
void destroy_point(Point *p);


#endif 