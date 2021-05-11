#include<stdio.h>
#include<string.h>

typedef int ElementType;
void swap(void *vp1, void *vp2, int size);

int main(){
    ElementType a = 5, b = 10;
    printf("a = %d, b = %d\n", a, b);

    swap(&a, &b, sizeof(ElementType));
    printf("a = %d, b = %d", a, b);
    
    return 0;
}

void swap(void *vp1, void *vp2, int size){
    char buffer[size];
    memcpy(buffer, vp1, size);
    memcpy(vp1, vp2, size);
    memcpy(vp2, buffer, size);
}