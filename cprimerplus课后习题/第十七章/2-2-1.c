#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"2-2.h"
void InitializeList(List* plist)
{
	(*plist).head=NULL;
}
bool Listisempty(const List*plist)
{
	if((*plist).head==NULL)
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
	Stack* newone=(*plist).head;
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
	Stack*pnew=(*plist).head;
	newone=(Stack*)malloc(sizeof(Stack));
	if(newone==NULL)
		return false;
	newone->item=item;
	newone->next=NULL;
	if((*plist).head==NULL)
		(*plist).head=newone;
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
	Stack*newone =(*plist).head;
	while(newone!=NULL)
	{
		(*pfun)(newone->item);
		newone=newone->next;
	}
}
void EmptyList(List*plist)
{
	Stack*newone;
	while((*plist).head!=NULL)
	{
		newone=(*plist).head->next;
		free((*plist).head);
		(*plist).head=newone;
	}
}
bool DeletItem(Item* item,List*plist)
{
	if(Listisempty(plist))
		return false;
	if((*plist).head->next==NULL)
	{
		*item=(*plist).head->item;
		free((*plist).head);
		(*plist).head=NULL;
	}
	else
	{
		Stack*newone=(*plist).head;
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
