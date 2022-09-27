#ifndef DOUBLE_MATH_H_INCLUDED
#define DOUBLE_MATH_H_INCLUDED

#include <math.h>

#define EPSILON 10e-6

enum COMPARE_RESULTS
{
    MORE = 1,
    EQUAL = 0,
    LESS = -1
};

int compare (double frst, double scnd)
{
    if (frst - scnd > EPSILON) 
        return MORE;
    if (abs(frst - scnd) < EPSILON)
        return EQUAL;
    
    return LESS;
}

#endif