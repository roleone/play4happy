#include<stdio.h>
int main(void)
{
	float speed, value;
	printf("�����������ٶȣ��ļ���С:\n");
	scanf_s("%f %f", &speed, &value);
	getchar();
	printf("At %.2f megabits per second,a file of %.2f megabits\ndownloads in %.2f seconds",speed,value,value/speed);
	getchar();
	return 0;
}