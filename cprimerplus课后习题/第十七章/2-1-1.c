#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 40
typedef struct film{
	char title[40];
	int rating;
	struct film *last;
	struct film *next;
}FILM;
char*s_gets(char*,int);
int main(void)
{
	FILM*head=NULL;
	FILM*tail=NULL;
	FILM*current=NULL;
	FILM*pre=NULL;
	char tmp[SIZE];
	puts("enter a film name");
	while(s_gets(tmp,SIZE)!=NULL&&tmp[0]!='\0')
	{
		current=(FILM*)malloc(sizeof(FILM));
		if(current==NULL)
		{
			fprintf(stderr,"no space\n");
			break;
		}
		else
		{
			strcpy(current->title,tmp);
			printf("enter the rating\n");
			while(scanf("%d",&(current->rating))!=1)
			{
				printf("enter a number\n");
				while(getchar()!='\n');
			}
			while(getchar()!='\n');
			current->next=NULL;
			if(!head)
			{
				head=current;
				current->last=NULL;
				tail=current;
			}
			else
			{
				for(pre=head;pre->next!=NULL;pre=pre->next);
				pre->next=current;
				current->last=pre;
				tail=current;
			}
			printf("enter next film name\n");
		}
	}
	if(!head)
		printf("no film\n");
	else
	{
		printf("\nthere is your film\n\n");
		current=head;
		while(current!=NULL)
		{
			printf("%s is %d\n",current->title,current->rating);
			current=current->next;
		}
		printf("\nthere is you film\n\n");
		current=tail;
		while(current!=NULL)
		{
			printf("%s is %d\n",current->title,current->rating);
			current=current->last;
		}
	}
	while(head!=NULL)
	{
		current=head->next;
		free(head);
	        head=current;
	}
	return 0;
}
char*s_gets(char*st,int n)
{
	char*kk,*kt;
	kk=fgets(st,n,stdin);
	if(kk)
	{
		if(kt=strchr(st,'\n'))
			*kt='\0';
		else
			while(getchar()!='\n');
	}
	return kk;
}
