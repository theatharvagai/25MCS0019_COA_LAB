#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void fn_work_prl(float* a, float* b, float* c, int n) 
{
    float x, y;
    int i;

#pragma omp parallel for private(x, y) shared(a, b, c)
    for (i = 0; i < n; i++) {
        x = a[i];
        y = b[i];
        c[i] = x + y;
    }
}
void fn_work_srl(float* a, float* b, float* c, int n) {
    float x, y;
    int i;

    for (i = 0; i < n; i++) {
        x = a[i];
        y = b[i];
        c[i] = x + y;
    }
}

void fn_run_vector_addition_prl() 
{
    int n = 10;
    float a[10], b[10], c[10];

    for (int i = 0; i < n; i++) {
        a[i] = i * 1.0;
        b[i] = (n - i) * 1.0;
    }
 
    fn_work_prl(a, b, c, n);

    printf("Result of vector addition:\n");
    for (int i = 0; i < n; i++) {
        printf("c[%d] = %.2f\n", i, c[i]);
    }
}

void fn_run_vector_addition_srl()
{
    int n = 10;
    float a[10], b[10], c[10];

    for (int i = 0; i < n; i++) {
        a[i] = i * 1.0;
        b[i] = (n - i) * 1.0;
    }

    fn_work_srl(a, b, c, n);

    printf("Result of vector addition:\n");
    for (int i = 0; i < n; i++) {
        printf("c[%d] = %.2f\n", i, c[i]);
    }
}