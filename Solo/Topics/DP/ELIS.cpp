
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

vector<int> arr;
int n;

int lengthOfLIS(vector<int> &a)
{
    // Initialize LIS for each element as at least 1
    // memo[i] = length of LIS possible ending with element nums[i]
    vector<int> memo(a.size(), 1);
    int n = a.size();

    for (int i = 0; i < a.size(); i++)
        for (int j = i - 1; j >= 0; j--)
            if (a[i] > a[j])
                memo[i] = max(memo[i], 1 + memo[j]);

    return *max_element(memo.begin(), memo.end());
}
int main()
{
    io();

    cin >> n;

    arr.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << lengthOfLIS(arr);
}