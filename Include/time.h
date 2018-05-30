#ifndef TIME_H_
#define TIME_H_

#include "../../OS/Include/sys/types.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct tm
    {
        /** @brief Seconds [0,60]. */
        int tm_sec;

        /** @brief Minutes [0,59]. */
        int tm_min;

        /** @brief Hour [0,23]. */
        int tm_hour;

        /** @brief Day of month [1,31]. */
        int tm_mday;

        /** @brief Month of year [0,11]. */
        int tm_mon;

        /** @brief Years since 1900. */
        int tm_year;

        /** @brief Day of week [0,6] (Sunday =0). */
        int tm_wday;

        /** @brief Day of year [0,365]. */
        int tm_yday;

        /** @brief Daylight Savings flag.
         * The value of tm_isdst shall be:
         * positive if Daylight Savings Time is in effect,
         * 0 if Daylight Savings Time is not in effect,
         * negative if the information is not available.
         */
        int tm_isdst;
    };

    struct timespec
    {
        /** @brief Seconds. */
        time_t  tv_sec;

        /** @brief Nanoseconds. */
        long    tv_nsec;
    };

    struct itimerspec
    {
        /** @brief Timer period. */
        struct timespec  it_interval;

        /** @brief Timer expiration. */
        struct timespec  it_value;
    };

    #if false
    #define NULL
    #endif

    /* TODO: Complete the definitions by some values in here */
    #define CLOCKS_PER_SEC

    #define CLOCK_MONOTONIC

    #define CLOCK_PROCESS_CPUTIME_ID

    #define CLOCK_REALTIME

    #define CLOCK_THREAD_CPUTIME_ID

    #define TIMER_ABSTIME

    char * asctime( const struct tm * );

    char * asctime_r( const struct tm * __restrict, char * __restrict );

    clock_t clock( void );

    int clock_getcpuclockid( pid_t, clockid_t * );

    int clock_getres( clockid_t, struct timespec * );

    int clock_gettime( clockid_t, struct timespec * );

    int clock_nanosleep( clockid_t, int, const struct timespec *, struct timespec * );

    int clock_settime( clockid_t, const struct timespec * );

    char * ctime( const time_t * );

    char * ctime_r( const time_t *, char * );

    double difftime( time_t, time_t );

    struct tm *getdate( const char * );

    struct tm *gmtime( const time_t * );

    struct tm *gmtime_r( const time_t * __restrict, struct tm * __restrict );

    struct tm *localtime( const time_t * );

    struct tm *localtime_r( const time_t * __restrict, struct tm * __restrict );

    time_t mktime( struct tm * );

    int nanosleep( const struct timespec *, struct timespec * );

    #if false
    size_t strftime( char * __restrict, size_t, const char * __restrict, const struct tm * __restrict );

    size_t strftime_l( char * __restrict, size_t, const char * __restrict, const struct tm * __restrict, locale_t );
    #endif

    char * strptime( const char * __restrict, const char * __restrict, struct tm * __restrict );

    time_t time( time_t * );

    int timer_create( clockid_t, struct sigevent * __restrict, timer_t * __restrict );

    int timer_delete( timer_t );

    int timer_getoverrun( timer_t );

    int timer_gettime( timer_t, struct itimerspec * );

    int timer_settime( timer_t, int, const struct itimerspec * __restrict, struct itimerspec * __restrict );

    void tzset( void );

     int    daylight;

     long   timezone;
#if false
     char * tzname[];
#endif

#ifdef __cplusplus
}
#endif

#endif /* TIME_H_ */
