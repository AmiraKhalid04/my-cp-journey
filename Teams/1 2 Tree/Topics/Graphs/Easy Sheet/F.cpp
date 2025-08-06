#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

vector<bool> visited;
ll sum = 0;
void IOFilesOpen()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void dfs(int v, vector<vector<int>> &adj, vector<ll> &nodes)
{
    visited[v] = true;
    sum += nodes[v];

    for (int u : adj[v])
    {
        if (!visited[u])
        {
            dfs(u, adj, nodes);
        }
    }
}
vector<ll> dp;

int maxChambers(int i, int n, int m, int l, vector<int> &pos, vector<ll> &vis)
{

    if (i > l || i < 0)
        return 0;

    if (vis[i])
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int current = pos[i];

    vis[i] = true;

    int op1 = maxChambers(i + n, n, m, l, pos, vis);
    int op2 = maxChambers(i - m, n, m, l, pos, vis);
    vis[i] = false;
    dp[i] = current + max(op1, op2);

    return dp[i];
}

void solve()
{

    int l, f, n, m;
    cin >> l >> f >> n >> m;
    l++;
    dp.assign(l + 1, -1);
    vector<ll> vis(l + 1, 0);

    vector<int> pos(l + 1);
    for (int i = 0; i < f; i++)
    {
        int x;
        cin >> x;
        pos[x]++;
    }

    cout << maxChambers(0, n, m, l, pos, vis);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    solve();

    return 0;
}