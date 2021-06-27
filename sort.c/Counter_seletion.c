#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int limit = 10000000;
const int num_experiments = 40;
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

int count_swap = 0;
void swap(int* arr, int i, int j)
{
  int t = arr[i];
  arr[i] = arr[j];
  arr[j] = t;
  count_swap++;
}

int count_compare = 0;

bool less(int x, int y)
{
  count_compare++;
  return x <= y;
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
    while (less(memory, arr[j]) && (j >= 0)) {
      arr[j + 1] = arr[j];
      count_swap++;
      --j;
    }

    arr[j + 1] = memory;
    count_swap++;
            }
        }
   }
}
bool check(int* arr, int size)
{
  for (int i = 0; i < size - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }

  return true;
}

void experiment(void algo(int*, int), int size)
{
  int total_swap = 0;
  int total_compare = 0;
  for (int i = 0; i < num_experiments; i++) {
    count_swap = 0;
    count_compare = 0;
    int* arr = gen_array(size, limit);

    algo(arr, size);

    if (check(arr, size) == false) {
      printf("Wrong result, algorithm has bug!\n");
      printf("Output array: \n");
      print_array(arr, size);
      return;
    }

    total_swap += count_swap;
    total_compare += count_compare;
    free(arr);
  }

  int avg_swap = total_swap / num_experiments;
  int avg_compare = total_compare / num_experiments;
  printf("n=%5d, avg_swap %10d, avg_compare %10d, n^2 %8d\n", size, avg_swap,
      avg_compare, size * size);
}

int main()
{
  time_t t;
  srand((unsigned)time(&t));

  int sizes[] = {
    0,
    1,
    2,
    4,
    8,
    16,
    128,
    1024,
    10240,
  };

  int number_of_sizes = sizeof(sizes) / sizeof(int);
  for (int i = 0; i < number_of_sizes; i++) {
    int size = sizes[i];
    experiment(selection_sort, size);
  }
  return 0;
}
