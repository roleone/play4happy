#include<stdio.h>
int main(void)
{
	int n=0,a,b,c=0;
	printf("����һ����\n");
	scanf_s("%d", &a);
	getchar();
	while (n< 20)
	{
		b = a + n;
		c = c + b;
		n++;
	}
	printf("���Ϊ%d", c);
	getchar();
	return 0;
}