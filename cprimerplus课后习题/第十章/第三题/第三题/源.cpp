#include<stdio.h>
int max(int[],int);
int main(void)
{
	int MAX;
	int k[10] = { 1,6,235,23,1,5,23,1,213,23 };
	MAX = max(k,10);
	printf("%d", MAX);
	getchar();
	return 0;
}
int max(int a[],int b)
{
	int tmp=0,i;
	for (i = 0; i < b; i++)
		tmp = (tmp < *(a + i)) ? a[i] : tmp;
	return tmp;
}