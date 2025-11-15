#include<stdio.h>
#include"ret_et_helloworld.h"
#include"ret_tid_helloworld.h"
#include <cstdlib>

int fn_mnudrvprg_020_parallel_construct()
{
	int choice;
	while (1)
	{
		printf("#####################\n");
		printf("List of choices\n");
		printf("#####################\n");
		printf("0. Exit\n");
		printf("1. Execution Time of Serial Programming output\n");
		printf("2. Execution Time of Parallel Programming output\n");
		printf("3. Thread ID of Serial Programming\n");
		printf("4. Thread ID of Parallel Programming\n");
		printf("Enter your choice\n");
		scanf_s("%d", &choice);				//secure scanf
		switch (choice)
		{
		case 0:
		{
			printf("You opted to exit the program.\n");
			exit(0);
		}
		case 1:
		{
			fn_ret_et_helloworld_srl();
			break;
		}
		case 2:
		{
			fn_ret_et_helloworld_prl();
			break;
		}
		case 3:
		{
			fn_ret_tid_helloworld_srl();
			break;
		}
		case 4:
		{
			fn_ret_tid_helloworld_prl();
			break;
		}
		default:
		{
			printf("Opted wrong choice\n");
			break;
		}
		}
	}
	return 0;
}