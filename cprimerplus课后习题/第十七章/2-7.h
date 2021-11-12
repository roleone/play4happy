#ifndef TRASER
#define TRASER
#include<stdbool.h>
#define MAX 20
typedef struct node{
	char word[MAX];
	int num;
	struct node*left;
	struct node*right;
}Node;
typedef struct list{
	Node*root;
	int count;
}List;
typedef struct dou{
	Node*parent;
	Node*child;
}Pair;
void Initialize(List*);
bool Add(List*,char*);
bool Delet(List*,char*);
bool Check(List*,char*);
bool Listisfull(List*);
bool Listisempty(List*);
bool Empty(List*);
int Count(List*);
void Traverse(List*,void(*pfun)(char*,int));
Pair Seek(List*,char*);
#endif
