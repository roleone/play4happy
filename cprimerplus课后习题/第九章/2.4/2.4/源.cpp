#include<stdio.h>
double kkp(double a, double b);
int main(void)
{
	double a, b,c;
	scanf("%lf%lf", &a, &b);
	c=kkp(a, b);
	printf("%lf", c);
	getchar();
	getchar();
	return 0;
}
double kkp(double a, double b)
{
	return 1 / ((1.0 / a + 1.0 / b) / 2);
}