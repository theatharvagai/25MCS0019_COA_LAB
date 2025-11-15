#include<stdio.h>
#include"helloworld_srl.h"
#include"helloworld_prl.h"
#include <cstdlib>

int fn_mnudrvprg_010_parallel_construct()
{
	int choice;
	while (1)
	{
		printf("#####################\n");
		printf("List of choices\n");
		printf("#####################\n");
		printf("0. Exit\n");
		printf("1. Hello World Serial Programming output\n");
		printf("2. Hello World Parallel Programming output\n");
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
			printf("This is output of Hello World Serial Programming\n");
			fn_helloworld_srl();
			break;
		}
		case 2:
		{
			printf("this is Hello World Parallel Programming\n");
			fn_helloworld_prl();
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