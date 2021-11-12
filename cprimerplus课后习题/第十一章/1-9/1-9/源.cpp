#include<stdio.h>
#include<string.h>
int hm(char * st);
char * s_gets(char *, int);
char * nll(char *);
int main(void)
{
	int n;
	char kkp[20];
	char *kkb;
	char *kk;
	char kkk[10];
	kkb=s_gets(kkp, 20);
	n = hm(kkb);
	printf("%d\n", n);
	if (kk = nll(kkb))
		printf("%c", kk - 1);
	fgets(kkk, 10, stdin);
	if (kk = nll(kkk))
		printf("%c", *--kk);
	getchar();
	return 0;
}
int hm(char * st)
{
	char * ch;
	int n = 0;
	ch = st;
	while (*ch != '\0')
	{
		ch++;
		n++;
	}
	return n;
}
char * s_gets(char * st, int n)
{
	char * ret_val,*x;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		if (x = strchr(st, '\n'))
			*x = '\0';
		else
			while (getchar() != '\n')
				continue;
		//while (*st != '\n'&&*st != '\0')
			//st++;
		//if (*st == '\n')
			//*st = '\0';
		//else
			//while (getchar() != '\n')
				//continue;
	}
	return ret_val;
}
char * nll(char * st)
{
	char * k;
	k = strchr(st, '\n');
	return k;
}