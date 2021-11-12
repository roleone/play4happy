#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
struct month{
	char name[10];
	char sx[3];
	int days;
	int num;
};
int main(void)
{
	int the,all=0;
	char mon[4];
	bool k=false;
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
	printf("please enter a month suoxie\n");
	while(scanf("%s",mon)==1)
	{
		while(getchar()!='\n')
			continue;
		for(int i=0;i<12;i++)
		{
			if(strcmp(year[i].sx,mon)==0)
			{
				the=i;
				k=true;
			}
		}
		if(k==true)
		{
			for(int i=0;i<=the;i++)
	        	{
		        	all+=year[i].days;
		        }
	        	printf("all days are %d\n",all);
		}
		else
		{
			fprintf(stderr,"NON\n");
			exit(EXIT_FAILURE);
		}
		k=false;
		all=0;
	}
	return 0;
}
