#include<stdio.h>
int main(void)
{
	int a, b=8;
	float num1[8], num2[8];
	printf("ÊäÈë°Ë¸öÊı\n");
	for (a = 0; a < b; a++)
	{
		scanf("%f", &num1[a]);
		getchar();
	}
	for (a = 1,num2[0]=num1[0]; a < b; a++)
	{
		num2[a] = num2[a - 1] + num1[a];
	}
	for (a = 0; a < b; a++)
	{
		printf("%5.2f  ", num1[a]);
	}
	printf("\n");
	for (a = 0; a < b; a++)
	{
		printf("%5.2f  ", num2[a]);
	}
	getchar();
	return 0;
}