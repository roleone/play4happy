#include<stdio.h>
void copy_arr(double[], double[], int);
void copy_ptr(double[], double[], int);
void copy_ptrs(double[], double[], double[]);
int main(void)
{
	int i;
	double source[5] = { 1.1,2.2,3.3,4.4,5.5 };
	double target1[5];
	double target2[5];
	double target3[5];
	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source+5);
	for (i = 0; i < 5; i++)
		printf("%lf  ", target1[i]);
	printf("\n");
	for (i = 0; i < 5; i++)
		printf("%lf  ", target2[i]);
	printf("\n");
	for (i = 0; i < 5; i++)
		printf("%lf  ", target3[i]);
	printf("\n");
	getchar();
	return 0;
}
void copy_arr(double a[], double b[], int c)
{
	int i;
	for (i = 0; i < c; i++)
		a[i] = b[i];
}
void copy_ptr(double a[], double b[], int c)
{
	int i;
	for (i = 0; i < c; i++)
	{
		*(a + i) = *(b + i);
	}
}
void copy_ptrs(double a[], double b[], double c[])
{
	double * i;
	int j;
	for (i = b, j = 0; i < c; i++, j++)
		*(a + j) = *(b + j);
}