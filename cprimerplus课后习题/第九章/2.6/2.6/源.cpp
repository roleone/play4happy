#include<stdio.h>
void justice(double *, double *, double *);
int main(void)
{
	double x, y, z;
	printf("���������������°���С����\n");
	scanf("%lf%lf%lf", &x, &y, &z);
	justice(&x, &y, &z);
	printf("%.2lf  %.2lf  %.2lf", x, y, z);
	while (getchar() != '\n')
		continue;
	getchar();
	return 0;
}
void justice(double *a, double *b, double *c)
{
	double temp;
	if (*a > *b)
	{
		temp = *b;
		*b = *a;
		*a = temp;
	}
	if (*a > *c)
	{
		temp = *c;
		*c = *a;
		*a = temp;
	}
	if (*b > *c)
	{
		temp = *c;
		*c = *b;
		*b = temp;
	}
}