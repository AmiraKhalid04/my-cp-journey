
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

vector<vector<pair<ll, ll>>> adj;
vector<bool> visited;
vector<ll> path;
vector<ll> subtreeSize;

int dfs(int u)
{
    if (visited[u])
    {
        return 0;
    }

    for (auto [v, w] : adj[u])
    {
        if (!visited[v])
        {
            path[v] += path[u];
            path[v] += w;
            subtreeSize[u] += dfs(v);
        }
    }
    return subtreeSize[u];
}

void solve()
{
    int n;
    ll x;

    cin >> n >> x;

    adj.assign(n, vector<pair<ll, ll>>());
    visited.assign(n, false);
    subtreeSize.assign(n, 1);
    path.assign(n, 0);

    vector<int> p(n, -1);

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;

        u--;
        v--;

        p[v] = u;

        adj[u].push_back({v, w});
    }

    int root = 0;

    for (int i = 0; i < n; i++)
    {
        if (p[i] == -1)
        {
            root = i;
        }
    }

    dfs(root);
    ll ans = accumulate(path.begin(), path.end(), 0ll);
    ll total = ans;

    for (int v = 0; v < n; v++)
    {
        if (v == root || x >= path[v])
        {
            continue;
        }
        ll curr = total - subtreeSize[v] * (path[v] - x);
        ans = min(ans, curr);
    }

    cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
