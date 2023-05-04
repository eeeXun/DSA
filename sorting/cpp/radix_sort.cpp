#include <algorithm>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#define ARRSIZE 20
using namespace std;

void generate_arr(vector<int>& arr, int N);
void counting_sort(vector<int>& arr, int digit);
void radix_sort(vector<int>& arr);
void print_arr(vector<int> arr);

int main()
{
    srand(time(NULL));
    vector<int> arr;
    generate_arr(arr, ARRSIZE);
    radix_sort(arr);
    print_arr(arr);

    return 0;
}

void generate_arr(vector<int>& arr, int N)
{
    for (int i = 0; i < N; i++) {
        arr.push_back(rand() % 100);
    }
}

void counting_sort(vector<int>& arr, int digit)
{
    int Range = 10, N = arr.size();
    int count[Range], output[N];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < N; i++) {
        count[(arr.at(i) / digit) % 10]++;
    }
    for (int i = 1; i < Range; i++) {
        count[i] += count[i - 1];
    }
    for (int i = N - 1; i >= 0; i--) {
        output[count[(arr.at(i) / digit) % 10] - 1] = arr.at(i);
        count[(arr.at(i) / digit) % 10]--;
    }
    for (int i = 0; i < N; i++) {
        arr.at(i) = output[i];
    }
}

void radix_sort(vector<int>& arr)
{
    int N = arr.size();
    int max_value = *max_element(arr.begin(), arr.end());
    for (int digit = 1; max_value / digit > 0; digit *= 10) {
        counting_sort(arr, digit);
    }
}

void print_arr(vector<int> arr)
{
    for (int i : arr) {
        cout << i << endl;
    }
}
