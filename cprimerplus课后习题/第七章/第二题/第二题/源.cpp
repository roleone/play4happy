#include<stdio.h>
int main(void)
{
	char c;
	int a=0;
	while ((c = getchar()) != '#')
	{
		if (c == '\n')
			continue;
		putchar(c);
		printf("%d", c);
		a++;
		if (a % 8 == 0)
			putchar('\n');
	}
	getchar();
	getchar();
	return 0;
}