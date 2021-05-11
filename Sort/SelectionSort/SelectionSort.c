void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[]){
    int minIndex;
    int len = sizeof(arr) / sizeof(int);
    for(int i = 0; i < len; i++){
        minIndex = i;
        for(int j = i+1; j < len; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }

        if(minIndex == i)   continue;
        swap(arr + i, arr + minIndex);
    }
}