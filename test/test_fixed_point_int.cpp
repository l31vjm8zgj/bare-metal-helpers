#include "doctest.h"

#include <cmath>

extern "C" {
    #include "fixed-point-int/fixed_point_int.h"
}

TEST_CASE("fpi_pow_10()")
{
    CHECK(fpi_pow_10(0) == 1);
    CHECK(fpi_pow_10(1) == 10);
    CHECK(fpi_pow_10(2) == 100);
    CHECK(fpi_pow_10(3) == 1000);
}

TEST_CASE("fpi_abs()")
{
    CHECK(fpi_abs(0) == 0);
    CHECK(fpi_abs(1) == 1);
    CHECK(fpi_abs(-1) == 1);
}

TEST_CASE("fpi_multiply()")
{
    struct fpi a;
    struct fpi b;
    struct fpi c;

    SUBCASE("result is zero") {
        a = MAKE_STRUCT_FPI(0, 2);
        b = MAKE_STRUCT_FPI(0, 2);
        c = MAKE_STRUCT_FPI(0, 2);
        fpi_multiply(&a, &b, &c);
        CHECK(c.value == 0);
    }

    SUBCASE("result is positive") {
        // c has same decimal-places
        a = MAKE_STRUCT_FPI(123, 2); // 1.23
        b = MAKE_STRUCT_FPI(234, 2); // 2.34
        c = MAKE_STRUCT_FPI(0, 2);
        fpi_multiply(&a, &b, &c);
        CHECK(c.value == 288); // 2.88

        // c has less decimal-places
        c = MAKE_STRUCT_FPI(0, 1);
        fpi_multiply(&a, &b, &c);
        CHECK(c.value == 29); // 2.9

        // c has more decimal-places
        c = MAKE_STRUCT_FPI(0, 3);
        fpi_multiply(&a, &b, &c);
        CHECK(c.value == 2878); // 2.878

        // c has much more decimal-places
        a = MAKE_STRUCT_FPI(14, 1);
        b = MAKE_STRUCT_FPI(23, 2);
        c = MAKE_STRUCT_FPI(0, 4);
        fpi_multiply(&a, &b, &c);
        CHECK(c.value == 3220);
    }

    SUBCASE("result is negative") {
        // c has same decimal-places
        a = MAKE_STRUCT_FPI(123, 2); // 1.23
        b = MAKE_STRUCT_FPI(-234, 2); // -2.34
        c = MAKE_STRUCT_FPI(0, 2);
        fpi_multiply(&a, &b, &c);
        auto value = std::round(-2.8782 * 100);
        CHECK(value == -288);
        CHECK(c.value == -288); // -2.88

        // c has less decimal places
        c = MAKE_STRUCT_FPI(0, 1);
        fpi_multiply(&a, &b, &c);
        CHECK(c.value == -29); // -2,9

        // c has much less decimal places
        c = MAKE_STRUCT_FPI(0, 0);
        fpi_multiply(&a, &b, &c);
        CHECK(c.value == -3); // -3

        // c has more decimal places
        c = MAKE_STRUCT_FPI(0, 3);
        fpi_multiply(&a, &b, &c);
        CHECK(c.value == -2878); // 2.878

        // c has much more decimal places
        a = MAKE_STRUCT_FPI(14, 1);
        b = MAKE_STRUCT_FPI(-23, 2);
        c = MAKE_STRUCT_FPI(0, 4);
        fpi_multiply(&a, &b, &c);
        CHECK(c.value == -3220);
    }
}