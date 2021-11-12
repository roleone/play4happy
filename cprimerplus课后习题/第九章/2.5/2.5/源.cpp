#include<stdio.h>
void larger_of(double *, double *);
int main(void)
{
	double a, b;
	printf("enter 2 numbers,i will let them become the bigger\n");
	scanf("%lf%lf", &a, &b);
	larger_of(&a, &b);
	printf("%.2lf  %.2lf", a, b);
	while (getchar() != '\n')
		continue;
	getchar();
	return 0;
}
void larger_of(double * a, double * b)
{
	*a = *b = (*a > *b) ? *a : *b;
}