#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i){
    int largest =i;
    int left = 2*i+1;
    int right = 2*i +2;

    if(left<n && arr[left]>arr[largest]) largest = left;
    if(right<n && arr[right]>arr[largest]) largest = right;

    if(largest!= i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n){
    for(int i = n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
}

void printHeap(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int extractMax(int arr[], int *n){
    if(*n<1) return -1;

    int max = arr[0];
    arr[0] = arr[*n-1];
    (*n)--;
    heapify(arr, *n, 0);
    return max;
}

void heapSort(int arr[], int n){
    buildHeap(arr, n);

    for(int i=n-1; i>=0;i--){
        swap(&arr[0], &arr[i]);
        printf("%d ", arr[i]);
        heapify(arr, i, 0);
    }
}


int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    buildHeap(arr, n);
    printHeap(arr, n);
    printf("Max: %d\n", extractMax(arr, &n));
    heapSort(arr, n);

    return 0;
}