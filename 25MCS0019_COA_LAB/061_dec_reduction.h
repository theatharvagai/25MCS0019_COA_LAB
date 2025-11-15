#include <stdio.h>
#include <omp.h>

void fn_dec_reduction_prl() {
    int n = 10;
    int arr[10];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;  
    }
#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Sum of array elements = %d\n", sum);
}

void fn_dec_reduction_srl() {
    int n = 10;
    int arr[10];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Sum of array elements = %d\n", sum);
}
