#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void quick_sort_recursive(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    if (start == end - 1)
    {
        if (arr[start] > arr[end])
        {
            swap(arr, start, end);
        }
        return;
    }

    int pivot = arr[start];
    int left = start;
    int right = end - 1;
    while (left <= right)
    {
        while (left < end && arr[left] <= pivot)
        {
            left++;
        }

        while (right >= 0 && arr[right] > pivot)
        {
            right--;
        }

        if (left < right)
        {
            swap(arr, left, right);
        }
    }

    swap(arr, start, right);
    int mid = left;
    quick_sort_recursive(arr, start, mid);
    quick_sort_recursive(arr, mid, end);
}

void quick_sort(int *arr, int size)
{
    quick_sort_recursive(arr, 0, size - 1);
}

int main()
{
    int arr[] = {6, 3, 4, 8, 1, 9};
    int size = sizeof(arr) / sizeof(int);
    quick_sort(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
