#include <stdio.h>
#include <stdlib.h>
const int limit = 100;
int* gen_array(int size, int limit)
{
    int* arr = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        int n = rand() % limit;
        arr[i] = n;
    }
    return arr;
}
void print_array(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void buble_sort(int* arr, int size)
{
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size - 1 - j; i++)
        {
            int x = arr[i];
            int y = arr[i + 1];
            if (x < y)
            {
                arr[i + 1] = x;
                arr[i] = y;
            }
        }
    }
}

int main()
{
    printf("Nhap so chu so can sort vao:\n");// chinh chut cho vui thoi ;/ //
    int size;
    scanf("%d", &size);

    int* arr = gen_array(size, limit);

    printf("Khoi dong array :\n");
    print_array(arr, size);

    buble_sort(arr, size);

    printf("Sorted array:\n");
    print_array(arr, size);

    free(arr);
    return 0;
}
