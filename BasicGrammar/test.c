#include<stdio.h>

int main()
{
	if(2147483647U < -2147483647 -1){
		printf("true\n");
	}else{
		printf("false\n");
	}
	
	printf("%u", -2147483647 -1);
	return 0;
}
