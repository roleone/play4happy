#include<stdio.h>
int main(void)
{
	float speed, value;
	printf("请输入下载速度，文件大小:\n");
	scanf_s("%f %f", &speed, &value);
	getchar();
	printf("At %.2f megabits per second,a file of %.2f megabits\ndownloads in %.2f seconds",speed,value,value/speed);
	getchar();
	return 0;
}