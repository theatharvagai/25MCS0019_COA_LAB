#include <stdio.h>
#include <omp.h>

void fn_dec_critical_prl() 
{
    int i, n = 10;
    int arr[10];
    int sum = 0;

    for (i = 0; i < n; i++)
        arr[i] = i + 1; 

#pragma omp parallel for
    for (i = 0; i < n; i++) {
#pragma omp critical
        {
            sum += arr[i];
            printf("Thread %d added %d to sum\n", omp_get_thread_num(), arr[i]);
        }
    }
    printf("Final Sum = %d\n", sum);
}
void fn_dec_critical_srl()
{
    int i, n = 10;
    int arr[10];
    int sum = 0;

    for (i = 0; i < n; i++)
        arr[i] = i + 1;
    for (i = 0; i < n; i++) 
    {
        sum += arr[i];
        printf("Thread %d added %d to sum\n", omp_get_thread_num(), arr[i]);
    }
    printf("Final Sum = %d\n", sum);
}
