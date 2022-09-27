#include "Geom.hpp"
#include "double_math.hpp"

/*bool Sphere::CheckBelongsXYZ (Point point)
{
    if (compare((point.x_*point.x_ + point.y_*point.y_ + point.z_*point.z_ - radius_*radius_), 0) == EQUAL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
*/

bool Sphere::CheckBelongsXY (Point point)
{
    if (compare((point.x_*point.x_ + point.y_*point.y_ - radius_*radius_), 0) ==LESS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Sphere::RestoreZ (Point point)
{
    return sqrt(radius_*radius_ - point.x_*point.x_ - point.y_*point.y_);
}