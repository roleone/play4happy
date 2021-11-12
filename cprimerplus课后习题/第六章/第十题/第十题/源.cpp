#include<stdio.h>
int main(void)
{
	int a, b,x,y,z;
	long k;
	printf("请输入一个上限和一个下限\n");
	scanf("%d%d", &a, &b);
	while (a > b)
	{
		x = a - b;
		for (y=0,k=0;y<=x;y++)
		{
			z = b + y;
			z *= z;
			k = k + z;
		}
		printf("%ld\n", k);
		scanf("%d%d", &a, &b);
	}
	return 0;
}