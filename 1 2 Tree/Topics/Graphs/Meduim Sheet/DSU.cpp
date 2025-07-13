#include <bits/stdc++.h>

using namespace std;

void initDSU(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}

int rootDSU(vector<int> arr, int i)
{
    // get arr[i] till arr[i]==i

    while (arr[i] != i)
    {
        i == arr[i];
    }

    return i;
}

void unionDSU(vector<int> &arr, int a, int b)
{

    // b->a: b is the parent
    int rootA = rootDSU(arr, a);

    int rootB = rootDSU(arr, b);

    arr[rootA] = rootB;
}
// if they have the same rootDSU, there will be a cycle
bool findDSU(vector<int> arr, int a, int b)
{
    int rootA = rootDSU(arr, a);
    int rootB = rootDSU(arr, b);
    if (rootA == rootB)
    {
        // cycle detected
        return 1;
    }
    return 0;
}