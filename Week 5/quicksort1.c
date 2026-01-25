//CH.SC.U4CSE24107
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionFirst(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;

        if (i < j)
            swap(&a[i], &a[j]);
    }

    swap(&a[low], &a[j]);
    return j;
}

void quickSortFirst(int a[], int low, int high) {
    if (low < high) {
        int p = partitionFirst(a, low, high);
        quickSortFirst(a, low, p - 1);
        quickSortFirst(a, p + 1, high);
    }
}

int main() {
    int a[] = {157,110,147,122,111,149,151,141,123,112,117,133};
    int n = 12;

    quickSortFirst(a, 0, n - 1);

    printf("Sorted array (First pivot):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
