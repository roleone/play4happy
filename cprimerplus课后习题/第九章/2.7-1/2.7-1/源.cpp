#include<stdio.h>
int location(char);
int main(void)
{
	char ch;
	int n;
	printf("ÊäÈëÒ»×é×Ö·û\n");
	while ((ch = getchar()) != EOF)
	{
		if (ch != '\n')
		{
			n = location(ch);
			if (n != -1)
				printf("%c  %d\n", ch, n);
			else
				printf("%d\n", n);
		}
	}
	getchar();
	return 0;
}
int location(char ch)
{
	if (ch>='a'&&ch<='z')
		return (int)ch - 96;
	else if (ch >= 'A'&&ch <= 'Z')
		return (int)ch - 64;
	else
		return -1;
}