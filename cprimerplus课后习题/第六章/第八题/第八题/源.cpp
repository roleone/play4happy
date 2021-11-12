#include<stdio.h>
double jisuan(double d_a,double d_b);
int main(void)
{
	double a, b;
	while (scanf("%lf %lf", &a, &b))
	{
		printf("%lf\n", jisuan(a, b));
	}
	return 0;
}
double jisuan(double d_a,double d_b)
{
	double d_c;
	d_c = (d_a - d_b) / (d_a*d_b);
	return d_c;
}