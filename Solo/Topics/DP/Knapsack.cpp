
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll knap_sack(vector<int> &weights, vector<ll> &benefits, int i, int totCap, int cap, vector<vector<ll>> &dp)
{
    if (i == weights.size() || totCap == cap)
    {
        return 0;
    }
    if (totCap > cap)
        return INT_MIN;
    if (dp[i][totCap] != -1)
        return dp[i][totCap];
    {
        // try to pick and not pick
        ll benefit1 = knap_sack(weights, benefits, i + 1, totCap, cap, dp);
        ll benefit2 = INT_MIN;
        if (totCap + weights[i] <= cap)
        {
            benefit2 = benefits[i] + knap_sack(weights, benefits, i + 1, totCap + weights[i], cap, dp);
        }
        dp[i][totCap] = max(benefit1, benefit2);
    }

    return dp[i][totCap];
}
void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}
int main()
{
    io();

    int n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1));
    vector<int> weights(n);
    vector<ll> benefits(n);

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i] >> benefits[i];
    }

    cout << knap_sack(weights, benefits, 0, 0, k, dp);
}