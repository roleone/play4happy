#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"2-7.h"
char*s_gets(char*,int);
char menue(void);
void rrr(FILE*,List*);
void ppp(List*);
void ccc(List*);
void print(char*,int);
int main(void)
{
	char tp;
	FILE*fp;
	List klist;
	List*llist=&klist;
	Initialize(llist);
	if((fp=fopen("2-7.txt","r"))==NULL)
	{
		fprintf(stderr,"open wrong\n");
		exit(EXIT_FAILURE);
	}
	rrr(fp,llist);
	while((tp=menue())!='q')
	{
		switch(tp)
		{
			case 'a':ppp(llist);
				break;
			case 'b':ccc(llist);
				break;
			default:
				break;
		}
	}
	Empty(llist);
	fclose(fp);
	puts("bye");
	return 0;
}
char menue(void)
{
	char ch;
	puts("choose the model");
	puts("a) printf all word and the number");
	puts("b) check a word");
	puts("q) quit");
	while(scanf("%c",&ch)==1)
	{
		while(getchar()!='\n');
		if(!strchr("abq",ch))
			puts("enter the abq");
		else
			break;
	}
	return ch;
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
void rrr(FILE*fp,List*llist)
{
	char tmp[MAX];
	while(fscanf(fp,"%s",tmp)==1)
		Add(llist,tmp);
}
void ppp(List*llist)
{
	if(llist->root==NULL)
	{
		fprintf(stderr,"no data\n");
		exit(EXIT_FAILURE);
	}
	Traverse(llist,print);
}
void ccc(List*llist)
{
	char tmp[MAX];
	if(llist->root==NULL)
	{
		fprintf(stderr,"no data\n");
		exit(EXIT_FAILURE);
	}
	puts("enter you want");
	s_gets(tmp,MAX);
	if(Check(llist,tmp))
		printf("%d\n",Seek(llist,tmp).child->num);
	else
		puts("no this word");
}
void print(char*kt,int t)
{
	printf("%s %d\n",kt,t);
}
