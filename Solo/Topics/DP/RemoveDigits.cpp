
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
    string s;
    cin >> s;
    totSum = stoi(s);
    int n = s.size();
    arr.resize(s.size());
    dp.assign(totSum + 1, 1e8);

    for (int i = 0; i < n; i++)
    {

        arr[i] = s[i] - '0';
    }

    dp[0] = 0;
    for (int sum = 1; sum <= totSum; sum++)
    {
        string str = to_string(sum);
        for (int j = 0; j < str.size(); j++)
        {
            if ((str[j] != '0'))
                dp[sum] = min(dp[sum], 1 + dp[sum - (str[j] - '0')]);
        }
    }

    cout << dp[totSum];
}