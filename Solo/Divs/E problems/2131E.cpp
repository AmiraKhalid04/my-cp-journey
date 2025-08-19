
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

bool solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    if (a[n - 1] != b[n - 1])
        return false;

    for (int i = 0; i < n - 1; i++)
    {
        if ((a[i] != b[i]) && ((a[i] ^ a[i + 1]) != b[i]) && ((a[i] ^ b[i + 1]) != b[i]))
            return false;
    }

    return true;
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
        if (solve())
            cout << "yes\n";
        else
            cout << "no\n";

    return 0;
}