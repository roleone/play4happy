#include<stdio.h>
int main(void)
{
	float a = 100.0, b = 100.0;
	int year = 0;
	do
	{
		a += 100 * 0.1;
		b += b*0.05;
		year++;
	} while (a >= b);
	printf("%d", year);
	getchar();
	return 0;
}
