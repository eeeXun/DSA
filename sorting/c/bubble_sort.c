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
void bubble_sort(int* arr, int N);
void print_arr(int* arr, int N);

int main()
{
    srand(time(NULL));
    int* arr;
    generate_arr(&arr, ARRSIZE);
    bubble_sort(arr, ARRSIZE);
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

void bubble_sort(int* arr, int N)
{
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                SWAP(arr[j], arr[j + 1]);
            }
        }
    }
}

void print_arr(int* arr, int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
}
