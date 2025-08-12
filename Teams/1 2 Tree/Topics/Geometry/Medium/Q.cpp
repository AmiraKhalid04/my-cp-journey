
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const double EPS = 1e-7;

void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void solve()
{
    ld x, y, t;
    cin >> x >> y >> t;
    ld d = sqrtl(x * x + y * y);
    if (d - t <= EPS)
        cout << setprecision(10) << d << endl;

    else

    {

        ld xr = sqrtl(t * t - y * y);

        cout << setprecision(10) << t + x - xr << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(0);
    io();
    // freopen("cross.in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
