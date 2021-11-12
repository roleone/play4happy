#ifndef TRASURE
#define TRASURE
#include<stdbool.h>
#define SIZE 40
typedef struct film{
	char title[SIZE];
	int rating;
}Item;
typedef struct list{
	Item entries[100];
	int items;
}List;
void InitializeList(List *);
bool Listisempty(const List*);
bool Listisfull(const List*);
unsigned int ListItemcount(const List*);
bool AddItem(Item,List*);
bool DeletItem(Item*,List*);
void Traverse(const List*,void (*pfun)(Item));
void EmptyList(List*);
#endif
