#include<stdio.h>
int main(void)
{
	int n_up, n_down,a,b=3,c,d,k,j;
	printf("输入一个上下限\n");
	scanf("%d %d", &n_up, &n_down);
	while (n_up > n_down)
	{
		c = n_up - n_down;
		for (a=0;a<=c;a++)
		{
			k = n_down + a;
			for (j=1,d = 0; d < b; d++)
			{
				printf("%4d  ", j*=k);
			}
			printf("\n");
		}
		scanf("%d %d", &n_up, &n_down);
	}
	getchar();
	return 0;
}
