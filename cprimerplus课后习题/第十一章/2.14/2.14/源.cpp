#include<stdio.h>
#include<stdlib.h>
int main(int argc, char * argv[])
{
	double db, num = 1;
	int i, j = 0;
	db = atof(argv[1]);
	i = atoi(argv[2]);
	while (j < i)
	{
		num *= db;
		j++;
	}
	printf("%lf\n", num);
	return 0;
}