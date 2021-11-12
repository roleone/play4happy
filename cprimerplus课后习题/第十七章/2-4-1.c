#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"2-4.h"
char*s_gets(char*,int);
void InitializeQueue(Queue*QQ)
{
	QQ->front=NULL;
	QQ->end=NULL;
	QQ->items=0;
}
bool Queueisfull(Queue*QQ)
{
	return QQ->items==MAXSIZE?true:false;
}
bool Queueisempty(Queue*QQ)
{
	return QQ->items==0?true:false;
}
bool AddQueue(Queue*QQ,Item tmp)
{
	Node*NN;
	if(Queueisfull(QQ))
	{
		fprintf(stderr,"no space\n");
		return false;
	}
	NN=(Node*)malloc(sizeof(Node));
	NN->temp=tmp;
	NN->next=NULL;
	if(Queueisempty(QQ))
	{
		QQ->front=NN;
		QQ->end=NN;
		QQ->items++;
	}
	else
	{
		QQ->end->next=NN;
		QQ->end=NN;
		QQ->items++;
	}
	return true;
}
bool DeletQueue(Queue*QQ,Item*tmp)
{
	Node*NN;
	if(Queueisempty(QQ))
	{
		fprintf(stderr,"no data\n");
		return false;
	}
	NN=QQ->front;
	QQ->front=QQ->front->next;
	*tmp=NN->temp;
	free(NN);
	QQ->items--;
	if(Queuecount(QQ)==0)
		QQ->end=NULL;
	return true;
}
void EmptyQueue(Queue*QQ)
{
	while(QQ->front!=NULL)
	{
		Node*NN=QQ->front;
		QQ->front=QQ->front->next;
		free(NN);
		QQ->items--;
	}
	QQ->end=NULL;
}
int Queuecount(Queue*QQ)
{
	return QQ->items;
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
	return 0;
}
