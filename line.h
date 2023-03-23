#ifndef LINE_H
#define LINE_H

#include "point.h"

typedef struct {
    Point *p1;
    Point *p2;
} Line;


Line* create_line(int x1, int y1, int x2, int y2);
void print_line(Line *p);
void destroy_line(Line *p);

#endif