#include<stdio.h>
int* mi(int);
int main(void)
{
	int n = 0;
	int *w;
	w=mi(n);
	printf("%d", *w);
	getchar();
	return 0;
}
int* mi(int n)
{
	static int k;
	return &k;
}