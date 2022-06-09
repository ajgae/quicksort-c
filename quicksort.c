
#include <stdio.h>

static int partition(int *values, int start, int end);
static void swap(int *values, int i, int j);
static void print_array(int *values, int start, int end);

void quicksort(int *values, int start, int end) {
  if (start < end) {
    int pivot = partition(values, start, end);
    quicksort(values, start, pivot - 1);
    quicksort(values, pivot + 1, end);
  }
}

static int partition(int *values, int start, int end) {
  int pivot = values[end];
  int i = start - 1;
  for (int j = start; j < end; ++j) {
    if (values[j] <= pivot) {
      i += 1;
      //printf("i: %d, j: %d\n", i, j);
      swap(values, i, j);
      //print_array(values, start, end);
    }
  }
  i += 1;
  //printf("i: %d\n", i);
  swap(values, i, end);
  //print_array(values, start, end);
  return i;
}

static void swap(int *values, int i, int j) {
   int tmp = values[j];
   values[j] = values[i];
   values[i] = tmp;
}

static void print_array(int *values, int start, int end) {
  for (int i = start; i <= end; ++i) {
    printf("%d ", values[i]);
  }
  printf("\n");
}

int main() {
  int values[] = {
    3, 14, 8, 1, 5, 82, 9, 124, 2, 22, 222, 3, 5, 81, 42,
  };
  print_array(values, 0, sizeof(values) / sizeof(int) - 1);
  quicksort(values, 0, sizeof(values) / sizeof(int) - 1);
  print_array(values, 0, sizeof(values) / sizeof(int) - 1);
}
