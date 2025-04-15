#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[low]);
    return i;
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    int n;


    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];


    srand(time(0));


    printf("Generated array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    printf("\n");


    clock_t start = clock();

    quickSort(arr, 0, n - 1);

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;


    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    printf("Time taken to sort: %f seconds\n", time_taken);

    return 0;
}
