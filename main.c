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
    Shape **L = malloc(1*sizeof(Shape*));
    L[0] = create_point_shape(1,1);
    int LS = 1;
    int i = input();
    while (i != 0)
    {
        if (i == 1) //display help
        {
            printf("=====================\nHelp\n=====================\n");
            printf("exit : quit the program\n");
            printf("help : display this message\n");
            printf("clear : clear the terminal\n");
            printf("plot : plot all shapes\n");
            printf("list : list all shapes\n");
            printf("erase : erase all shapes\n");
            printf("delete : delete a shape\n");
            printf("new : create a new shape\n");
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
            printf("List :\n");
            if (LS == 0)
            {
                printf("Empty\n");
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
        }
        else if (i == 6)
        {
            printf("With what id ?\n");
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
        }
        else if (i == 7)
        {
            printf("New\n");
        }

        i = input();
    }

    /*
    //clearscreen();
    Shape *point = create_point_shape(2,2);
    print_shape(point);
    delete_shape(point);

    Shape *line = create_line_shape(1,1,6,5);
    print_shape(line);
    delete_shape(line);

    Shape *circle = create_circle_shape(1,1,5);
    print_shape(circle);
    delete_shape(circle);

    Shape *rectangle = create_rectangle_shape(1,1,5,5);
    print_shape(rectangle);
    delete_shape(rectangle);

    Shape *square = create_square_shape(1,1,5);
    print_shape(square);
    delete_shape(square);

    Point *points[2] = {create_point(1,1),create_point(6,5)};
    Shape *polygon = create_polygon_shape(points,2);
    print_shape(polygon);
    delete_shape(polygon);
    */
    
    return 0;
}