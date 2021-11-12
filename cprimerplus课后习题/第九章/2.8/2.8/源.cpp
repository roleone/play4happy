#include<stdio.h>
double em(double, int);
int main(void)
{
	double a,c;
	int b;
	while (1)
	{
		printf("输入一个数和一个次方\n");
		scanf("%lf%d", &a, &b);
		c = em(a, b);
		printf("%lf\n", c);
		if (getchar() != '\n')
			break;
	}
	return 0;
}
double em(double p, int n)
{
	double result;
	int a;
	if (p != 0)
	{
		if (n >= 0)
		{
			for (result = 1, a = 0; a < n; a++)
				result *= p;
		}
		else
		{
			for (result = 1, a = 0; a > n; a--)
				result *= p;
			result = 1.0 / result;
		}
	}
	else
	{
		if (n != 0)
			result = 0;
		else
		{
			printf("未定义\n");
			result = 1;
		}
	}
	return result;
}