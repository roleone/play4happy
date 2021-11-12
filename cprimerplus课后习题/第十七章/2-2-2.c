#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include"2-2.h"
char menue();
char*s_gets(char*,int);
void PRINT(Item);
void ADD(Item*,List*);
void DELET(Item*,List*);
int main(void)
{
	List klist;
	List* llist=&klist;
	Item litem;
	InitializeList(llist);
	char ch;
	unsigned int n;
	while((ch=menue())!='q')
	{
		switch(ch)
		{
			case 'a':ADD(&litem,llist);
				break;
			case 'd':DELET(&litem,llist);
				break;
			case 'p':Traverse(llist,PRINT);
				break;
			case 'c':n=ListItemcount(llist);
				 printf("the are %d data\n",n);
				 break;
			default:
				break;
		}
	}
	EmptyList(llist);
	return 0;
}
char menue(void)
{
	char cg;
	printf("a)add     d)delet   c)count   p)prnitf   q)quit\n");
	while((cg=getchar())!=EOF)
	{
		cg=tolower(cg);
		while(getchar()!='\n');
		if(strchr("adcpq",cg)==NULL)
		{
			fprintf(stderr,"enter wrong");
		}
		else
		break;
	}
	if(cg==EOF)
		cg='q';
	return cg;
}
void PRINT(Item item)
{
	printf("%s is %d\n",item.title,item.rating);
}
char*s_gets(char*st,int n)
{
	char*kk,*kt;
	kk=fgets(st,n,stdin);
	if(kk)
	{
		kt=strchr(st,'\n');
		if(kt)
			*kt='\0';
		else
			while(getchar()!='\n');
	}
	return kk;
}
void ADD(Item* item,List*klist)
{
	if(Listisfull(klist))
		fprintf(stderr,"no spase\n");
	else
	{
		printf("enter the name:\n");
		s_gets((*item).title,40);
		printf("enter the rating\n");
		scanf("%d",&((*item).rating));
		while(getchar()!='\n');
		if(AddItem((*item),klist))
			printf("add success\n");
		else
			printf("add wrong\n");
	}
}
void DELET(Item* item,List* klist)
{
	if(Listisempty(klist))
		fprintf(stderr,"no data\n");
	else
	{
		DeletItem(item,klist);
		printf("%s(%d) is deleted\n",(*item).title,(*item).rating);
	}
}

