#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

const int numOfArrays = 10;
const int elements = 1000000;

void QuickSort(vector<double> &a, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    double pivot = a[(left + right) / 2];
    int i = left, j = right;

    while (i <= j)
    {
        while (a[i] < pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    QuickSort(a, left, j);
    QuickSort(a, i, right);
}

int main()
{
    freopen("data.txt", "r", stdin);
    freopen("quicksort.txt", "w", stdout);

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

        QuickSort(a, 0, elements - 1);

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