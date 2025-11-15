#include "stdio.h"
#include "omp.h"

void fn_helloworld_prl()
{
    double start = omp_get_wtime();

#pragma omp parallel
    printf("Hello world parallel. \n");

    double end = omp_get_wtime();
    printf("Execution Time (Parallel): %.9f seconds\n", end - start);
}
