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

void insertion_sort(int* arr, int size)
{
    for(int i = 1 ;i<size;i++)
    {
        int hung = i - 1;
        int hung2 = arr[i];
        while((arr[hung]>hung2)&&(hung >= 0 ))
        {
            arr[hung + 1] = arr[hung];
            hung--;
        }
        arr[hung+1] = hung2;
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

    insertion_sort(arr, size);

    printf("Sorted array:\n");
    print_array(arr, size);

    free(arr);
    return 0;
}
