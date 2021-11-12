#include<stdio.h>
int main()
{
	float f_a;
	scanf_s("%f", &f_a);
	getchar();
	printf("%.2f\n%e\n", f_a, f_a);
	getchar();
	return 0;
}