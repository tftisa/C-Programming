#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define PRINT_INT(a) printf(#a " = %d\n", a)  
#define PRINT_FLOAT(a) printf(#a " = %f\n", a)
#define MK_ID(n) i##n
#define GENERIC_MAX(type) type type_##Max(type x, type y) \
        {                                                 \
            return x > y ? x : y;                         \
        }                                                 
#define TWO_PI (PI * 2)
#define PI 3.14                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
#define ECHO(x) (gets(x), puts(x))

int main(){ 
    PRINT_INT(2 / 1);

    int MK_ID(1), MK_ID(2);   //int i1, i2;                                                                                                                            
    i1 = 2;
    i2 = 3;

    PRINT_INT(i1);
    PRINT_INT(i2);
    PRINT_FLOAT(TWO_PI);
    char str[20];
    //ECHO(str);
    printf("Compiled on %s at %s\n", __DATE__, __TIME__);
    printf("%d %s", __LINE__, __FILE__);
    return 0;
}
                                                                                                                                        