#include<stdio.h>
char * find(char * , char ,int);
int main(void)
{
	char n1;
	int n2;
	char * k;
	char kk[20];
	printf("enter the limit number\n");
	scanf("%d", &n2);
	getchar();
	printf("enter the number you want to see\n");
	scanf("%c", &n1);
	getchar();
	while (n1 < 32 || n1>126)
	{
		printf("please enter\n");
		scanf("%c", &n1);
		getchar();
	}
	k = find(kk, n1, n2+1);
	if (k)
	{
		printf("%s\n", k);
	}
	else
		printf("NONE\n");
	getchar();
	return 0;
}
char * find(char * st, char n1,int n2)
{
	char * cr;
	int i=0;
	cr=fgets(st, n2, stdin);
	if (cr)
	{
		while (st[i] != '\0'&&st[i] != '\n')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	for (i = 0; st[i] != '\0'; i++)
	{
		if (st[i] == n1)
		{
			cr += i;
			break;
		}
	}
	if (st[i] == '\0')
		cr=NULL;
	return cr;
}