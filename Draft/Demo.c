#include<stdio.h>
#include<string.h>
#include<stdbool.h>


int main(){
    char a = 'a';
    char *ps = &a;
    char *p = ps;
    printf("%c", *p);
    return 0;
}
