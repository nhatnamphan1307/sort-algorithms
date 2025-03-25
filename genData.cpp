#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdio>
#include <functional>

using namespace std;

const int numOfArrays = 10;
const int elements = 1000000;

int main()
{
    freopen("data.txt", "w", stdout);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0.0, 1000000.0);

    vector<double> v(elements);
    for (int i = 1; i <= numOfArrays; i++)
    {
        for (int j = 0; j < elements; j++)
        {
            v[j] = dist(gen);
        }
        if (i == 1)
            sort(v.begin(), v.end());
        if (i == 2)
            sort(v.begin(), v.end(), greater<double>());
        for (auto it : v)
            cout << it << ' ';
        cout << '\n';
    }
    fclose(stdout);
    cerr << "Done" << endl;
    return 0;
}