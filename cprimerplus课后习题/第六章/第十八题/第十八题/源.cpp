#include<stdio.h>
int main(void)
{
	int num = 5,week=0;
	while (num < 150)
	{
		week++;
		num -= week;
		num *= 2;
		printf("第%d周有%d个朋友\n", week, num);
	}
	getchar();
	return 0;
}