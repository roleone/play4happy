#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void noblank(char*);
char* s_gets(char *, int);
bool allblank(char *,int);
int main(void)
{
	char st[20];
	int num;
	while (1)
	{
		printf("enter a string\n");
		s_gets(st, 20);
		num = strlen(st);
		if (allblank(st, num))
			break;
		noblank(st);
		puts(st);
	}
	return 0;
}
void noblank(char * st)
{
	int i,j=0;
	char * blank;
	while (st[j] != '\0')
	{
		blank = strchr(st, '\040');
		if (blank)
		{
			for (i = 0; *(blank + i) != '\0'; i++)
			{
				blank[i] = blank[i + 1];
			}
			j++;
		}
		else
			break;
	}
}
bool allblank(char * st,int n)
{
	bool kk;
	int i = 0;
	while (st[i] == '\40')
		i++;
	if (i == n)
		return kk = true;
	else
		return kk = false;
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