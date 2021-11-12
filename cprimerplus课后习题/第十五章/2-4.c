#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
bool test(int ,int);
int main(void)
{
	int a,b;
	bool n;
	while(1)
	{
		printf("enter a number and the position:\n");
		if(scanf("%d%d",&a,&b)!=2||b<0||b>32)
		{
			fprintf(stderr,"enter wrong\n");
			exit(EXIT_FAILURE);
		}
		n=test(a,b);
		if(n)
		{
			printf("%d at no.%d is true\n",a,b);
		}
		else
		{
			printf("%d at no.%d is false\n",a,b);
		}
	}
	return 0;
}
bool test(int a,int b)
{
	int k=1;
	bool choose;
	k<<=(b-1);
	if(a&k)
		choose=true;
	else
		choose=false;
	return choose;
}
