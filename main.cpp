#include "DrowScene.hpp"
#include <iostream>

int main()
{
    PRINT_LINE
    std::vector<Pixel> pixels;
    FillInPixels (BACKGROUND_COLOR, &pixels);
    PRINT_LINE
    Sphere sphere( Point{0,0,0}, X_LIM);
    Object object = {sphere, RED, 21};
    Light light = {{-4000, 4000, 4000}, WHITE};
    Point veiwer = {0, 0, 1600};
    Scene scene = {object, light, veiwer, WHITE};
    scene.ObjectInPixels(&pixels);
    PRINT_LINE
    CycleDrowing(&pixels);
    PRINT_LINE

    return 0;
}