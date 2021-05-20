#include<stdio.h>

#define DEBUG 1

int main(){         
    #if DEBUG
    printf("%d\n", 23);
    #endif

    return 0;
}