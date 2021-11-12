#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	double db[10];
	for(int i=0;i<10;i++)
		db[i]=(i+1)*2.0;
	FILE *fp;
	fp=fopen("13-1-4.txt","wb+");
	fwrite(db,sizeof(double),10,fp);
	fclose(fp);
	return 0;
}
