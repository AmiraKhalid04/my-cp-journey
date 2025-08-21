
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
    vector<int> w(10);

    for (int i = 0; i < 10; i++)
        cin >> w[i];

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 10; j++)
        {
            int x;
            cin >> x;
            ans[i] += (x * w[j]);
        }

    sort(ans.rbegin(), ans.rend());

    cout << accumulate(ans.begin(), ans.begin() + k, 0);
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