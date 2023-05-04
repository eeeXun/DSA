#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRSIZE 20
#define SWAP(a, b)                                                             \
    {                                                                          \
        typeof(a) _tmp = a;                                                    \
        a = b;                                                                 \
        b = _tmp;                                                              \
    }

void generate_arr(int** arr, int N);
void heap_sort(int* arr, int N);
void heapify(int* arr, int heap_size, int i);
void print_arr(int* arr, int N);

int main()
{
    srand(time(NULL));
    int* arr;
    generate_arr(&arr, ARRSIZE);
    heap_sort(arr, ARRSIZE);
    print_arr(arr, ARRSIZE);

    return 0;
}

void generate_arr(int** arr, int N)
{
    *arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        (*arr)[i] = rand() % 100;
    }
}

void heap_sort(int* arr, int N)
{
    // build max heap
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(arr, N, i);
    }
    // heap sort
    for (int i = N - 1; i >= 0; i--) {
        SWAP(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify(int* arr, int heap_size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heap_size && arr[left] > arr[largest])
        largest = left;
    if (right < heap_size && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        SWAP(arr[i], arr[largest]);
        heapify(arr, heap_size, largest);
    }
}

void print_arr(int* arr, int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
}
