#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
int getBit(int num, int i)
{
    return ((num & (1 << i)) != 0);
}
ll fastPower(ll x, ll n, ll m = 1e9 + 7)
{
    ll res = 1;
    x = x % m;

    while (n > 0)
    {
        if (n % 2)
            res = res * x % m;
        x = x * x % m;
        n /= 2;
    }

    return res;
}
void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}
void BFS(int root, vector<vector<int>> &adj_list,
         vector<int> &vis, vector<int> &level)
{
    queue<int> q;

    q.push(root);

    vis[root] = 1;
    level[root] = 0;
    int p = root;
    while (q.empty() == 0)
    {
        p = q.front();
        // cout << p<<" ";
        q.pop();
        for (int i = 0; i < adj_list[p].size(); i++)
        {
            if (vis[adj_list[p][i]] == 0)
            {
                vis[adj_list[p][i]] = 1;
                level[adj_list[p][i]] = level[p] + 1;
                q.push(adj_list[p][i]);
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    int edges = n - 1;
    vector<vector<int>> adj_list(n);
    vector<int> vis(n, 0);
    vector<int> level(n);
    vector<vector<int>> levels(n);
    vector<int> levVisit(n, 0);

    while (edges--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    BFS(0, adj_list, vis, level);

    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        levels[level[i]].push_back(i);
        mx = max(mx, level[i]);
    }

    int time = 2;
    levVisit[1] = 1;

    int currL = 1;
    int currR = 1;

    bool r = 1, l = 1;

    while (r || l)
    {
        currL += time;

        if (currL <= mx && !levVisit[currL])
        {
            levVisit[currL] = 1;

            time++;
            // lev = currL;
        }

        else
        {
            l = 0;
        }

        currR -= time;

        if (currR >= 0 && !levVisit[currR])
        {
            levVisit[currR] = 1;

            time++;
            // lev = currL;
        }
        else if (abs(currR) <= mx && !levVisit[currR])
        {
            levVisit[currR] = 1;

            time++;
        }
        else
        {
            r = 0;
        }
    }

    int ans = 0;
    for (int i = 2; i <= mx; i++)
    {
        if (!levVisit[i])
            ans += levels[i].size();
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    io();

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
