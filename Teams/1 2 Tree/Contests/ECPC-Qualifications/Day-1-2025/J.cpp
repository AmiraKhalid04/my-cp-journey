#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

// prob tle
void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);

    for (auto &x : a)
    {
        cin >> x;
    }

    vector<ll> prefix(n);
    vector<ll> suffix(n);

    prefix[0] = a[0];
    suffix[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], a[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], a[i]);
    }

    ll ans = LLONG_MAX;
    ll mx = -1;

    for (int i = 1; i < n - 1; i++)
    {

        ans = min(ans, a[i] + prefix[i - 1] + suffix[i + 1]);
        mx = max(a[i], mx);
    }

    cout << min(ans, mx + a[0] + a[n - 1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    io();

    // int t;
    // cin >> t;

    // while (t--)
    solve();

    return 0;
}
