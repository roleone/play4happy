#include<stdio.h>
#include<string.h>
int main(void)
{
	const int days[] = { 1,2,3,4,5 };
	char ch[10];
	int day[5];
	int index;
	for (index = 0; index < sizeof days/*/sizeof days[0]*/;index++)
		printf("month %2d has %d days.\n", index + 1, days[index]);
	printf("%zd  %zd  %zd", sizeof days,sizeof day,sizeof ch);
	getchar();
	getchar();
	return 0;
}