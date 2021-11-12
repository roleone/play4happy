#include<stdio.h>
#define b 8
int main(void)
{
	int num[9],a,c,d=0;
	for (a = 0; a < b; a++)
	{
		for (c=0,num[a]=1;c<a;c++)
		{
			num[a] *= 2;
		}
	}
	do
	{
		printf("%d\n", num[d]);
		d++;
	} while (d < 8);
	getchar();
	return 0;
}