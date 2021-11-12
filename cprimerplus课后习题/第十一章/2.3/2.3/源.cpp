#include<stdio.h>
#include<ctype.h>
char * find(char *, int);
int main(void)
{
	char k[20],*kk;
	int n;
	printf("enter a limit num\n");
	scanf("%d", &n);
	getchar();
	printf("please enter\n");
	kk=find(k, n+1);
	printf("%s\n", kk);
	getchar();
	return 0;
}
char * find(char * st, int n)
{
	char * kz;
	int i=0,j=1;
	kz=fgets(st, n,stdin);
	if (kz)
	{
		while (isblank((unsigned char)*kz))
			kz++;
		while (kz[i] != '\n'&&kz[i] != '\40'&&kz[i] != '\0')
			i++;
		if (kz[i] == '\n')
			kz[i] = '\0';
		else if(kz[i]=='\0')
			while (getchar() != '\n')
				continue;
		else
		{
			kz[i] = '\0';
			while (kz[i + j] != '\0')
			{
				kz[i + j] = '\0';
				j++;
			}
		}
	}
	return kz;
}