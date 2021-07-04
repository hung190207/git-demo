#include <stdio.h>
#include <stdlib.h>
void merge_sort_recursive(int *arr, int start , int end)
{
    if(end - start <= 1)
    {
        return;
    }
    int middle = start + ( end - start ) / 2;
    merge_sort_recursive(arr,start,middle);
    merge_sort_recursive(arr,middle,end);
    int* temp = (int*)calloc(end - start,sizeof(int));
    int i = start;
    int j = middle;
    int t = 0;
    while( i < middle && j < end)
    {
        if(arr[i] < arr[j])
        {
            temp[t] = arr[i];
            t++;
            i++;
        }
        else if(arr[i] == arr[j])
        {
            temp[t] = arr[i];
            temp[t] = arr[j];
            j++;
            i++;
            t++;
        }
        else if(arr[i] > arr[j])
        {
            temp[t] = arr[j];;
            j++;
            t++;
        }
    }
    while( i < middle)
    {
        temp[t] = arr[i];
        t++;
        i++;
    }
    while( j < end)
    {
        temp[t] = arr[j];
        t++;
        j++;
    }
    for(int i = 0 ; i <  end - start ; i++)
    {
        arr[start+i] = temp[i];
    }
    free(temp);
}
void merge_sort(int* arr, int size)
{
    merge_sort_recursive(arr,0,size);
}
void print_array(int* arr, int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {6, 3, 4, 8, 1, 9};
    int size = sizeof(arr) / sizeof(int);
    merge_sort(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
