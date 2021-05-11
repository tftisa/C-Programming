#include<stdio.h>

void MyFun1(int x);
void MyFun2(int x);
void MyFun3(int x);
typedef void (*FunType)(int);
void CallMyFun(FunType fp, int x);

int main(int argc, char* argv[]){
    CallMyFun(MyFun1, 10);
    CallMyFun(MyFun2, 20);
    CallMyFun(MyFun3, 30);
}

void CallMyFun(FunType fp, int x){
    fp(x);
    (*fp)(x);
}

void MyFun1(int x){
    printf("Fun1: %d\n", x);
}

void MyFun2(int x){
    printf("Fun2: %d\n", x);
}

void MyFun3(int x){
    printf("Fun3: %d\n", x);
}