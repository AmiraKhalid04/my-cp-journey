#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128_t lll;
void IOFilesOpen()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}
ll a, b, c, d;
ll ans = -1;

lll solveCubic(ll x)
{
    lll x_ = x; // Convert to __int128
    return (lll)a * x_ * x_ * x_ + (lll)b * x_ * x_ + (lll)c * x_ + (lll)d;
}

ll solveQuad(ll x)
{
    return 3 * a * x * x + (2 * b * x) + c;
}

bool binarySearch(ll l, ll r, bool increasing)
{
    while (l <= r)
    {

        ll mid = l + (r - l) / 2;
        lll sol = solveCubic(mid);

        if (sol == 0)
        {
            ans = mid;
            cout << "Yes\n";

            cout << ans << endl;
            return 1;
        }
        else if (sol > 0)
        {
            if (increasing)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else if (sol < 0)
        {
            if (increasing)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return 0;
}

void solve()
{

    cin >> a >> b >> c >> d;

    ll disc = (4LL * b * b) - (12LL * a * c);

    bool increasing = 0;
    if (a > 0)
        increasing = true;
    if (disc > 0)
    {
        double minRoot = ((-2LL * b) - (sqrt(disc))) / (6 * a);
        double maxRoot = ((-2LL * b) + (sqrt(disc))) / (6 * a);

        // first loop max->1e9

        if (binarySearch(ceil(maxRoot), 1e9, increasing))
            return;

        // second loop min->max

        if (binarySearch(floor(minRoot), ceil(maxRoot), !increasing))
            return;

        // third loop -1e9 -> min

        if (binarySearch(-1e9, floor(minRoot), increasing))
            return;
    }

    else if (disc == 0)
    {
        double minRoot = (-2 * b) - (((sqrt(disc))) / (6 * a));
        double maxRoot = (-2 * b) + (((sqrt(disc))) / (6 * a));

        if (binarySearch(ceil(maxRoot), 1e9, increasing))
            return;
        if (binarySearch(-1e9, ceil(maxRoot), !increasing))
            return;
    }

    else
    {

        if (solveQuad(0) > 0)
            increasing = true;

        if (binarySearch(-1e9, 1e9, increasing))
            return;
    }

    cout << "No\n";
}
int main()
{
    // Please revise data types and casting
    // IOFilesOpen();
    // Just commit for testing
    int q;
    cin >> q;
    while (q--)
        solve();
}