#include<stdio.h>
#include<string.h>
#include"stack-generic.h"

int main(){
    const char *friends[] = {"Al", "Bob", "Carl"};
    stack stringStack;
    StackNew(&stringStack, sizeof(char *));

    for(int i = 0; i < 3; i++){
        char *copy = strdup(friends[i]);
        StackPush(&stringStack, &copy);
    }

    char *name;
    for(int i = 0; i < 3; i++){
        StackPop(&stringStack, &name);
        printf("%s\n", name);
        free(name);
    }

    StackDispose(&stringStack);

    return 0;
}