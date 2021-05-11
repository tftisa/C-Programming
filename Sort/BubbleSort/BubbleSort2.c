#include<stdio.h>
int* BubbleSort(int *arr, int size);
void swap(int *a, int *b);

int main(){
    int arr[] = {1, 3, 6, 7, 2, 1, 3, 67, 2};
    BubbleSort(arr, 9);

    for(int i = 0; i < 9; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void swap(int * a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* BubbleSort(int *arr, int size){
    int swapped = 1;
    for(int i = 0; i < size - 1; i++){
        if(!swapped)    break;
        swapped = 0;
        for(int j = 0; j < size - i -1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr + j, arr + j +1);
                swapped = 1;
            }
        }
    }

    return arr;
}