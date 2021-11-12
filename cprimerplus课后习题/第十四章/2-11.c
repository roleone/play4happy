#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void transform(double*,double*,int,double(*ptr)(double));
double (*pla)(double);
double add(double);
int main(void)
{
	typedef double T[20];
	T a,b;
	for(int i=0;i<20;i++)
	{
		a[i]=i*1.1;
		printf("%-7.2lf",a[i]);
		if(i==9)
			putchar('\n');
	}
	putchar('\n');
	pla=round;
	transform(a,b,20,pla);
	for(int i=0;i<20;i++)
	{
		printf("%-7.2lf",b[i]);
		if(i==9)
			putchar('\n');
	}
	putchar('\n');
	pla=sqrt;
	transform(a,b,20,pla);
	for(int i=0;i<20;i++)
	{
		printf("%-7.2lf",b[i]);
		if(i==9)
			putchar('\n');
	}
	putchar('\n');
	pla=add;
	transform(a,b,20,pla);
	for(int i=0;i<20;i++)
	{
		printf("%-7.2lf",b[i]);
		if(i==9)
			putchar('\n');
	}
	putchar('\n');
	return 0;
}
void transform(double* st1,double*st2,int n,double(*ptr)(double))
{
	int k=0;
	while(k<n)
	{
		st2[k]=(*ptr)(st1[k]);
		k++;
	}
}
double add(double n)
{
	return n+0.2;
}
