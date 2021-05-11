#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int arraySize);
void swap(int *a, int *b);
void mergeSort(int *arr, int arraySize);
void mergeSort2(int *arr, int start, int end, int *result);
void merge(int *arr, int start, int end, int *result);

int main(){
    int arr[] = {1, 2, 1, 5, 3, 4, 9, 8, 5, 6, 3, 6, 7, 4, 3};
    int arraySize = sizeof(arr) / sizeof(int);
    mergeSort(arr, arraySize);
    printArray(arr, arraySize);

    return 0;
}

void printArray(int *arr, int arraySize){
    for(int i = 0; i < arraySize; i++){
        printf("%d ", arr[i]);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void mergeSort(int *arr, int arraySize){
    if (arraySize == 0) return;

    int result[arraySize];
    for(int i = 0; i < arraySize; i++){
        result[i] = 0;
    }

    mergeSort2(arr, 0, arraySize - 1, result);

}

void mergeSort2(int *arr, int start, int end, int *result){
    if (start == end) return;
    int middle = (start + end) / 2;
    // 拆分左边区域，并将归并排序的结果保存到 result 的 [start, middle] 区间
    mergeSort2(arr, start, middle, result);
    // 拆分右边区域，并将归并排序的结果保存到 result 的 [middle + 1, end] 区间
    mergeSort2(arr, middle + 1, end, result);
    // 合并左右区域到 result 的 [start, end] 区间
    merge(arr, start, end, result);

}

void merge(int *arr, int start, int end, int *result){
    int end1 = (start + end) / 2;
    int start2 = end1 + 1;
    // 用来遍历数组的指针
    int index1 = start;
    int index2 = start2;
    while (index1 <= end1 && index2 <= end) {
        if (arr[index1] <= arr[index2]) {
            result[index1 + index2 - start2] = arr[index1++];
        } else {
            result[index1 + index2 - start2] = arr[index2++];
        }
    }
    // 将剩余数字补到结果数组之后
    while (index1 <= end1) {
        result[index1 + index2 - start2] = arr[index1++];
    }
    while (index2 <= end) {
        result[index1 + index2 - start2] = arr[index2++];
    }
    // 将 result 操作区间的数字拷贝到 arr 数组中，以便下次比较
    while (start <= end) {
        arr[start] = result[start++];
    }

}