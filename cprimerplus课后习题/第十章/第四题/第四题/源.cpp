#include<stdio.h>
int _max_(double[], int);
int main(void)
{
	int zd,_max;
	double k[] = { 34,123.12,23.34,23,23,12.43,123.4,12.3,4.5,12.4 };
	zd = sizeof(k) / sizeof(double);
	_max = _max_(k, zd);
	printf("%d", _max);
	getchar();
	return 0;
}
int _max_(double a[], int b)
{
	double tmp=0;
	int i;
	for (i = 0; i < b; i++)
		tmp = (tmp > *(a + i)) ? tmp : *(a + i);
	for (i = 0; i < b; i++)
	{
		if (tmp == a[i])
			break;
	}
	return i;
}