#ifndef TRASER
#define TRASER
#define MAX 20
#include<stdbool.h>
typedef struct ch{
	char ct;
	struct ch *last;
	struct ch *next;
}Ch;
typedef struct list{
	Ch*head;
	Ch*tail;
	int count;
}List;
void Initialize(List*);
int Count(List*);
bool Listisfull(List*);
bool Listisempty(List*);
bool Add(List*,char);
bool Delet(List*,char*);
bool Empty(List*);
void Traverse(List*,bool,void(*pfun)(char));
#endif
