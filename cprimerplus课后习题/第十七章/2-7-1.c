#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"2-7.h"
static bool Toleft(char*,char*);
static bool Toright(char*,char*);
static bool AddNode(Node*,Node*);
static void DeletNode(Node**);
static void DeletallNode(Node*);
static void Inorder(Node*,void(*pfun)(char*,int));
void Initialize(List*plist)
{
	(*plist).root=NULL;
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
bool Add(List*plist,char* cc)
{
	Node*pnew;
	if(Listisfull(plist))
	{
		fprintf(stderr,"no space\n");
		return false;
	}
	if(Check(plist,cc))
	{
		Pair look=Seek(plist,cc);
		look.child->num++;
		return false;
	}
	pnew=(Node*)malloc(sizeof(Node));
	pnew->right=NULL;
	pnew->left=NULL;
	pnew->num=1;
	strcpy(pnew->word,cc);
	if(Count(plist)==0)
		(*plist).root=pnew;
	else
		AddNode(plist->root,pnew);
	plist->count++;
	return false;
}
bool Delet(List* plist,char*cc)
{
	Pair pair;
	if(Listisempty(plist))
	{
		puts("no data");
		return false;
	}
	pair=Seek(plist,cc);
	if(pair.child==NULL)
		return false;
	else if(pair.parent==NULL)
		DeletNode(&(plist->root));
	else
	{
		if(pair.child==pair.parent->left)
			DeletNode(&(pair.parent->left));
		else
			DeletNode(&(pair.parent->right));
	}
	plist->count--;
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
	if(plist->root!=NULL)
		DeletallNode(plist->root);
	Initialize(plist);
	return true;
}
void Traverse(List*plist,void(*pfun)(char*,int))
{
	if(plist!=NULL)
		Inorder(plist->root,pfun);
}
bool Check(List*plist,char*cc)
{
	return Seek(plist,cc).child==NULL?false:true;
}
static bool Toleft(char*c1,char*c2)
{
	return strcmp(c1,c2)>0;
}
static bool Toright(char*c1,char*c2)
{
	return strcmp(c1,c2)<0;
}
static bool AddNode(Node*mnode,Node*pnode)
{
	if(Toleft(mnode->word,pnode->word))
	{
		if(mnode->left==NULL)
		{
			mnode->left=pnode;
			return 1;
		}
		else
			AddNode(mnode->left,pnode);
	}
	else if(Toright(mnode->word,pnode->word))
	{
		if(mnode->right==NULL)
		{
			mnode->right=pnode;
			return 1;
		}
		else
			AddNode(mnode->right,pnode);
	}
	else
		return 0;
}
Pair Seek(List*plist,char*cc)
{
	Pair look;
	look.parent=NULL;
	look.child=plist->root;
	if(look.child==NULL)
		return look;
	while(look.child!=NULL)
	{
		if(Toleft(look.child->word,cc))
		{
			look.parent=look.child;
			look.child=look.child->left;
		}
		else if(Toright(look.child->word,cc))
		{
			look.parent=look.child;
			look.child=look.child->right;
		}
		else
			break;
	}
	return look;
}
static void DeletNode(Node**ppnode)
{
	Node*tmp;
	if((*ppnode)->left==NULL)
	{
		tmp=*ppnode;
		*ppnode=(*ppnode)->right;
		free(tmp);
	}
	else if((*ppnode)->right==NULL)
	{
		tmp=*ppnode;
		*ppnode=(*ppnode)->left;
		free(tmp);
	}
	else
	{
		tmp=(*ppnode)->left;
		while(tmp->right!=NULL)
			tmp=tmp->right;
		tmp->right=(*ppnode)->right;
		tmp=*ppnode;
		*ppnode=(*ppnode)->left;
		free(tmp);
	}
}
static void DeletallNode(Node*pnode)
{
	Node*tmp;
	if(pnode!=NULL)
	{
		tmp=pnode->right;
		DeletallNode(pnode->left);
		free(pnode);
		DeletallNode(tmp);
	}
}
static void Inorder(Node*pnode,void(*pfun)(char*,int))
{
	if(pnode!=NULL)
	{
		Inorder(pnode->left,pfun);
		(*pfun)(pnode->word,pnode->num);
		Inorder(pnode->right,pfun);
	}
}
