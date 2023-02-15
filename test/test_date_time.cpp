#include "doctest.h"

extern "C" {
    #include "date-time/date_time.h"
}

TEST_CASE("dati_is_leap_year()")
{
    CHECK(dati_is_leap_year(1900) == false);
    CHECK(dati_is_leap_year(1904) == true);
    CHECK(dati_is_leap_year(1959) == false);
    CHECK(dati_is_leap_year(1960) == true);
    CHECK(dati_is_leap_year(1961) == false);
    CHECK(dati_is_leap_year(1995) == false);
    CHECK(dati_is_leap_year(1996) == true);
    CHECK(dati_is_leap_year(1997) == false);
    CHECK(dati_is_leap_year(1999) == false);
    CHECK(dati_is_leap_year(2000) == true);
    CHECK(dati_is_leap_year(2001) == false);
    CHECK(dati_is_leap_year(2002) == false);
    CHECK(dati_is_leap_year(2003) == false);
    CHECK(dati_is_leap_year(2004) == true);
    CHECK(dati_is_leap_year(2005) == false);
    CHECK(dati_is_leap_year(2020) == true);
    CHECK(dati_is_leap_year(2023) == false);
    CHECK(dati_is_leap_year(2095) == false);
    CHECK(dati_is_leap_year(2096) == true);
    CHECK(dati_is_leap_year(2097) == false);
    CHECK(dati_is_leap_year(2099) == false);
    CHECK(dati_is_leap_year(2100) == false);
    CHECK(dati_is_leap_year(2101) == false);
    CHECK(dati_is_leap_year(2102) == false);
    CHECK(dati_is_leap_year(2103) == false);
    CHECK(dati_is_leap_year(2104) == true);
    CHECK(dati_is_leap_year(2105) == false);
}

TEST_CASE("dati_get_days_of_month()")
{
    SUBCASE("not a leap year") {
        CHECK(dati_get_days_of_month(1999, DATI_MONTH_JANUARY) == 31);
        CHECK(dati_get_days_of_month(1999, DATI_MONTH_FEBRUARY) == 28);
        CHECK(dati_get_days_of_month(1999, DATI_MONTH_MARCH) == 31);
        CHECK(dati_get_days_of_month(1999, DATI_MONTH_APRIL) == 30);
        CHECK(dati_get_days_of_month(1999, DATI_MONTH_MAY) == 31);
        CHECK(dati_get_days_of_month(1999, DATI_MONTH_JUNE) == 30);
        CHECK(dati_get_days_of_month(1999, DATI_MONTH_JULY) == 31);
        CHECK(dati_get_days_of_month(1999, DATI_MONTH_AUGUST) == 31);
        CHECK(dati_get_days_of_month(1999, DATI_MONTH_SEPTEMBER) == 30);
        CHECK(dati_get_days_of_month(1999, DATI_MONTH_OCTOBER) == 31);
        CHECK(dati_get_days_of_month(1999, DATI_MONTH_NOVEMBER) == 30);
        CHECK(dati_get_days_of_month(1999, DATI_MONTH_DECEMBER) == 31);
    }

    SUBCASE("not a leap year") {
        CHECK(dati_get_days_of_month(2000, DATI_MONTH_JANUARY) == 31);
        CHECK(dati_get_days_of_month(2000, DATI_MONTH_FEBRUARY) == 29);
        CHECK(dati_get_days_of_month(2000, DATI_MONTH_MARCH) == 31);
        CHECK(dati_get_days_of_month(2000, DATI_MONTH_APRIL) == 30);
        CHECK(dati_get_days_of_month(2000, DATI_MONTH_MAY) == 31);
        CHECK(dati_get_days_of_month(2000, DATI_MONTH_JUNE) == 30);
        CHECK(dati_get_days_of_month(2000, DATI_MONTH_JULY) == 31);
        CHECK(dati_get_days_of_month(2000, DATI_MONTH_AUGUST) == 31);
        CHECK(dati_get_days_of_month(2000, DATI_MONTH_SEPTEMBER) == 30);
        CHECK(dati_get_days_of_month(2000, DATI_MONTH_OCTOBER) == 31);
        CHECK(dati_get_days_of_month(2000, DATI_MONTH_NOVEMBER) == 30);
        CHECK(dati_get_days_of_month(2000, DATI_MONTH_DECEMBER) == 31);
    }
}

TEST_CASE("dati_is_date_time_valid()")
{
    // TODO
}