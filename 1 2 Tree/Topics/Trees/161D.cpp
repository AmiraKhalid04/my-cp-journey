
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

void DFSrec(vector<vector<int>> &adj,
            int u, vector<bool> &visited, vector<vector<int>> &dp, int k, ll &ans)
{
    visited[u] = true;
    // count of vertices of distance zero from me
    dp[u][0] = 1;

    for (auto i : adj[u])
    {
        if (visited[i] == false)

        {
            DFSrec(adj, i, visited, dp, k, ans);
            for (int j = 0; j <= k; j++)
            {
                ans += 1LL * dp[u][j] * dp[i][k - j - 1];
                if (j)
                    dp[u][j] += dp[i][j - 1];
            }
        }
    }
    return;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj_list(n);
    vector<bool> visited(n, 0);
    vector<vector<int>>
        dp(n, vector<int>(k + 1, 0));
    int edges = n - 1;
    ll ans = 0;

    while (edges--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    DFSrec(adj_list, 0, visited, dp, k, ans);
    cout << ans << "\n";
    return;
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

    return solve(), 0;
}
