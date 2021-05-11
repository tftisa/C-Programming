void BubbleSort(int A[]){
	int len = sizeof(A) / sizeof(int);

	for(int i = 0; i < len; i++){
		for(int j = 0; j < len - 1 - i; j++){
			if(A[j] > A[j+1]){
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}