#include<stdio.h>
int main(void)
{
	int sum = 0, num,statu;
	printf("请输出一个数");
	statu = scanf_s("%d", &num);
	while (statu == 1)
	{
		printf("请输入下一个数");
		sum = num + sum;
		statu=scanf_s("%d", &num);
	}
	getchar();
	getchar();
	printf("总和为%d", sum);
	getchar();
	return 0;
}