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
    vector<double> freq(26);
    double sum = 0;

    for (int i = 0; i < 26; i++)
    {
        cin >> freq[i];
        sum += freq[i];
    }
    // cout << sum << endl;
    double ans = 0;
    ans = -1 + sqrt(1.0 + (8.0 * sum));
    ans /= 2.0;

    cout << ll(ans) << endl;
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