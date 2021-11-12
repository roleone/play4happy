#include<stdio.h>
void print(double[], int);
void back(double[], int);
int main(void)
{
	int n;
	double kk[] = { 1.0,2.4,2.3,4.2,4.5,6.7,2.4,21.3,3.4 };
	n = sizeof(kk) / sizeof(double);
	print(kk, n);
	back(kk, n);
	print(kk, n);
	getchar();
	return 0;
}
void back(double a[], int b)
{
	double tmp;
	int i;
	for (i = 0; i < (b / 2); i++)
	{
		tmp = *(a+i);
		*(a + i) = *(a + b - 1 - i);
		*(a + b - 1 - i) = tmp;
	}
}
void print(double a[], int b)
{
	int i;
	for (i = 0; i < b; i++)
	{
		printf("%-7.3lf  ", *(a + i));
	}
	printf("\n");
}