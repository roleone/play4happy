#include<stdio.h>
void jisuan(float tall,float canshu);
void main(void)
{
	float tall_a;
	printf("请输入身高\n");
	scanf_s("%f", &tall_a);
	getchar();
	jisuan(tall_a,2.54);
	getchar();
}
void jisuan(float tall,float canshu)
{
	printf("身高为%.2fcm", tall*canshu);
}