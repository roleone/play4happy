#include<stdio.h>
int main(void)
{
	int sum = 0, num,statu;
	printf("�����һ����");
	statu = scanf_s("%d", &num);
	while (statu == 1)
	{
		printf("��������һ����");
		sum = num + sum;
		statu=scanf_s("%d", &num);
	}
	getchar();
	getchar();
	printf("�ܺ�Ϊ%d", sum);
	getchar();
	return 0;
}