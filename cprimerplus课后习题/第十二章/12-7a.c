#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"12-7.h"
int main(void)
{
	srand(time(NULL));
	int sets,sides,dice,the;
	int * eger;
	int i;
	printf("Enter the number of sets;enter q to stop:");
	while(scanf("%d",&sets)==1&&sets>0)
	{
		i=0;
		printf("How many sides and how many dice?");
		if((the=scanf("%d%d",&sides,&dice))!=2)
		{
			if(the==EOF)
				break;
			else
			{
				printf("You should enter a integer\n");
				while(getchar()!='\n')
					continue;
				printf("please enter again\n");
				continue;
			}
		}
		eger=(int *)malloc(sets*sizeof(int));
		while(i<sets)
		{
			eger[i]=roll_n_dice(dice,sides);
			i++;
		}
		i=0;
		printf("here are %d sets of %d-%dsided throws.",sets,dice,sides);
		while(i<sets)
		{
			printf("%d ",*(eger+i));
			i++;
		}
		printf("\n");
	        printf("Enter the number of sets;enter q to stop:");
	}
	printf("bye\n");
	free(eger);
	return 0;
}
