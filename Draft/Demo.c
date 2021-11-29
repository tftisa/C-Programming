#include <stdio.h>
#include <string.h>

//utility function to implement generic binary search
int binarysearch(void *key, void *base, int len, int elemSize, int (*compare )(void *, void *));
int intCmp(void *elem1, void *elem2);
int strCmp(void *elem1, void *elem2);

int main() {
    int key = 1;
    int arr[10];

    for (int i = 0; i < 10; ++i) {
        arr[i] = i + 1;
    }

    int index = binarysearch(&key, arr, 10, sizeof(int), intCmp);

    printf("%d", arr[index]);

    return 0;
}

int binarysearch(void *key, void *base, int len, int elemSize, int (*compare)(void *, void *)) {
    int i = len / 2;
    char *p = base;

    while (i < len) {
        int res = compare(base + i * elemSize, key);

        if (res == 0) {
            return i;
        } else if (res > 0) {
            len = i;
            i /= 2;
        } else {
            i = (len - i ) / 2 + i;
        }
    }

    return  -1;
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
