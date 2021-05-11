#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int countChar(FILE *f);
int countWord(FILE *f);

int main(int argc, char *argv[]){
    FILE *f;
    int cnt;
    char c;

    if(argc == 3){  //参数个数为3
        f = fopen(argv[2], "r"); //argv[2]表示第二个参数，也就是文件, "r"表示只读
        if(f == NULL){      //打开失败
            printf("Failed to open the file!!!");
            exit(1);
        }

        //根据argv[1]中保存的参数，确定要完成的功能
        if(!strcmp(argv[1], "-c")){   //统计字符个数
            cnt = countChar(f);
            printf("The number of charactor: %d\n", cnt);
        }else if(!strcmp(argv[1], "-w")){   //统计单词个数
            cnt = countWord(f);
            printf("The number of word: %d\n", cnt);
        }else{
            printf("输入的参数有误");
        }
    }
}

int countChar(FILE *f){
    int cnt = 0;   //用于记录字符个数
    char c; //用于保存当前字符

    while( (c = fgetc(f)) != EOF){   //while中的判断语句用于判断是否读到文件结尾
        cnt++;
    }

    rewind(f);    //将文件指针指向文件开头，便于下一次使用
    return cnt;
}

int countWord(FILE *f){
    int cnt = 0;   //用于统计单词个数
    char c;

    while(feof(f) == 0){    //判断是否到达文件末尾
        c = fgetc(f);    //用c来保存当前的字符
        if( c == ' ' || c == ','){
            cnt++;
        }
    }
    cnt++;   //加上末尾的单词

    rewind(f);    //将文件指针指向文件开头
    return cnt;
}