#include "date_time.h"

bool dati_is_date_time_valid(struct date_time* dati)
{
    if((dati->year < DATI_YEAR_MIN) || (dati->year > DATI_YEAR_MAX)) {
        return false;
    }
    if(
        (dati->month < ((uint8_t)DATI_MONTH_JANUARY)) ||
        (dati->month > ((uint8_t)DATI_MONTH_DECEMBER))
    ) {
        return false;
    }
    if((dati->day < DATI_DAY_MIN) || (dati->day > DATI_DAY_MAX)) {
        return false;
    }
    if(dati->day > dati_get_days_of_month(dati->year, (enum dati_month)dati->month)) {
        return false;
    }
    if((dati->hour < DATI_HOUR_MIN) || (dati->hour > DATI_HOUR_MAX)) {
        return false;
    }
    if((dati->minute < DATI_MINUTE_MIN) || (dati->minute > DATI_MINUTE_MAX)) {
        return false;
    }
    if((dati->second < DATI_SECOND_MIN) || (dati->second > DATI_SECOND_MAX)) {
        return false;
    }
    return true;
}

void dati_increment_date_time(struct date_time* dati)
{
    dati->second++;
    if(dati->second > DATI_SECOND_MAX) {
        dati->second = DATI_SECOND_MIN;
        dati->minute++;
    }
    if(dati->minute > DATI_MINUTE_MAX) {
        dati->minute = DATI_MINUTE_MIN;
        dati->hour++;
    }
    if(dati->hour > DATI_HOUR_MAX) {
        dati->hour = DATI_HOUR_MIN;
        dati->day++;
    }
    uint8_t max_days = dati_get_days_of_month(dati->year, (enum dati_month)dati->month);
    if(dati->day > max_days) {
        dati->day = DATI_DAY_MIN;
        dati->month++;
    }
    if(dati->month > DATI_MONTH_DECEMBER) {
        dati->month = DATI_MONTH_JANUARY;
        dati->year++;
    }
}