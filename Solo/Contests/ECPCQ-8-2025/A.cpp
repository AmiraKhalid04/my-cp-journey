
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

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second > ans)
            ans += v[i].second - ans + 1;

        else
            ans++;
    }

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout.tie(0);
    IOFilesOpen();
    // int t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}