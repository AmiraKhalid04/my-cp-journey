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

bool canReachAziza(ll i, int t, int n, int z, ll k)
{
    i = ((i % n));

    if (t < 0)
        return 0ll;

    if (i % n == z || (i == z))
        return 1ll;
    ;

    if (dp[i] == -1)
    {
        ll op1 = canReachAziza(i + k, t - 1, n, z, k);
        ;
        ll op2 = canReachAziza(i + k + 1, t - 1, n, z, k);
        dp[i] = op1 || op2;
    }

    return dp[i];
}

void solve()
{
    ll n, t, k, b, z;
    cin >> n >> t >> k >> b >> z;
    b--, z--;
    dp.assign(n + 1, -1);

    if (canReachAziza(b, t, n, z, k))
        cout << "yes";
    else
        cout << "no";
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