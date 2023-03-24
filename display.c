#include <stdio.h>
#include <math.h>

#include "display.h"

#define SIZE_X 70
#define SIZE_Y 30

void draw_point(Point *p, char M[SIZE_Y][SIZE_X], char symbol) {
    M[p->y][p->x] = symbol;
}

void draw_line(Line *l, char M[SIZE_Y][SIZE_X], char symbol) {
    int x0 = l->p1->x, y0 = l->p1->y, 
        x1 = l->p2->x, y1 = l->p2->y;
    int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
    int err = dx + dy, e2; /* error value e_xy */
    
    do {  /* loop */
        Point *p = create_point(x0,y0);
        draw_point(p, M, symbol);
        destroy_point(p);

        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
        if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
    }
    while (x0 != x1 || y0 != y1);
}

void draw_rectangle(Rectangle *r, char M[SIZE_Y][SIZE_X], char symbol) {
    Line *top = create_line(r->point->x,r->point->y,r->point->x+r->width,r->point->y);
    Line *right = create_line(r->point->x+r->width,r->point->y,r->point->x+r->width,r->point->y+r->height);
    Line *bottom = create_line(r->point->x,r->point->y+r->height,r->point->x+r->width,r->point->y+r->height);
    Line *left = create_line(r->point->x,r->point->y,r->point->x,r->point->y+r->height);
    draw_line(top, M, symbol);
    draw_line(right, M, symbol);
    draw_line(bottom, M, symbol);
    draw_line(left, M, symbol);
    destroy_line(top);
    destroy_line(right);
    destroy_line(bottom);
    destroy_line(left);
}

void display_square(Square *s, char M[SIZE_Y][SIZE_X], char symbol) {
    Rectangle *r = create_rectangle(s->origin->x,s->origin->y,s->length,s->length);
    draw_rectangle(r, M, symbol);
    destroy_rectangle(r);
}

void display_polygon(Polygon *p, char M[SIZE_Y][SIZE_X], char symbol) {
    for (int i=0; i<p->n-1; i++) {
        Line *l = create_line(p->points[i]->x,p->points[i]->y,p->points[i+1]->x,p->points[i+1]->y);
        draw_line(l, M, symbol);
        destroy_line(l);
    }
    Line *l = create_line(p->points[p->n-1]->x,p->points[p->n-1]->y,p->points[0]->x,p->points[0]->y);
    draw_line(l, M, symbol);
    destroy_line(l);
}


void display(Shape ** L, int SIZE) {
    char M[SIZE_Y][SIZE_X];
    for(int i=0; i<SIZE_Y; i++)  for(int j=0; j<SIZE_X; j++)  M[i][j] = '.';
    char symbol = '#';



    for (int i=0; i<SIZE; i++) {
        Shape *shape = L[i];

        if (shape->shape_type == POINT) {
            draw_point(shape->ptrShape, M, symbol);
        }

        else if (shape->shape_type == LINE) {
            draw_line(shape->ptrShape, M, symbol);
        }
        
        else if (shape->shape_type == CIRCLE) {}
        
        else if (shape->shape_type == RECTANGLE) {
            draw_rectangle(shape->ptrShape, M, symbol);
        }
        
        else if (shape->shape_type == SQUARE) {
            display_square(shape->ptrShape, M, symbol);
        }
        
        else if (shape->shape_type == POLYGON) {
            display_polygon(shape->ptrShape, M, symbol);
        }
    }

    for(int i=0; i<SIZE_Y; i++) {
        for(int j=0; j<SIZE_X; j++) printf("%c", M[i][j]);
        printf("\n");
    }
}




