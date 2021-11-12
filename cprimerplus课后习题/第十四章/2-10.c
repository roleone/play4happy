#include<stdio.h>
int add(int,int);
int sub(int,int);
int mul(int,int);
int div(int,int);
int (*plr)(int,int);
void show(int(*ptr)(int,int),int,int);
int main(void)
{
	char ch;
	int a,b;
	printf("a:+\nb:-\nc:*\nd:/\n:");
	while((ch=getchar())>='a'&&ch<='d')
	{
		while(getchar()!='\n')
			continue;
		switch(ch)
		{
			case 'a':plr=add;
				 break;
			case 'b':plr=sub;
				 break;
			case 'c':plr=mul;
				 break;
			case 'd':plr=div;
				 break;
			default:
				 break;
		}
		printf("enter a and b:\n");
		scanf("%d%d",&a,&b);
		while(getchar()!='\n')
			continue;
		show(plr,a,b);
		printf("a:+\nb:-\nc:*\nd:/\n:");
	}
	return 0;
}
void show(int(*ptr)(int,int),int a,int b)
{
	printf("answer is %d\n",(*ptr)(a,b));
}
int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int div(int a,int b)
{
	return a/b;
}
