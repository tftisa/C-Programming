#include<stdio.h>

void printArray(int *arr, int arraySize){
    for(int i = 0; i < arraySize; i++)
        printf("%d ", *(arr + i));
}

void insertSort(int arr[], int arraySize){
    for(int i = 1; i < arraySize; i++){
        int currentNumber = arr[i];
        int j = i - 1;
        while(j >= 0 && currentNumber < arr[j]){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = currentNumber;
    }
}

int main(){
    int arr[] = {1, 2, 7, 6, -2, 10};
    int arraySize = sizeof(arr) / sizeof(int);
    insertSort(arr, arraySize);

    printArray(arr,arraySize);
    return 0;
}

