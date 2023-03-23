#include "point.h"
#include <stdio.h>
#include <stdlib.h>


Point* Create_Point(int x, int y)
{
    Point *p = malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}

void Draw_Point(Point *p)
{
    printf("Point: (%d, %d)", p->x, p->y);
}

void Destroy_Point(Point *p)
{
    free(p);
}

int main(void)
{
    Point *p = Create_Point(10, 20);
    Draw_Point(p);
    Destroy_Point(p);
    return 0;
}