#include<stdio.h>
#define b 8
int main(void)
{
	int num1[8];
	int a;
	char ch;
	do
	{
		printf("����˸�����\n");
		for (a = 0; a<b; a++)
		{
			scanf("%d", &num1[a]);
			getchar();
		}
		for (a = 0; a < b; a++)
		{
			printf("%d", num1[7 - a]);
		}
		printf("\n�Ƿ����Y/N\n");
		scanf("%c", &ch);
		getchar();
	} while (ch=='Y');
	printf("end");
	getchar();
	return 0;
}