#include<stdio.h>
#include<math.h>
struct jiaodu{
	float mo;
	float du;
};
struct jiaodu jisuan(struct jiaodu);
int main(void)
{
	char ch;
	struct jiaodu A={0,0};
	while(1)
	{
		printf("enter a mo and jiaodu:\n");
		while(scanf("%f%f",&A.mo,&A.du)!=2||A.mo<=0)
		{
			if((ch=getchar())=='q')
				break;
			else if(ch!='\n')
				while((ch=getchar())!='\n')
					continue;
			printf("enter wrong:\n");
		}
		if(ch=='q')
			break;
		A.du*=4*atan(1)/180;
		A=jisuan(A);
		printf("x is %f,y is %f\n",A.mo,A.du);
	}
	return 0;
}
struct jiaodu jisuan(struct jiaodu KK)
{
	struct jiaodu AA;
	AA.mo=KK.mo*cos(KK.du);
	AA.du=KK.mo*sin(KK.du);
	return AA;
}
