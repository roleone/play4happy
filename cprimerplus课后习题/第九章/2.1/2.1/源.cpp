#include<stdio.h>
double smaller(double x, double y);
int main(void)
{
	double a, b,n;
	printf("enter 2 number to choose the smaller\n");
	scanf("%lf%lf", &a, &b);
	n=smaller(a, b);
	printf("%lf", n);
	getchar();
	getchar();
	return 0;
}
double smaller(double x, double y)
{
	x = (x > y) ? y : x;
	return x;
}