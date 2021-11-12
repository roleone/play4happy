#include<stdio.h>
int main(void)
{
	float high;
	printf("请输入一个身高(cm)\n");
	scanf_s("%f", &high);
	while (high > 0)
	{
		printf("%.2f cm=%.2f m,%.2f dm\n",high, high / 100, high / 10);
		printf("请输入一个身高(cm)\n");
		scanf_s("%f", &high);
	}
	getchar();
	printf("bye");
	getchar();
	return 0;
}