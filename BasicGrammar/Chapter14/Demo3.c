#include<stdio.h>

#define DEBUG 1

int main(){

    // if identifier DEBUG has been defined, the defined() will return true
    #if defined(DEBUG)
    printf("DEBUG is defined");
    #endif
    
    return 0;
}