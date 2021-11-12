#ifndef TRASER
#define TRASER
#define MAX 20
#include<stdbool.h>
typedef struct mess{
	char NAME[MAX];
	char KIND[MAX];
}Mess;
typedef struct kind{
	char anim[MAX];
	struct kind* next;
}Kind;
typedef struct list{
	Kind* head;
	int num;
}List;
typedef struct pet{
	char name[MAX];
	List klist;
}Pet;
typedef struct node{
	Pet PET;
	struct node *left;
	struct node *right;
}Node;
typedef struct tree{
	Node*root;
	int count;
}Tree;
typedef struct pair{
	Node*parent;
	Node*child;
}Pair;
bool Treeisfull(Tree*);
bool Treeisempty(Tree*);
int Count(Tree*);
bool Add(Tree*,Mess);
bool Delet(Tree*,Mess);
void Empty(Tree*);
void Initialize(Tree*);
void Traverse(Tree*,void(*pfun)(Pet));
bool Check(Tree*,Mess);
Pair Seek(Tree*,Mess);
#endif
