#include<stdio.h>
int main(void)
{
	int zippo[4][2] = { {1,2} ,{3,4}, {5,6}, {7,8} };
	printf("zippo[0]地址为%p,zippo[0]的值为%p\n", &zippo[0], zippo[0]);
	printf("zippo[0][0]的地址为%p\n", &zippo[0][0]);
	int a[4];
	printf("%p %p %p", a,&a[0],&a);
	getchar();
	getchar();
	return 0;
}