#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(void)
{
	FILE*fp;
	char *name;
	char tmp[50];
	printf("enter a filename\n");
	scanf("%s",name);
	while(getchar()!='\n')
		continue;
	if((fp=fopen(name,"r"))==NULL)
	{
		fprintf(stderr,"open wrong");
		exit(EXIT_FAILURE);
	}
	fscanf(fp,"%s",tmp);
	fclose(fp);
	for(int i=0;tmp[i]!='\0';i++)
		if(islower(tmp[i]))
			tmp[i]=toupper(tmp[i]);
	if((fp=fopen(name,"w"))==NULL)
	{
		fprintf(stderr,"open wrong");
		exit(EXIT_FAILURE);
	}
	fprintf(fp,"%s",tmp);
	fclose(fp);
	return 0;
}
