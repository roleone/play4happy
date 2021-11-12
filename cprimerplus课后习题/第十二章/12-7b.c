#include<stdio.h>
#include<stdlib.h>
int roll_n_dice(int n,int m)
{
	int pop=0;
	if(m<2)
	{
		printf("Need at least 2 sides.\n");
		return -1;
	}
	if(n<1)
	{
		printf("Need at least 1 dice.\n");
		return -2;
	}
	for(int i=0;i<n;i++)
	{
		pop+=rand()%m+1;
	}
	return pop;
}
