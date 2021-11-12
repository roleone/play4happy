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
			temp_2 = temp_1;//由于没执行到下一步，但是执行了上次循环的temp_1=temp，因此当前temp_1是上次循环的上一值，传给temp_2
		temp_1 = temp;//执行到这一步之后，temp_1变成了当前这次循环的上一值
		num = temp_1 + temp_2;
	}
	return num;
}