#include<stdio.h>
void two_more(int[][5], int);
void print(int[][5], int);
int main(void)
{
	int k[3][5]=
	{
		{3,4,1,3,4},
		{1,3,4,12,32},
		{213,42,123,12,1}
	};
	print(k, 3);
	printf("\n");
	two_more(k, 3);
	print(k, 3);
	getchar();
	return 0;
}
void two_more(int a[][5], int b)
{
	int i,j;
	for (i = 0; i < b; i++)
		for (j = 0; j < 5; j++)
			*(*(a + i) + j) = 2 * (*(*(a + i) + j));
}
void print(int a[][5], int b)
{
	int i, j;
	for (i = 0; i < b; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%-5d  ", *(*(a + i) + j));
		printf("\n");
	}
}