#include<stdio.h>
void print(double[][5],int);
void copy_ar(double[][5],double[][5],int);
int main()
{
	double k1[3][5]=
	{
		{23.4,23.1,12.3,12.3,123.4},
		{232.4,13.1,32.4,23.1,21.3},
		{12.32,13.23,12.3,12.3,12.3}
	};
	double k2[3][5];
	copy_ar(k2, k1, 3);
	print(k1, 3);
	printf("\n");
	print(k2, 3);
	getchar();
	return 0;
}
void print(double a[][5], int c)
{
	int i, j;
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%5.2lf  ", *(*(a + i) + j));
		printf("\n");
	}
}
void copy_ar(double a[][5], double b[][5], int c)
{
	int i,j;
	for (i = 0; i < c; i++)
		for (j = 0; j < 5; j++)
			*(*(a + i) + j) = *(*(b + i) + j);
}
