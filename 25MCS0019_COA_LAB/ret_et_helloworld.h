#include "stdio.h"
#include "omp.h"

void fn_ret_et_helloworld_srl()
{
	double start, end;
	start = omp_get_wtime();

	printf("Hello World Serial. \n");
	
	end = omp_get_wtime();
	printf("Execution time od serial program is %f\n", end - start);
}
void fn_ret_et_helloworld_prl()
{
	double start, end;
	start = omp_get_wtime();
#pragma omp parallel
	printf("Hello World Parallel. \n");

	end = omp_get_wtime();
	printf("Execution time od Parallel program is %f\n", end - start);

}