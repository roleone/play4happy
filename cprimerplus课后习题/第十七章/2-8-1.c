#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"2-8.h"
static bool Toleft(Node*,char*);
static bool Toright(Node*,char*);
static Node* MakeNode(Mess);
static void AddNode(Node*,Node*);
static void DeletNode(Node**);
static void DeletallNode(Node*);
static void Inorder(Node*,void(*pfun)(Pet));
static bool Addkind(List*,Mess);
static bool Deletkind(List*,Mess);
static int Num(Node*);
bool Treeisfull(Tree*ptree)
{
	return ptree->count==MAX?true:false;
}
bool Treeisempty(Tree*ptree)
{
	return ptree->count==0?true:false;
}
void Initialize(Tree*ptree)
{
	ptree->root=NULL;
	ptree->count=0;
}
int Count(Tree*ptree)
{
	if(ptree->root!=NULL)
		return Num(ptree->root);
	return 0;
}
bool Add(Tree*ptree,Mess pmess)
{
	if(Treeisfull(ptree))
	{
		fprintf(stderr,"full\n");
		return false;
	}
	if(Check(ptree,pmess))
	{
		Pair look=Seek(ptree,pmess);
		Addkind(&(((look.child)->PET).klist),pmess);
		return true;
	}
	else
	{
		Node*pnew;
		pnew=MakeNode(pmess);
		if(ptree->root==NULL)
			ptree->root=pnew;
		else
			AddNode(ptree->root,pnew);
		ptree->count++;
		return true;
	}
}
bool Delet(Tree*ptree,Mess pmess)
{
	if(Treeisempty(ptree))
	{
		fprintf(stderr,"no data\n");
		return false;
	}
	if(!Check(ptree,pmess))
	{
		fprintf(stderr,"no this data\n");
		return false;
	}
	Pair look;
	look=Seek(ptree,pmess);
	if(look.parent==NULL)
	{
		if(strcmp(pmess.KIND,"all")==0||(look.child->PET).klist.num==1)
		{
			DeletNode(&(ptree->root));
			ptree->count--;
		}
		else
			Deletkind(&((ptree->root->PET).klist),pmess);
	}
	else if(look.child==look.parent->left)
	{
		if(strcmp(pmess.KIND,"all")==0||(look.child->PET).klist.num==1)
		{
			DeletNode(&(look.parent->left));
			ptree->count--;
		}
		else
			Deletkind(&((look.child->PET).klist),pmess);
	}
	else
	{
		if(strcmp(pmess.KIND,"all")==0||(look.child->PET).klist.num==1)
		{
			DeletNode(&(look.parent->right));
			ptree->count--;
		}
		else
			Deletkind(&((look.child->PET).klist),pmess);
	}
	return true;
}
void Empty(Tree*ptree)
{
	DeletallNode(ptree->root);
	Initialize(ptree);
}
bool Check(Tree*ptree,Mess pmess)
{
	Pair look=Seek(ptree,pmess);
	if(look.child==NULL)
		return false;
	else 
		return true;
}
Pair Seek(Tree*ptree,Mess pmess)
{
	Pair look;
	look.parent=NULL;
	look.child=ptree->root;
	while(look.child!=NULL)
	{
		if(Toleft(look.child,pmess.NAME))
		{
			look.parent=look.child;
			look.child=look.child->left;
		}
		else if(Toright(look.child,pmess.NAME))
		{
			look.parent=look.child;
			look.child=look.child->right;
		}
		else
			break;
	}
	return look;
}
void Traverse(Tree*ptree,void(*pfun)(Pet))
{
	if(ptree->root!=NULL)
		Inorder(ptree->root,pfun);
}
static bool Toleft(Node*pnode,char*ch)
{
	if(strcmp((pnode->PET).name,ch)>0)
		return true;
	else
		return false;
}
static bool Toright(Node*pnode,char*ch)
{
	if(strcmp((pnode->PET).name,ch)<0)
		return true;
	else
		return false;
}
static Node* MakeNode(Mess pmess)
{
	Node*pnew;
	Pet ppet;
	strcpy(ppet.name,pmess.NAME);
	List plist;
	plist.num=1;
	Kind*pkind=(Kind*)malloc(sizeof(Kind));
	strcpy(pkind->anim,pmess.KIND);
	pkind->next=NULL;
	plist.head=pkind;
	ppet.klist=plist;
	pnew=(Node*)malloc(sizeof(Node));
	if(pnew!=NULL)
	{
		pnew->left=NULL;
		pnew->right=NULL;
		pnew->PET=ppet;
	}
	return pnew;
}
static void AddNode(Node*pnode,Node*pnew)
{
	Kind*ktmp;
	if(Toleft(pnode,(pnew->PET).name))
	{
		if(pnode->left==NULL)
			pnode->left=pnew;
		else
			AddNode(pnode->left,pnew);
	}
	else if(Toright(pnode,(pnew->PET).name))
	{
		if(pnode->right==NULL)
			pnode->right=pnew;
		else
			AddNode(pnode->right,pnew);
	}
	else
	{
		fprintf(stderr,"add same pet\n");
		exit(EXIT_FAILURE);
	}
}
static void DeletNode(Node**ppnode)
{
	Node*tmp;
	Kind*ktmp;
	if((*ppnode)->left==NULL)
	{
		tmp=*ppnode;
		*ppnode=(*ppnode)->right;
		while((tmp->PET).klist.head!=NULL)
		{
			ktmp=(tmp->PET).klist.head;
			(tmp->PET).klist.head=(tmp->PET).klist.head->next;
			free(ktmp);
		}
		free(tmp);
	}
	else if((*ppnode)->right==NULL)
	{
		tmp=*ppnode;
		*ppnode=(*ppnode)->left;
		while((tmp->PET).klist.head!=NULL)
		{
			ktmp=(tmp->PET).klist.head;
			(tmp->PET).klist.head=(tmp->PET).klist.head->next;
			free(ktmp);
		}
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
		while((tmp->PET).klist.head!=NULL)
		{
			ktmp=(tmp->PET).klist.head;
			(tmp->PET).klist.head=(tmp->PET).klist.head->next;
			free(ktmp);
		}
		free(tmp);
	}
}
static void DeletallNode(Node*pnode)
{
	Node*tmp;
	Kind*ktmp;
	if(pnode!=NULL)
	{
		tmp=pnode->right;
		DeletallNode(pnode->left);
		(pnode->PET).klist.num=0;
		while((pnode->PET).klist.head!=NULL)
		{
			ktmp=(pnode->PET).klist.head;
			(pnode->PET).klist.head=(pnode->PET).klist.head->next;
			free(ktmp);
		}
		free(pnode);
		DeletallNode(tmp);
	}
}
static void Inorder(Node*pnode,void(*pfun)(Pet))
{
	if(pnode!=NULL)
	{
		Inorder(pnode->left,pfun);
		(*pfun)(pnode->PET);
		Inorder(pnode->right,pfun);
	}
}
bool Addkind(List*plist,Mess pmess)
{
	if(plist->num==MAX)
	{
		fprintf(stderr,"no space\n");
		return false;
	}
	Kind*kktmp=NULL;
	Kind*ktmp=plist->head;
	while(ktmp!=NULL&&strcmp(ktmp->anim,pmess.KIND)!=0)
	{
		kktmp=ktmp;
		ktmp=ktmp->next;
	}
	if(ktmp!=NULL)
	{
		fprintf(stderr,"this kind is have\n");
		return false;
	}
	else
	{
		ktmp=(Kind*)malloc(sizeof(Kind));
		if(ktmp==NULL)
		{
			fprintf(stderr,"no space\n");
			return false;
		}
		kktmp->next=ktmp;
		strcpy(ktmp->anim,pmess.KIND);
		ktmp->next=NULL;
	}
	plist->num++;
	return true;
}
bool Deletkind(List*plist,Mess pmess)
{
	if(plist->num==0)
	{
		fprintf(stderr,"no data\n");
		return false;
	}
	Kind*kktmp=NULL;
	Kind*ktmp=plist->head;
	while(strcmp(ktmp->anim,pmess.KIND)!=0&&ktmp!=NULL)
	{
		kktmp=ktmp;
		ktmp=ktmp->next;
	}
	if(ktmp==NULL)
	{
		fprintf(stderr,"no this kind\n");
		return false;
	}
	else
	{
		if(kktmp!=NULL)
			kktmp->next=NULL;
		else
			plist->head=plist->head->next;
		free(ktmp);
	}
	plist->num--;
	return true;
}
static int Num(Node*pnode)
{
	int Count=0;
	if(pnode!=NULL)
	{
		Num(pnode->left);
		Count+=(pnode->PET).klist.num;
		Num(pnode->right);
	}
	return Count;
}
