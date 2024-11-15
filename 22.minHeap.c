#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void buildHeap(int ar[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(ar, n, i);
    }
}

void printHeap(int arr[] ,int n){
    for(int i=0; i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int extractMin(int arr[], int *n){
    if(*n<1) return -1;

    int min = arr[0];
    arr[0] = arr[*n-1];
    *n = *n-1;
    heapify(arr, *n, 0);
    return min;
}

void heapSort(int arr[], int n){
    buildHeap(arr,n);

    for(int i = n-1; i>=0; i--){
        swap(&arr[0], &arr[i]);
        printf("%d ", arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildHeap(arr, n);
    printHeap(arr, n);
    printf("Min: %d\n", extractMin(arr, &n));
    printHeap(arr, n);
    heapSort(arr, n);
    return 0;
}