
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
    int x, a, b;
    cin >> x >> a >> b;

    cout << x - (a + b);
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