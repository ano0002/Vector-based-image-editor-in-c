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
    else if (strcmp(buffer,"plot"))
    {
        return 3;
    }
    else if (strcmp(buffer,"list"))
    {
        return 4;
    }
    else if (strcmp(buffer,"erase"))
    {
        return 5;
    }
    else if (strcmp(buffer,"delete"))
    {
        return 6;
    }
    else if (strcmp(buffer,"new"))
    {
        return 7;
    }
    else{
        return input();
    }
}