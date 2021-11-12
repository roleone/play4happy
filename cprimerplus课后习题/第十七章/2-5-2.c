#include<stdio.h>
#include"2-5.h"
void show(char);
int main(void)
{
	char ck;
	List llist;
	Initialize(&llist);
	printf("enter a char\n");
	while((ck=getchar())!='#'&&Count(&llist)<=MAX)
		Add(&llist,ck);
	Traverse(&llist,1,show);
	putchar('\n');
	Traverse(&llist,0,show);
	putchar('\n');
	Empty(&llist);
	Traverse(&llist,1,show);
	return 0;
}
void show(char ch)
{
	printf("%c",ch);
}
