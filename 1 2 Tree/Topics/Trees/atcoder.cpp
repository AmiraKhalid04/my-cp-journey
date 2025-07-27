
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

vector<int> ans(2002, 0);
void DFSrec(vector<vector<int>> &adj,
            int u, vector<bool> &visited, int cnt, int k)
{
    visited[u] = true;
    if (cnt > k)
        ans[u]++;

    for (auto i : adj[u])
    {
        if (visited[i.first] == false)

        {
            DFSrec(adj, i.first, visited, cnt + 1, k);
        }
    }
    return;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj_list(n);
    vector<bool> vis(n, 0);
    int edges = n - 1;
    while (edges--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    if (k % 2 == 0)
        for (int i = 0; i < n; i++)
            DFSrec(adj_list, i, vis, 0, k / 2);

    else
    {
        }
    int vertices = INT_MAX;
    for (int i : ans)
    {
        vertices = min(vertices, ans[i]);
    }

    cout << vertices;

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
