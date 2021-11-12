#include<stdio.h>
int main(void)
{
	float weight;
	float value;
	printf("Are you?\n");
	printf("Let's check\n");
	printf("Please enter:");
	scanf_s("%f",&weight);
	getchar();
	value = weight*1700.0*14.5833;
	printf("Your weight in platinm is $%.2f.\n", value);
	getchar();
	return 0;
}