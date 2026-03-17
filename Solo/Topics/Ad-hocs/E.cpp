#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void io()
{

    freopen("mosalah.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
}

vector<ll> sieve(int n)
{
    vector<ll> primes;

    vector<char> comp(n + 1, false);
    comp[0] = comp[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!comp[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && (i * primes[j]) <= n; j++)
        {
            comp[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    return primes;
}
ll fastPower(ll x, ll n, ll m = 1e9 + 7)
{
    ll res = 1;
    x = x % m;

    while (n > 0)
    {
        if (n % 2)
            res = res * x % m;
        x = x * x % m;
        n /= 2;
    }

    return res;
}

void solve()
{
    int t, s;
    cin >> t >> s;
    cout << min(t, s);
}
int main()
{
    io();
    // int q;
    // cin >> q;
    // while (q--)
    {
        solve();
    }

    return 0;
}