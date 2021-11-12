#include<stdio.h>
int main(void)
{
	char ch;
	int n = 0;
	while ((ch = getchar()) != EOF)
	{
		n++;
		if (ch=='\n'||ch=='\t')
		{
			printf("%s %-5d", ch=='\n' ? "\\n" : "\\t",ch);
		}
		else if (ch>31)
		{
			printf("%c %-5d", ch, ch);
		}
		else
		{
			printf("\^%c -5d", ch + 64, ch);
		}
		if (ch == '\n')
			n = 0;
		if (ch != '\n'&&n == 10)
			printf("\n");
	}
	return 0;
}