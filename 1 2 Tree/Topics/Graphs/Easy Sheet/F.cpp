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
ll ans = 0;

int maxChambers(int i, int n, int m, int l, vector<int> &pos)
{

    if (i > l || i < 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int op1 = pos[i] + maxChambers(i + n, n, m, l, pos);
    int op2 = pos[i] + maxChambers(i - m, n, m, l, pos);

    dp[i] = op1 + op2;

    return dp[i];
}

void solve()
{

    int l, f, n, m;
    cin >> l >> f >> n >> m;
    l++;
    dp.assign(l + 1, -1);

    vector<int> pos(l + 1);
    for (int i = 0; i < f; i++)
    {
        int x;
        cin >> x;
        pos[x]++;
    }

    cout << maxChambers(0, n, m, l, pos);
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