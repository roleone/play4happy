#include<stdio.h>
void remember(double[][5], int);
void average(double[][5],double[], int);
double total_average(double[][5], int);
double MAX(double[][5], int);
void print(double[][5], int);
int main(void)
{
	double k[3][5];
	double kk[3];
	double arg, max;
	printf("输入15个数字：\n");
	remember(k, 3);
	print(k, 3);
	average(k, kk, 3);
	for (int i = 0; i < 3; i++)
		printf("第%d行平均值为%-5.2lf\n",i+1, *(kk + i));
	arg = total_average(k, 3);
	max = MAX(k, 3);
	printf("总平均为%-5.2lf\n", arg);
	printf("最大值为%-5.2lf\n", max);
	while (getchar() != '\n')
		continue;
	getchar();
	return 0;
}
void remember(double a[][5], int b)
{
	int i, j;
	for (i = 0; i < b; i++)
		for (j = 0; j < 5; j++)
			scanf("%lf", *(a + i) + j);
}
void average(double a[][5], double c[], int b) 
{
	double tmp;
	int i, j;
	for (i = 0; i < b; i++)
	{
		for (j = 0, tmp = 0; j < 5; j++)
			tmp += *(*(a + i) + j);
		*(c + i) = tmp/5;
	}
}
double total_average(double a[][5], int b)
{
	double tmp;
	int i, j;
	for (i = 0,tmp=0; i < b; i++)
		for (j = 0; j < 5; j++)
			tmp += *(*(a + i) + j);
	return tmp/(5*b);
}
double MAX(double a[][5], int b)
{
	double tmp = a[0][0];
	int i, j;
	for (i = 0; i < b; i++)
		for (j = 0; j < 5; j++)
			tmp = (tmp > *(*(a + i) + j)) ? tmp : a[i][j];
	return tmp;
}
void print(double a[][5], int b)
{
	int i, j;
	for (i = 0; i < b; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%-5.2lf  ", *(*(a + i) + j));
		printf("\n");
	}
}