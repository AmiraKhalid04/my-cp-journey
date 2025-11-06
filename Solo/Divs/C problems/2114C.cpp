
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

vector<ll> score(10, 0);
void IOFilesOpen()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int cnt = 1;

    for (auto it = v.begin(); it != v.end();)
    {
        int val = *it;
        auto it2 = upper_bound(it, v.end(), val + 1);

        if (it2 != v.end())

        {
            cnt++;
            it = it2;
        }
        else
            it++;
    }

    cout << cnt << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout.tie(0);
    IOFilesOpen();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}