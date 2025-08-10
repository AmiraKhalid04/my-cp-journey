
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // v[n] = (v[0] + 360);

    sort(v.begin(), v.end());

    int mx = -1;
    mx = 360 - (v[n - 1] - v[0]);
    for (int i = 0; i < n - 1; i++)
    {
        mx = max(v[i + 1] - v[i], mx);
    }

    cout << (360 - mx + k - 1) / k << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(0);
    io();
    // freopen("jaguar.in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
