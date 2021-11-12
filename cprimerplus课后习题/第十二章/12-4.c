#include<stdio.h>
int ff(void);
int main(void)
{
	int n,i,j;
	while(scanf("%d",&n)==1)
	{
		j=0;
		while(j<n)
		{
			i=ff();
			j++;
		}
		printf("%d\n",i);
	}
	return 0;
}
int ff(void)
{
	static int k;
	k++;
	return k;
}
