#include<stdio.h>
int main(void)
{
	float high;
	printf("������һ�����(cm)\n");
	scanf_s("%f", &high);
	while (high > 0)
	{
		printf("%.2f cm=%.2f m,%.2f dm\n",high, high / 100, high / 10);
		printf("������һ�����(cm)\n");
		scanf_s("%f", &high);
	}
	getchar();
	printf("bye");
	getchar();
	return 0;
}