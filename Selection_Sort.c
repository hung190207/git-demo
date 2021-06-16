#include <stdio.h>
#include <stdlib.h>

const int limit = 100;

int* gen_array(int size, int limit)
{
    int* arr = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        int n = rand() % limit;
        arr[i] = n;
    }
    return arr;
}

void print_array(int* arr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int* arr, int size)
{
    for(int i = 0; i < size; ++i) {
        int min = i;
        for(int j = min+1; j < size; ++j) {
            if(arr[min] > arr[j]) {
                min = j;
            }
            if(arr[i] > arr[min]) {
                int memory = arr[min];
                arr[min] = arr[i];
                arr[i] = memory;
            }
        }
    }
}

int main()
{
    printf("Nhap size cua array:\n");
    int size;
    scanf("%d", &size);

    int* arr = gen_array(size, limit);

    printf("Khoi dong array:\n");
    print_array(arr, size);

    selection_sort(arr, size);

    printf("Sorted array:\n");
    print_array(arr, size);

    free(arr);
    return 0;
}
