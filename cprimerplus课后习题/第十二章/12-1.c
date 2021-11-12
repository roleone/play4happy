#include<stdio.h>
void critic(int *);
int main(void)
{
	int units;
	printf("guess\n");
	scanf("%d",&units);
	while(units!=56)
		critic(&units);
	printf("hah\n");
	return 0;
}
void critic(int *k)
{
	printf("nope\n");
	scanf("%d",k);
}
