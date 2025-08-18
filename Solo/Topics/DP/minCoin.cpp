
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

vector<int> arr;
vector<int> dp;
int n;

int main()
{
    // io();
    int totSum;
    cin >> n;
    cin >> totSum;
    arr.resize(n);
    dp.assign(totSum + 1, 1e8);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dp[0] = 0;
    for (int sum = 1; sum <= totSum; sum++)
    {
        for (int j = 0; j < n; j++)
        {
            if (sum >= arr[j])
                dp[sum] = min(dp[sum], 1 + dp[sum - arr[j]]);
        }
    }
    if (dp[totSum] != 1e8)
        cout << dp[totSum];
    else
        cout << -1;
}