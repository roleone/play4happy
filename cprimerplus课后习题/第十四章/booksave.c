#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
char *s_gets(char *,int);
struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
int main(void)
{
	struct book library[MAXBKS];
	int count=0;
	int index,filecount;
	FILE *pbooks;
	int size=sizeof(struct book);
	if((pbooks=fopen("book.dat","a+b"))==NULL)
	{
		fprintf(stderr,"open wrong\n");
		exit(1);
	}
	rewind(pbooks);
	while(count<MAXBKS&&fread(&library[count],size,1,pbooks)==1)
	{
		if(count==0)
			puts("Current content of book.dat:");
		printf("%s by %s:$%.2f\n",library[count].title,library[count].author,library[count].value);
		count++;
	}
	filecount=count;
	if(count==MAXBKS)
	{
		fputs("The book.dat file is full",stderr);
		exit(2);
	}
	puts("please add a new book title.");
	puts("Press [enter] at the start of a line to stop");
	while(count<MAXBKS&&s_gets(library[count].title,MAXTITL)!=NULL&&library[count].title[0]!='\0')
	{
		puts("now enter the author");
		s_gets(library[count].author,MAXAUTL);
		puts("now enter the value");
		scanf("%f",&library[count++].value);
		while(getchar()!='\n')
			continue;
		if(count<MAXBKS)
			puts("the next title");
	}
	if(count>0)
	{
		puts("here is the list of your books:");
		for(index=0;index<count;index++)
			printf("%s by %s:$%.2f\n",library[index].title,library[index].author,library[index].value);
		fwrite(&library[filecount],size,count-filecount,pbooks);
	}
	else
		puts("no book");
	puts("bye");
	fclose(pbooks);
	return 0;
}
char* s_gets(char*st,int n)
{
	int i;
	char * kk;
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
