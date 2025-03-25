#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

const int numOfArrays = 10;
const int elements = 1000000;

int main()
{
    freopen("data.txt", "r", stdin);
    freopen("cppsort.txt", "w", stdout);

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

        sort(a.begin(), a.end());

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