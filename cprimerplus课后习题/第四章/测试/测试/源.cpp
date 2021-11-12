#include<stdio.h>
int main()
{
	int a, b,c;
	printf("shuru\n");
	c=scanf_s("%d%d", &a, &b);
	getchar();
	printf("%d,%d\n", a, b);
	printf("%d", c);
	getchar();
	return 0;
}