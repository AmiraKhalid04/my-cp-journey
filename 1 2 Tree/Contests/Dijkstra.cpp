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
void DFSrec(vector<vector<pair<int, ll>>> &adj, int u, vector<bool> &visited, stack<int> &stk)
{
    visited[u] = true;
    for (auto i : adj[u])
    {
        if (visited[i.first] == false)
        {
            DFSrec(adj, i.first, visited, stk);
        }
    }
    stk.push(u);
}
void topological(vector<vector<pair<int, ll>>> &adj, stack<int> &stk, int v, int i)
{
    vector<bool> visited(v + 1, false);
    ;

    DFSrec(adj, i, visited, stk);
}

vector<ll> shortestpath(vector<vector<pair<int, ll>>> &adj, stack<int> &stk, int source)
{
    int v = adj.size();
    vector<ll> dist(v, LLONG_MAX);
    dist[source] = 0;

    while (stk.empty() != true)
    {
        int u = stk.top();
        stk.pop();

        for (auto i : adj[u])
        {
            if (dist[i.first] > dist[u] + i.second)
                dist[i.first] = dist[u] + i.second;
        }
    }
    return dist;
}

vector<ll> dp;
ll ans = 0;
const int N = 1e6 + 10;
vector<ll> dist;
vector<ll> parent;
void init()
{
    dist.assign(N, LLONG_MAX);
    parent.assign(N, -1);
}

void Dijkstra()
{
    // only for testing
}

void solve()
{
    int n, edges;

    cin >> n >> edges;

    vector<vector<pair<int, ll>>> adj_list(n);

    while (edges--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    init();

    int src = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    dist[src] = 0;

    // call Dijkstra
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int q;
    cin >> q;
    while (q--)

        solve();

    return 0;
}