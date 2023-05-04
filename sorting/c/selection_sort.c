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
void selection_sort(int* arr, int N);
void print_arr(int* arr, int N);

int main()
{
    srand(time(NULL));
    int* arr;
    generate_arr(&arr, ARRSIZE);
    selection_sort(arr, ARRSIZE);
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

void selection_sort(int* arr, int N)
{
    for (int i = 0; i < N; i++) {
        int index_min = i;
        for (int j = i + 1; j < N; j++) {
            if (arr[index_min] > arr[j])
                index_min = j;
        }
        SWAP(arr[i], arr[index_min]);
    }
}

void print_arr(int* arr, int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
}
