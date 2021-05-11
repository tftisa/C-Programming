#include<stdio.h>
#include"stack-generic.h"

int main(){
    int val;
    stack intStack;
    
    StackNew(&intStack, sizeof(int));
    for(val = 0; val < 6; val++){
        StackPush(&intStack, &val);
    }

    while(!StackEmpty(&intStack)){
        StackPop(&intStack, &val);
        printf("This just popped: %d\n", val);
    }

    StackDispose(&intStack);
}
