#include<stdio.h>
int main(void)
{
	int a, b;
	printf("����һ������\n");
	scanf_s("%d", &a);
	getchar();
	printf("����һ��������\n");
	scanf_s("%d", &b);
	getchar();
	while (b > 0)
	{
		printf("%d %% %d is %d\n����һ��������\n", b, a, b%a);
		scanf_s("%d", &b);
	}
	getchar();
	printf("end");
	getchar();
	return 0;
}