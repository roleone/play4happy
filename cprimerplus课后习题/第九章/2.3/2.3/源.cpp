#include<stdio.h>
void print(char ch, int n, int i);
int main(void)
{
	char cr;
	int a, b;
	printf("enter a charm,and how many to print,and the i\n");
	scanf("%c%d%d", &cr, &a, &b);
	print(cr, a, b);
	getchar();
	getchar();
	return 0;
}
void print(char ch, int n, int i)
{
	int a, b;
	for (a = 0; a < i-1; a++)
	{
		printf("\n");
	}
	for (b = 0; b < n; b++)
	{
		printf("%c", ch);
	}
}