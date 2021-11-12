#include<stdio.h>
struct mess{
	unsigned int ID:8;
	unsigned int size:7;
	unsigned int alig:2;
	unsigned int add:1;
	unsigned int ltal:1;
	unsigned int under:1;
};
void change1(struct mess*);
void change2(struct mess*);
void change3(struct mess*);
void change4(struct mess*);
void change5(struct mess*);
void change6(struct mess*);
int main(void)
{
	char ch;
	struct mess word={0,0,0,0,0};
	struct mess* ptr=&word;
	char *ALIG[3]=
	{
		"left",
		"mid",
		"right"
	};
	char *choose[2]=
	{
		"off",
		"on",
	};
	printf("ID  SIZE ALIGNMENT B  I  U  :\n");
	printf("%3d %3d  %5s    %3s %3s %3s\n",word.ID,word.size,ALIG[word.alig],choose[word.add],choose[word.ltal],choose[word.under]);
	while(1)
	{
		printf("a) change font  b) change size    c) change alignment\n");
		printf("d) toggle bold  e) toggle italic  f) toggle underline\n");
		printf("q) quit\n");
		if((ch=getchar())<'a'||(ch>'f'&&ch!='q'))
		{
			printf("enter a-f q to quit:\n");
			continue;
		}
		else if(ch=='q')
			break;
		while(getchar()!='\n')
			continue;
		switch(ch)
		{
			case 'a':change1(ptr);
				break;
			case 'b':change2(ptr);
				break;
			case 'c':change3(ptr);
				break;
			case 'd':change4(ptr);
				break;
			case 'e':change5(ptr);
				break;
			case 'f':change6(ptr);
				break;
			default:
				break;
		}
		printf("ID  SIZE ALIGNMENT B  I  U  :\n");
		printf("%3d %3d  %5s    %3s %3s %3s\n",word.ID,word.size,ALIG[word.alig],choose[word.add],choose[word.ltal],choose[word.under]);
	}
	return 0;
}
void change1(struct mess* plr)
{
	int num;
	printf("enter the num(0-255)\n");
	while(scanf("%d",&num)!=1||num<0||num>255)
	{
		while(getchar()!='\n')
			continue;
		printf("enter a number 0-255\n");
	}
	while(getchar()!='\n')
		continue;
	plr->ID=num;
}
void change2(struct mess* plr)
{
	int num;
	printf("enter the num(0-127)\n");
	while(scanf("%d",&num)!=1||num<0||num>127)
	{
		while(getchar()!='\n')
			continue;
		printf("enter a number 0-127\n");
	}
	while(getchar()!='\n')
		continue;
	plr->size=num;
}
void change3(struct mess* plr)
{
	int num;
	printf("enter the num(0-2)\n");
	while(scanf("%d",&num)!=1||num<0||num>2)
	{
		while(getchar()!='\n')
			continue;
		printf("enter a number 0-2\n");
	}
	while(getchar()!='\n')
		continue;
	plr->alig=num;
}
void change4(struct mess* plr)
{
	 if(plr->add==0)
		plr->add=1;
	 else
		 plr->add=0;
}
void change5(struct mess* plr)
{
	 if(plr->ltal==0)
		plr->ltal=1;
	 else
		 plr->ltal=0;
}
void change6(struct mess* plr)
{
	 if(plr->under==0)
		plr->under=1;
	 else
		 plr->under=0;
}
