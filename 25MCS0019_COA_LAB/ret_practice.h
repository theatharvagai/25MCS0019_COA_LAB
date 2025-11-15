#include"stdio.h"
#include"omp.h"

double speedup(double et_serial, double et_parallel)
{
	double s;
	s = (et_serial / (double)et_parallel);
	return s;
}
double efficiency(double speed, int no_of_cores)
{
	double eff;
	eff = (speed / (double)no_of_cores) * 100;
	return eff;

}
void fn_ret_practice_srl()
{
	double start, end;
	start = omp_get_wtime();
	printf("helloworld serial\n");
	end = omp_get_wtime();
	printf("ID for this program is %d\n", omp_get_thread_num());
	printf("Execution time for serial program = %fns\n", -start + end);
	//printf("speed up is %f\n", speedup(2, 2));
}
void fn_ret_practice_prl()
{
	double start, end;
	start = omp_get_wtime();
	printf("helloworld serial\n");
	end = omp_get_wtime();
	double ex1 = end - start;
	printf("Execution time for serial program = %fns\n", ex1);
	double start1, end1;
	start1 = omp_get_wtime();
	omp_set_num_threads(4);
#pragma omp parallel
	{
		printf("ID for this program is %d\n", omp_get_thread_num());
	}
	end1 = omp_get_wtime();
	double ex2 = end1 - start1;
	printf("Execution time for parallel program = %fns\n", ex2);
	double s = speedup(ex1, ex2);
	printf("speed up is %f\n", s);
	double eff = efficiency(s, 2);
	printf("efficiency is %f\n", eff);
}