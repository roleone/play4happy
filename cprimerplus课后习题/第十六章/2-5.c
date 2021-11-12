#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define R 50
void voit(int *,int ,int);
int main(void)
{
	srand(time(NULL));
	int st[R];
	int round;
	for(int i=0;i<R;i++)
		st[i]=(i+1)*2-3;
	printf("enter the round:\n");
	if(scanf("%d",&round)!=1)
	{
		fprintf(stderr,"enter wrong\n");
		exit(EXIT_FAILURE);
	}
	while(getchar()!='\n')
		continue;
	voit(st,R,round);
	return 0;
}
void voit(int *ch,int a,int b)
{
	int many;
	int k;
	printf("enter a round how many:\n");
	while(scanf("%d",&many)!=1||a<b*many)
		printf("enter wrong enter again:\n");
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<many;j++)
		{
			do
			{
				k=rand()%R;
			}while(ch[k]==-100);
			printf("%4d  ",ch[k]);
			ch[k]=-100;
		}
		printf("\n");
	}
}
