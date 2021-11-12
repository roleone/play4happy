#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"2-3.h"
void InitializeList(List* plist)
{
	for(int i=0;i<100;i++)
	{
		strcpy((*plist).entries[i].title,"\0");
		(*plist).entries[i].rating=0;
	}
	(*plist).items=0;
}
bool Listisempty(const List*plist)
{
	return (*plist).items==0?true:false;
}
bool Listisfull(const List*plist)
{
	return (*plist).items==100?true:false;;
}
unsigned int ListItemcount(const List*plist)
{
	return (*plist).items;
}
bool AddItem(Item item,List*plist)
{
	if((*plist).items<100)
	{
		(*plist).entries[(*plist).items]=item;
		(*plist).items++;
		return true;
	}
	else
		return false;
}
void Traverse(const List*plist,void(*pfun)(Item item))
{
	for(int i=0;i<(*plist).items;i++)
		(*pfun)((*plist).entries[i]);
}
void EmptyList(List*plist)
{
	for(int i=0;i<100;i++)
	{
		strcpy((*plist).entries[i].title,"\0");
		(*plist).entries[i].rating=0;
	}
	(*plist).items=0;
}
bool DeletItem(Item* item,List*plist)
{
	if((*plist).items>0)
	{
		strcpy((*item).title,(*plist).entries[(*plist).items-1].title);
		(*item).rating=(*plist).entries[(*plist).items-1].rating;
		strcpy((*plist).entries[(*plist).items-1].title,"\0");
		(*plist).entries[(*plist).items-1].rating=0;
		(*plist).items--;
		return true;
	}
	else
		return false;
}
