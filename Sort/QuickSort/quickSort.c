#include<stdio.h>

void swap(int *a, int *b);
void quickSort(int *arr, int start, int end);
int partition(int *arr, int start, int end);

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int *arr, int start, int end){
    // 取第一个数位基数
    int pivot = arr[start];
    int left = start + 1;
    int right = end;
    while(left < right){
        // 找到第一个大于基数的位置
        while(left < right && arr[left] <= pivot)   left++;
        //经过 while 循环，如果 left 不等于 right 
        //那么left所指向的数小于 pivot 交换left和right指向的数
        if(left != right){
            swap(arr + left, arr + right);
            right--;
        }
    }

    // 如果 left 和 right 相等，单独比较 arr[right] 和 pivot
    if(left == right && arr[right] > pivot) right--;
    // 将基数和中间数交换
    if(right != start)  swap(arr + start, arr + right);
    // 返回中间值的下标
    return right;
}

void quickSort(int *arr, int start, int end){
    // 如果区域内的数字小于2个，退出递归
    if(start >= end)    return;
    // 将数组分区，并获得中间值的下标
    int middle = partition(arr, start, end);
    // 对左边区域快速排序
    quickSort(arr, start, middle - 1);
    // 对右边区域快速排序
    quickSort(arr, middle + 1, end);
}

int main()
{
    int arr[] = {1, 9, 2, 5, 20, 35};
    int arraySize = sizeof(arr) / sizeof(int);
    int start = 0, end = arraySize - 1;

    quickSort(arr, start, end);

    for(int i = 0; i < arraySize; i++)
        printf("%d ", arr[i]);
    
    return 0;
}