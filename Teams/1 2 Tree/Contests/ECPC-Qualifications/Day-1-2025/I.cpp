
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
    double l;
    double k;
    cin >> n >> l >> k;
    ll ans = 0;

    while (n--)
    {
        ll x, y;
        cin >> x >> y;

        ll mag = ceil(sqrt(x * x + y * y));

        if (mag > l)
        {

            ll inc = ceil((mag - l) / k);

            ll multi = ceil(log2(mag / l));

            ans += min(inc, multi);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    IOFilesOpen();
    // cout << sqrt(5);
    int t;
    cin >> t;
    while (t--)
        // cout << log2(sqrt(2) * 1e9);
        solve();
    return 0;
}
