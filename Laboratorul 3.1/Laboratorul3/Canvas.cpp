#include "Canvas.h"
#include <cmath>
#include <cstdarg>
#include <cstdio>

Canvas::Canvas(int lines, int columns)
{
	this->linis = lines;
	this->columns = columns;
}

void Canvas::set_pixel(int x, int y, char value) {
    if (x >= 0 && x < linis && y >= 0 && y < columns) {
        a[x][y] = value;
    }
}

void Canvas::set_pixels(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        char value = va_arg(args, char);
        set_pixel(x, y, value);
    }
    va_end(args);
}

void Canvas::clear() {
    for (int i = 0; i < linis; i++) {
        for (int j = 0; j < columns; j++) {
            a[i][j] = '.';
        }
    }
}

void Canvas::print()  {
    for (int i = 0; i < linis; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}