#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRSIZE 20

void generate_arr(int** arr, int N);
void merge_sort(int* arr, int left, int right);
void merge(int* arr, int left, int mid, int right);
void print_arr(int* arr, int N);

int main()
{
    srand(time(NULL));
    int* arr;
    generate_arr(&arr, ARRSIZE);
    merge_sort(arr, 0, ARRSIZE - 1);
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

void merge_sort(int* arr, int left, int right)
{
    if (left == right)
        return;

    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void merge(int* arr, int left, int mid, int right)
{
    int left_size = mid - left + 1;
    int right_size = right - mid;
    int* left_arr = (int*)malloc(sizeof(int) * left_size);
    int* right_arr = (int*)malloc(sizeof(int) * right_size);
    for (int i = 0; i < left_size; i++) {
        left_arr[i] = arr[left + i];
    }
    for (int i = 0; i < right_size; i++) {
        right_arr[i] = arr[mid + 1 + i];
    }
    // merging
    int index_left = 0;
    int index_right = 0;
    int index_merge = left;
    while (index_left < left_size && index_right < right_size) {
        if (left_arr[index_left] <= right_arr[index_right]) {
            arr[index_merge] = left_arr[index_left];
            index_left++;
        } else {
            arr[index_merge] = right_arr[index_right];
            index_right++;
        }
        index_merge++;
    }
    // copy remainging left to arr
    while (index_left < left_size) {
        arr[index_merge] = left_arr[index_left];
        index_left++;
        index_merge++;
    }
    // copy remainging right to arr
    while (index_right < right_size) {
        arr[index_merge] = right_arr[index_right];
        index_right++;
        index_merge++;
    }
}

void print_arr(int* arr, int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
}
