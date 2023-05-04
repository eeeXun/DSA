#include <ctime>
#include <iostream>
#include <vector>
#define ARRSIZE 20
using namespace std;

void generate_arr(vector<int>& arr, int N);
void quick_sort(vector<int>& arr, int left, int right);
void print_arr(vector<int> arr);

int main()
{
    srand(time(NULL));
    vector<int> arr;
    generate_arr(arr, ARRSIZE);
    quick_sort(arr, 0, arr.size() - 1);
    print_arr(arr);

    return 0;
}

void generate_arr(vector<int>& arr, int N)
{
    for (int i = 0; i < N; i++) {
        arr.push_back(rand() % 100);
    }
}

void quick_sort(vector<int>& arr, int left, int right)
{
    if (left < right) {
        int pivot = arr.at(right);
        int l = left - 1, r = right;
        while (l < r) {
            while (l < right && arr.at(++l) < pivot)
                ;
            while (r > left && arr.at(--r) > pivot)
                ;
            if (l >= r)
                break;
            swap(arr.at(l), arr.at(r));
        }
        swap(arr.at(l), arr.at(right));
        quick_sort(arr, left, l - 1);
        quick_sort(arr, l + 1, right);
    }
}

void print_arr(vector<int> arr)
{
    for (int i : arr) {
        cout << i << endl;
    }
}
