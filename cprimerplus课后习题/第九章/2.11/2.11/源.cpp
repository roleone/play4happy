#include<stdio.h>
long Fibonacci(int n);
int main(void)
{
	int n;
	long number;
	while (1)
	{
		scanf("%d", &n);
		number = Fibonacci(n);
		printf("%ld\n", number);
		if (getchar() != '\n')
			break;
	}
	return 0;
}
long Fibonacci(int n)
{
	int a;
	long num, temp, temp_1 = 0, temp_2 = 0;
	for (a=0;a<n;a++)
	{
		if (a < 2)
			temp = 1;
		else
			temp=num;
		if(a>1)
			temp_2 = temp_1;//����ûִ�е���һ��������ִ�����ϴ�ѭ����temp_1=temp����˵�ǰtemp_1���ϴ�ѭ������һֵ������temp_2
		temp_1 = temp;//ִ�е���һ��֮��temp_1����˵�ǰ���ѭ������һֵ
		num = temp_1 + temp_2;
	}
	return num;
}