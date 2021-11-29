#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int intCmp(void *elem1, void *elem2);
int strCmp(void *elem1, void *elem2);

int binsearch(void *elt, size_t size, void *arr, size_t length,
              int (*compare)(void *, void *));

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int index = binsearch(&arr[4], sizeof(int), arr, 9, intCmp);

    printf("%d", arr[index]);

    return 0;
}

int binsearch(void *elt, size_t size, void *arr, size_t length,
              int (*compare)(void *, void *)) {
    size_t i = length / 2;
    char *array = arr;

    while (i < length) {
        int comparison = compare(array + i * size, elt);

        if (comparison == 0) {
            return i;
        }

        if (comparison < 0) {
            i += (length - i + 1) / 2;
        } else {
            length = i;
            i /= 2;
        }
    }

    return -1;
}

int intCmp(void *elem1, void *elem2) {
    int *vp1 = elem1;
    int *vp2 = elem2;

    return *vp1 - *vp2;
}

int strCmp(void *elem1, void *elem2) {
    char *vp1 = *(char **)elem1;
    char *vp2 = *(char **)elem2;

    return strcmp(vp1, vp2);
}