#ifndef TRASER
#define TRASER
#include<stdbool.h>
#define MAXSIZE 10
typedef struct item{
	long arrive;
	int processtime;
}Item;
typedef struct node{
	Item temp;
	struct node *next;
}Node;
typedef struct queue{
	struct node*front;
	struct node*end;
	int items;
}Queue;
void InitializeQueue(Queue *);
bool Queueisfull(Queue*);
bool Queueisempty(Queue*);
bool AddQueue(Queue*,Item);
bool DeletQueue(Queue*,Item*);
void EmptyQueue(Queue*);
int Queuecount(Queue*);
#endif
