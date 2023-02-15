#ifndef DATE_TIME_H_INCLUDED
#define DATE_TIME_H_INCLUDED

// dati -> date-time

#include <stdbool.h>
#include <stdint.h>

#define DATI_YEAR_MIN      1900
#define DATI_YEAR_MAX      4000
#define DATI_DAY_MIN       1
#define DATI_DAY_MAX       31
#define DATI_HOUR_MIN      0
#define DATI_HOUR_MAX      23
#define DATI_MINUTE_MIN    0
#define DATI_MINUTE_MAX    59
#define DATI_SECOND_MIN    0
#define DATI_SECOND_MAX    59 // TODO: allow leap second?

enum dati_month {
    DATI_MONTH_JANUARY = 1,
    DATI_MONTH_FEBRUARY = 2,
    DATI_MONTH_MARCH = 3,
    DATI_MONTH_APRIL = 4,
    DATI_MONTH_MAY = 5,
    DATI_MONTH_JUNE = 6,
    DATI_MONTH_JULY = 7,
    DATI_MONTH_AUGUST = 8,
    DATI_MONTH_SEPTEMBER = 9,
    DATI_MONTH_OCTOBER = 10,
    DATI_MONTH_NOVEMBER = 11,
    DATI_MONTH_DECEMBER = 12,
    DATI_MONTH_MIN,
};

enum date_time_flags {
    DATE_TIME_FLAG_LEAP_SECOND_ADD = (0x01 << 0),
    DATE_TIME_FLAG_LEAP_SECOND_SKIP = (0x01 << 1)
};

struct date_time {
    uint16_t year;  // 1900..4000
    uint8_t month;  // 1..12
    uint8_t day;    // enum dati_month
    uint8_t hour;   // 0..23
    uint8_t minute; // 0..59
    uint8_t second; // 0..60
    uint8_t flags;  // enum date_time_flags
};

static inline bool dati_is_leap_year(uint16_t year)
{
    if((year % 400) == 0) {
        return true;
    }
    if((year % 100) == 0) {
        return false;
    }
    if((year % 4) == 0) {
        return true;
    }
    return false;
}

static inline uint8_t dati_get_days_of_month(uint16_t year, enum dati_month month)
{
    switch(month) {
        case DATI_MONTH_APRIL:
        case DATI_MONTH_JUNE:
        case DATI_MONTH_SEPTEMBER:
        case DATI_MONTH_NOVEMBER: {
            return 30;
        }
        case DATI_MONTH_FEBRUARY: {
            if(dati_is_leap_year(year)) {
                return 29;
            }
            return 28;
        }
        default: {
            return 31;
        }
    }
}

static inline bool dati_are_date_time_equal(struct date_time* first, struct date_time* second)
{
    if(
        (first->year != second->year) ||
        (first->month != second->month) ||
        (first->day != second->day) ||
        (first->hour != second->hour) ||
        (first->minute != second->minute) ||
        (first->second != second->second)
    ) {
        return false;
    }
    return true;
}

bool dati_is_date_time_valid(struct date_time* dati);
void dati_increment_date_time(struct date_time* dati);

#endif // DATE_TIME_H_INCLUDED
