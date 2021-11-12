#include<stdio.h>
void print(char, int, int);
int main(void)
{
	char ch;
	int i, j;
	printf("enter a charm,and i ,j\n");
	scanf("%c%d%d", &ch, &i, &j);
	print(ch, i, j);
	getchar();
	getchar();
	return 0;
}
void print(char ch, int i, int j)
{
	int a, b;
	for (a = 0;a < i; a++)
	{
		for (b = 0;b < j; b++)
		{
			putchar(ch);
		}
		printf("\n");
	}
}