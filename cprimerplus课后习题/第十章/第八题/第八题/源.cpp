#include<stdio.h>
void copy_ptr(double a[], double b[], int c);
void print(double a[], int b);
int main(void)
{
	double k1[7] = { 2.3,42.1,3.4,1.2,3.1,13.4,23.1 };
	double k2[3];
	copy_ptr(k2, &k1[2], 3);
	print(k1, 7);
	printf("\n");
	print(k2, 3);
	getchar();
	return 0;
}
void copy_ptr(double a[], double b[], int c)
{
	int i;
	for (i = 0; i < c; i++)
	{
		*(a + i) = *(b + i);
	}
}
void print(double a[], int b)
{
	int i;
	for (i = 0; i < b; i++)
		printf("%5.2lf  ", a[i]);
}