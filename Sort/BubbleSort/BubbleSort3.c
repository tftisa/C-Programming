#include<stdio.h>

void BubbleSort(int *arr, int arraySize);
void swap(int *a, int *b);
void printArray(int *arr, int arraySize);

int main(){
    int arr[] = {1, 4, 2, 6, 213, 3, 5, 6};
    int arrySize = sizeof(arr) / sizeof(int); 

    BubbleSort(arr, 8);

    printArray(arr, 8);

    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *arr, int arraySize){
    for(int i = 0; i < arraySize; i++){
        printf("%d ", arr[i]);
    }
}

void BubbleSort(int *arr, int arraySize){
    int swapped = 1;
    int indexOfLastUnsortedElement = arraySize - 1;

    int swappedIndex = -1; //记录上次发生交换的位置

    while(swapped){
        swapped = 0;
        for(int i = 0; i < indexOfLastUnsortedElement; i++){
            if(arr[i] > arr[i + 1]){
                swap(arr + i, arr + i + 1);
                swapped = 1;
                swappedIndex = i;
            }
        }

        indexOfLastUnsortedElement = swappedIndex;
    }
}