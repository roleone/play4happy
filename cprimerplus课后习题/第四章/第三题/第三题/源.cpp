#include<stdio.h>
int main()
{
	float value;
	printf("������һ��������\n");
	scanf_s("%f", &value);
	getchar();
	printf("The input is %.1f or %.1e\n", value, value);
	printf("The input is %.3f or %.3E\n", value, value);
	getchar();
	return 0;
}