#include<stdio.h>
void print(double[], int);
void copy_arr(double [],double [], int);
int main(void)
{
	int i;
	double k1[3][2] = 
	{
		{3.3,2.1},{3.2,4.1},{2.5,3.6}
	};
	double k2[3][2];
	for (i = 0; i < 3; i++)
		copy_arr(k2[i], *(k1+i), 2);
	for (i = 0; i < 3; i++)
	{
		print(k1[i], 2);
		printf("\n");
	}
	for (i = 0; i < 3; i++)
	{
		print(k2[i], 2);
		printf("\n");
	}
	getchar();
	return 0;
}
void copy_arr(double a[],double b[], int c)
{
	int i;
	for (i = 0; i < c; i++)
		a[i] = b[i];
}
void print(double a[], int b)
{
	int i;
	for (i = 0; i < b; i++)
		printf("%5.2lf  ", a[i]);
}