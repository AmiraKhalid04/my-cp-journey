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
ll gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
bool getBit(ll num, int i)
{
    return ((num & (1ll << i)) != 0);
}
ll lcm(ll a, ll b)
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
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    int splits = 0;
    vector<bool> split(n, 0);

    for (int i = 0; i < s.size(); i++)
    {
        if (i != n - 1 && s[i + 1] < s[i])
        {
            split[i] = 1;
            k--;
        }
        // trailig zeros

        else if (s[i] == '0' && i != n - 1 && s[i + 1] != '0')
        {
            split[i] = 1;
            k--;
        }
    }
    if (k <= 0)
    {
        cout << -1 << endl;
        return;
    }
    else if (k > 1)
    {

        for (int i = 0; i < s.size(); i++)
        {
            if (!split[i])
            {

                split[i] = 1;
                k--;
            }
            if (k == 1)
                break;
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (split[i])
            cout << s[i] << " ";
        else
            cout << s[i];
    }

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    IOFilesOpen();

    int t;
    cin >> t;
    while (t--)

        solve();
    return 0;
}