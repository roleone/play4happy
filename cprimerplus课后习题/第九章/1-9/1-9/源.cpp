#include<stdio.h>
char option(void);
int get_in(int a, int b,char *cr);
int main(void)
{
	char ch;
	int a,b,c;
	printf("ѡ��һ��\n");
	if ((ch = option()) == '4')
		return 0;
	printf("����һ�������޺�һ������\n");
	while (1)
	{
		while (scanf("%d%d", &a, &b) != 2)
		{
			while (getchar() != '\n')
				continue;
			printf("��������\n");
		}
		if (a < b)
			break;
		else
		{
			printf("��������\n");
		}
	}
	c=get_in(a, b,&ch);
	if (ch== '4')
		return 0;
	printf("%d����\n",c);
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
		printf("����һ����Χ�ڵ���\n");
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