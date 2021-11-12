#include<stdio.h>
double oversize(double[], int);
int main(void)
{
	double ov;
	int n;
	double k[] = { 34.1,123.4,12,31.4,123.4,12.3,42.1,34.1,3.1,32.1,32.4 };
	n = sizeof(k) / sizeof(double);
	ov = oversize(k, n);
	printf("%lf", ov);
	getchar();
	return 0;
}
double oversize(double a[], int b)
{
	int i;
	double tmp,tmp_in=a[0], tmp_ax=a[0];
	for (i = 0; i < b; i++)
	{
		tmp_in = (tmp_in < a[i]) ? tmp_in : a[i];
		tmp_ax = (tmp_ax > *(a + i)) ? tmp_ax : *(a + i);
	}
	tmp = tmp_ax - tmp_in;
	return tmp;
}