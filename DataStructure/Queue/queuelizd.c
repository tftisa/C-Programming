#include <stdio.h>
#include "queuelizd.h"

int main(void) {
    Queue Q = CreateQueue();

    for (int i = 0; i < 10; ++i) {
        Enqueue(Q, i);
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d\n", Dequeue(Q));
    }

    DisposeQueue(Q);
    return 0;
}