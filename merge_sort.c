#include <stdio.h>
#include <stdlib.h>

// Merge sort function
int* merge_sort(int* array, int length) {
    if (length < 2)
        return array;

    int mid = length / 2;

    int* left = (int*) calloc(mid, sizeof(int));
    int* right = (int*) calloc(length - mid, sizeof(int));

    // Splitting
    for (int i = 0; i < mid; i++)
        left[i] = array[i];
    for (int i = mid; i < length; i++)
        right[i - mid] = array[i];

    left = merge_sort(left, mid);
    right = merge_sort(right, length - mid);

    // Merging
    int* result = (int*) malloc(length * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < mid && j < length - mid) {
        if (left[i] < right[j])
            result[k++] = left[i++];
        else
            result[k++] = right[j++];
    }
    while (i < mid)
        result[k++] = left[i++];
    while (j < length - mid)
        result[k++] = right[j++];

    free(left);
    free(right);

    return result;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int* arr = (int*) malloc(n * sizeof(int));
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int* sorted = merge_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", sorted[i]);
    printf("\n");

    free(arr);
    free(sorted);
    return 0;
}
