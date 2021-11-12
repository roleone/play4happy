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
	struct book library;
	int count=0;
	int index,filecount;
	FILE *pbooks;
	char ch;
	int size=sizeof(struct book);
	if((pbooks=fopen("2-7.txt","r+b"))==NULL)
	{
		fprintf(stderr,"open wrong\n");
		exit(1);
	}
	rewind(pbooks);
	while(count<MAXBKS&&fread(&library,size,1,pbooks)==1)
	{
		if(count==0)
			puts("Current content of book.dat:");
		printf("%s by %s:$%.2f\n",library.title,library.author,library.value);
		printf("change or delet or none:\n");
		while(ch=getchar())
		{
	        	while(getchar()!='\n')
		        	continue;
			if(ch!='c'&&ch!='d'&&ch!='n')
				continue;
			switch(ch)
			{
				case 'c':fseek(pbooks,ftell(pbooks)-(long)size,SEEK_SET);
					 printf("enter the title:\n");
					 s_gets(library.title,MAXTITL);
		                        printf("enter the author:\n");
		                        s_gets(library.author,MAXAUTL);
                                        printf("enter the value:\n");
                                        scanf("%f",&(library.value));
                                        while(getchar()!='\n')
                                            continue;
                                        fwrite(&library,size,1,pbooks);
					 break;
				case 'd':fseek(pbooks,ftell(pbooks)-(long)size,SEEK_SET);
					 struct book library={"\0","\0",0};
					 fwrite(&library,size,1,pbooks);
					break;
				case 'n':
					break;
				default:
					break;
			}
	           	count++;
			break;
		}
	}
	filecount=count;
	if(count==MAXBKS)
	{
		fputs("The book.dat file is full",stderr);
		exit(2);
	}
	puts("please add a new book title.");
	puts("Press [enter] at the start of a line to stop");
	while(count<MAXBKS&&s_gets(library.title,MAXTITL)!=NULL&&library.title[0]!='\0')
	{
		puts("now enter the author");
		s_gets(library.author,MAXAUTL);
		puts("now enter the value");
		scanf("%f",&library.value);
		count++;
		while(getchar()!='\n')
			continue;
		fwrite(&library,size,1,pbooks);
		if(count<MAXBKS)
			puts("the next title");
	}
	if(count>0)
	{
		rewind(pbooks);
		puts("here is the list of your books:");
		for(index=0;index<count;index++)
		{
			fread(&library,size,1,pbooks);
			printf("%s by %s:$%.2f\n",library.title,library.author,library.value);
		}
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
