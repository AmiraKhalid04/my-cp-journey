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
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
    }

    if (m < n - 1)
    {
        cout << -1 << endl;

        return;
    }

    m -= (n - 1);

    ll cost = 0LL;

    for (int i = 2; i <= n; i++)
    {
        cost += (1 + i);
    }

    ll i = 2LL;

    set<pair<ll, int>> sets;
    vector<int> last(n + 1);

    for (int i = 2; i < n; i++)
    {
        last[i] = i + 1;
        sets.insert({i + last[i], i});
    }

    while (m)
    {
        auto it = sets.begin();
        cost += it->first;
        m--;

        sets.erase(it);
        if (it->first - it->second < n)
            sets.insert({it->first + 1LL, it->second});
    }

    cout << cost << endl;
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
