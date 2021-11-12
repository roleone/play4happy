#include<stdio.h>
int main()
{
	float tall;
	char name[20];
	printf("请输入你的名字和身高(cm)\n");
	scanf_s("%s %f", name, sizeof(name), &tall);
	getchar();
	printf("%s,you are %.3f m tall", name, tall / 100);
	getchar();
	return 0;
}