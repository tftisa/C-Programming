#include<stdio.h>

void MyFun(int x);
void (*FunP) (int );

int main(int argc, char* argv[]){
    //1
    MyFun(10);
          
    //2
    FunP = &MyFun;
    (*FunP) (20);

    //3
    FunP = MyFun;
    FunP(30);

    //4
    FunP = MyFun;
    (*FunP)(40);

    //5
    (*MyFun)(50);

    return 0;
}

void MyFun(int x){
    printf("%d\n", x);
}