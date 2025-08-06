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
    int x;
    cin >> x;
    cout << 100 - x;
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
