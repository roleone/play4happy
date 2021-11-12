#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define ANSWER "GREAT"
char * s_gets(char *, int);
int main(void)
{
	char * k,kk[20];
	printf("请输入一个答案\n");
	k = s_gets(kk, 20);
	while (k)
	{
		for (int i = 0; kk[i] != '\0'; i++)
		{
			if (islower(kk[i]))
				kk[i] = toupper(kk[i]);
		}
		if (strcmp(kk, ANSWER))
		{
			printf("not,please enter a new number\n");
			k = s_gets(kk, 20);
		}
		else
			break;
	}
	printf("congrasad!");
	getchar();
	return 0;
}
char * s_gets(char * st, int n)
{
	char * ret_val;
	int i=0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n'&&st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}