#include "CorrectOp.hpp"

uint8_t CorrectSum (uint8_t term1, uint8_t term2)
{
    uint16_t sum = term1 + term2;
    if (sum <= 255)
    {
        return sum;
    }
    else
    {
        return 255;
    }
}

uint8_t CorrectMul (uint8_t factor1, uint8_t factor2)
{
    uint16_t mul = factor1 * factor2;
    if (mul <= 255)
    {
        return mul;
    }
    else
    {
        return 255;
    }
}

uint8_t CorrectMulC (uint8_t elem, double coef)
{
    uint16_t mulc = elem * coef;
    if (mulc <= 255)
    {
        return mulc;
    }
    else
    {
        return 255;
    }
}