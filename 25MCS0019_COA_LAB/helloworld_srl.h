#include "stdio.h"
#include "omp.h"

void fn_helloworld_srl()
{
    double start, end, execTime;

    start = omp_get_wtime();


    printf("Hello World\n");

    end = omp_get_wtime();

    execTime = end - start;

    printf("Execution Time (Serial): %.9f seconds\n", execTime);
}
