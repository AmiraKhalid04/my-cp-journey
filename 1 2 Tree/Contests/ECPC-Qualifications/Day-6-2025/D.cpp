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
    string s;
    cin >> s;

    if (s == "Black")
    {
        cout << "Contestant";
    }

    else if (s == "Green")
    {
        cout << "Coach";
    }
    else
    {
        cout << "Judge";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    io();

    // int t;
    // cin >> t;

    // while (t--)
    solve();

    return 0;
}
