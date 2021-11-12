#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"2-8.h"
char*s_gets(char*,int);
char menue(void);
void print(Pet);
void addpet(Tree*);
void showpet(Tree*);
void numpet(Tree*);
void findpet(Tree*);
void deletpet(Tree*);
int main(void)
{
	Tree pets;
	Initialize(&pets);
	char ct;
	while((ct=menue())!='q')
	{
		switch(ct)
		{
			case 'a':addpet(&pets);
				break;
			case 's':showpet(&pets);
				break;
			case 'n':numpet(&pets);
				break;
			case 'f':findpet(&pets);
				break;
			case 'd':deletpet(&pets);
				break;
			default:fprintf(stderr,"wrong\n");
				exit(EXIT_FAILURE);
				break;
		}
	}
	Empty(&pets);
	puts("bye");
	return 0;
}
char*s_gets(char*st,int n)
{
	char*kk,*kt;
	kk=fgets(st,n,stdin);
	if(kk)
	{
		if(kt=strchr(st,'\n'))
			*kt='\0';
		else
			while(getchar()!='\n');
	}
	return kk;
}
char menue(void)
{
	char ch;
	puts("enter your choice");
	puts("a)add a pet       s)show list of pets");
	puts("n)number of pet   f)find pet");
	puts("d)delet  pet      q)quit");
	while((ch=getchar())!=EOF)
	{
		while(getchar()!='\n');
		if(strchr("asnfdq",ch)==NULL)
			printf("enter asnfdq\n");
		else
			break;
	}
	if(ch==EOF)
		ch='q';
	return ch;
}
void print(Pet ppet)
{
	Kind*kkind;
	printf("name:%s\n",ppet.name);
	kkind=ppet.klist.head;
	while(kkind!=NULL)
	{
		printf("kind:%s  ",kkind->anim);
		kkind=kkind->next;
	}
	putchar('\n');
}
void addpet(Tree*petre)
{
	Mess petmes;
	puts("enter the name:");
	s_gets(petmes.NAME,MAX);
	puts("enter the kind:");
	s_gets(petmes.KIND,MAX);
	Add(petre,petmes);
}
void showpet(Tree*petre)
{
	if(Treeisempty(petre))
		puts("no data");
	else
		Traverse(petre,print);
}
void numpet(Tree*petre)
{
	printf("have %d pets\n", Count(petre));
}
void findpet(Tree*petre)
{
	Pair look;
	Mess petmes;
	Kind*petkind;
	puts("enter the name:");
	s_gets(petmes.NAME,MAX);
	if(Check(petre,petmes))
	{
		look=Seek(petre,petmes);
		petkind=(look.child->PET).klist.head;
		while(petkind!=NULL)
		{
			printf("%s  ",petkind->anim);
			petkind=petkind->next;
		}
		putchar('\n');
	}
	else
		puts("no data");
}
void deletpet(Tree*petre)
{
	Mess petmes;
	puts("enter the name:");
	s_gets(petmes.NAME,MAX);
	puts("enter the kind:(you can enter all)");
	s_gets(petmes.KIND,MAX);
	Delet(petre,petmes);
}
