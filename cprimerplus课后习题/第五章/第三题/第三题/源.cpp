#include<stdio.h>
int main(void)
{
	const int week = 7;
	int day;
	printf("请输入天数\n");
	scanf_s("%d", &day);
	while (day > 0)
	{
		printf("%d days are %d weeks,%d days.\n", day, day / week, day%week);
		printf("请输入天数\n");
		scanf_s("%d", &day);
	}
	getchar();
	printf("end");
	getchar();
	return 0;
}