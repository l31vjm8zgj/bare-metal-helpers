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
    SUBCASE("zero init") {
        struct date_time dati = {0, 0, 0, 0, 0, 0, 0};
        CHECK(dati_is_date_time_valid(&dati) == false);
    }
    SUBCASE("lower limit") {
        struct date_time dati = {1900, 1, 1, 0, 0, 0};
        CHECK(dati_is_date_time_valid(&dati) == true);
        SUBCASE("year") {
            dati.year = 1899;
            CHECK(dati_is_date_time_valid(&dati) == false);
        }
        SUBCASE("month") {
            dati.month = 0;
            CHECK(dati_is_date_time_valid(&dati) == false);
        }
        SUBCASE("day") {
            dati.day = 0;
            CHECK(dati_is_date_time_valid(&dati) == false);
        }
    }
    SUBCASE("upper limit") {
        struct date_time dati = {4000, 12, 31, 23, 59, 59};
        CHECK(dati_is_date_time_valid(&dati) == true);
        SUBCASE("year") {
            dati.year = 4001;
            CHECK(dati_is_date_time_valid(&dati) == false);
        }
        SUBCASE("month") {
            dati.month = 13;
            CHECK(dati_is_date_time_valid(&dati) == false);
        }
        SUBCASE("day") {
            dati.day = 32;
            CHECK(dati_is_date_time_valid(&dati) == false);
        }
        SUBCASE("hour") {
            dati.hour = 24;
            CHECK(dati_is_date_time_valid(&dati) == false);
        }
        SUBCASE("minute") {
            dati.minute = 60;
            CHECK(dati_is_date_time_valid(&dati) == false);
        }
        SUBCASE("second") {
            dati.second = 60;
            CHECK(dati_is_date_time_valid(&dati) == false);
        }
    }
    SUBCASE("no leap year") {
        struct date_time dati = {2023, 2, 15, 15, 47, 56, 0};
        CHECK(dati_is_date_time_valid(&dati) == true);

        dati.day = 28;
        CHECK(dati_is_date_time_valid(&dati) == true);

        dati.day = 29;
        CHECK(dati_is_date_time_valid(&dati) == false);
    }
    SUBCASE("leap year") {
        struct date_time dati = {2024, 2, 28, 10, 21, 31};
        CHECK(dati_is_date_time_valid(&dati) == true);

        dati.day = 29;
        CHECK(dati_is_date_time_valid(&dati) == true);

        dati.day = 30;
        CHECK(dati_is_date_time_valid(&dati) == false);
    }
}

TEST_CASE("dati_increment_date_time()")
{
    struct date_time dati = {2023, 2, 15, 15, 47, 56, 0};
    struct date_time check = {2023, 2, 15, 15, 47, 57, 0};
    dati_increment_date_time(&dati);
    CHECK(dati_are_date_time_equal(&dati, &check) == true);

    dati = {2022, 12, 31, 23, 59, 59};
    dati_increment_date_time(&dati);
    check = {2023, 1, 1, 0, 0, 0};
    CHECK(dati_are_date_time_equal(&dati, &check) == true);

    dati = {2024, 2, 28, 23, 59, 59};
    dati_increment_date_time(&dati);
    check = {2024, 2, 29, 0, 0, 0};
    CHECK(dati_are_date_time_equal(&dati, &check) == true);
}