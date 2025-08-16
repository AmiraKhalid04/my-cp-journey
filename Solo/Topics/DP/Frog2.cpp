
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;
int n, k;
vector<int> arr(100005);
vector<int> dp(1000005, -1);

int solve(int i)
{
    if (i == n - 1)
        return 0;

    if (i > n - 1)
        return INT_MAX;
    if (dp[i] != -1)
        return dp[i];
    int mx1 = INT_MAX;

    for (int j = 1; j <= k; j++)
        if (i + j < n)
            mx1 = min(mx1, abs(arr[i] - arr[i + j]) + solve(i + j));

    return dp[i] = mx1;
}
void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int main()
{
    io();
    cin >> n >> k;
    for (int j = 0; j < n; j++)
    {
        cin >> arr[j];
    }
    cout << solve(0);

    return 0;
}