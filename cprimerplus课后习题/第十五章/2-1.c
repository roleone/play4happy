#include<stdio.h>
struct math{
	unsigned int a:1;
	unsigned int b:1;
	unsigned int c:1;
	unsigned int d:1;
	unsigned int e:1;
	unsigned int f:1;
	unsigned int g:1;
	unsigned int h:1;
};
int main(void)
{
	struct math num={0,0,0,0,0,0,0,0};
	char ch;
	for(int i=0;i<8;i++)
	{
		printf("enter no.%d byte:\n",i+1);
		while((ch=getchar())<'0'||ch>'1')
		{	while(getchar()!='\n')
				continue;
			printf("enter 0 or 1\n");
		}
		while(getchar()!='\n')
			continue;
		switch(i)
		{
			case 0:num.a=ch-48;
				break;
			case 1:num.b=ch-48;
				break;
			case 2:num.c=ch-48;
				break;
			case 3:num.d=ch-48;
				break;
			case 4:num.e=ch-48;
				break;
			case 5:num.f=ch-48;
				break;
			case 6:num.g=ch-48;
				break;
			case 7:num.h=ch-48;
				break;
			default:
			       break;
		}
	}
	printf("the number is %d\n",num);
	return 0;
}
