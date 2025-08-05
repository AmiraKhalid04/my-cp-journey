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
    vector<int> v(n);

    set<int> sets;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        while (v[i] % 2 == 0)
        {
            v[i] /= 2;
        }

        sets.insert(v[i]);
    }

    cout << sets.size() << endl;
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
