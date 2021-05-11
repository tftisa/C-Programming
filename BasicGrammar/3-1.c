#include<stdio.h>
#include<time.h>

/*
int binsearch_pro(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	
	while(low <= high && x != v[mid]){
		if(x != v[mid]){
			high = mid - 1;
		}else{
			low = mid + 1;
		}
		
		mid = (low + high) / 2;
	}
	
	if ( x == v[mid]){
		return mid;
	}else{
		return -1;
	}
}
*/
int binsearch_pro(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low+high) / 2;
    while ( low <= high && x != v[mid] ) {
        if ( x < v[mid] )
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low+high) / 2;
    }
    if ( x == v[mid] )
        return mid;
    else
        return -1;
}


int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	
	while( low <= high ){
		mid = (low + high) / 2;
		
		if( x < v[mid] ){
			high = mid - 1;
		}else if ( x > v[mid] ){
			low = mid + 1;
		}else{
			return mid;
		}
	}
	
	return -1;
}

int main()
{
	int v[] = {1, 2, 4, 6, 7, 11, 34, 45, 78};
	int n = 9;
	int x;
	int i = 100000000000;
	
	clock_t start, finish;
	double duration;
	
	start = clock();
	x =binsearch_pro(4, v, n);
	while(i--);
	finish = clock();
	i = 100000000000;
	
	duration = (double)(start - finish) / CLOCKS_PER_SEC;
	printf("binsearch_pro: %f seconds \n", duration); 
	printf("%d\n", x);
	
	start = clock();
	x = binsearch(4, v, n);
	while(i--);
	finish = clock();
	
	duration = (double)(start - finish) / CLOCKS_PER_SEC;
	printf("binsearch: %f seconds \n", duration); 
	printf("%d\n", x);
	
	return 0;
}
