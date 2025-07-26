#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int* array, int length) {
	for(int i = 1; i < length; i++) {
		int key = array[i];
		int j = i - 1;
		while(j >= 0 && array[j] > key){
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}

int main() {
	printf("Demonstration of Insertion Sort\n");
	printf("Enter the size of the array = \n");
	int length;
	scanf("%d", &length);
	int* array = (int*) calloc(length, sizeof(int));
	printf("Enter %d integers: \n", length);
	for(int i = 0; i < length; i++)
		scanf("%d", &array[i]);
	insertion_sort(array, length);
	printf("Printing sorted array: ");
	for(int i = 0; i < length; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}
