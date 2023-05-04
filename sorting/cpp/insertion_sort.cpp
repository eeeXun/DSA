#include <ctime>
#include <iostream>
#include <vector>
#define ARRSIZE 20
using namespace std;

void generate_arr(vector<int>& arr, int N);
void insetion_sort(vector<int>& arr);
void print_arr(vector<int> arr);

int main()
{
    srand(time(NULL));
    vector<int> arr;
    generate_arr(arr, ARRSIZE);
    insetion_sort(arr);
    print_arr(arr);

    return 0;
}

void generate_arr(vector<int>& arr, int N)
{
    for (int i = 0; i < N; i++) {
        arr.push_back(rand() % 100);
    }
}

void insetion_sort(vector<int>& arr)
{
    int N = arr.size();
    int key, j;
    for (int i = 1; i < N; i++) {
        key = arr.at(i), j = i - 1;
        while (j >= 0 && key < arr.at(j)) {
            arr.at(j + 1) = arr.at(j);
            j--;
        }
        arr.at(j + 1) = key;
    }
}

void print_arr(vector<int> arr)
{
    for (int i : arr) {
        cout << i << endl;
    }
}
