#include "DrowScene.hpp"

double ColumnToX (float column)
{
    return ((column - WIDTH/2) * 2 * X_LIM / WIDTH);
}

double LineToY (float line)
{
    return ((-line + HEIGHT/2) * 2* Y_LIM / HEIGHT);
}

Point PixelToPoint (Pixel pixel)
{
    Pos position = pixel.Position();

    Point point(ColumnToX(position.column), LineToY(position.line));

    return point;
}

unsigned char Intensity (Point point,  Sphere sphere, Light_t Light)
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

int SpherInPixels (std::vector<Pixel> *pixels,  Sphere sphere, Light_t Light)
{
    for (auto& pixel : *pixels)
    {
        Point point = PixelToPoint(pixel);
        
        if(sphere.CheckBelongsXY (point))
        {
            //pixel.setFillColor({225, 0, 0, Intensity(point, sphere, Light)});
            pixel.setColor(Color{225, 0, 0, Intensity(point, sphere, Light)});
        }
    }

    return 0;
}