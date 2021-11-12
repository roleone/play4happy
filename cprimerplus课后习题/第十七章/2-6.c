#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 10
bool check(int*,int,int);
int line(const void*,const void *);
int main(void)
{
	int *ts1,*ts2,*ts3;
	int tmp[MAX];
	int n1,n2,n3;
	int want;
	int *temp;
	int nn;
	for(int i=0;i<3;i++)
	{
		nn=0;
		printf("enter the number line%d:\n",i+1);
		for(int j=0;j<MAX;j++)
		{
			if(scanf("%d",&tmp[j])!=1)
				break;
			else
				nn++;
		}
		while(getchar()!='\n');
		temp=(int*)malloc(nn*sizeof(int));
		for(int j=0;j<nn;j++)
			*(temp+j)=tmp[j];
		qsort(temp,nn,sizeof(int),line);
		switch(i)
		{
			case 0:ts1=temp;
			       n1=nn;
				break;
			case 1:ts2=temp;
			       n2=nn;
				break;
			case 2:ts3=temp;
			       n3=nn;
				break;
		}
	}
	for(int j=0;j<n1;j++)
		printf("%d ",ts1[j]);
	putchar('\n');
	for(int j=0;j<n2;j++)
		printf("%d ",ts2[j]);
	putchar('\n');
	for(int j=0;j<n3;j++)
		printf("%d ",ts3[j]);
	putchar('\n');
	puts("enter your want");
	while(scanf("%d",&want)!=1)
	{
		printf("enter a number\n");
		while(getchar()!='\n');
	}
	if(check(ts1,n1,want))
		printf("%d is in no.1\n",want);
	if(check(ts2,n2,want))
		printf("%d is in no.2\n",want);
	if(check(ts3,n3,want))
		printf("%d is in no.3\n",want);
	free(ts1);
	free(ts2);
	free(ts3);
	return 0;
}
bool check(int*st,int n,int num)
{
/*	int min=0,max=n-1;
	int nn=n/2;
	if(num>st[n-1]||num<st[0])
		return false;
	while(st[nn]!=num)
	{
		if(max-min<=1&&num!=st[max]&&num!=st[min])
			return false;
		if(st[nn]>num)
		{
			max=nn;
			nn=(min+nn)/2;
		}
		else if(st[nn]<num)
		{
			min=nn;
			nn=(max+nn)/2;
		}
	}
	return true;
*/
	if(n==1&&num!=st[0])
		return false;
	if(st[n/2]>num)
		return check(st,n%2==0?n/2:n/2+1,num);
	else if(st[n/2]<num)
		return check(st+n/2,n%2==0?n/2:n/2+1,num);
	else
		return true;
}
int line(const void*st1,const void*st2)
{
	return *(int*)st1-*(int*)st2;
}
