#include<stdio.h>
int main(void)
{
	char c;
	int num=0;
	while ((c = getchar()) != '#')
	{
		if (c == '\n')
			continue;
		else if (c == '!')
		{
			putchar('!');
			putchar('!');
			num++;
		}
		else if (c == '.')
		{
			putchar('!');
			num++;
		}
		else
			putchar(c);
	}
	getchar();
	printf("%d", num);
	getchar();
	return 0;
}