#ifndef PTHREAD_H_
#define PTHREAD_H_

#include "../../OS/Include/sched.h"
#include "../../OS/Include/time.h"

#ifdef __cplusplus
extern "C" {
#endif

    /* Detach state.  */
    enum
    {
        PTHREAD_CREATE_JOINABLE,
        PTHREAD_CREATE_DETACHED
    };

    /* Mutex types.  */
    enum
    {
        PTHREAD_MUTEX_DEFAULT,
        PTHREAD_MUTEX_ERRORCHECK,
        PTHREAD_MUTEX_NORMAL,
        PTHREAD_MUTEX_RECURSIVE,
        PTHREAD_MUTEX_ROBUST,
        PTHREAD_MUTEX_STALLED
    };

    /* Mutex protocols.  */
    enum
    {
        PTHREAD_PRIO_NONE,
        PTHREAD_PRIO_INHERIT,
        PTHREAD_PRIO_PROTECT
    };

    #if false
    /* Read-write lock types.  */
    enum
    {
      PTHREAD_RWLOCK_PREFER_READER_NP,
      PTHREAD_RWLOCK_PREFER_WRITER_NP,
      PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
      PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP
    };
    #endif

    /* Scheduler inheritance.  */
    enum
    {
        PTHREAD_INHERIT_SCHED,
        PTHREAD_EXPLICIT_SCHED
    };

    /* Scope handling.  */
    enum
    {
        PTHREAD_SCOPE_SYSTEM,
        PTHREAD_SCOPE_PROCESS
    };


    /* Process shared or private flag.  */
    enum
    {
        PTHREAD_PROCESS_PRIVATE,
        PTHREAD_PROCESS_SHARED
    };

    /* Cancellation */
    enum
    {
        PTHREAD_CANCEL_ENABLE,
        PTHREAD_CANCEL_DISABLE
    };

    enum
    {
        PTHREAD_CANCEL_DEFERRED,
        PTHREAD_CANCEL_ASYNCHRONOUS
    };

    #define PTHREAD_CANCELED ((void *) -1)

    /* Single execution handling.  */
    #define PTHREAD_ONCE_INIT 0


    /* Value returned by 'pthread_barrier_wait' for one of the threads after
       the required number of threads have called this function.
       -1 is distinct from 0 and all errno constants */
    #define PTHREAD_BARRIER_SERIAL_THREAD -1

    /** @brief Initializer for type pthread_cond_t */
    #define PTHREAD_COND_INITIALIZER    /* TODO */
    /** @brief Initializer for type pthread_mutex_t */
    #define PTHREAD_MUTEX_INITIALIZER   /* TODO */
    /** @brief Initializer for type pthread_rwlock_t */
    #define PTHREAD_RWLOCK_INITIALIZER  /* TODO */

    /*
     * Thread
     */
    int pthread_atfork(void (*)( void ), void (*)( void ), void(*)( void )  );

    int pthread_create( pthread_t * __restrict, const pthread_attr_t * __restrict, void * (*)( void * ), void * __restrict );

    int pthread_detach( pthread_t );

    int pthread_equal( pthread_t, pthread_t );

    void pthread_exit(void * );

    int pthread_getcpuclockid( pthread_t, clockid_t * );

    void * pthread_getspecific( pthread_key_t );

    int pthread_join( pthread_t, void ** );

    int pthread_key_create( pthread_key_t *, void (*)( void * ) );

    int pthread_key_delete( pthread_key_t );

    int pthread_cancel( pthread_t );

    void pthread_testcancel( void );

    int pthread_setcancelstate(int, int * );

    int pthread_setcanceltype(int, int * );

    pthread_t pthread_self(void );

    int pthread_setspecific( pthread_key_t, const void * );

    void pthread_cleanup_pop( int execute );

    void pthread_cleanup_push( void (*)( void * ), void * );

    /*
     * Thread Attribute
     */
    int pthread_attr_destroy( pthread_attr_t * );

    int pthread_attr_getdetachstate( const pthread_attr_t *, int * );

    int pthread_attr_getguardsize( const pthread_attr_t * __restrict, size_t * __restrict );

    int pthread_attr_getinheritsched( const pthread_attr_t * __restrict, int * __restrict );

    int pthread_attr_getschedparam( const pthread_attr_t * __restrict, struct sched_param * __restrict );

    int pthread_attr_getschedpolicy( const pthread_attr_t * __restrict, int * __restrict );

    int pthread_attr_getscope( const pthread_attr_t * __restrict, int * __restrict );

    int pthread_attr_getstack( const pthread_attr_t * __restrict, void ** __restrict, size_t * __restrict );

    int pthread_attr_getstacksize( const pthread_attr_t * __restrict, size_t * __restrict );

    int pthread_attr_init( pthread_attr_t * );

    int pthread_attr_setdetachstate( pthread_attr_t *, int );

    int pthread_attr_setguardsize( pthread_attr_t *, size_t );

    int pthread_attr_setinheritsched( pthread_attr_t *, int );

    int pthread_attr_setschedparam( pthread_attr_t * __restrict, const struct sched_param * __restrict );

    int pthread_attr_setschedpolicy( pthread_attr_t *, int );

    int pthread_attr_setscope( pthread_attr_t *, int );

    int pthread_attr_setstack( pthread_attr_t *, void *, size_t );

    int pthread_attr_setstacksize( pthread_attr_t *, size_t );

    /*
     * Thread Once
     */
    int pthread_once( pthread_once_t *, void (*)( void ) );

    /*
     * Barrier
     */
    int pthread_barrier_destroy( pthread_barrier_t * );

    int pthread_barrier_init( pthread_barrier_t * __restrict, const pthread_barrierattr_t * __restrict, unsigned );

    int pthread_barrier_wait( pthread_barrier_t * );

    /*
     * Barrier Attribute
     */
    int pthread_barrierattr_destroy( pthread_barrierattr_t * );

    int pthread_barrierattr_getpshared( const pthread_barrierattr_t * __restrict, int * __restrict );

    int pthread_barrierattr_init( pthread_barrierattr_t * );

    int pthread_barrierattr_setpshared( pthread_barrierattr_t *, int );

    /*
     * Condition Variable
     */
    int pthread_cond_broadcast( pthread_cond_t * );

    int pthread_cond_destroy( pthread_cond_t * );

    int pthread_cond_init( pthread_cond_t * __restrict, const pthread_condattr_t * __restrict );

    int pthread_cond_signal( pthread_cond_t * );

    int pthread_cond_timedwait( pthread_cond_t * __restrict, pthread_mutex_t * __restrict, const struct timespec * __restrict );

    int pthread_cond_wait( pthread_cond_t * __restrict, pthread_mutex_t * __restrict );

    /*
     * Condition Variable Attribute
     */
    int pthread_condattr_destroy( pthread_condattr_t * );

    int pthread_condattr_getclock( const pthread_condattr_t * __restrict, clockid_t * __restrict );

    int pthread_condattr_getpshared( const pthread_condattr_t * __restrict, int * __restrict );

    int pthread_condattr_init( pthread_condattr_t * );

    int pthread_condattr_setclock( pthread_condattr_t *, clockid_t );

    int pthread_condattr_setpshared( pthread_condattr_t *, int );

    /*
     * Scheduling
     */
    int pthread_getconcurrency(void );

    int pthread_setconcurrency(int );

    int pthread_getschedparam( pthread_t, int * __restrict, struct sched_param * __restrict );

    int pthread_setschedparam( pthread_t, int, const struct sched_param * );

    int pthread_setschedprio( pthread_t, int );

    /*
     * Mutex
     */
    int pthread_mutex_consistent( pthread_mutex_t * );

    int pthread_mutex_destroy( pthread_mutex_t * );

    int pthread_mutex_getprioceiling( const pthread_mutex_t * __restrict, int * __restrict );

    int pthread_mutex_init( pthread_mutex_t * __restrict, const pthread_mutexattr_t * __restrict );

    int pthread_mutex_lock( pthread_mutex_t * );

    int pthread_mutex_setprioceiling( pthread_mutex_t * __restrict, int, int * __restrict );

    int pthread_mutex_timedlock( pthread_mutex_t * __restrict, const struct timespec * __restrict );

    int pthread_mutex_trylock( pthread_mutex_t * );

    int pthread_mutex_unlock( pthread_mutex_t * );

    /*
     * Mutex Attribute
     */
    int pthread_mutexattr_destroy( pthread_mutexattr_t * );

    int pthread_mutexattr_getprioceiling( const pthread_mutexattr_t * __restrict, int * __restrict );

    int pthread_mutexattr_getprotocol( const pthread_mutexattr_t * __restrict, int * __restrict );

    int pthread_mutexattr_getpshared( const pthread_mutexattr_t * __restrict, int * __restrict );

    int pthread_mutexattr_getrobust( const pthread_mutexattr_t * __restrict, int * __restrict );

    int pthread_mutexattr_gettype( const pthread_mutexattr_t * __restrict, int * __restrict );

    int pthread_mutexattr_init( pthread_mutexattr_t * );

    int pthread_mutexattr_setprioceiling( pthread_mutexattr_t *, int );

    int pthread_mutexattr_setprotocol( pthread_mutexattr_t *, int );

    int pthread_mutexattr_setpshared( pthread_mutexattr_t *, int );

    int pthread_mutexattr_setrobust( pthread_mutexattr_t *, int );

    int pthread_mutexattr_settype( pthread_mutexattr_t *, int );

    /*
     * Read-Write Lock
     */
    int pthread_rwlock_destroy( pthread_rwlock_t * );

    int pthread_rwlock_init( pthread_rwlock_t * __restrict, const pthread_rwlockattr_t * __restrict );

    int pthread_rwlock_rdlock( pthread_rwlock_t * );

    int pthread_rwlock_timedrdlock( pthread_rwlock_t * __restrict, const struct timespec * __restrict );

    int pthread_rwlock_timedwrlock( pthread_rwlock_t * __restrict, const struct timespec * __restrict );

    int pthread_rwlock_tryrdlock( pthread_rwlock_t * );

    int pthread_rwlock_trywrlock( pthread_rwlock_t * );

    int pthread_rwlock_unlock( pthread_rwlock_t * );

    int pthread_rwlock_wrlock( pthread_rwlock_t * );

    /*
     * Read-Write Lock Attribute
     */
    int pthread_rwlockattr_destroy( pthread_rwlockattr_t * );

    int pthread_rwlockattr_getpshared( const pthread_rwlockattr_t * __restrict, int * __restrict );

    int pthread_rwlockattr_init( pthread_rwlockattr_t * );

    int pthread_rwlockattr_setpshared( pthread_rwlockattr_t *, int );

    /*
     * Spinlock
     */
    int pthread_spin_destroy( pthread_spinlock_t * );

    int pthread_spin_init( pthread_spinlock_t *, int );

    int pthread_spin_lock( pthread_spinlock_t * );

    int pthread_spin_trylock( pthread_spinlock_t * );

    int pthread_spin_unlock( pthread_spinlock_t * );

#ifdef __cplusplus
}
#endif

#endif /* PTHREAD_H_ */
