#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.out", "w", stdout);
}

vector<ll> primes;

void sieve(int n)
{
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
}
// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     if (!(n % m))
//     {

//         cout << 0;
//         return;
//     }

//     cout << min(m - (n % m), n % m);
// }

void solveL()
{
    int n;
    cin >> n;

    int ans = (n / 4) * 3;
    ans += n % 4;
    cout << ans << endl;
}

void solveJ()
{
    string s, t;
    cin >> s >> t;

    char prevA = s[0];
    string resA;
    resA = resA + prevA;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != prevA)
        {
            resA = resA + s[i];
        }
        prevA = s[i];
    }

    char prevB = t[0];
    string resB;
    resB = resB + prevB;
    for (int i = 1; i < t.size(); i++)
    {
        if (t[i] != prevB)
        {
            resB = resB + t[i];
        }
        prevB = t[i];
    }

    if (resA == resB)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

void solveK()
{
    string s;
    cin >> s;

    int i = 0;
    int j = s.size() - 1;

    bool ans = true;

    while (i < j)
    {
        int x = s[i] - '0';
        if ((s[i] - '0') >= 4)
        {
            x = 7 - (s[i] - '0');
        }

        int y = s[j] - '0';
        if ((s[j] - '0') >= 4)
        {
            y = 7 - (s[j] - '0');
        }

        if (x != y)
        {
            ans = false;
            break;
        }

        i++;
        j--;
    }

    if (ans)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

void solveG()
{
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    ll ans = 1ll;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ans = ll(ans * abs(arr[i])) % MOD;
    }

    cout << ans << endl;
}

void solve()
{
    string s, k;
    cin >> s >> k;

    int f = 0;
    int ns = s.size();
    int nk = k.size();

    if (nk != 2 * ns - 1 && nk != 2 * ns)
    {
        cout << "NO\n";
        return;
    }
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == k[j])
        {
            j++;
            if (j < k.size())
            {
                if (k[j] == s[i])
                    j++;

                else if (i < ns && k[j] == s[i + 1] && !f)
                    f += 1;

                else
                {
                    cout << "NO\n";
                    return;
                }
            }

            else
            {
                if (f == 1 || f == 0)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
                return;
            }
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

void solveA()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll xo = v[0];
    ll sum = v[0];
    int p = 0;
    bool ne = 0;

    for (int i = 1; i < n; i++)
    {

        if (ne)
        {
            xo = v[i];
            sum = v[i];
            ne = 0;
        }

        else
        {
            xo ^= v[i];
            sum += v[i];
            if (sum <= xo)
            {
                if (i == n - 1)
                {

                    if (p >= 1)
                    {
                        cout << p << endl;
                        return;
                    }
                    cout << -1 << endl;
                    return;
                }
            }
            else
            {

                p++;
                ne = 1;
            }
        }
    }
    if (p >= 1)
        cout << p << endl;
    else
        cout << -1 << endl;
}

void solveB()
{

    int n;
    cin >> n;

    sieve(n);

    ll last = 2;
    cout << 2 << " ";
    ll j = 3;
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cout << j << " ";
            last = j;
            j += 2ll;
        }

        else
        {

            cout << last * 2ll << " ";
        }
    }

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    io();

    int t;
    cin >> t;
    while (t--)
        solveB();

    return 0;
}