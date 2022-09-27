#include "DrowScene.hpp"

double ColumnToX (float column)
{
    return ((column - WIDTH/2) * 2 * X_LIM / WIDTH);
}

double LineToY (float line)
{
    return ((-line + HEIGHT/2) * 2* Y_LIM / HEIGHT);
}

scene_objs::Point PixelToPoint (sf::RectangleShape pixel)
{
    sf::Vector2f position = pixel.getPosition();

    scene_objs::Point point(ColumnToX(position.x), LineToY(position.y));

    return point;
}

unsigned char Intensity (scene_objs::Point point, scene_objs::Sphere sphere, Light_t Light)
{
    point.z_ = sphere.RestoreZ(point);
    Vector RV = point.RVector();

    Vector RVLight = Light.place_.RVector();

    int DifLight = D * (RV^RVLight);
    int I = A + DifLight;

    if (DifLight > 0)
    {
        if (I >= 255)
        {
            return 255;
        }

        return (unsigned char) I;
    }

    return A;
}

int SpherInPixels (std::vector<sf::RectangleShape> *pixels, scene_objs::Sphere sphere, Light_t Light)
{
    for (auto& pixel : *pixels)
    {
        scene_objs::Point point = PixelToPoint(pixel);
        
        if(sphere.CheckBelongsXY (point))
        {
            pixel.setFillColor({225, 0, 0, Intensity(point, sphere, Light)});
        }
    }

    return 0;
}