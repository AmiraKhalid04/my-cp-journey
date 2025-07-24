
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
bool customCompare(const std::pair<int, ll> &a, const std::pair<int, ll> &b)
{
    if (a.second == b.second)
    {
        return score[a.first] > score[b.first];
    }
    return a.second > b.second;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> lit(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i + v[i] < n)
            lit[i + v[i]]++;
    }
    for (int i = 1; i < n; i++)
    {
        lit[i] = lit[i] + lit[i - 1];
    }
    int cnt = 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, cnt - lit[i]);
        cnt++;
    }
    cout << ans << endl;
}

int main()
{
    IOFilesOpen();

    // int t;
    // cin >> t;
    // while (t--)

    solve();
    return 0;
}