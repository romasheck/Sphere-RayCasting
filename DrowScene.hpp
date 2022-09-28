#ifndef DROWSCENE_H_INCLUDED
#define DROWSCENE_H_INCLUDED

#include "Geom.hpp"
#include "libDrow.hpp"
#include <math.h>

#define A 0.3
#define D 0.7

struct Light
{
    Point place_;
    Color color_;
};

struct Object
{
    Sphere sphere_;
    Color color_;
    uint8_t n_exp;
};

class Scene
{
    Object object_;
    Light light_;
    Point viewer_;
    Color ambient_;

    public:

    Scene(Object obj, Light l, Point view, Color amb): object_(obj), light_(l), viewer_(view), ambient_(amb) {};
    ~Scene() {};

    void ObjectInPixels (std::vector<Pixel> *pixels);

    private:

    Color CalcColor (Point point);
};

double                  ColumnToX           (float column);

double                  LineToY             (float line);

//uint32_t                CoordToPos          (double coord);

Point                   PixelToPoint        (Pixel pixel);

//sf::RectangleShape      PointToPixel        (scene_objs::Point point);

//unsigned char           Intensity           (Point point,Sphere sphere, Light Light);

#define BACKGROUND_COLOR Color{30, 30, 30, 30}
#define MATERIAL_COLOR   Color{255, 0, 0}

#endif