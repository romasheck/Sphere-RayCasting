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
/*
unsigned char Intensity (Point point,  Sphere sphere, Light light)
{
    point.z_ = sphere.RestoreZ(point);
    Vector RV = point.RVector();

    Vector RVLight = light.place_.RVector();

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
*/

using namespace scn;

void Scene::ObjectInPixels (std::vector<Pixel> *pixels)
{
    for (auto& pixel : *pixels)
    {
        Point point = PixelToPoint(pixel);
        
        if(object_.sphere_.CheckBelongsXY (point))
        {
            //pixel.setFillColor({225, 0, 0, Intensity(point, sphere, Light)});
            pixel.setColor(CalcColor(point));
        }
    }
}

Color Scene::CalcColor (Point point)
{
    point.z_ = object_.sphere_.RestoreZ(point);

    Vector R = point.RVector();
    Vector V = viewer_.RVector();
    Vector L = light_.place_.RVector();

    Color Amb_term = ambient_ * object_.color_ * A;

    Vector RL = L - R;
    Color Dif_term = (light_.color_ * object_.color_ * (RL^R) * D);

    Vector RV = V - R;
    double cos_VL = RV^(RL.reflect(R));
    if (cos_VL < 0)
    {
        cos_VL = 0;
    }
    Color Spec_term = (light_.color_ * pow(cos_VL, object_.n_exp));//
    
    return Dif_term + Amb_term + Spec_term;
}
/*
int SpherInPixels (std::vector<Pixel> *pixels,  Sphere sphere, Light light)
{
    for (auto& pixel : *pixels)
    {
        Point point = PixelToPoint(pixel);
        
        if(sphere.CheckBelongsXY (point))
        {
            //pixel.setFillColor({225, 0, 0, Intensity(point, sphere, Light)});
            pixel.setColor(Color{225, 0, 0, Intensity(point, sphere, light)});
        }
    }

    return 0;
}
*/