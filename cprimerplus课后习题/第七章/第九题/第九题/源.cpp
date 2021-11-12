#include<stdio.h>
int main(void)
{
	int num,a,b,n;
	float r;
	printf("请输入一个正整数\n");
	while (scanf("%d", &num) == 1)
	{
		n = 0;
		if (num < 1)
			continue;
		for (a=2;a<=num;a++)
		{
			for (b=2,n=0;b<a;b++)
			{
				if (a%b == 0)
					n++;
			}
			if (n == 0)
				printf("%d ", a);
		}
		printf("\n");
	}
	getchar();
	getchar();
	return 0;
}