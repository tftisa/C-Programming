#include<stdio.h>
#include<string.h>

void swap(void *vp1, void *vp2, int size);

int main(){
    char *husband = "abcdefghiX";
    char *wife = "ABCDEFGHI";
    swap(&husband, &wife, sizeof(char *));
    int i; 
 
    for(i = 0; *(husband + i) != '\0'; i++){
        printf("%c", *(husband + i));
    }
    
    printf("\n");

    for(i = 0; *(wife + i) != '\0'; i++){
        printf("%c", *(wife + i));
    }
}

void swap(void *vp1, void *vp2, int size){
    char buffer[8];
    memcpy(buffer, vp1, size);
    memcpy(vp1, vp2, size);
    memcpy(vp2, buffer, size);
}
