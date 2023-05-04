#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ARRSIZE 10

void generate_arr(int** arr, int N);
void counting_sort(int* arr, int N);
void print_arr(int* arr, int N);

int main()
{
    srand(time(NULL));
    int* arr;
    generate_arr(&arr, ARRSIZE);
    counting_sort(arr, ARRSIZE);
    print_arr(arr, ARRSIZE);

    return 0;
}

void generate_arr(int** arr, int N)
{
    *arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        (*arr)[i] = rand() % 10;
    }
}

void counting_sort(int* arr, int N)
{
    int Range = 10;
    int count[Range], output[N];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < N; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i < Range; i++) {
        count[i] += count[i - 1];
    }
    for (int i = N - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < N; i++) {
        arr[i] = output[i];
    }
}

void print_arr(int* arr, int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
}
