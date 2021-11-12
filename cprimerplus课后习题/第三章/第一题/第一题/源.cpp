#include<stdio.h>
int main()
{
	int i_a = 4294967295;
	float f_a = 1e37;
	float f_b = 2.000001;
	printf("%d\n", i_a + 1);
	printf("%f\n", f_a*100);
	printf("%f\n", f_b / 2);
	getchar();
	return 0;
}