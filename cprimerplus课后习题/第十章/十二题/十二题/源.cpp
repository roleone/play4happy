#include<stdio.h>
#define MONTH 12
#define YEARS 5
float aka(const float a[][MONTH], int b);
void kak(const float a[][MONTH], int b);
int main(void)
{
	const float rain[YEARS][MONTH] =
	{
		{ 4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6 },
		{ 8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3 },
		{ 9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4 },
		{ 7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2 },
		{ 7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2 }
	};
	float total;
	printf("YEAR   RAINFALL (inches)\n");
	total = aka(rain, YEARS);
	printf("\nThe yearly average is %.1f inches\n", total / YEARS);
	printf("MONTH AVERAGES:\n");
	printf(" JAN  FEB  MAR  APR  MAY  JUN  JUL  AUG  SEP  OCT  NOV  DEC\n");
	kak(rain, 5);
	getchar();
	return 0;
}
float aka(const float a[][MONTH], int b)
{
	int year, month;
	float subtot, total;
	for (year = 0, total = 0; year < b; year++)
	{
		for (month = 0, subtot = 0; month < MONTH; month++)
		{
			subtot += *(*(a + year) + month);
		}
		printf("%5d %15.1f\n", 2010 + year, subtot);
		total += subtot;
	}
	return total;
}
void kak(const float a[][MONTH], int b)
{
	int year, month;
	float subtot;
	for (month = 0; month < MONTH; month++)
	{
		for (year = 0, subtot = 0; year < b; year++)
		{
			subtot += *(*(a + year) + month);
		}
		printf("%4.1f ", subtot / b);
	}
}