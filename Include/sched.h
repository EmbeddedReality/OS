#ifndef SCHED_H_
#define SCHED_H_

#include "../../OS/Include/sys/types.h"
#include "../../OS/Include/time.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct sched_param
    {
        /** @brief Process or thread execution scheduling priority. */
        int sched_priority;

        /** @brief Low scheduling priority for sporadic server. */
        int sched_ss_low_priority;

        /** @brief Replenishment period for sporadic server. */
        struct timespec sched_ss_repl_period;

        /** @brief Initial budget for sporadic server. */
        struct timespec sched_ss_init_budget;

        /** @brief Maximum pending replenishments for sporadic server. */
        int sched_ss_max_repl;
    };

    enum
    {
        SCHED_FIFO,
        SCHED_RR,
        SCHED_SPORADIC,
        SCHED_OTHER
    };

    int sched_get_priority_max( int );

    int sched_get_priority_min( int );

    int sched_getparam( pid_t, struct sched_param * );

    int sched_getscheduler( pid_t );

    int sched_rr_get_interval( pid_t, struct timespec * );

    int sched_setparam( pid_t, const struct sched_param * );

    int sched_setscheduler( pid_t, int, const struct sched_param * );

    int sched_yield( void );

#ifdef __cplusplus
}
#endif

#endif /* SCHED_H_ */
