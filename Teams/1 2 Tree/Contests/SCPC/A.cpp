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

struct Point
{
    double x, y;
};

double distancePointToSegment(Point p, Point v, Point w)
{
    double l2 = pow(w.x - v.x, 2) + pow(w.y - v.y, 2);
    if (l2 == 0.0) // v == w case
        return hypot(p.x - v.x, p.y - v.y);

    double t = ((p.x - v.x) * (w.x - v.x) + (p.y - v.y) * (w.y - v.y)) / l2;
    t = std::max(0.0, std::min(1.0, t));

    Point projection = {v.x + t * (w.x - v.x), v.y + t * (w.y - v.y)};
    return hypot(p.x - projection.x, p.y - projection.y);
}

void solveF()
{
    int n;
    cin >> n;

    multiset<double> sets;
    vector<pair<double, double>> v(n);
    map<int, pair<double, double>> mapo;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        mapo[i] = v[i];
    }
    double pegX, pegY;
    cin >> pegX >> pegY;
    for (int i = 0; i < n; i++)
    {
        double dist = (pegX - v[i].first) * (pegX - v[i].first) + (pegY - v[i].second) * (pegY - v[i].second);
        double sqrtDist = sqrt(dist);

        sets.insert(sqrtDist);

        double lineDist = distancePointToSegment({pegX, pegY}, {v[i].first, v[i].second}, {v[(i + 1) % n].first, v[(i + 1) % n].second});

        sets.insert(lineDist);
    }

    cout << fixed << setprecision(10) << *sets.begin() << endl;

    int q;
    cin >> q;
    while (q--)
    {
        int ind;
        cin >> ind;
        ind--;

        auto it = mapo.find(ind);

        auto it2 = it;

        auto it3 = it;

        if (it != mapo.begin())
        {
            it2--;
        }
        else
            it2 = prev(mapo.end());

        double lineDist = distancePointToSegment({pegX, pegY}, {(it2->second).first, (it2->second).second}, {(it->second).first, (it->second).second});
        sets.erase(lineDist);

        if (it != prev(mapo.end()))
        {

            it3++;
        }
        else
            it3 = mapo.begin();

        double lineDist2 = distancePointToSegment({pegX, pegY}, {(it->second).first, (it->second).second}, {(it3->second).first, (it3->second).second});
        sets.erase(lineDist2);

        double dist = (pegX - v[ind].first) * (pegX - v[ind].first) + (pegY - v[ind].second) * (pegY - v[ind].second);
        double sqrtDist = sqrt(dist);
        sets.erase(sqrtDist);

        double lineDist3 = distancePointToSegment({pegX, pegY}, {(it2->second).first, (it2->second).second}, {(it3->second).first, (it3->second).second});

        sets.insert(lineDist3);

        mapo.erase(ind);

        cout << fixed << setprecision(10) << *sets.begin() << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << distancePointToSegment({.5, .5}, {1, 1}, {-1, -1});

    io();
    // int q;
    // cin >> q;
    // while (q--)
    //     solveF();

    return 0;
}