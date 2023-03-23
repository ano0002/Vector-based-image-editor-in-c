#include <stdlib.h>
#include <stdio.h>

#include "shapes.h"

void clearscreen() {
    system("clear");
    system("cls");
}

int main(void) {
    clearscreen();
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

    return 0;
}