#include <bits/stdc++.h>

typedef long long ll;

const int MOD = 1e9 + 7;

using namespace std;

vector<ll> linearSieve(int n)
{
    vector<ll> primes;
    vector<char> composite(n + 1, false);
    composite[0] = composite[1] = true;

    for (int i = 2; i <= n; i++)
    {
        if (!composite[i])
        {
            primes.push_back(i);
        }
    }

    return primes;
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> a(m);
        vector<int> freq(n + 1);

        for (int i = 1; i <= n; i++)
        {
            freq[i] = 1;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
            freq[a[i]] = 0;
        }
        int mn = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            if (freq[i])
            {
                mn = i;
                break;
            }
        }
        if (mn < a[0])
            cout << "No\n";

        else
        {
            cout << "Yes\n";

            for (int i = 1; i <= n; i++)
            {
                if (freq[i])
                    cout << i << " ";
            }

            for (int i = 0; i < a.size(); i++)
            {
                cout << a[i];

                if (i != m - 1)
                    cout << " ";
            }

            cout << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    solve();

    return 0;
}