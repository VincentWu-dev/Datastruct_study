#include "stdio.h"
#include "stdlib.h"


void PrintArray(int *arr, int size_arr)
{
    for (int i=0;i< size_arr;i++) printf("arr[%d]: %d\n",i,*(arr+i));
    printf("\n");
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int *arr,int front,int end)
{
    int pivot = *(arr+end);
    int i = front -1;
    for (int j=front; j<end+1; j++) {
        if (arr[j] < pivot) {
            printf("%d\n",arr[j]);
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    printf("pivot: %d, i: %d\n",pivot, i);
    return i;
}

void QuickSort(int *arr, int front, int end)
{
    if (front < end) {
        int pivot = Partition(arr,front, end);
        QuickSort(arr, front, pivot-1);
        QuickSort(arr, pivot+1, end);
    }

}
int main(int argc, char *argv[])
{
    int arr[] = {9, 4, 1, 6, 7, 3, 8, 2, 5, 8, 10, 20};
    int size_arr = sizeof(arr)/sizeof(int);
    int front = 0;

    PrintArray(arr, size_arr);
    QuickSort(arr, front, size_arr-1);
    PrintArray(arr, size_arr);
return 0;
}
