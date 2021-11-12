#include<stdio.h>
int main(void)
{
	float dollar = 100.0;
	int year = 0;
	while (dollar >= 10)
	{
		dollar *= 1.08;
		dollar -= 10;
		year++;
	}
	year++;
	printf("%d", year);
	getchar();
	return 0;
}