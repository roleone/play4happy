#include<stdio.h>
int main(void)
{
	int kua;
	printf("�����������\n");
	scanf_s("%d", &kua);
	getchar();
	printf("ˮ������Ϊ%.0f", kua * 950 / 3e-23);
	getchar();
}