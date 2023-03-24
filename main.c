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
        if (i == 1)
        {
            printf("Help\n");
            printf("exit\n");
            printf("help\n");
            printf("clear\n");
            printf("plot\n");
            printf("list\n");
            printf("erase\n");
            printf("delete\n");
            printf("new\n");
        }
        else if (i == 2)
        {
            clearscreen();
        }
        else if (i == 3)
        {
            display(L,LS);
        }
        else if (i == 4)
        {
            printf("List\n");
        }
        else if (i == 5)
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
            printf("Delete\n");
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