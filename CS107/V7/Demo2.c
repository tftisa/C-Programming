#include <stdio.h>
#include <string.h>

void rotate(void *front, void *middle, void *end);

int main () {
    int arr[10];
    for (int i = 1; i < 11; ++i) {
        arr[i - 1] = i;
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d\n", arr[i]);
    }

    printf("After that.....\n");
    rotate(arr, &arr[1], (arr + 10));

    for (int i = 0; i < 10; ++i) {
        printf("%d\n", arr[i]);
    }
}

void rotate(void *front, void *middle, void *end) {
    int frontSize = middle - front;
    int backSize = end - middle;

    char buffer[frontSize];
    memcpy(buffer, front, frontSize);
    memcpy(front, middle, backSize);
    memcpy((char *)front + backSize, buffer, frontSize);
}