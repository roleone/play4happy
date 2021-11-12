#include<stdio.h>
#include<stdbool.h>
struct number{
	unsigned int a:1;
	unsigned int  :31;
};
union choose{
	struct number one;
	unsigned int two;
};
void test(union choose *,int);
int main(void)
{
	union choose three;
	union choose *four=&three;
	unsigned int k2;
	while(1)
	{
		printf("enter a number and move byte:\n");
		if(scanf("%u%d",&(three.two),&k2)!=2)
			break;
		test(four,k2);
	}
	return 0;
}
void test(union choose*num,int n)
{
	bool an=false;
	unsigned int k=2147483648,answer=num->two;
	for(int i=0;i<n;i++)
	{
		if(num->two&k)
			an=true;
		num->two<<=1;
		if(an)
			num->one.a=1;
		an=false;
	}
	printf("%u move %d is %u\n",answer,n,num->two);
}
