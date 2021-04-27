#include<stdio.h>
void swap(int *a, int *b);
void selectionSort(int *arr, int arraySize);
void printArray(int *arr, int arraySize);

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *arr, int arraySize){
    for(int i = 0; i < arraySize; i++)
        printf("%d ", *(arr + i));
}

void selectionSort(int *arr, int arraySize){
    int minIndex, maxIndex;
    for(int i = 0; i < arraySize / 2; i++){
        minIndex = maxIndex = i;
        for(int j = i + 1; j < arraySize - i; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }

            if(arr[j] >arr[maxIndex]){
                maxIndex = j;
            }
        }

        //如果最大值和最小值的下标相同(值都等于i),说明已经排序完成了
        if(minIndex == maxIndex) break;

        //交换最小值
        swap(arr + i, arr + minIndex);
        
        //如果i就是最大值下标，那么经过上面的交换，最大值的下标变成了minIndex
        if(maxIndex == i)
            maxIndex = minIndex;
        
        swap(arr + arraySize - i - 1, arr + maxIndex);
    }
}

int main(){
    int arr[] = {2, 1, -5, 53, 2, 1};
    int arraySize = sizeof(arr) / sizeof(int);

    selectionSort(arr, arraySize);
    printArray(arr,arraySize);

    return 0;
}


//Java代码
/*
class Solution {
    public int[] sortArray(int[] nums) {
        int minIndex, maxIndex;
        int numsSize = nums.length;

        for(int i = 0; i < numsSize /2; i++){
            minIndex = i;
            maxIndex = i;
            for(int j = i + 1; j < numsSize - i; j++){
                if(nums[j] < nums[minIndex])
                    minIndex =  j;
                
                if(nums[j] > nums[maxIndex])
                    maxIndex = j;
            }

            if(minIndex == maxIndex)    break;
            
            //交换最小值
            int temp = nums[minIndex];
            nums[minIndex] = nums[i];
            nums[i] = temp;

            //如果最大值的下标为i，那么经过上述过程，最大值下标变成了minIndex
            if(maxIndex == i)   maxIndex = minIndex;

            //交换最大值
            temp = nums[maxIndex];
            nums[maxIndex] = nums[numsSize - i - 1];
            nums[numsSize - i - 1] = temp;
        }

        return nums;
    }
}
*/