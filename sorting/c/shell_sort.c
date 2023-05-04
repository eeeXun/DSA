// Kunth's sequence
// gap = gap * 3 + 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRSIZE 20

void generate_arr(int** arr, int N);
void shell_sort(int* arr, int N);
void print_arr(int* arr, int N);

int main()
{
    srand(time(NULL));
    int* arr;
    generate_arr(&arr, ARRSIZE);
    shell_sort(arr, ARRSIZE);
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

void shell_sort(int* arr, int N)
{
    int gap = 1;
    while (gap < N) {
        gap = gap * 3 + 1;
    }
    while (gap > 1) {
        gap /= 3;
        int key, j;
        for (int i = gap; i < N; i++) {
            key = arr[i], j = i - gap;
            while (j >= 0 && key < arr[j]) {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = key;
        }
    }
}

void print_arr(int* arr, int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
}
