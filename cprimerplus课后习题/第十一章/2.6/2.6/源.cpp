#include<stdio.h>
#include<string.h>
#define limit 20
int test(char, char *);
char* s_gets(char* ,int);
int main(void)
{
	char ch;
	char kk[limit];
	int n;
	do
	{
		printf("please enter a charm\n");
		scanf("%c", &ch);
		while (getchar() != '\n')
			continue;
		if (ch == 'q')
		{
			printf("are you want to quit?\n");
			scanf("%c", &ch);
			while (getchar() != '\n')
				continue;
			while (ch != 'y'&&ch != 'n')
			{
				printf("please enter y or n\n");
				scanf("%c", &ch);
				while (getchar() != '\n')
					continue;
			}
			if (ch == 'y')
				break;
			else
				ch = 'q';
		}
		printf("please enter a string\n");
		s_gets(kk, limit);
		n = test(ch, kk);
		if (n)
			printf("the string have the charm\n");
		else
			printf("the string have not the charm\n");
	} while (1);
	return 0;
}
int test(char ch, char *st)
{
	char * cr;
	int n;
	cr=strchr(st, ch);
	if (cr)
		n = *cr;
	else
		n = 0;
	return n;
}
char * s_gets(char* st, int n)
{
	int i = 0;
	char*k;
	k = fgets(st, n, stdin);
	if (k)
	{
		while (st[i] != '\n'&&st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return k;
}