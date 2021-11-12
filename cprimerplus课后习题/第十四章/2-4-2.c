#include<stdio.h>
#include<stdlib.h>
struct name{
	char fname[10];
	char iname[10];
	char lname[10];
};
struct numb{
	long shebao;
	struct name kb;
};
char *s_gets(char*,int);
void structprintf(struct numb*);
struct numb*ptr;
int main(void)
{
	struct numb all[5]={{.shebao=0},{.shebao=0},{.shebao=0},{.shebao=0},{.shebao=0}};
	ptr=all;
	printf("enter shebao\n");
	for(int i=0;i<5&&scanf("%ld",&(all[i].shebao))==1;i++)
	{
		while(getchar()!='\n')
			continue;
		printf("fname\n");
		s_gets(all[i].kb.fname,10);
		printf("iname\n");
		s_gets(all[i].kb.iname,10);
		printf("lname\n");
		s_gets(all[i].kb.lname,10);
		if(i!=5)
			printf("enter shebao\n");
	}
	structprintf(ptr);
	return 0;
}
char*s_gets(char*st,int n)
{
	int i=0;
	char*kk;
	kk=fgets(st,n,stdin);
	if(kk)
	{
		while(st[i]!='\0'&&st[i]!='\n')
			i++;
		if(st[i]=='\n')
			st[i]='\0';
		else
			while(getchar()!='\n')
				continue;
	}
	return kk;
}
void structprintf(struct numb *ab)
{
	int k=0;
	while(k<5&&(ab+k)->shebao!=0)
	{	printf("%s, %s %c.--%ld\n",(ab+k)->kb.lname,(ab+k)->kb.fname,(ab+k)->kb.iname[0],(ab+k)->shebao);
		k++;
	}
}
