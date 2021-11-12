#include<stdio.h>
int main(void)
{
	int kua;
	printf("请输入夸脱数\n");
	scanf_s("%d", &kua);
	getchar();
	printf("水分子数为%.0f", kua * 950 / 3e-23);
	getchar();
}