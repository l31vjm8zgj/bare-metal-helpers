#include "fixed_point_int.h"

int32_t fpi_pow_10(uint8_t exp)
{
    int32_t result = 1;
    for(uint8_t e = 0; e < exp; ++e) {
        result *= 10;
    }
    return result;
}

int16_t fpi_abs(int16_t value)
{
    if(value < 0) {
        return value * (-1);
    }
    return value;
}

void fpi_add(const struct fpi* first, const struct fpi* second, struct fpi* result)
{
    // TODO
}

void fpi_subtract(const struct fpi* first, const struct fpi* second, struct fpi* result)
{
    // TODO
}

void fpi_multiply(const struct fpi* first, const struct fpi* second, struct fpi* result)
{
    int32_t value = ((int32_t)(first->value)) * ((int32_t)(second->value)); 
    int16_t decimal_places =
        ((int16_t)(first->decimal_places)) +
        ((int16_t)(second->decimal_places)) -
        ((int16_t)(result->decimal_places));
    int32_t pow_10 = fpi_pow_10(fpi_abs(decimal_places));
    if(decimal_places >= 0) {
        if(value > 0) {
            result->value = (value + (pow_10 / 2)) / pow_10;
        }
        else {
            result->value = (value - (pow_10 / 2)) / pow_10;
        }
    }
    else {
        result->value = value * pow_10;
    }
}

void fpi_divide(const struct fpi* first, const struct fpi* second, struct fpi* result)
{
    // TODO
}