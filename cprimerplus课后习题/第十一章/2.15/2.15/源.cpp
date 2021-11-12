#include<stdio.h>
#include<ctype.h>
int myatoi(char *);
char*s_gets(char*, int);
int mi(int);
int main(void)
{
	int num;
	char kj[20];
	s_gets(kj, 20);
	num = myatoi(kj);
	printf("%d", num);
	getchar();
	return 0;
}
int myatoi(char * st)
{
	int i = 0,j=0;
	int num = 0;
	while (isdigit(st[i]))
	{
		i++;
	}
	if (st[i] == '\0')
	{
		while (j < i)
		{
			num += (st[j]-48) * mi(i - j-1);
			j++;
		}
	}
	return num;
}
char*s_gets(char* st, int n)
{
	int i = 0;
	char*kk;
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
int mi(int n)
{
	int i = 0, num = 1;
	while (i < n)
	{
		num *= 10;
		i++;
	}
	return num;
}