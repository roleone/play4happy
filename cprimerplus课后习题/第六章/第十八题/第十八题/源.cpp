#include<stdio.h>
int main(void)
{
	int num = 5,week=0;
	while (num < 150)
	{
		week++;
		num -= week;
		num *= 2;
		printf("��%d����%d������\n", week, num);
	}
	getchar();
	return 0;
}