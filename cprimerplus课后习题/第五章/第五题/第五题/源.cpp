#include<stdio.h>
int main(void)
{
	int n=0,a,b,c=0;
	printf("输入一个数\n");
	scanf_s("%d", &a);
	getchar();
	while (n< 20)
	{
		b = a + n;
		c = c + b;
		n++;
	}
	printf("结果为%d", c);
	getchar();
	return 0;
}