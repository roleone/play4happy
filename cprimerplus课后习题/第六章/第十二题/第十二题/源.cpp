#include<stdio.h>
int mi(int n);
int main(void)
{
	int times,round;
	double a;
	printf("ÊäÈë´ÎÊý\n");
	scanf("%d",&round);
	getchar();
	while (round > 0)
	{
		for (times = 0, a = 1.0; times < round; times++)
		{
			a +=1.0 /(times+2);
		}
		printf("%lf\n", a);
		for (times = 0, a = 1; times < round; times++)
		{
			a += mi(times + 1) *1.0/ (times + 2);
		}
		printf("%lf\n", a);
		scanf("%d", &round);
		getchar();
	}
	printf("end");
	getchar();
	return 0;
}
int mi(int n)
{
	int k = 0,m=-1;
	do
	{
		m *= -1;
		k++;
	} while (k <= n);
	return m;
}