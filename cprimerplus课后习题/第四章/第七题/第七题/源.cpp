#include<stdio.h>
#include<float.h>
int main(void)
{
	float f_a;
	double d_a;
	f_a = 1.0 / 3.0;
	d_a = 1.0 / 3.0;
	printf("float位数:%d\ndouble位数:%d\n", FLT_DIG, DBL_DIG);
	printf("%.6f %.6f\n", f_a, d_a);
	printf("%.12f %.12f\n", f_a, d_a);
	printf("%.16f %.16f\n", f_a, d_a);
	getchar();
	return 0;
}