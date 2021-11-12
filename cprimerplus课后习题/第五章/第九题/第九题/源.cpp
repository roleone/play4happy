#include<stdio.h>
int Temperatures(double huashi);
int main(void)
{
	int a;
	double wendu;
	printf("请输入一个华氏温度\n");
	a=scanf_s("%lf", &wendu);
	while (a == 1)
	{
		Temperatures(wendu);
		printf("请输入一个华氏温度\n");
		a = scanf_s("%lf", &wendu);
	}
	getchar();
	return 0;
}
int Temperatures(double huashi)
{
	const float a = 5.0, b = 9.0, c = 32.0, d = 273.16;
	printf("摄氏温度为%.2lf\n开氏温度为%.2lf\n", a / b*(huashi - c), a / b*(huashi - c) + d);
	return 0;
}