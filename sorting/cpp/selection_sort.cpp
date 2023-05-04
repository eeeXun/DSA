#include <ctime>
#include <iostream>
#include <vector>
#define ARRSIZE 20
using namespace std;

void generate_arr(vector<int>& arr, int N);
void selection_sort(vector<int>& arr);
void print_arr(vector<int> arr);

int main()
{
    srand(time(NULL));
    vector<int> arr;
    generate_arr(arr, ARRSIZE);
    selection_sort(arr);
    print_arr(arr);

    return 0;
}

void generate_arr(vector<int>& arr, int N)
{
    for (int i = 0; i < N; i++) {
        arr.push_back(rand() % 100);
    }
}

void selection_sort(vector<int>& arr)
{
    int N = arr.size();
    for (int i = 0; i < N; i++) {
        int index_min = i;
        for (int j = i + 1; j < N; j++) {
            if (arr.at(index_min) > arr.at(j))
                index_min = j;
        }
        swap(arr.at(i), arr.at(index_min));
    }
}

void print_arr(vector<int> arr)
{
    for (int i : arr) {
        cout << i << endl;
    }
}
