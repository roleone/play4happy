#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(void)
{
	int * ch;
	int i=0,k,j=0;
	ch=(int *)malloc(100*sizeof(int));
	srand(time(NULL));
	while(i<100)
	{
		*(ch+i)=rand()%10+1;
		i++;
	}
	i=0;
/*	while(i<99)
	{
		k=1;
		while(k<100-i)
		{
		if(ch[i]<ch[i+k])
		{
		int tmp;
	tmp=ch[i];
ch[i]=ch[i+k];
ch[i+k]=tmp;
		}
		k++;
		}
		i++;
	}*/
	i=0;
	while(i<100)
	{
		printf("%d ",ch[i]);
		i++;
	}
	printf("\n");
	free(ch);
	return 0;
}
