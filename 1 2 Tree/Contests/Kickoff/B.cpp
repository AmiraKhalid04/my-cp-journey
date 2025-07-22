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
int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}
void primeFactors(ll &n, vector<int> &f)
{
    while (n % 2ll == 0)
    {
        f.push_back(2);
        n /= 2ll;
    }

    for (ll i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            f.push_back(i);
            n /= i;
        }
    }

    if (n > 2ll)
    {
        f.push_back(n);
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    ll fact = n * m;
    vector<int> f;
    primeFactors(fact, f);
    map<int, int> mapo;
    ll ans = 1;
    for (int i = 0; i < f.size(); i++)
        mapo[f[i]]++;

    for (auto it = mapo.begin(); it != mapo.end(); it++)
    {
        if (it->second % 2)

        {
            ans *= it->first;
        }
    }
    cout << ans << endl;
}

int main()
{
    IOFilesOpen();

    int t;
    cin >> t;
    while (t--)

        solve();
    return 0;
}