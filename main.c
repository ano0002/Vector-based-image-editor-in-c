#include <stdlib.h>
#include <stdio.h>

#include "shapes.h"
#include "input.h"
#include "display.h"

void clearscreen() {
    system("clear");
    system("cls");
}



int main(void) {
    Shape **L = malloc(0*sizeof(Shape*)); //list of shapes
    int LS = 0; //length of the list
    printf("========= Help =========\n"
           "new : create a new shape\n"
           "delete : delete a shape\n"
           "list : list all shapes\n"
           "erase : erase all shapes\n"
           "plot : plot the grid\n"
           "clear : clear the terminal\n"
           "exit : quit the program\n"
           "\n");
    int i = input();
    while (i != 0)
    {
        if (i == 1) //display help
        {
            printf("\n========= Help =========\n"
                   "new : create a new shape\n"
                   "delete : delete a shape\n"
                   "list : list all shapes\n"
                   "erase : erase all shapes\n"
                   "plot : plot the grid\n"
                   "clear : clear the terminal\n"
                   "exit : quit the program\n"
                   "\n");
        }
        else if (i == 2) //clear terminal
        {
            clearscreen();
        }
        else if (i == 3) //plot all shapes
        {
            display(L,LS);
        }
        else if (i == 4) //list all shapes
        {
            printf("List of shapes :\n");
            if (LS == 0) //if list is empty
            {
                printf("No shapes in list\n");
            }
            else{
                for (int j = 0; j < LS; j++)
                {
                    print_shape(L[j]);
                }
            }
        }
        else if (i == 5) //erase all
        {
            printf("Erase\n");
            for (int j = 0; j < LS; j++)
            {
                delete_shape(L[j]);
            }
            free(L);
            L = malloc(0*sizeof(Shape*));
            LS = 0;
            display(L,LS);
        }
        else if (i == 6)
        {
            //list all shapes
            printf("List of shapes :\n");
            if (LS == 0) //if list is empty
            {
                printf("No shapes in list\n");
            }
            else{
                for (int j = 0; j < LS; j++)
                {
                    print_shape(L[j]);
                }
            }
            printf("\nWhat shape do you want to delete? (enter id) \n");
            int id;
            scanf("%d",&id);
            for (int j = 0; j < LS; j++)
            {
                if (L[j]->id == id)
                {
                    delete_shape(L[j]);
                    for (int k = j; k < LS-1; k++)
                    {
                        L[k] = L[k+1];
                    }
                    LS--;
                    L = realloc(L,LS*sizeof(Shape*));
                    break;
                }
            }
            display(L,LS);
        }
        else if (i == 7)
        {
            printf("\n========= Shapes =========\n"
                   "- point x y : add a point\n"
                   "- line x1 y1 x2 y2 : add a segment connecting two points (x1, y1) and (x2, y2)\n"
                   "- circle x y radius : add a circle of centre (x, y) and a radius radius\n"
                   "- square x y length : add a square whose upper left corner is (x, y) and whose side is length.\n"
                   "- rectangle x y width height : add a rectangle whose upper left corner is (x, y), whose width\n"
                   "  is width and whose height is height\n"
                   "- polygon x1 y1 x2 y2 x3 y3 .. .. : add a polygon with the list of given points\n\n");
            Shape *s = create_shape();
            if (s == NULL) {
                printf("Error\n");
                continue;
            }
            else {
                L = realloc(L,(LS+1)*sizeof(Shape*));
                L[LS] = s;
                LS++;
                display(L,LS);
            }
        }

        i = input();
    }
    
    return 0;
}