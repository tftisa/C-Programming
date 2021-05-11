#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void mergeSort(int *arr, int arraySize);
void mergeSort2(int *arr, int start, int end, int *result);
void merge(int *arr, int start, int end, int *result);

void mergeSort(int *arr, int arraySize){
    if(!arraySize)  return;

    int *result = (int *)malloc(sizeof(int) * arraySize);
    for(int i = 0; i < arraySize; i++)
        result[i] = 0;

    mergeSort2(arr, 0, arraySize - 1, result);
}

void mergeSort2(int *arr, int start, int end, int *result){
    if(start == end)    return;
    int middle = (end - start) / 2 + start;
    mergeSort2(arr, start, middle, result);
    mergeSort2(arr, middle + 1, end, result);
    merge(arr, start, end, result);
}

void merge(int *arr, int start, int end, int *result){
    int end1 = (end - start) / 2 + start;
    int start2 = end1 + 1;
    
    int index1 = start;
    int index2 = start2;
    
    while(index1 <= end1 && index2 <= end){
        if(arr[index1] < arr[index2]){
            result[index1 + index2 - start2] = arr[index1++];
        }else{
            result[index1 + index2 - start2] = arr[index2++];
        }
    }

    while(index1 <= end1){
        result[index1 + index2 - start2] = arr[index1++];
    }

    while(index2 <= end){
        result[index1 + index2 - start2] = arr[index2++];
    }

    while(start <= end)  arr[start] = result[start++];
}

int main(){
    int arr[] = {0,1,1,1,1,1,1,1};
    mergeSort(arr, 8);

    for(int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}