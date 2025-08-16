
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;
int n;
vector<vector<int>> mat(100005, vector<int>(3));
vector<vector<int>> dp(1000005, vector<int>(4, -1));

int solve(int i, int prev)
{

    if (i > n)
        return 0;

    int mx = -1;
    if (dp[i][prev] != -1)
        return dp[i][prev];
    {

        if (prev != 0)
            mx = max(mx, mat[i][0] + solve(i + 1, 0));
        if (prev != 1)
            mx = max(mx, mat[i][1] + solve(i + 1, 1));
        if (prev != 2)
            mx = max(mx, mat[i][2] + solve(i + 1, 2));
    }
    return dp[i][prev] = mx;
}
void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int main()
{
    // io();
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> mat[j][i];
        }
    }
    cout << solve(0, 3);

    return 0;
}