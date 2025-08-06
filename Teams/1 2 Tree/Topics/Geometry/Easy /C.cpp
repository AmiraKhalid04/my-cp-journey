
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

int DFSrec(vector<vector<int>> &adj,
           int u, vector<bool> &visited, vector<vector<int>> &dp, int k)
{

    visited[u] = true;
    // count of vertices of distance zero from me
    dp[u][0] = 1;
    int ans = 0;

    for (auto i : adj[u])
    {
        if (visited[i] == false)

        {
            ans += DFSrec(adj, i, visited, dp, k);
            for (int j = 0; j < k; j++)
            {
                ans += (dp[u][j] * dp[i][k - j - 1]);
                if (j)
                    dp[u][j] += dp[i][j - 1];
            }
        }
    }
    if (ans == 4)
        return 4;
    return ans;
}

bool ansExist(int s, int m, vector<int> &v)
{

    // no of rectangles in the nest
    int cnt = 1;
    // smallest elemnt in the nest
    int el = v[0];

    for (int i = 0; i < v.size(); i++)
    {
        if (el - v[i] >= s)
        {
            cnt++;
            el = v[i];
        }
    }

    if (cnt >= m)
        return true;

    return false;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.rbegin(), v.rend());

    int m;
    cin >> m;
    int l = 0, r = 1e5;
    int ans = 0;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        // mid is s

        if (ansExist(mid, m, v))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    IOFilesOpen();

    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
