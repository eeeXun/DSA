#include <ctime>
#include <iostream>
#include <vector>
#define ARRSIZE 20
using namespace std;

void generate_arr(vector<int>& arr, int N);
void bubble_sort(vector<int>& arr);
void print_arr(vector<int> arr);

int main()
{
    srand(time(NULL));
    vector<int> arr;
    generate_arr(arr, ARRSIZE);
    bubble_sort(arr);
    print_arr(arr);

    return 0;
}

void generate_arr(vector<int>& arr, int N)
{
    for (int i = 0; i < N; i++) {
        arr.push_back(rand() % 100);
    }
}

void bubble_sort(vector<int>& arr)
{
    int N = arr.size();
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr.at(j) > arr.at(j + 1)) {
                swap(arr.at(j), arr.at(j + 1));
            }
        }
    }
}

void print_arr(vector<int> arr)
{
    for (int i : arr) {
        cout << i << endl;
    }
}
