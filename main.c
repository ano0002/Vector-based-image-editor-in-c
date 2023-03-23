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
    return 0;
}