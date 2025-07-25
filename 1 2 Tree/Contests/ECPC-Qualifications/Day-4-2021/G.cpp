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
    string key;
    cin >> key;
    set<char> keys;
    string ans = "";

    for (int i = 0; i < key.size(); i++)
    {
        keys.insert(key[i]);
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (keys.find(s[i]) != keys.end())
        {
            if (i != s.size() - 1 && s[i + 1] == 'k')
            {
                ans += s[i];
                i++;
            }
            else
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
        else
        {
            ans += s[i];
        }
    }
    cout << ans << endl;
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