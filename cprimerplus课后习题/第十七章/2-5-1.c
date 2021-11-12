#include<stdio.h>
#include<stdlib.h>
#include"2-5.h"
void Initialize(List*plist)
{
	(*plist).head=NULL;
	(*plist).tail=NULL;
	(*plist).count=0;
}
int Count(List*plist)
{
	return (*plist).count;
}
bool Listisfull(List*plist)
{
	return (*plist).count==MAX;
}
bool Listisempty(List*plist)
{
	return (*plist).count==0;
}
bool Add(List*plist,char cc)
{
	Ch*pnew;
	if(Listisfull(plist))
	{
		fprintf(stderr,"no space\n");
		return false;
	}
	pnew=(Ch*)malloc(sizeof(Ch));
	pnew->next=NULL;
	pnew->ct=cc;
	if(Count(plist)==0)
	{
		pnew->last=NULL;
		(*plist).head=pnew;
		(*plist).tail=pnew;
	}
	else
	{
		pnew->last=plist->head;
		while(pnew->last->next!=NULL)
			pnew->last=pnew->last->next;
		pnew->last->next=pnew;
		plist->tail=pnew;
	}
	plist->count++;
	return true;
}
bool Delet(List* plist,char*cc)
{
	if(Listisempty(plist))
	{
		puts("no data");
		return false;
	}
	if(Count(plist)==1)
	{
		free(plist->tail);
		Initialize(plist);
	}
	else
	{
		plist->tail=plist->tail->last;
		*cc=plist->tail->next->ct;
		free(plist->tail->next);
		plist->tail->next=NULL;
		plist->count--;
	}
	return true;
}
bool Empty(List*plist)
{
	char kk;
	if(Listisempty(plist))
	{
		puts("no data");
		return false;
	}
	while(plist->head!=NULL)
		Delet(plist,&kk);
	return true;
}
void Traverse(List*plist,bool choice,void(*pfun)(char))
{
	Ch*go;
	if(choice)
	{
		go=plist->head;
		while(go!=NULL)
		{
			(*pfun)(go->ct);
			go=go->next;
		}
	}
	else
	{
		go=plist->tail;
		while(go!=NULL)
		{
			(*pfun)(go->ct);
			go=go->last;
		}
	}
}
