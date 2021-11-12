#include<stdio.h>
#include<string.h>
char * string_in(char*, char*);
char * s_gets(char*, int);
int main(void)
{
	char st[20];
	char ss[20];
	char* oook;
	while (1)
	{
		printf("enter the goal\n");
		s_gets(st, 20);
		if (!strcmp(st, "q"))
			break;
		printf("enter the you want to see\n");
		s_gets(ss, 20);
		oook = string_in(st, ss);
		if (oook)
			printf("%s\n", oook);
		else
			printf("NONE\n");
	}
	return 0;
}
char * string_in(char * st, char * ss)
{
	int i = 0,k=0;
	char * kk;
	while (st[i] != '\0')
	{
		if (st[i] == ss[0])
		{
			for (int j = i; (st[j] == ss[k])&&ss[k]!='\0'; j++, k++)
				continue;
		}
		if (!ss[k])
			break;
		else
			i++;
		k = 0;
	}
	if (!st[i])
		kk = NULL;
	else
		kk = st + i;
	return kk;
}
char * s_gets(char * st, int n)
{
	char * kk;
	int i = 0;
	kk = fgets(st, n, stdin);
	if (kk)
	{
		while (st[i] != '\n'&&st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return kk;
}