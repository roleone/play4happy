#include<stdio.h>
#include<stdlib.h>
#define A(x,y) (1/((1/(x)+1/(y))/2))
int main(int argc,char*argv[])
{
	if(argc!=3)
	{
		fprintf(stderr,"enter wrong\n");
		exit(EXIT_FAILURE);
	}
	printf("%lf\n",A(atof(argv[1]),atof(argv[2])));
	return 0;
}
