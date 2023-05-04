#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ARRSIZE 20

void generate_arr(int** arr, int N);
int MAX(int* arr);
void counting_sort(int* arr, int N, int digit);
void radix_sort(int* arr, int N);
void print_arr(int* arr, int N);

int main()
{
    srand(time(NULL));
    int* arr;
    generate_arr(&arr, ARRSIZE);
    radix_sort(arr, ARRSIZE);
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

int MAX(int* arr)
{
    int max = arr[0];
    for (int i = 1; i < ARRSIZE; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void counting_sort(int* arr, int N, int digit)
{
    int Range = 10;
    int count[Range], output[N];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < N; i++) {
        count[(arr[i] / digit) % 10]++;
    }
    for (int i = 1; i < Range; i++) {
        count[i] += count[i - 1];
    }
    for (int i = N - 1; i >= 0; i--) {
        output[count[(arr[i] / digit) % 10] - 1] = arr[i];
        count[(arr[i] / digit) % 10]--;
    }
    for (int i = 0; i < N; i++) {
        arr[i] = output[i];
    }
}

void radix_sort(int* arr, int N)
{
    int max_value = MAX(arr);
    for (int digit = 1; max_value / digit > 0; digit *= 10) {
        counting_sort(arr, N, digit);
    }
}

void print_arr(int* arr, int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
}
