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
void quick_sort(int* arr, int left, int right);
void print_arr(int* arr, int N);

int main()
{
    srand(time(NULL));
    int* arr;
    generate_arr(&arr, ARRSIZE);
    quick_sort(arr, 0, ARRSIZE - 1);
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

void quick_sort(int* arr, int left, int right)
{
    if (left < right) {
        int pivot = arr[right];
        int l = left - 1, r = right;
        while (l < r) {
            while (l < right && arr[++l] < pivot)
                ;
            while (r > left && arr[--r] > pivot)
                ;
            if (l >= r)
                break;
            SWAP(arr[l], arr[r]);
        }
        SWAP(arr[l], arr[right]);
        quick_sort(arr, left, l - 1);
        quick_sort(arr, l + 1, right);
    }
}

void print_arr(int* arr, int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
}
