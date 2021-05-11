#include<stdio.h>
#include<string.h>

struct student{
    char *name;
    char suid[8];
    int numUnits;
};

int main(){
    struct student pupils[5];

    pupils[0].numUnits = 2;
    pupils[2].name = strdup("Adam");
    pupils[3].name = pupils[0].suid + 6;
    strcpy(pupils[3].name, "123456");
    

    int a = 0b00110110001101010011010000110011;
    printf("%d\n", a);
    printf("%x\n", '3');
    printf("%d", pupils[0].numUnits);


    return 0;
}