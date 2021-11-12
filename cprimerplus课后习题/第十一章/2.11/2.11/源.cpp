#include<stdio.h>
#include<string.h>
#define lim 10
#define gem 40
char * s_gets(char*, int);
void aa(char(*)[gem]);
void bb(char(*)[gem]);
void cc(char(*)[gem]);
void dd(char(*)[gem]);
int first(char*);
int main(void)
{
	char org[lim][gem];
	char ans;
	int i;
	while (1)
	{
		printf("a) 打印源字符串列表\n");
		printf("b) 以ASCII中的顺序打印\n");
		printf("c) 按长度递增顺序打印\n");
		printf("d) 按字符串中第一个单词的长度打印\n");
		printf("e) 退出\n");
		scanf("%c", &ans);
		while (getchar() != '\n')
			continue;
		if ('a' <= ans&&'d' >= ans)
		{
			for (i = 0; i < lim; i++)
			{
				printf("请输入第%d个字符串:\n", i + 1);
				s_gets(org[i], gem);
				if (org[i][0] == EOF)
					break;
			}
			switch (ans)
			{
			case 'a':
				aa(org);
				break;
			case 'b':
				bb(org);
				aa(org);
				break;
			case 'c':
				cc(org);
				aa(org);
				break;
			case 'd':
				dd(org);
				aa(org);
				break;
			default:
				break;
			}
		}
		else if (ans == 'e')
			break;
		else
		{
			continue;
		}
	}
	return 0;
}
char * s_gets(char* st, int n)
{
	int i = 0;
	char * kk;
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
void aa(char(*st)[gem])
{
	int i = 0;
	while (i < 10 && st[i][0] != EOF)
	{
		puts(st[i]);
		i++;
	}
}
void bb(char(*st)[gem])
{
	int i,j;
	char tmp[gem];
	for (i = 0; i < lim - 1 && st[i][0] != EOF; i++)
	{
		for (j = i+1; j < lim; j++)
		{
			if (strcmp(st[i], st[j])>0)
			{
				strcpy(tmp, st[i]);
				strcpy(st[i], st[j]);
				strcpy(st[j], tmp);
			}
		}
	}
}
void cc(char(*st)[gem])
{
	int i, j;
	char tmp[gem];
	for (i = 0; i < lim - 1 && st[i][0] != EOF; i++)
	{
		for (j = i + 1; j < lim; j++)
		{
			if (strlen(st[i])>strlen(st[j]))
			{
				strcpy(tmp, st[i]);
				strcpy(st[i], st[j]);
				strcpy(st[j], tmp);
			}
		}
	}
}
void dd(char(*st)[gem])
{
	int i, j;
	char tmp[gem];
	for (i = 0; i < lim - 1 && st[i][0] != EOF; i++)
	{
		for (j = i + 1; j < lim; j++)
		{
			if (first(st[i])>first(st[j]))
			{
				strcpy(tmp, st[i]);
				strcpy(st[i], st[j]);
				strcpy(st[j], tmp);
			}
		}
	}
}
int first(char*st)
{
	int i = 0,j=0;
	while (st[i] == '\40'&&i<gem)
		i++;
	while (st[i + j] != '\40'&&st[i+j]!='\0')
		j++;
	return j;
}