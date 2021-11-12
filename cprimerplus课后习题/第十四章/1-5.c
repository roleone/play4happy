#include<stdio.h>
#include<stdlib.h>
struct month{
	char name[10];
	char sx[3];
	int days;
	int num;
};
int main(void)
{
	int the,all=0,n;
	struct month year[12]=
	{
		{"January","Jan",31,1},
		{"February","Feb",29,2},
		{"March","Mar",31,3},
		{"April","Apr",30,4},
		{"May","May",31,5},
		{"June","Jun",30,6},
		{"July","Jul",31,7},
		{"August","Aug",31,8},
		{"September","Sep",30,9},
		{"October","Oct",31,10},
		{"November","Nov",30,11},
		{"December","Dec",31,12}
	};
	printf("please enter a month number\n");
	while(scanf("%d",&n)==1)
	{
		if(0>=n||n>=13)
		{
			fprintf(stderr,"the number is 1-12\n");
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<12;i++)
		{
			if(year[i].num==n)
				the=i;
		}
		for(int i=0;i<=the;i++)
		{
			all+=year[i].days;
		}
		printf("all days are %d\n",all);
		all=0;
	}
	return 0;
}
