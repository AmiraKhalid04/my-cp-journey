
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
void DFSrec(vector<vector<pair<int, int>>> &adj,
            int u, vector<bool> &visited, vector<int> &dp)
{
    visited[u] = true;

    for (auto i : adj[u])
    {
        if (visited[i.first] == false)

        {
            if (i.second == -1)
                dp[0]++;
            DFSrec(adj, i.first, visited, dp);
        }
    }
    return;
}
void DFSreroot(vector<vector<pair<int, int>>> &adj,
               int u, vector<bool> &visited, vector<int> &dp)
{
    visited[u] = true;

    for (auto i : adj[u])
    {
        if (visited[i.first] == false)

        {
            if (i.second == -1)
                dp[i.first] = dp[u] - 1;
            else
                dp[i.first] = dp[u] + 1;
            DFSreroot(adj, i.first, visited, dp);
        }
    }
    return;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj_list(n);
    vector<bool> visited(n, 0);
    vector<int> dp(n, 0);
    int edges = n - 1;

    while (edges--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj_list[u].push_back({v, 1});
        adj_list[v].push_back({u, -1});
    }
    DFSrec(adj_list, 0, visited, dp);
    // cout << dp[0] << "\n";
    visited.assign(n, 0);

    DFSreroot(adj_list, 0, visited, dp);
    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dp[i]);
    }

    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == ans)
            cout << i + 1 << " ";
    }

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
