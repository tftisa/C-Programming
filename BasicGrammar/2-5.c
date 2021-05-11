/*
编写函数any(s1, s2)，将字符串s2中的任一字符在字符串s1中第一次出现的位置作为返回结果。如果s1中不包含s2中的字符，则返回-1. 
*/ 

#include<stdio.h>
#include<stdbool.h>

int any(char s1[], char s2[]); 

int main(){
	char s1[20], s2[20];
	
	scanf("%s", s1);
	scanf("%s", s2);
	
	int seq = any(s1, s2);
	
	printf("%d", seq);
	return 0;
} 

int any(char s1[], char s2[])
{
	int i, j, seq;
	bool flag;
	
	flag = false;
	
	for(i = 0; s1[i] != '\0'; i++){
		for(j = 0; s2[j] != '\0'; j++){
			if(s1[i] == s2[j]){
				seq = i;
				flag = true;
				break;
			} 
		}
		if(flag){
			break;
		}
	}
}
