// Kunth's sequence
// gap = gap * 3 + 1

#include <ctime>
#include <iostream>
#include <vector>
#define ARRSIZE 20
using namespace std;

void generate_arr(vector<int>& arr, int N);
void shell_sort(vector<int>& arr);
void print_arr(vector<int> arr);

int main()
{
    srand(time(NULL));
    vector<int> arr;
    generate_arr(arr, ARRSIZE);
    shell_sort(arr);
    print_arr(arr);

    return 0;
}

void generate_arr(vector<int>& arr, int N)
{
    for (int i = 0; i < N; i++) {
        arr.push_back(rand() % 100);
    }
}

void shell_sort(vector<int>& arr)
{
    int N = arr.size();
    int gap = 1;
    while (gap < N) {
        gap = gap * 3 + 1;
    }
    while (gap > 1) {
        gap /= 3;
        int key, j;
        for (int i = gap; i < N; i++) {
            key = arr.at(i), j = i - gap;
            while (j >= 0 && key < arr.at(j)) {
                arr.at(j + gap) = arr.at(j);
                j -= gap;
            }
            arr.at(j + gap) = key;
        }
    }
}

void print_arr(vector<int> arr)
{
    for (int i : arr) {
        cout << i << endl;
    }
}
