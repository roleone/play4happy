#include<stdio.h>
void print(int a[], int b);
void add_(int[], int[], int[], int);
int main(void)
{
	int n;
	int k1[] = { 1,4,2,5,23,53,23,12,12 };
	int k2[] = { 1,13,234,1,12,3,13,32,13 };
	n = sizeof(k1) / sizeof(int);
	int k3[sizeof(k1) / sizeof(int)];
	add_(k1, k2, k3, n);
	print(k1, n);
	print(k2, n);
	print(k3, n);
	getchar();
	return 0;
}
void add_(int a[], int b[], int c[], int d)
{
	int i;
	for (i = 0; i < d; i++)
		*(c + i) = a[i] + b[i];
}
void print(int a[], int b)
{
	int i;
	for (i = 0; i < b; i++)
		printf("%-5d  ", a[i]);
	printf("\n");
}