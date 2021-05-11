#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArray(int *arr, int arraySize);
//对[1,9]范围内的数进行排序
void countingSort9(int *arr, int arraySize);

void printArray(int *arr, int arraySize){
    for(int i = 0; i < arraySize; i++){
        printf("%d ", arr[i]);
    }
}

void countingSort9(int *arr, int arraySize){
    int *counting;
    counting = (int *)malloc(sizeof(int) * 9);

    for(int i = 0; i < 9; i++){
        counting[i] = 0;
    }

    for(int i = 0; i < arraySize; i++){
        counting[arr[i] - 1]++;
    }

    int index = 0;
    for(int i = 0; i < 9; i++){
        while(counting[i]){
            arr[index++] = i + 1;
            counting[i]--;
        }
    }
}

int main(){
    int arr[] = {1, 2, 1, 5, 3, 4, 9, 8, 5, 6, 3, 6, 7, 4, 3};
    int arraySize = sizeof(arr) / sizeof(int);
    countingSort9(arr, arraySize);
    printArray(arr, arraySize);

    return 0;
}