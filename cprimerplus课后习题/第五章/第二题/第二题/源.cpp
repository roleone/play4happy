#include<stdio.h>
int main(void)
{
	int n,a=0;
	printf("请输入一个整数\n");
	scanf_s("%d", &n);
	getchar();
	while (a < 11)
	{
		printf("%d\n", n + a);
		a++;
	}
	getchar();
	return 0;
}