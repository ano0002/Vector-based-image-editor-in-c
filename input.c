#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

int input(){
    char buffer[100];
    printf("Enter a command: ");
    gets(buffer);
    if (strcmp(buffer, "exit") == 0){
        return 0;
    }
    else if (strcmp(buffer, "help") == 0){
        return 1;
    }
    else if (strcmp(buffer, "clear") == 0){
        return 2;
    }
    else if (strcmp(buffer,"plot") == 0)
    {
        return 3;
    }
    else if (strcmp(buffer,"list") == 0)
    {
        return 4;
    }
    else if (strcmp(buffer,"erase") == 0)
    {
        return 5;
    }
    else if (strcmp(buffer,"delete") == 0)
    {
        return 6;
    }
    else if (strcmp(buffer,"new") == 0)
    {
        return 7;
    }
    else{
        printf("Unknown command\n");
        return input();
    }
}

Shape *create_shape(){
    char buffer[100];
    printf("Enter a shape: ");
    gets(buffer);
    if (strncmp(buffer, "line",4) == 0){
        int x1,y1,x2,y2;
        sscanf(buffer, "line %d %d %d %d", &x1, &y1, &x2, &y2);
        return create_line_shape(x1,y1,x2,y2);
    }
    else if (strncmp(buffer, "circle",6) == 0){
        int x,y,r;
        sscanf(buffer, "circle %d %d %d", &x, &y, &r);
        return create_circle_shape(x,y,r);
    }
    else if (strncmp(buffer, "rectangle",9) == 0){
        int x,y,w,h;
        sscanf(buffer, "rectangle %d %d %d %d", &x, &y, &w, &h);
        return create_rectangle_shape(x,y,w,h);
    }
    else if (strncmp(buffer, "square",6) == 0){
        int x,y,s;
        sscanf(buffer, "square %d %d %d", &x, &y, &s);
        return create_square_shape(x,y,s);
    }
    else{
        printf("Unknown shape\n");
        return NULL;
    }
}