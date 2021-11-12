#include<stdio.h>
int main(void)
{
	if (getchar() == '1')
		printf("ok");
	else if (getchar() == '2')
		printf("oh");
	else
		printf("pa");
	getchar();
	getchar();
	return 0;
}