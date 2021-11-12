#include<stdio.h>
void to_base_on(int number, int base);
int main(void)
{
	int number, base;
	while (1)
	{
		printf("请输入数字和进制\n");
		scanf("%d%d", &number, &base);
		to_base_on(number, base);
		printf("\n");
		if (getchar() != '\n')
			break;
	}
	return 0;
}
void to_base_on(int number, int base)
{
	int temp,number_p;
	if (number / base > 0)
	{
		number_p = number / base;
		to_base_on(number_p, base);
	}		
	temp = number%base;
	printf("%d", temp);
}