#ifndef DROWSCENE_H_INCLUDED
#define DROWSCENE_H_INCLUDED

#include "scene.hpp"
#include "libDrow.hpp"

enum LightCoefs
{
    A = 26,
    D = 230,
    S = 0
};

struct Light_t
{
    scene_objs::Point place_;
    sf::Color color_;

    Light_t(scene_objs::Point place, sf::Color color): place_(place), color_(color) {};
    ~Light_t () {};
};

double                  ColumnToX             (float column);

double                  LineToY           (float line);

//uint32_t                CoordToPos          (double coord);

scene_objs::Point       PixelToPoint        (sf::RectangleShape pixel);

//sf::RectangleShape      PointToPixel        (scene_objs::Point point);

unsigned char           Intensity           (scene_objs::Point point, scene_objs::Sphere sphere, Light_t Light);

int                     SpherInPixels       (std::vector<sf::RectangleShape> *pixels, scene_objs::Sphere sphere, Light_t Light);

#endif