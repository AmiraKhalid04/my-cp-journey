#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}
ll fastPower(ll x, ll n, ll m = 1e9 + 7)
{
    ll res = 1;
    x = x % m;

    while (n > 0)
    {
        if (n % 2)
            res = res * x % m;
        x = x * x % m;
        n /= 2;
    }

    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> aAns;
    vector<int> bAns;
    vector<int> aSorted;
    vector<int> bSorted;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            aAns.push_back(a[i]);
            bAns.push_back(b[i]);

            aSorted.push_back(a[i]);
            bSorted.push_back(b[i]);
        }
    }
    sort(aSorted.begin(), aSorted.end());
    sort(bSorted.begin(), bSorted.end());

    vector<int> ans;
    ll answer = 0;
    int k = 0;

    for (int i = 0; i < aAns.size(); i++)
    {
        int cnt = 0;

        // first element >= me

        auto it2 = lower_bound(bSorted.begin() + k, bSorted.end(), aSorted[i]);
        // index of answer
        int idx = it2 - bSorted.begin();

        if (idx != 0)
        {
            // answer += (fastPower(2, idx - i) % mod - 1) % mod;

            answer = (answer + (fastPower(2, idx - i) - 1) % mod) % mod;

            // answer -= (fastPower(2, k - i) % mod - 1) % mod;

            answer = (answer - (fastPower(2, k - i) - 1) % mod + mod) % mod;

            k = idx;
        }
    }
    cout << answer % mod << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    io();

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
