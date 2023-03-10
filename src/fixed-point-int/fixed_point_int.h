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

int32_t fpi_pow_10(uint8_t exp);
int16_t fpi_abs(int16_t value);
void fpi_add(const struct fpi* first, const struct fpi* second, struct fpi* result);
void fpi_subtract(const struct fpi* first, const struct fpi* second, struct fpi* result);
void fpi_multiply(const struct fpi* first, const struct fpi* second, struct fpi* result);
void fpi_divide(const struct fpi* first, const struct fpi* second, struct fpi* result);

#endif // FIXED_POINT_INT_H_INCLUDED
