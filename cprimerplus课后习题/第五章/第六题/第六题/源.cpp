#include<stdio.h>
int main(void)
{
	int n = 1,a=0,b,c=0;
	printf("���뵽��һλ��ƽ��\n");
	scanf_s("%d", &b);
	getchar();
	while (n<b+1)
	{
		a = n*n;
		c = c + a;
		n++;
	}
	printf("���Ϊ%d", c);
	getchar();
	return 0;
}