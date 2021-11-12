#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NM 40
struct name {
	char* first;
	char* last;
};
void fillarray(struct name*,int);
void showarray(struct name*,int);
int mycomp(const void*,const void*);
void freeee(struct name*,int);
int main(void)
{
	int num;
	printf("enter the name number:\n");
	scanf("%d",&num);
	struct name NAME[num];
	fillarray(NAME,num);
	printf("\nyour name list :\n");
	showarray(NAME,num);
	printf("\n==========================\n\n");
	qsort(NAME,num,sizeof(struct name),mycomp);
	printf("your name list after list:\n");
	showarray(NAME,num);
	freeee(NAME,num);
	return 0;
}
void freeee(struct name *st,int n)
{
	for(int i=0;i<n;i++)
	{
		free(st[i].first);
		free(st[i].last);
	}
}
void fillarray(struct name*st,int n)
{
	char tmp[NM];
	for(int i=0;i<n;i++)
	{
		printf("enter a first name:\n");
		scanf("%s",tmp);
		st[i].first=malloc(strlen(tmp)+1);
		strncpy(st[i].first,tmp,NM);
		printf("enter a last name:\n");
		scanf("%s",tmp);
		st[i].last=malloc(strlen(tmp)+1);
		strncpy(st[i].first,tmp,NM);
	}
}
void showarray(struct name*st,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%s %s\n",st[i].first,st[i].last);
	}
}
int mycomp(const void*st,const void*sd)
{
	int n;
	if((n=strcmp((*(struct name*)st).first,(*(struct name*)sd).first))==0)
		return strcmp(((struct name*)st)->last,((struct name*)sd)->last);
	else return n;
}
