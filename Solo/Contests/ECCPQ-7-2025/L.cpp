
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

    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    set<int> sets;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (sets.find(k - v[i]) != sets.end())
        {
            ans++;
            sets.clear();
        }

        else
            sets.insert(v[i]);
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