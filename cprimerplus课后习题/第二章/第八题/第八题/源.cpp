#include<stdio.h>
void one_three(void);
void two(void);
int main()
{
	printf("starting now:");
	printf("\n");
	one_three();
	two();
	printf("three\n");
	printf("done!");
	getchar();
	return 0;
}
void one_three(void)
{
	printf("one\n");
}
void two(void)
{
	printf("two\n");
}