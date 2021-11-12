#include<stdio.h>
void sq(double,int,double *);
int main(void)
{
	double p=0,result;
	int n=0;
	while (1)
	{
		printf("请输入一个数和一个次方\n");
		scanf("%lf%d", &p, &n);
		if (p != 0)
		{
			if (n >= 0)
			{
				sq(p, n, &result);
			}
			else
			{
				sq(p, -n, &result);
				result = 1.0 / result;
			}
		}
		else
		{
			if (n != 0)
				result = 0;
			else
			{
				result = 1;
				printf("未定义\n");
			}
		}
		if (getchar() != '\n')
			break;
		printf("%lf\n", result);
	}
	return 0;
}
void sq(double num,int n,double * kk)
{
	if (n > 0)
		sq(num, n - 1,kk);
	if (n == 0)
		*kk = 1.0;
	else
	{
		*kk *= num;
	}
}