#include<stdio.h>
int MAX(int, int, int);
void get_in(int * a,int * b,int * c);
int main(void)
{
	int max, x, y, z;
	get_in(&x, &y, &z);
	return 0;
}
int MAX(int a, int b, int c)
{
	a = (a > b) ? a : b;
	a = (a > c) ? a : c;
	return a;
}
void get_in(int *a,int *b,int *c)
{
	int max;
	char ch = '\n';
	printf("input three number,i will get the max\n");
	while (ch != 'q')
	{
		while (scanf("%d%d%d", a, b, c) != 3)
		{
			if ((ch = getchar()) == 'q')
			{
				break;
			}
			else
			{
				printf("please input again\n");
				while (getchar() != '\n')
					continue;
			}
		}
		if (ch != 'q')
		{
			max = MAX(*a, *b, *c);
			printf("the max=%d\n", max);
			while (getchar() != '\n')
				continue;
			printf("input three number,i will get the max\n");
		}
	}
}