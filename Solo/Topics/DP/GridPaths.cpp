
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

vector<vector<int>> dp(1001, vector<int>(1001, 0));
;
int n;

int main()
{
    // io();
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            arr[i][j] = (x == '*') ? 1 : 0;
        }
    }
    if (!arr[n - 1][n - 1])
        dp[n - 1][n - 1] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {

            if (i == n - 1 && j == n - 1)
                continue;
            if (arr[i][j])
                dp[i][j] = 0;
            else

                dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % mod;
        }
    }

    cout << dp[0][0];
}