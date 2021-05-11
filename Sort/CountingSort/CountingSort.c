#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int arraySize);
void countingSort(int *arr, int arraySize);

void printArray(int *arr, int arraySize){
    for(int i = 0; i < arraySize; i++){
        printf("%d ", arr[i]);
    }
}

void countingSort(int *arr, int arraySize){
    if(arr == NULL || arraySize <= 1)   return;
    
    //找到数组arr的最大值和最小值，以确定范围区间
    int max = arr[0];
    int min = arr[0];
    for(int i = 1; i < arraySize; i++){
        if(arr[i] > max)    max = arr[i];
        else if(arr[i] < min)   min = arr[i];
    }
    int range = max - min + 1;

    int *counting;
    counting = (int *)malloc(sizeof(int) * range);

    //初始化counting数组
    for(int i = 0; i < range; i++){
        counting[i] = 0;
    }

    //将每个整数出现的次数统计到计数数组中对应下标的位置
    for(int i = 0; i < arraySize; i++){
        counting[arr[i] - min]++;
    }

    //记录前面比自己小的数字个数
    int preCounts = 0;
    for(int i = 0; i < range; i++){
        preCounts += counting[i];
        //将counting计算成当前数字在结果中的起始下标位置(即比自己小的数字的个数)
        counting[i] = preCounts - counting[i];
    }

    int *result;
    result = (int *)malloc(sizeof(int) * arraySize);

    //初始化result数组
    for(int i = 0; i < arraySize; i++){
        result[i] = 0;
    }

    for(int i = 0; i < arraySize; i++){
        int index = counting[arr[i] - min];
        result[index] = arr[i];
        counting[arr[i] - min]++;
    }

    //将result值赋给arr
    for(int i = 0 ;i < arraySize; i++){
        arr[i] = result[i];
    }
}

int main(){
    int arr[] = {1, 2, 1, 5, 3, 4, 9, 8, 5, 6, 3, 6, 7, 4, 3};
    int arraySize = sizeof(arr) / sizeof(int);
    countingSort(arr, arraySize);
    printArray(arr, arraySize);

    return 0;
}