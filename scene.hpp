#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <iostream>
#include "Vector.hpp"

#define PRINT_LINE printf ("I am at line %d\n", __LINE__);//

enum CoordLimits
{
    X_LIM = 400,
    Y_LIM = 400
};

namespace scene_objs
{

struct Point 
{
    double x_;
    double y_;
    double z_;

    Point(double x, double y): x_(x), y_(y) {};
    Point(double x, double y, double z): x_(x), y_(y), z_(z) {};
    ~Point() {};

    Vector RVector() 
    {
        return Vector{x_, y_, z_};
    }
};

class Sphere
{
    Point center_;
    double radius_;

    public:

    Sphere(Point center, double radius) : center_(center), radius_(radius) {}; 

    ~Sphere () {};

    //bool CheckBelongsXYZ (Point point);

    bool CheckBelongsXY (Point point);

    double RestoreZ (Point point);
};

}

#endif