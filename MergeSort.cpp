#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

const int numOfArrays = 10;
const int elements = 1000000;

void Merge(vector<double> &a, int low, int mid, int high)
{
    int n = high - low + 1;
    vector<double> T(n);
    int left = low;
    int right = mid + 1;
    int k = 0;

    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right])
            T[k++] = a[left++];
        else
            T[k++] = a[right++];
    }

    while (left <= mid)
        T[k++] = a[left++];

    while (right <= high)
        T[k++] = a[right++];

    for (int i = low; i <= high; i++)
    {
        a[i] = T[i - low];
    }
}

void MergeSort(vector<double> &a, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    MergeSort(a, low, mid);
    MergeSort(a, mid + 1, high);
    Merge(a, low, mid, high);
}

int main()
{
    freopen("data.txt", "r", stdin);
    freopen("mergesort.txt", "w", stdout);

    vector<double> a(elements);

    for (int i = 0; i < numOfArrays; i++)
    {
        for (int j = 0; j < elements; j++)
        {
            if (!(cin >> a[j]))
            {
                cerr << "Error" << endl;
                return 1;
            }
        }

        auto start = high_resolution_clock::now();

        MergeSort(a, 0, elements - 1);

        auto end = high_resolution_clock::now();
        double duration = duration_cast<milliseconds>(end - start).count();

        for (int j = 0; j < elements; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;

        cerr << "Dataset " << i + 1 << ": " << duration << " ms" << endl;
    }

    return 0;
}