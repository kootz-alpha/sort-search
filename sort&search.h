#include <iostream>
using namespace std;

void merge(int arr[], int lb, int mid, int ub) {
	
	int size = ub - lb + 1;
    int newArr[size];
    
    int pointer1 = lb; //for subArray1
    int pointer2 = mid + 1; //for subArray2
    int pointer3 = 0; //for newArr
    
    while (pointer1 <= mid && pointer2 <= ub) {
    	
    	if (arr[pointer1] < arr[pointer2]) {
    		newArr[pointer3] = arr[pointer1];
    		pointer1++;
		}
		else {
			newArr[pointer3] = arr[pointer2];
			pointer2++;
		}
		
		pointer3++;
	}
	
	if (pointer1 > mid) {
		for (pointer2 = pointer2; pointer2 <= ub; pointer2++) {
			newArr[pointer3] = arr[pointer2];
			pointer3++;
		}
	}
	else {
		for (pointer1 = pointer1; pointer1 <= mid; pointer1++) {
			newArr[pointer3] = arr[pointer1];
			pointer3++;
		}
	}
	
	for (int i = 0; i < size; i++) {
		arr[lb] = newArr[i];
		lb++;
	}
    
    
}

void mergeSort(int arr[], int lb, int ub) {
	if (lb < ub) {
		int mid = (lb + ub) / 2;
		mergeSort(arr,lb,mid);
		mergeSort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


