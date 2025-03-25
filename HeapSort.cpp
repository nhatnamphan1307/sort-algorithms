#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <chrono>
#include <math.h>

using namespace std;
using namespace chrono;

const int numOfArrays = 10;
const int elements = 1000000;

void Heapify(vector<double> &a, int i, int heap_size)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if ((left <= heap_size) && (a[left] > a[largest]))
    {
        largest = left;
    }
    if ((right <= heap_size) && (a[right] > a[largest]))
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(a[i], a[largest]);
        Heapify(a, largest, heap_size);
    }
}

void Build_max_heap(vector<double> &a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(a, i, n - 1);
    }
}

void HeapSort(vector<double> &a, int n)
{
    Build_max_heap(a, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        Heapify(a, 0, i - 1);
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    freopen("heapsort.txt", "w", stdout);

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

        HeapSort(a, elements);

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