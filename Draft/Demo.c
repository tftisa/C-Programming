#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n = 20;
	int *restrict p = &n;
	int *restrict p2 = &n;
	*p2 = 30;
	printf("%d", *p);
	return 0;
}