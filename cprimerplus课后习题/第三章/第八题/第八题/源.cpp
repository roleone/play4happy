#include<stdio.h>
int main()
{
	float B; 
	printf("�����뱭��\n___��");
	printf("\b\b\b\b\b");
	scanf_s("%f",&B);
	getchar();
	printf("%.1fƷ��,%.0f��˾,%.0f������,%.0f����",B/2,B*8,B*16,B*48);
	getchar();
	return 0;
}