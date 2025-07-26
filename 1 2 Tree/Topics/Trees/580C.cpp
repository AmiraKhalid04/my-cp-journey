
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
int ans = 0;
void DFSrec(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<int> &cats, int cnt, int m, vector<bool> &isLeaf)
{
    visited[u] = true;
    if (cats[u])
    {
        cnt++;
        if (cnt > m)
            return;
    }
    else
        cnt = 0;
    for (auto i : adj[u])
    {
        if (visited[i] == false)

        {
            DFSrec(adj, i, visited, cats, cnt, m, isLeaf);
        }
    }

    if (adj[u].size() == 1 && u && cnt <= m)
    {
        ans++;
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> cats(n);
    vector<bool> vis(n, 0);
    vector<bool> isLeaf(n, 1);

    vector<vector<int>> adj_list(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cats[i];
    }
    int edges = n - 1;
    while (edges--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        isLeaf[u] = 0;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    DFSrec(adj_list, 0, vis, cats, 0, m, isLeaf);
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
