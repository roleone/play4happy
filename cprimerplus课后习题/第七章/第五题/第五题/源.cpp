#include<stdio.h>
int main(void)
{
	int num = 0;
	char c;
	while ((c = getchar()) != '#')
	{
		switch (c)
		{
		case '\n':continue;
		case '.':putchar('!');
			num++;
			break;
		case '!':putchar('!');
			putchar('!');
			num++;
			break;
		default:putchar(c);
		}
	}
	getchar();
	printf("\n%d´Î", num);
	getchar();
	return 0;
}