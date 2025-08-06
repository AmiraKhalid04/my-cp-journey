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
    int n;
    cin >> n;
    string s;

    cin >> s;

    int firstChar = 0; // still  not interrupted
    char firstC = s[0];
    int cnt1 = 0;
    int start = 0;

    int i = 0;

    while (i < n && s[i] == firstC)
    {
        start++;
        i++;
    }
    cnt1 = start;
    int ans = start;

    for (i; i < n; i++)
    {
        cnt1 = start;
        while (s[i] == firstC && i < n)
        {
            cnt1++;
            i++;
        }
        ans = max(ans, cnt1);
    }

    ;
    int cnt2 = 0;

    int ans2 = 0;
    for (int j = 1; j < n; j++)
    {
        cnt2 = 1;
        while (j < n && s[j] != firstC && s[j] == s[j - 1])
        {
            cnt2++;
            j++;
        }
        ans2 = max(cnt2, ans2);
    }

    ans = max(ans, ans2);
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