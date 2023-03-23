#include <stdio.h>
#include <stdlib.h>

#include "line.h"

#include "point.h"

Line* create_line(int x1, int y1, int x2, int y2)
{
    Line *l = malloc(sizeof(Line));
    l->p1 = create_point(x1, y1);
    l->p2 = create_point(x2, y2);
    return l;
}

void display_line(Line *l)
{
    printf("Line: ");
    display_point(l->p1);
    printf(" - ");
    display_point(l->p2);
}

void destroy_line(Line *l)
{
    destroy_point(l->p1);
    destroy_point(l->p2);
    free(l);
}