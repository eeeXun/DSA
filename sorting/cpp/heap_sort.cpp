#include <ctime>
#include <iostream>
#include <vector>
#define ARRSIZE 20
using namespace std;

void generate_arr(vector<int>& arr, int N);
void heap_sort(vector<int>& arr);
void heapify(vector<int>& arr, int heap_size, int i);
void print_arr(vector<int> arr);

int main()
{
    srand(time(NULL));
    vector<int> arr;
    generate_arr(arr, ARRSIZE);
    heap_sort(arr);
    print_arr(arr);

    return 0;
}

void generate_arr(vector<int>& arr, int N)
{
    for (int i = 0; i < N; i++) {
        arr.push_back(rand() % 100);
    }
}

void heap_sort(vector<int>& arr)
{
    int N = arr.size();
    // build max heap
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(arr, N, i);
    }
    // heap sort
    for (int i = N - 1; i >= 0; i--) {
        swap(arr.at(0), arr.at(i));
        heapify(arr, i, 0);
    }
}

void heapify(vector<int>& arr, int heap_size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heap_size && arr.at(left) > arr.at(largest))
        largest = left;
    if (right < heap_size && arr.at(right) > arr.at(largest))
        largest = right;
    if (largest != i) {
        swap(arr.at(i), arr.at(largest));
        heapify(arr, heap_size, largest);
    }
}


void print_arr(vector<int> arr)
{
    for (int i : arr) {
        cout << i << endl;
    }
}
