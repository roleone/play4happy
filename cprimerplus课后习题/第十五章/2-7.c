#include<stdio.h>
unsigned long change(unsigned long,int,int,int);
int main(void)
{
	char ch;
	unsigned long word=0;
	char *ALIG[3]=
	{
		"left",
		"mid",
		"right"
	};
	char *choose[2]=
	{
		"off",
		"on"
	};
	printf("ID  SIZE ALIGNMENT B  I  U  :\n");
	printf("%3d %3d  %5s    %3s %3s %3s\n",word&255,(word&(127<<8))>>8,ALIG[(word&(3<<15))>>15],choose[(word&(1<<17))>>17],choose[(word&(1<<18))>>18],choose[(word&(1<<19))>>19]);
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
			case 'a':word=change(word,1,8,8);
				break;
			case 'b':word=change(word,2,15,7);
				break;
			case 'c':word=change(word,3,17,2);
				break;
			case 'd':word=change(word,4,18,1);
				break;
			case 'e':word=change(word,5,19,1);
				break;
			case 'f':word=change(word,6,20,1);
				break;
			default:
				break;
		}
		printf("ID  SIZE ALIGNMENT B  I  U  :\n");
		printf("%3d %3d  %5s    %3s %3s %3s\n",word&255,(word&(127<<8))>>8,ALIG[(word&(3<<15))>>15],choose[(word&(1<<17))>>17],choose[(word&(1<<18))>>18],choose[(word&(1<<19))>>19]);
	}
	return 0;
}
unsigned long change(unsigned long plr,int n1,int n2,int n3)
{
	int num;
	struct rio{
		unsigned long k:1;
		unsigned long :0;
	};
	union haoba{
		struct rio kk;
		unsigned long u;
	};
	union haoba uu;
	uu.u=1;
	switch(n1)
	{
		case 1:
		printf("enter the num(0-255)\n");
		while(scanf("%d",&num)!=1||num<0||num>255)
		{
			while(getchar()!='\n')
				continue;
			printf("enter a number 0-255\n");
		}
		while(getchar()!='\n')
			continue;
		break;
		case 2:
		printf("enter the num(0-127)\n");
		while(scanf("%d",&num)!=1||num<0||num>127)
		{
			while(getchar()!='\n')
				continue;
			printf("enter a number 0-127\n");
		}
		while(getchar()!='\n')
			continue;
		break;
		case 3:
		printf("enter the num(0-2)\n");
		while(scanf("%d",&num)!=1||num<0||num>2)
		{
			while(getchar()!='\n')
				continue;
			printf("enter a number 0-2\n");
		}
		while(getchar()!='\n')
			continue;
		break;
	}
	if(n1<4)
	{
		for(int i=0;i<n2-1;i++)
		{
			uu.u<<=1;
			if(n3-->1)
				uu.kk.k=1;
		}
		if(n1==2)
			num<<=8;
		if(n1==3)
			num<<=15;
		uu.u=~uu.u;
		plr&=uu.u;
		plr|=num;
	}
	else
	{
		for(int i=0;i<n2-1;i++)
			uu.u<<=1;
		plr^=uu.u;
	}
	return plr;
}
