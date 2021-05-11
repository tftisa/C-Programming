#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void radixSort(int *arr, int arraySize);
void printArray(int *arr, int arraySize);

int main(){
    int arr[] = {1, 2, 1, 5, -3, 4, -9, 8, 5, 6, 3, 6, 7, 4, 3};
    int arraySize = sizeof(arr) / sizeof(int);
    radixSort(arr, arraySize);
    printArray(arr, arraySize);

    return 0;
}

void printArray(int *arr, int arraySize){
    for(int i = 0; i < arraySize; i++){
        printf("%d ", arr[i]);
    }
}

//对于包含负数的数组，将每个基数加上9变成正数，而此时正数也加上9，正数始终必负数大
void radixSort(int *arr, int arraySize){
    if(arr == NULL) return;
    int max = 0;

    for(int i = 0; i < arraySize; i++){
        if(max < abs(arr[i]))
            max = abs(arr[i]);
    }

    int maxDigitLength = 0;
    while(max != 0){
        maxDigitLength++;
        max /= 10;
    }

    //取值区间为[-9, 9], 将每个数加上9之后变成了[0, 18]，区间总共19个元素
    int countingLength = 19;
    int *counting = (int *)malloc(sizeof(int) * countingLength);
    int *result = (int *)malloc(sizeof(int) * arraySize);
    int dev = 1;

    for(int i = 0; i < countingLength; i++){
        counting[i] = 0;
    }
    
    for(int i = 0; i < arraySize; i++){
        result[i] = 0;
    }

    for(int i = 0 ; i < maxDigitLength; i++){
        for(int j = 0; j < arraySize; j++){
            int radix = arr[j] / dev % 10 + 9;
            counting[radix]++;
        }

        for(int j = 1; j < countingLength; j++){
            counting[j] += counting[j - 1];
        }

        for(int j = arraySize - 1; j >= 0; j--){
            int radix = arr[j] / dev % 10 + 9;
            result[--counting[radix]] = arr[j];
        }

        for(int j = 0; j < arraySize; j++){
            arr[j] = result[j];
        }

        for(int j = 0; j < countingLength; j++){
            counting[j] = 0;
        }

        dev *= 10;
    }
}
