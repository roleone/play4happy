#include<stdio.h>
int test(int);
void rm(void);
int main(void)
{
	int num;
	printf("enter a number:\n");
	while(scanf("%d",&num)==1)
	{
		rm();
		printf("%d have %d open\n",num,test(num));
		printf("enter a number\n");
	}
	rm();
	return 0;
}
int test(int n)
{
	int count=0,cat=1;
	for(int i=0;i<8;i++)
	{
		if((n&cat)==1)
			count++;
		n>>=1;
	}
	return count;
}
void rm(void)
{
	while(getchar()!='\n')
		continue;
}
