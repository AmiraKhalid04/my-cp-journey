
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

vector<int> arr;
vector<int> dp;

int n;

////////////////////////////////INIT CODE//////////////////////////
//////////////////////////////////////////////////////////////////

// void solve(int i, int sum)
// {
//     if (sum > totSum || i == n)
//         return 0;

//     if (dp[i][sum] != -1)
//         return dp[i][sum];

//     for (int j = 0; j < n; j++)
//     {
//         int op = 0;
//         ;
//         if (sum + arr[j] <= totSum)
//         {
//             op = solve(j + 1, sum + arr[j]);
//         }
//         dp[i][sum] = op + solve(j + 1, sum);
//     }

//     return dp[i][sum];
// }

////////////////////////////////FINAL CODE//////////////////////////
//////////////////////////////////////////////////////////////////

// TLE
int totSum;
// int solve(int sum)
// {
//     if (sum < 0)
//         return 0;
//     if (sum == 0)
//         return 1;

//     if (dp[sum] != -1)
//         return dp[sum];

//     int ans = 0;
//     for (int j = 0; j < n; j++)
//     {
//         ans = (ans % mod + solve(sum - arr[j]) % mod) % mod;
//     }

//     return dp[sum] = ans;
// }

int solve(int sum)
{
    if (sum < 0)
        return 0;
    if (sum == 0)
        return 1;

    if (dp[sum] != -1)
        return dp[sum];

    int ans = 0;
    for (int j = 0; j < n; j++)
    {
        ans = (ans % mod + solve(sum - arr[j]) % mod) % mod;
    }

    return dp[sum] = ans;
}

int main()
{
    // io();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    cin >> totSum;
    arr.resize(n);
    dp.assign(totSum + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dp[0] = 1;

    sort(arr.begin(), arr.end());

    // dp[9] =dp[7]+ dp[5]+ dp[4]
    // dp[7] =dp[5]+ dp[4]+ dp[2]
    // dp[5] =dp[2]+ dp[3]+ dp[0]
    // dp[4] =dp[2]+ dp[1]+ dp[-1]

    // 2 3 5

    for (int sum = 1; sum <= totSum; sum++)
    {
        for (int j = 0; j < n; j++)
        {
            if (sum >= arr[j])
                dp[sum] = (dp[sum] + dp[sum - arr[j]]) % mod;
            else
                break;
        }
    }
    cout << dp[totSum];
}