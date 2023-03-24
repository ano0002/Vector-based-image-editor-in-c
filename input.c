#include <stdio.h>
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

int startWith(const char *pre, const char *str)
{
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? 0 : strncmp(pre, str, lenpre) == 0;
}

Shape *create_shape(){
    char buffer[100];
    printf("Enter a shape: ");
    gets(buffer);
    if (strcmp(buffer, "line") == 0){
        return create_line_shape(1,1,3,5);
    }
    else if (strcmp(buffer, "circle") == 0){
        return create_circle_shape(1,1,3);
    }
    else if (strcmp(buffer, "rectangle") == 0){
        return create_rectangle_shape(1,1,3,5);
    }
    else if (strcmp(buffer, "square") == 0){
        return create_square_shape(1,1,3);
    }
    else{
        printf("Unknown shape\n");
        return NULL;
    }
}