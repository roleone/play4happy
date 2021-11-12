#include<stdio.h>
#include<string.h>
#define CSIZE 4
struct name{
	char fname[10];
	char lname[10];
};
struct student{
	struct name NM;
	float grade[3];
	float per;
};
char*s_gets(char*,int);
void getdigit(struct student *);
void mathper(struct student *);
void structprintf(struct student );
int main(void)
{
	struct student all[CSIZE]={
		{{{"1"},{"2"}},{0.0,0.0,0.0},0.0},
		{{{"1"},{"2"}},{0.0,0.0,0.0},0.0},
		{{{"1"},{"2"}},{0.0,0.0,0.0},0.0},
		{{{"1"},{"2"}},{0.0,0.0,0.0},0.0}
	};
	for(int i=0;i<3;i++)
		getdigit(all+i);
	for(int i=0;i<3;i++)
	        mathper(all+i);
	for(int i=0;i<3;i++)
	        structprintf(all[i]);
	printf("all per is %.2f\n",(all[0].per+all[1].per+all[2].per)/3);
	return 0;
}
void getdigit(struct student *ptr)
{
	printf("enter first name:\n");
	s_gets(ptr->NM.fname,10);
	printf("enter last name:\n");
	s_gets(ptr->NM.lname,10);
	printf("enter grade for 3:\n");
	scanf("%f%f%f",ptr->grade,ptr->grade+1,ptr->grade+2);
	while(getchar()!='\n')
		continue;
}
void mathper(struct student*ptr)
{
	ptr->per=(ptr->grade[0]+ptr->grade[1]+ptr->grade[2])/3;
}
void structprintf(struct student ab)
{
	printf("%8s %8s grade1=%.2f,grade2=%.2f,grade3=%.2f,per=%.2f\n",ab.NM.fname,ab.NM.lname,ab.grade[0],ab.grade[1],ab.grade[2],ab.per);
}
char*s_gets(char*st,int n)
{
	char*kk;
	char*kz;
	kk=fgets(st,n,stdin);
	if(kk)
	{
		if(kz=strchr(st,'\n'))
			*kz='\0';
		else
			while(getchar()!='\n')
				continue;
	}
	return kk;
}
