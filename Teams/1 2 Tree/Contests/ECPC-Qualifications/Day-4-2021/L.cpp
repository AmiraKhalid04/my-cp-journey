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
bool ansExist(int l, int r, vector<vector<int>> &freqS, vector<int> &freqP)
{
    vector<int> chars;
    int mx = -1;
    int freqProblem = 0;
    // for (int i = l; i <= r; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            int pre = freqS[r][j];
            if (l)
                pre -= freqS[l - 1][j];

            if (pre < freqP[j])
            {
                chars.push_back(j);
                freqProblem = pre;
            }
            if (freqP[j] == 0)
            {
                mx = max(mx, pre);
            }
        }
    }
    if (chars.size() > 1)
        return false;
    if (chars.size() == 0)
        return true;
    // which character to choose?

    if (freqProblem + mx >= freqP[chars[0]])
        return true;
    return false;
}

void solve()
{
    string s, p;
    cin >> s >> p;

    int n = s.size();
    vector<vector<int>> freqS(n, vector<int>(26, 0));
    vector<int> freqP(26, 0);
    // prefix sum
    freqS[0][s[0] - 'a']++;
    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            freqS[i][j] = freqS[i - 1][j];
            if (j == s[i] - 'a')
                freqS[i][j]++;
        }
    }
    for (int i = 0; i < p.size(); i++)
    {
        freqP[p[i] - 'a']++;
    }
    // binary search
    bool noAns = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i, r = n - 1;
        int res = -2;
        if (!noAns)
        {
            while (l <= r)
            {
                int mid = l + (r - l) / 2;

                if (ansExist(i, mid, freqS, freqP))
                {
                    res = mid;

                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        cout << res + 1 << " ";
        if (res == -2)
            noAns = 1;
    }
    cout << "\n";
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