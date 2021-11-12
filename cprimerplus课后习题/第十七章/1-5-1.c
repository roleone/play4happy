#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"1-5.h"
void InitializeList(List* plist)
{
	*plist=NULL;
}
bool Listisempty(const List*plist)
{
	if(*plist==NULL)
		return true;
	else 
		return false;
}
bool Listisfull(const List*plist)
{
	Stack* newone;
	bool track;
	newone=(Stack*)malloc(sizeof(Stack));
	track=newone==NULL?true:false;
	free(newone);
	return track;
}
unsigned int ListItemcount(const List*plist)
{
	unsigned int count=0;
	Stack* newone=*plist;
	while(newone!=NULL)
	{
		count++;
		newone=(*newone).next;
	}
	return count;
}
bool AddItem(Item item,List*plist)
{
	Stack*newone;
	Stack*pnew=*plist;
	newone=(Stack*)malloc(sizeof(Stack));
	if(newone==NULL)
		return false;
	newone->item=item;
	newone->next=NULL;
	if((*plist)==NULL)
		*plist=newone;
	else
	{	
		while(pnew->next!=NULL)
			pnew=pnew->next;
		pnew->next=newone;
	}
	return true;
}
void Traverse(const List*plist,void(*pfun)(Item item))
{
	Stack*newone =*plist;
	while(newone!=NULL)
	{
		(*pfun)(newone->item);
		newone=newone->next;
	}
}
void EmptyList(List*plist)
{
	Stack*newone;
	while(*plist!=NULL)
	{
		newone=(*plist)->next;
		free(*plist);
		*plist=newone;
	}
}
bool DeletItem(Item* item,List*plist)
{
	if(Listisempty(plist))
		return false;
	if((*plist)->next==NULL)
	{
		*item=(*plist)->item;
		free(*plist);
		*plist=NULL;
	}
	else
	{
		Stack*newone=*plist;
		Stack*last=NULL;
		while(newone->next!=NULL)
		{
			last=newone;
			newone=newone->next;
		}
		*item=newone->item;
		free(newone);
		last->next=NULL;
	}
	return true;
}
