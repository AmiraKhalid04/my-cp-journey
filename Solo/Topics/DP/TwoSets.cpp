
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

vector<vector<int>> dp(1001, vector<int>(100001, -1));
;
int n;

int solve(int i, int sum)
{
    if (i == n + 1)
        if (sum == 0)
            return 1;
        else
            return 0;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    int ans = solve(i + 1, sum);

    if (sum - i >= 0)
        ans = (ans + solve(i + 1, sum - i)) % mod;

    return dp[i][sum] = ans;
}
int main()
{
    // io();
    cin >> n;

    int mod_inv = (mod + 1) / 2;

    int s = n * (n + 1) / 2;

    if (s % 2)
        cout << 0;

    else
    {
        s /= 2;
        cout << (1ll * solve(1, s) * mod_inv) % mod;
    }
}