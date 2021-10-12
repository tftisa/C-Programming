#include <stdio.h>

int main () {
    int a = 715;
    char s[32];
    _itoa(a, s, 2);
    printf("%s\n", s);

    return 0;
}