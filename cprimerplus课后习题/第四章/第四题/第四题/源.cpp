#include<stdio.h>
int main()
{
	float tall;
	char name[20];
	printf("������������ֺ����(cm)\n");
	scanf_s("%s %f", name, sizeof(name), &tall);
	getchar();
	printf("%s,you are %.3f m tall", name, tall / 100);
	getchar();
	return 0;
}