#include<stdio.h>
#include<stdlib.h>

void radixSort(int *arr, int arraySize);
void printArray(int *arr, int arraySize);

int main(){
    int arr[] = {1, 2, 1, 5, 3, 4, 9, 8, 5, 6, 3, 6, 7, 4, 3};
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

void radixSort(int *arr, int arraySize){
    if(arr == NULL) return;

    int max = 0;
    for(int i = 0; i < arraySize; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }

    int maxDigitLength = 0;
    while(max){
        maxDigitLength++;
        max /= 10;
    }

    //利用计数排序对基数进行排序
    int countingLength = 10;   //基数取值范围区间的大小，在本程序中，基数取值为[0, 9]，一共10个元素
    int *counting = (int *)malloc(sizeof(int) * countingLength);
    int *result = (int *)malloc(sizeof(int) * arraySize);
    int dev = 1;

    //将counting和result数组元素设置为0
    for(int i = 0; i < countingLength; i++){
        counting[i] = 0;
    }

    for(int i = 0; i < arraySize; i++){
        result[i] = 0;
    }

    for(int i = 0; i < maxDigitLength; i++){
        for(int j = 0; j < arraySize; j++){
            //radix里保存基数
            int radix = arr[j] / dev % 10; //得到第j+1位
            counting[radix]++;
        }

        for(int j = 1; j < countingLength; j++){
            counting[j] += counting[j - 1];
        }

        //从数组结尾开始遍历是为了保证排序的稳定性
        for(int j = arraySize - 1; j >= 0; j--){
            int radix = arr[j] / dev % 10;
            result[--counting[radix]] = arr[j];
        }

        //将result中的数拷贝到arr中
        for(int i = 0; i < arraySize; i++){
            arr[i] = result[i];
        }

        //将counting中的数组设置为0
        for(int i = 0; i < countingLength; i++){
            counting[i] = 0;
        }

        dev *= 10;
    }
}