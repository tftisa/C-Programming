#include<stdio.h>
#include<string.h>

void *lsearch(void *key, void *base, int n, int elemSize);

int main(){
    char *key = "h";
    char *s = "abcdefghijk";
    char *elemAddr = lsearch(key, s, 11, 1);x
    printf("%c", *elemAddr);
    return 0;
}

void *lsearch(void *key, void *base, int n, int elemSize){
    for(int i = 0; i < n; i++){
        void *elemAddr = (char *)base + i * elemSize;
        
        if(memcmp(key, elemAddr, elemSize) == 0)
            return elemAddr;`
    }

    return NULL;
}