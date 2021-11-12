#include<stdio.h>
int main()
{
	float B; 
	printf("请输入杯数\n___杯");
	printf("\b\b\b\b\b");
	scanf_s("%f",&B);
	getchar();
	printf("%.1f品脱,%.0f盎司,%.0f大汤勺,%.0f茶勺",B/2,B*8,B*16,B*48);
	getchar();
	return 0;
}