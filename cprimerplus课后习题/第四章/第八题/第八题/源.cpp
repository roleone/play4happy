#include<stdio.h>
#define carren 3.785
#define yinli 1.609
int main(void)
{
	float licheng, qiyou;
	printf("请输入里程和汽油量\n");
	scanf_s("%f %f", &licheng, &qiyou);
	getchar();
	printf("%.1f\n", licheng / qiyou);
	printf("%.1f", 3.785 / (160.9*licheng / qiyou));
	getchar();
	return 0;
}