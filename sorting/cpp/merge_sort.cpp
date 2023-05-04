#include <ctime>
#include <iostream>
#include <vector>
#define ARRSIZE 20
using namespace std;

void generate_arr(vector<int>& arr, int N);
void merge_sort(vector<int>& arr, int left, int right);
void merge(vector<int>& arr, int left, int mid, int right);
void print_arr(vector<int> arr);

int main()
{
    srand(time(NULL));
    vector<int> arr;
    generate_arr(arr, ARRSIZE);
    merge_sort(arr, 0, ARRSIZE - 1);
    print_arr(arr);

    return 0;
}

void generate_arr(vector<int>& arr, int N)
{
    for (int i = 0; i < N; i++) {
        arr.push_back(rand() % 100);
    }
}

void merge_sort(vector<int>& arr, int left, int right)
{
    if (left == right)
        return;

    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void merge(vector<int>& arr, int left, int mid, int right)
{
    int left_size = mid - left + 1;
    int right_size = right - mid;
    vector<int> left_arr;
    vector<int> right_arr;
    for (int i = 0; i < left_size; i++) {
        left_arr.push_back(arr.at(left + i));
    }
    for (int i = 0; i < right_size; i++) {
        right_arr.push_back(arr.at(mid + 1 + i));
    }
    // merging
    int index_left = 0;
    int index_right = 0;
    int index_merge = left;
    while (index_left < left_size && index_right < right_size) {
        if (left_arr.at(index_left) <= right_arr.at(index_right)) {
            arr.at(index_merge) = left_arr.at(index_left);
            index_left++;
        } else {
            arr.at(index_merge) = right_arr.at(index_right);
            index_right++;
        }
        index_merge++;
    }
    // copy remainging left to arr
    while (index_left < left_size) {
        arr.at(index_merge) = left_arr.at(index_left);
        index_left++;
        index_merge++;
    }
    // copy remainging right to arr
    while (index_right < right_size) {
        arr.at(index_merge) = right_arr.at(index_right);
        index_right++;
        index_merge++;
    }
}

void print_arr(vector<int> arr)
{
    for (int i : arr) {
        cout << i << endl;
    }
}
