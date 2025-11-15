#include <stdio.h>
#include "omp.h"
//#include <omp_llvm.h>

// 1. omp_set_num_threads
void fn_rter_omp_set_num_threads(int num_threads)
{
#pragma omp parallel
    omp_set_num_threads(num_threads);
    printf("Number of threads set to: %d\n", num_threads);
    printf("Thread %d out of %d\n", omp_get_thread_num(), omp_get_num_threads());
}

// 2. omp_get_num_threads
void fn_rter_omp_get_num_threads()
{
    int num_threads = omp_get_num_threads();
    printf("Number of threads: %d\n", num_threads);
}

// 3. omp_get_max_threads
void fn_rter_omp_get_max_threads()
{
    int max_threads = omp_get_max_threads();
    printf("Maximum number of threads: %d\n", max_threads);
}

// 4. omp_get_thread_num
void fn_rter_omp_get_thread_num()
{
    int thread_num = omp_get_thread_num();
    printf("Current thread number: %d\n", thread_num);
}

// 5. omp_get_num_procs
void fn_rter_omp_get_num_procs()
{
    int num_procs = omp_get_num_procs();
    printf("Number of processors available: %d\n", num_procs);
}

// 6. omp_in_parallel
void fn_rter_omp_in_parallel()
{
    if (omp_in_parallel())
        printf("Currently in parallel region.\n");
    else
        printf("Not in parallel region.\n");
#pragma omp parallel
    {
        if (omp_in_parallel()) {
            printf("Thread %d: Inside parallel region\n", omp_get_thread_num());
        } else {
            printf("Thread %d: Outside parallel region\n", omp_get_thread_num());
        }
    }
}

// 7. omp_set_dynamic
void fn_rter_omp_set_dynamic(int dynamic_threads)
{
#pragma omp parallel
    omp_set_dynamic(dynamic_threads);
    printf("Dynamic threads set to: %d\n", dynamic_threads);
}

// 8. omp_get_dynamic
void fn_rter_omp_get_dynamic()
{
    int dynamic_threads = omp_get_dynamic();
    printf("Dynamic threads: %d\n", dynamic_threads);
}

// 9. omp_get_cancellation
void fn_rter_omp_get_cancellation()
{
    printf("Cancellation is not directly retrievable in OpenMP.\n");
}

// 10. omp_set_nested
void fn_rter_omp_set_nested(int nested)
{
#pragma omp parallel
    omp_set_nested(nested);
    printf("Nested parallelism set to: %d\n", nested);
}

// 11. omp_get_nested
void fn_rter_omp_get_nested()
{
    int nested = omp_get_nested();
    printf("Nested parallelism: %d\n", nested);
}

// 12. omp_set_schedule
void fn_rter_omp_set_schedule(int chunk_size)
{
#if defined(_OPENMP) && (_OPENMP >= 200805)
    omp_set_schedule(omp_sched_dynamic, chunk_size);
    printf("Schedule set to kind: %d with chunk size: %d\n", omp_sched_dynamic, chunk_size);
#else
    printf("omp_set_schedule is not supported by this compiler/OpenMP version.\n");
#endif
}

// 13. omp_get_schedule
void fn_rter_omp_get_schedule()
{
#if defined(_OPENMP) && (_OPENMP >= 200805)
    int kind, chunk_size;
    omp_get_schedule(&kind, &chunk_size);
    printf("Current schedule kind: %d, chunk size: %d\n", kind, chunk_size);
#else
    printf("omp_get_schedule is not supported by this compiler/OpenMP version.\n");
#endif
}

// 14. omp_get_thread_limit
void fn_rter_omp_get_thread_limit()
{
#if defined(_OPENMP) && (_OPENMP >= 201107)
    int limit = omp_get_thread_limit();
    printf("Thread limit: %d\n", limit);
#else
    printf("omp_get_thread_limit is not supported by this compiler/OpenMP version.\n");
#endif
}

// 15. omp_set_max_active_levels
void fn_rter_omp_set_max_active_levels(int max_levels)
{
#if defined(_OPENMP) && (_OPENMP >= 201107)
    omp_set_max_active_levels(max_levels);
    printf("Max active levels set to: %d\n", max_levels);
#else
    printf("omp_set_max_active_levels is not supported by this compiler/OpenMP version.\n");
#endif
}

// 16. omp_get_max_active_levels
void fn_rter_omp_get_max_active_levels()
{
#if defined(_OPENMP) && (_OPENMP >= 201107)
    int max_levels = omp_get_max_active_levels();
    printf("Max active levels: %d\n", max_levels);
#else
    printf("omp_get_max_active_levels is not supported by this compiler/OpenMP version.\n");
#endif
}

// 17. omp_get_level
void fn_rter_omp_get_level()
{
#if defined(_OPENMP) && (_OPENMP >= 201107)
    int level = omp_get_level();
    printf("Current parallel level: %d\n", level);
#else
    printf("omp_get_level is not supported by this compiler/OpenMP version.\n");
#endif
}

// 18. omp_get_ancestor_thread_num
void fn_rter_omp_get_ancestor_thread_num(int level)
{
#if defined(_OPENMP) && (_OPENMP >= 201107)
    int ancestor = omp_get_ancestor_thread_num(level);
    printf("Ancestor thread num at level %d: %d\n", level, ancestor);
#else
    printf("omp_get_ancestor_thread_num is not supported by this compiler/OpenMP version.\n");
#endif
}

// 19. omp_get_team_size
void fn_rter_omp_get_team_size(int level)
{
#if defined(_OPENMP) && (_OPENMP >= 201107)
    int size = omp_get_team_size(level);
    printf("Team size at level %d: %d\n", level, size);
#else
    printf("omp_get_team_size is not supported by this compiler/OpenMP version.\n");
#endif
}

// 20. omp_get_active_level
void fn_rter_omp_get_active_level()
{
#if defined(_OPENMP) && (_OPENMP >= 201107)
    int active_level = omp_get_active_level();
    printf("Active parallel level: %d\n", active_level);
#else
    printf("omp_get_active_level is not supported by this compiler/OpenMP version.\n");
#endif
}

// 21. omp_in_final
void fn_rter_omp_in_final()
{
#if defined(_OPENMP) && (_OPENMP >= 201107)
#pragma omp parallel
    {
        if (omp_in_final())
            printf("Thread %d: In final region\n", omp_get_thread_num());
        else
            printf("Thread %d: Not in final region\n", omp_get_thread_num());
    }
#else
    printf("omp_in_final is not supported by this compiler/OpenMP version.\n");
#endif
}

// 22. omp_get_proc_bind
void fn_rter_omp_get_proc_bind()
{
#if defined(_OPENMP) && (_OPENMP >= 201307)
    omp_proc_bind_t bind = omp_get_proc_bind();
    printf("Proc bind: %d\n", bind);
#else
    printf("omp_get_proc_bind is not supported by this compiler/OpenMP version.\n");
#endif
}

// 23. omp_set_default_device
void fn_rter_omp_set_default_device(int device)
{
#if defined(_OPENMP) && (_OPENMP >= 201307)
    omp_set_default_device(device);
    printf("Default device set to: %d\n", device);
#else
    printf("omp_set_default_device is not supported by this compiler/OpenMP version.\n");
#endif
}

// 24. omp_get_default_device
void fn_rter_omp_get_default_device()
{
#if defined(_OPENMP) && (_OPENMP >= 201307)
    int device = omp_get_default_device();
    printf("Default device: %d\n", device);
#else
    printf("omp_get_default_device is not supported by this compiler/OpenMP version.\n");
#endif
}

// 25. omp_get_num_devices
void fn_rter_omp_get_num_devices()
{
#if defined(_OPENMP) && (_OPENMP >= 201307)
    int num_devices = omp_get_num_devices();
    printf("Number of devices: %d\n", num_devices);
#else
    printf("omp_get_num_devices is not supported by this compiler/OpenMP version.\n");
#endif
}

// 26. omp_get_num_teams
void fn_rter_omp_get_num_teams()
{
#if defined(_OPENMP) && (_OPENMP >= 201307)
#pragma omp target teams map(from:teams)
    {
        int teams = omp_get_num_teams();
        printf("Number of teams: %d\n", teams);
    }
#else
    printf("omp_get_num_teams is not supported by this compiler/OpenMP version.\n");
#endif
}

// 27. omp_get_team_num
void fn_rter_omp_get_team_num()
{
#if defined(_OPENMP) && (_OPENMP >= 201307)
#pragma omp target teams map(from:team_num)
    {
        int team_num = omp_get_team_num();
        printf("Team num: %d\n", team_num);
    }
#else
    printf("omp_get_team_num is not supported by this compiler/OpenMP version.\n");
#endif
}
