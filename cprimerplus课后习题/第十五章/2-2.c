#include<stdio.h>
#include<stdlib.h>
struct num{
	unsigned int a:1;
	unsigned int b:1;
	unsigned int c:1;
	unsigned int d:1;
	unsigned int e:1;
	unsigned int f:1;
	unsigned int g:1;
	unsigned int h:1;
};
union choose{
	struct num nn;
	unsigned int nnn;
};
int main(int argc,char*argv[])
{
	if(argc!=3)
	{
		fprintf(stderr,"enter wrong\n");
		exit(EXIT_FAILURE);
	}
	union choose num1={{0,0,0,0,0,0,0,0}};
	union choose num2={{0,0,0,0,0,0,0,0}};
	union choose num3={{0,0,0,0,0,0,0,0}};
	for(int i=0;i<8;i++)
	{
		if(argv[1][i]!='0'&&argv[1][i]!='1')
		{
			fprintf(stderr,"enter wrong\n");
			exit(EXIT_FAILURE);
		}
		switch(i)
		{
			case 0:num1.nn.h=argv[1][i]-48;
			       break;
			case 1:num1.nn.g=argv[1][i]-48;
			       break;
			case 2:num1.nn.f=argv[1][i]-48;
			       break;
			case 3:num1.nn.e=argv[1][i]-48;
			       break;
			case 4:num1.nn.d=argv[1][i]-48;
			       break;
			case 5:num1.nn.c=argv[1][i]-48;
			       break;
			case 6:num1.nn.b=argv[1][i]-48;
			       break;
			case 7:num1.nn.a=argv[1][i]-48;
			       break;
		}
		if(argv[2][i]!='0'&&argv[2][i]!='1')
		{
			fprintf(stderr,"enter wrong\n");
			exit(EXIT_FAILURE);
		}
		switch(i)
		{
			case 0:num2.nn.h=argv[2][i]-48;
			       break;
			case 1:num2.nn.g=argv[2][i]-48;
			       break;
			case 2:num2.nn.f=argv[2][i]-48;
			       break;
			case 3:num2.nn.e=argv[2][i]-48;
			       break;
			case 4:num2.nn.d=argv[2][i]-48;
			       break;
			case 5:num2.nn.c=argv[2][i]-48;
			       break;
			case 6:num2.nn.b=argv[2][i]-48;
			       break;
			case 7:num2.nn.a=argv[2][i]-48;
			       break;
		}
	}
	num3.nnn=~num1.nnn;
	printf("%d%d%d%d%d%d%d%d\n",num3.nn.h,num3.nn.g,num3.nn.f,num3.nn.e,num3.nn.d,num3.nn.c,num3.nn.b,num3.nn.a);
	num3.nnn=~num2.nnn;
	printf("%d%d%d%d%d%d%d%d\n",num3.nn.h,num3.nn.g,num3.nn.f,num3.nn.e,num3.nn.d,num3.nn.c,num3.nn.b,num3.nn.a);
	num3.nnn=num1.nnn&num2.nnn;
	printf("%d%d%d%d%d%d%d%d\n",num3.nn.h,num3.nn.g,num3.nn.f,num3.nn.e,num3.nn.d,num3.nn.c,num3.nn.b,num3.nn.a);
	num3.nnn=num1.nnn|num2.nnn;
	printf("%d%d%d%d%d%d%d%d\n",num3.nn.h,num3.nn.g,num3.nn.f,num3.nn.e,num3.nn.d,num3.nn.c,num3.nn.b,num3.nn.a);
	num3.nnn=num1.nnn^num2.nnn;
	printf("%d%d%d%d%d%d%d%d\n",num3.nn.h,num3.nn.g,num3.nn.f,num3.nn.e,num3.nn.d,num3.nn.c,num3.nn.b,num3.nn.a);
	return 0;
}
