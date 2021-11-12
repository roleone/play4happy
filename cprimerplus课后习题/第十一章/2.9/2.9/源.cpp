#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reversal(char *,int);
char*s_gets(char*, int);
int main(void)
{
	char ST[20];
	int num1,num2;
	while (1)
	{
		printf("enter a string\n");
		s_gets(ST, 20);
		if (!strcmp(ST, "quit"))
			break;
		num1 = strlen(ST);
		printf("enter the length\n");
		while (!scanf("%d", &num2) || num2 > num1)
		{
			printf("please enter the length again\n");
			while (getchar() != '\n')
				continue;
		}
		while (getchar() != '\n')
			continue;
		reversal(ST, num2);
		puts(ST);
	}
	return 0;
}
void reversal(char * st, int n)
{
	char tmp;
	for (int i = 0; i < n / 2; i++)
	{
		tmp = st[i];
		st[i] = st[n - 1 - i];
		st[n - 1 - i] = tmp;
	}
}
char* s_gets(char * st, int n)
{
	char * kk;
	int i = 0;
	kk = fgets(st, n, stdin);
	if (kk)
	{
		while (st[i] != '\0'&&st[i] != '\n')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return kk;
}