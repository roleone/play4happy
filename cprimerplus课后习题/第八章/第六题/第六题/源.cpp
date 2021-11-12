#include<stdio.h>
#include<ctype.h>
char get_first(void);
int main(void)
{
	char ch;
	while (ch = get_first())
	{
		putchar(ch);
		putchar('\n');
	}
	getchar();
	return 0;
}
char get_first(void)
{
	int ch, cr;
	while ((ch = getchar()) == '\n'||ch == '\t'||ch == ' ')
		continue;
	while ((cr = getchar()) != '\n')
		continue;
	return ch;
}