#ifndef DROWSCENE_H_INCLUDED
#define DROWSCENE_H_INCLUDED

#include "Geom.hpp"
#include "libDrow.hpp"

enum LightCoefs
{
    A = 26,
    D = 230,
    S = 0
};

struct Light_t
{
    Point place_;
    Color color_;
};

double                  ColumnToX             (float column);

double                  LineToY           (float line);

//uint32_t                CoordToPos          (double coord);

Point       PixelToPoint        (Pixel pixel);

//sf::RectangleShape      PointToPixel        (scene_objs::Point point);

unsigned char           Intensity           (Point point,Sphere sphere, Light_t Light);

int                     SpherInPixels       (std::vector<Pixel> *pixels, Sphere sphere, Light_t Light);

#endif