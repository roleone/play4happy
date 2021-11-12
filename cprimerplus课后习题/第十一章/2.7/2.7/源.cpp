#include<stdio.h>
#include<string.h>
#define limit 40
char * mystrncpy(char *,const char *, int);
char * s_gets(char *, int);
int main(void)
{
	char st[limit];
	char ss[limit];
	char * end;
	int num,n;
	s_gets(st, limit);
	s_gets(ss, limit);
	num=strlen(st);
	n = limit - num - 1;
	end=mystrncpy(st, ss, n);
	puts(end);
	getchar();
	return 0;
}
char * mystrncpy(char * st, const char * ss, int n)
{
	int i = 0,j=0,k;
	while (st[i] != '\0')
		i++;
	k=strlen(ss);
	if (k < n)
	{
		while (j < k)
		{
			st[i] = ss[j];
			i++;
			j++;
		}
	}
	else
	{
		while (j < n)
		{
			st[i] = ss[j];
			i++;
			j++;
		}
	}
	st[i] = '\0';
	return st;
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