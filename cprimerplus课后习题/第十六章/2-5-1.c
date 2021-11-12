#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define R 50
struct A{
	int number;
	int sign;
};
void voit(struct A *,int ,int);
int main(void)
{
	srand(time(NULL));
	struct A st[R];
	int round;
	for(int i=0;i<R;i++)
	{
		st[i].number=(i+1)*2-3;
		st[i].sign=0;
	}
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
void voit(struct A *ch,int a,int b)
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
			}while(ch[k].sign==1);
			printf("%4d  ",ch[k]);
			ch[k].sign=1;
		}
		printf("\n");
	}
}
