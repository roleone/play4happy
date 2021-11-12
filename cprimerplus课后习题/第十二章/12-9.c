#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main(void)
{
	int num,i=0,j;
	char**ch;
	char cr[50];
	char cc;
	printf("How many words do you wish to enter?");
	scanf("%d",&num);
	while(getchar()!='\n')
		continue;
	ch=(char**)malloc(num*sizeof(char*));
	while(i<num)
	{
		j=0;
		while(isspace(cc=getchar()))
			continue;
		do
		{
			cr[j]=cc;
			j++;
		}while(!isspace(cc=getchar()));
		ch[i]=(char*)malloc(strlen(cr)+1);
		strcpy(ch[i],cr);
		for(int k=0;k<50;k++)
			cr[k]='\0';
		i++;
	}
	i=0;
	printf("this is your words:\n");
	while(i<num)
	{
		printf("%s\n",ch[i]);
		free(ch[i]);
		i++;
	}
	free(ch);
	return 0;
}
