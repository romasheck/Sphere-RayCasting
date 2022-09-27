#include "Vector.hpp"

Vector Vector::operator + (Vector a)
{
    return Vector {a.x_ + x_, a.y_ + y_, a.z_ + z_};
};

Vector Vector::operator - (Vector b)
{
    return Vector {x_ - b.x_, y_ - b.y_, z_ - b.z_};
}

Vector& Vector::operator += (Vector b)
{
    x_ += b.x_;
    y_ += b.y_;
    z_ += b.z_;

    return *this;
}

Vector& Vector::operator -= (Vector b)
{
    x_ -= b.x_;
    y_ -= b.y_;
    z_ -= b.z_;

    return *this;
}

double Vector::operator * (Vector b)
{
    return (x_*b.x_ + y_*b.y_ + z_*b.z_);
}

double Vector::norm()
{
    return sqrt(x_*x_ + y_*y_ + z_*z_);
}

Vector Vector::operator * (double coef)
{
    return Vector {coef*x_, coef*y_, coef*z_};
}

Vector Vector::projection (Vector base)
{
    return ((*this) - (base * ((*this) * base / (base*base)))); 
}

Vector Vector::reflect (Vector base)
{
    return ((*this) + (base - (*this).projection(base)) * (2));
}

double Vector::operator ^ (Vector a)
{
    return (((*this)*a)/((*this).norm()*a.norm()));
}

