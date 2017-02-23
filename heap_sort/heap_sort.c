#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int n);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

int main()
{
    int arr[] = {1, 11, 53, 15, 16, 17};
    int n = 6;

    heapSort(arr, n);

    printf("The sorted array is:");
    printArray(arr, n);
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;


    if (l < n && arr[l] > arr[largest])
        largest = l;


    if (r < n && arr[r] > arr[largest])
        largest = r;


    if (largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n)
{
    int i;
    for (i= n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (i=n-1; i>=0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}


void printArray(int arr[], int n)
{
    int i;
    for (i=0; i<n; ++i)
        printf("%d ",arr[i]);
    printf("\n");
}
