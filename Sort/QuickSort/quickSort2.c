#include<stdio.h>

void swap(int *a, int *b);
void quickSort(int *arr, int start, int end);
int partition(int *arr, int start, int end);

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int *arr, int start, int end){
    if(start >= end)    return;
    int middle = partition(arr, start, end);

    quickSort(arr, start, middle - 1);
    quickSort(arr, middle + 1, end);
}

int partition(int *arr, int start, int end){
    int pivot = arr[start];
    int left = start + 1;
    int right = end;
    while(left < right){
        while(left < right && arr[left] <= pivot)   left++;
        
        while(left < right && arr[right] >= pivot)  right--;

        if(left < right){
            swap(arr + left, arr + right);
            left++;
            right--;
        }
    }

    if(right == left && pivot < arr[right]) right--;

    if(right != start)  swap(arr + start, arr + right);

    return right;
}

