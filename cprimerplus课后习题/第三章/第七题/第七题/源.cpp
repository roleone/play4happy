#include<stdio.h>
void jisuan(float tall,float canshu);
void main(void)
{
	float tall_a;
	printf("���������\n");
	scanf_s("%f", &tall_a);
	getchar();
	jisuan(tall_a,2.54);
	getchar();
}
void jisuan(float tall,float canshu)
{
	printf("���Ϊ%.2fcm", tall*canshu);
}