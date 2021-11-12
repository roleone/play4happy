#include<stdio.h>
int main(void)
{
	int a, b;
	printf("输入一个除数\n");
	scanf_s("%d", &a);
	getchar();
	printf("输入一个被除数\n");
	scanf_s("%d", &b);
	getchar();
	while (b > 0)
	{
		printf("%d %% %d is %d\n输入一个被除数\n", b, a, b%a);
		scanf_s("%d", &b);
	}
	getchar();
	printf("end");
	getchar();
	return 0;
}