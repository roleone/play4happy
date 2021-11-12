#include<stdio.h>
char option(void);
int get_in(int a, int b,char *cr);
int main(void)
{
	char ch;
	int a,b,c;
	printf("选择一个\n");
	if ((ch = option()) == '4')
		return 0;
	printf("输入一个上下限和一个整数\n");
	while (1)
	{
		while (scanf("%d%d", &a, &b) != 2)
		{
			while (getchar() != '\n')
				continue;
			printf("重新输入\n");
		}
		if (a < b)
			break;
		else
		{
			printf("重新输入\n");
		}
	}
	c=get_in(a, b,&ch);
	if (ch== '4')
		return 0;
	printf("%d正常\n",c);
	getchar();
	return 0;
}
char option(void)
{
	char ch;
	while (1)
	{
		printf("Please choose one of the following:\n");
		printf("1)copy files         2)move files\n");
		printf("3)remove files       4)quit\n");
		printf("Enter the number of your choice:\n");
		if ((ch = getchar()) > '0' && ch < '5')
		{
			while (getchar() != '\n')
				continue;
			break;
		}
		else
		{
			while (getchar() != '\n')
				continue;
			printf("try again:\n");
		}
	}
	return ch;
}
int get_in(int a, int b,char *cr)
{
	int n;
	while (1)
	{
		printf("输入一个范围内的数\n");
		if (scanf("%d", &n) == 1)
		{
			while (getchar() != '\n')
				continue;
			if (n<a || n>b)
			{
				*cr=option();
				if (*cr == '4')
					return -1;
			}
			else
			{
				printf("option is %c\n", *cr);
				return n;
			}
		}
		else
		{
			while (getchar() != '\n')
				continue;
			printf("option is %c\n", *cr);
			return 4;
		}
	}
}