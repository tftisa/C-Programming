#include <stdio.h>
#include "queuearzd.h"

int main(void) {
    Queue Q = CreateQueue(11);

    for (int i = 0; i < 10; ++i) {
        AddQ(Q, i);
    }

    for (int i = 0; i < 10; ++i) {
        int data = DeleteQ(Q);
        printf("%d\n", data);
    }

    DisposeQueue(Q);
    return 0;
}