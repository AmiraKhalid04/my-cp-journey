#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;

vector<int> primes;

void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.out", "w", stdout);
}

// map<int, int> primeFactors(int n)
// {
//     map<int, int> factors;

//     for (int prime : primes)
//     {
//     }
// }

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
ll fast_power(ll x, ll n, ll m = 1e9 + 7)
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

ll mod = 1000000007;

ll fastpow_nomod(ll b, ll p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return b;
    ll res = fast_power(b, p / 2);
    res = (res * res) % mod;
    if (p & 1)
    {
        res = (res * b) % mod;
    }
    return res;
}

bool isComp(ll n, ll a, ll d, int s)
{
    ll x = fastPower(a, d, n);

    if (x == 1 || x == n - 1)
        return false;

    for (int i = 1; i < s; i++)
    {
        x = x * x % n;

        if (x == n - 1)
            return false;
    }

    return true;
}

bool isPrime(ll n)
{
    if (n == 0 || n == 1)
        return false;

    int s = 0;
    ll d = n - 1;

    while (!(d % 2))
    {
        d /= 2;
        s++;
    }

    for (int a : {2, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
            return true;

        if (isComp(n, a, d, s))
            return false;
    }

    return true;
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

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

void normalPrimeFactors(int &n, vector<int> &f)
{
    while (n % 2 == 0)
    {
        f.push_back(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            f.push_back(i);
            n /= i;
        }
    }

    if (n > 2)
    {
        f.push_back(n);
    }
}

void solve()
{
    int m, n;
    cin >> m >> n;
    cout << n - 1 << endl;
}

void solveShady()
{
    ll m, n;
    cin >> m >> n;

    if (m == 1)
    {
        ll ans;
        if (n == 1)
        {
            ans = 0;
        }
        else
        {
            ans = ((n - 1ll) * n) / 2ll;
        }
        cout << ans << "\n";
    }
    else
    {
        ll count = 1;
        ll cost = 0;
        ll total = 1;
        ll sum = 0;

        while (total <= n)
        {
            sum += (count * cost);
            count *= m;
            cost++;
            total += count;
        }

        if (total != n)
        {
            ll rem = n - (total - count);
            sum += (rem * cost);
        }
        cout << sum << "\n";
    }
}

void solve2()
{
    ll m, n;

    cin >> m >> n;

    if (n == 1 || n <= m)
    {
        cout << n - 1 << endl;
        return;
    }
    if (m == 1)
    {
        cout << n * (n - 1) / 2 << endl;
        return;
    }
    int height = ceil(log2(n * (m - 1ll) + 1ll) / log2(m));
    ll levels = height - 1;
    ll completeNodes = (1ll - powl(m, levels)) / (1ll - m);

    ll llNodes = n - completeNodes;

    ll ans = 1ll - ((levels)*powl(m, levels - 1ll)) + ((levels - 1ll) * powl(m, levels));
    ans = ans / ((1ll - m) * (1ll - m));
    ans *= m;

    ans += (llNodes)*levels;

    cout << ans << endl;
}

void dfs(int root, vector<vector<bool>> &adj, vector<bool> &vis)
{
    vis[root] = true;

    for (int v = 1; v < adj[root].size(); v++)
    {
        if (!vis[v] && v != root)
        {
            dfs(v, adj, vis);
        }
    }
}

// void DFSrec(vector<vector<pair<int, ll>>> &adj, int u, vector<bool> &visited, stack<int> &stk)
// {
//     visited[u] = true;
//     for (auto i : adj[u])
//     {
//         if (visited[i.first] == false)
//         {
//             DFSrec(adj, i.first, visited, stk);
//         }
//     }
//     stk.push(u);
// }

void solveN()
{
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
    vector<int> edges(n + 1, 0);

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        adj[u][v] = true;
        adj[v][u] = true;

        edges[u]++;
        edges[v]++;
    }

    int connectedCount = 0;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited);
            connectedCount++;
        }
        else
        {
            continue;
        }
    }

    if (connectedCount > x)
    {
        cout << -1 << endl;
        return;
    }

    // cout << connectedCount << endl;

    if (connectedCount == x)
    {
        cout << 0 << endl;
        cout << 0 << " " << 0 << endl;
        return;
    }

    queue<int> process;

    for (int i = 1; i <= n; i++)
    {
        if (edges[i] == 1)
        {
            // cout << i << endl;
            process.push(i);
        }
    }

    int first = 0;
    int second = 0;

    while (process.size() > 0)
    {
        // cout << "length" << " " << process.size() << endl;
        int curr = process.front();
        // cout << "popped " << curr << "length " << edges[curr] << endl;

        process.pop();

        if (edges[curr] == 0)
        {
            // cout << "curr" << curr << endl;
            continue;
        }

        first++;

        for (int v = 1; v <= n; v++)
        {
            if (adj[curr][v])
            {
                adj[curr][v] = false;
                adj[v][curr] = false;

                edges[v]--;
                edges[curr]--;

                if (edges[v] == 1 && v != curr)
                {
                    // cout << "v" << " " << edges[v] << endl;

                    process.push(v);
                }
                if (edges[v] == 0)
                {
                    x--;
                }
            }
        }
    }

    second = x - first;
    if (first == 0)
        second--;

    cout << first + second << endl;
    cout << first << " " << second << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    io();
    int q;
    cin >> q;
    while (q--)
        solve2();

    return 0;
}