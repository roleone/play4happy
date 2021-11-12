#include<stdio.h>
#define value 60
int main(void)
{
	int min;
	printf("输入现在的分钟数\n");
	scanf_s("%d", &min);
	while (min>0)
	{
		printf("hours is %d,min is %d\n", min / value, min%value);
		printf("输入现在的分钟数\n");
		scanf_s("%d", &min);
	}
	getchar();
	printf("end");
	getchar();
	return 0;
}