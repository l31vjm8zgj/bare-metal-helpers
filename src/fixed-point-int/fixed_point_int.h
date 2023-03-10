#ifndef FIXED_POINT_INT_H_INCLUDED
#define FIXED_POINT_INT_H_INCLUDED

#include <stdint.h>

struct fpi {
    int16_t value;
    uint8_t decimal_places;
};

#define MAKE_STRUCT_FPI(value_init, decimal_places_init) \
    {                                                    \
        .value = value_init,                             \
        .decimal_places = decimal_places_init            \
    }

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

void fpi_multiply(const struct fpi* first, const struct fpi* second,
    struct fpi* result)
{
    int32_t value = ((int32_t)(first->value)) * ((int32_t)(second->value));
    
    int16_t decimal_places_sum =
        ((int16_t)(first->decimal_places)) + ((int16_t)(second->decimal_places));

    int16_t decimal_places_diff = decimal_places_sum - ((int16_t)(result->decimal_places));

    int32_t pow_10 = fpi_pow_10(fpi_abs(decimal_places_diff));
    if(decimal_places_diff >= 0) {
        if(value > 0) {
            result->value = (value + (pow_10 / 2)) / pow_10;
        }
        else if(value < 0){
            result->value = (value - (pow_10 / 2)) / pow_10;
        }
        else {
            result->value = 0;
        }
    }
    else {
        result->value = value * pow_10;
    }

}

#endif // FIXED_POINT_INT_H_INCLUDED
