
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
bool getBit(int num, int i)
{
    return ((num & (1 << i)) != 0);
}
void solve()
{
    int a, b, l, r;
    cin >> a >> b >> l >> r;
    int ok = 0;

    vector<int> bits;

    for (int i = 0; i < 32; i++)
    {
        if (getBit(b, i) && !getBit(a, i))
        {
            cout << "NO" << endl;
            return;
        }
        else if (!getBit(b, i) && getBit(a, i))
        {
            bits.push_back(i);
        }
    }
    for (int i = 0; i < bits.size(); i++)
    {
        int num = pow(2, bits[i]);

        if (num >= l && num <= r)
            ok++;

        else if (getBit(l, bits[i]) || getBit(r, bits[i]))
            ok++;

        else
        {
            if (num + l <= r)
                ok++;
        }
    }

    if (ok == bits.size())
        cout << "YES\n";
    else
        cout << "NO\n";
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