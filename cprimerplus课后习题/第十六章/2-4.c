#include<stdio.h>
#include<time.h>
#include<stdlib.h>
clock_t report(void);
int main(void)
{
	double timer;
	clock_t now;
	printf("enter a time:\n");
	if(scanf("%lf",&timer)!=1)
	{
		fprintf(stderr,"enter wrong\n");
		exit(EXIT_FAILURE);
	}
	now=clock();
	while(timer>((double)report()-(double)now)/CLOCKS_PER_SEC)
		continue;
	return 0;
}
clock_t report(void)
{
	clock_t old;
	old=clock();
	printf("now is %lf\n",(double)old/CLOCKS_PER_SEC);
	return old;
}
