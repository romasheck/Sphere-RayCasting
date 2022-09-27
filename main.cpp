#include "DrowScene.hpp"
#include <iostream>

int main()
{
    PRINT_LINE
    std::vector<Pixel> pixels;
    FillInPixels (Color{30,30,30,30}, &pixels);
    PRINT_LINE
    Sphere sphere( Point{0,0,0}, X_LIM);
    PRINT_LINE
    Light_t Light = {{400, 400, 400}, WHITE};
    SpherInPixels(&pixels, sphere, Light);
    PRINT_LINE
    CycleDrowing(&pixels);
    PRINT_LINE

    return 0;
}