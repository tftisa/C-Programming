#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int arraySize);
void countingSort(int *arr, int arraySize);

int main(){
    int arr[] = {1, 2, 1, 5, 3, 4, 9, 8, 5, 6, 3, 6, 7, 4, 3};
    int arraySize = sizeof(arr) / sizeof(int);
    countingSort(arr, arraySize);
    printArray(arr, arraySize);

    return 0;
}

void printArray(int *arr, int arraySize){
    for(int i = 0; i < arraySize; i++){
        printf("%d ", arr[i]);
    }
}

void countingSort(int *arr, int arraySize){
    //确定取值范围
    int max = arr[0], min = arr[0];
    for(int i = 1; i < arraySize; i++){
        if(max < arr[i])
            max = arr[i];
        
        if(min > arr[i])
            min = arr[i];
    }

    int range = max - min + 1;
    int *counting = (int *)malloc(sizeof(int) * range);
    for(int i = 0; i < range; i++){
        counting[i] = 0;
    }

    for(int i = 0; i < arraySize; i++){
        counting[arr[i] - min]++;
    }

    //确定最后一个数组元素在数组中的下标位置（数组下标从0开始，所以要减一）
    counting[0]--;
    for(int i = 1; i < range; i++){
        counting[i] += counting[i - 1];
    }

    //初始化result数组
    int *result = (int *)malloc(sizeof(int) * arraySize);
    for(int i = 0; i < arraySize; i++){
        result[i] = 0;
    }

    for(int i = arraySize - 1; i >= 0; i--){
        result[counting[arr[i] - min]--] = arr[i];
    }

    for(int i = 0; i < arraySize; i++){
        arr[i] = result[i];
    }
}