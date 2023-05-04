#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRSIZE 20

void generate_arr(int** arr, int N);
void insetion_sort(int* arr, int N);
void print_arr(int* arr, int N);

int main()
{
    srand(time(NULL));
    int* arr;
    generate_arr(&arr, ARRSIZE);
    insetion_sort(arr, ARRSIZE);
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

void insetion_sort(int* arr, int N)
{
    int key, j;
    for (int i = 1; i < N; i++) {
        key = arr[i], j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print_arr(int* arr, int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
}
