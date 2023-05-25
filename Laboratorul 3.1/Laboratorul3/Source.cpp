#include "Canvas.h"
#include <iostream>

int main() {
    // Create a canvas with width 40 and height 20
    Canvas canvas(40, 20);

    // Draw a circle with center (20, 10), radius 8, and character '#'
    canvas.DrawCircle(20, 10, 8, '#');

    // Fill a circle with center (20, 10), radius 4, and character '*'
    canvas.FillCircle(20, 10, 4, '*');

    // Draw a rectangle with top-left corner (5, 5), bottom-right corner (35, 15), and character '-'
    canvas.DrawRect(5, 5, 35, 15, '-');

    // Fill a rectangle with top-left corner (10, 7), bottom-right corner (30, 13), and character '+'
    canvas.FillRect(10, 7, 30, 13, '+');

    // Draw a line from (5, 5) to (35, 15) with character '='
    canvas.DrawLine(5, 5, 35, 15, '=');

    // Print the canvas to the console
    canvas.Print();

    // Clear the canvas
    canvas.Clear();

    // Set a point at (20, 10) with character 'X'
    canvas.SetPoint(20, 10, 'X');

    // Print the canvas to the console
    canvas.Print();

    // Exit the program
    return 0;
}