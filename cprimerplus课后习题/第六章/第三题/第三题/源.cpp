#include<stdio.h>
int main(void)
{
	int a, b=6, c;
	for (a = 0; a < b; a++)
	{
		for (c = 0; c <= a; c++)
		{
			printf("%c", 'F' - c);
		}
		printf("\n");
	}
	getchar();
	return 0;
}