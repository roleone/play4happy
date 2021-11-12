#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LIMIT 20
char * bb(char *, int);
int main()
{
	int n;
	char foryou[LIMIT];
	char * aa;
	printf("enter a number for the limit\n");
	scanf("%d", &n);
	getchar();
	aa = bb(foryou, n+1);
	printf("%s\n", aa);
	getchar();
	return 0;
}
char * bb(char * st, int n)
{
	char * k;
	int i = 0;
	k=fgets(st, n, stdin);
	if (k)
	{
		while (!isspace((unsigned char)st[i])&&st[i]!='\0')
			i++;
		if (st[i] == '\0')
			while (getchar() != '\n')
				continue;
		else
			st[i] = '\0';
	}
	return k;
}