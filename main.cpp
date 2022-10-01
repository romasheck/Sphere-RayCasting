#include "DrowScene.hpp"
#include <iostream>

int main()
{
    std::vector<Pixel> pixels;
    FillInPixels (BACKGROUND_COLOR, &pixels);

    Sphere sphere( Point{0,0,0}, X_LIM);
    scn::Object object = {sphere, RED, 20};
    scn::Light light = {{5*X_LIM, 5*X_LIM, 5*X_LIM}, WHITE};
    Point veiwer = {0, 0, 5*X_LIM};

    scn::Scene scene = {object, light, veiwer, Color{128, 0, 255}};

    scene.ObjectInPixels(&pixels);
    
    CycleDrowing(&pixels);


    return 0;
}