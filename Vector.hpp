#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <math.h>

class Vector
{
    double x_;
    double y_;
    double z_;

    public: 

    Vector(double x, double y, double z): x_(x),y_(y), z_(z) {};
    ~Vector() {};

    Vector operator + (Vector a);

    Vector operator - (Vector b);

    Vector& operator += (Vector b);

    Vector& operator -= (Vector b);

    double operator * (Vector b);

    double norm();

    Vector operator * (double coef);

    Vector projection (Vector base);

    Vector reflect (Vector base);

    double operator ^ (Vector a);
};

#endif