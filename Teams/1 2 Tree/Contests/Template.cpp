#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
void IOFilesOpen()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}
//////////////////////Sorting map by Values///////////////////////
//////////////////////////////////////////////////////////////////
bool cmpMap(pair<string, int> &a,
            pair<string, int> &b)
{
    return a.second < b.second;
}

// Function to sort the map according
// to value in a (key-value) pairs
void sortMap(map<string, int> &M)
{
    vector<pair<string, int>> A;

    for (auto &it : M)
    {
        A.push_back(it);
    }

    sort(A.begin(), A.end(), cmpMap);
}

//////////////////////Get all numbers factors///////////////////////
//////////////////////////////////////////////////////////////////
vector<int> primes;

// Function to find prime factorization of n using a vector of primes
map<int, int> getPrimeFactorization(int n)
{
    map<int, int> factors; // Map to store prime factors and their exponents

    // Iterate through each prime in the vector
    for (int prime : primes)
    {
        if (prime * prime > n)
        {
            break;
        }
        // Keep dividing n by the current prime as long as possible
        while (n % prime == 0)
        {
            factors[prime]++; // Increment the exponent of the prime
            n /= prime;
        }
        // If n becomes 1, no need to check further primes
        if (n == 1)
            break;
    }

    // If n is still greater than 1, it could be a prime number itself
    // or a number not divisible by any prime in the vector
    if (n > 1)
    {
        factors[n] = 1; // Treat n as a prime factor with exponent 1
    }

    return factors;
}

// Function to generate all factors from prime factorization
vector<int> getFactors(const map<int, int> &primeFactors)
{
    vector<int> factors = {1}; // Initialize with 1 as a factor

    // For each prime factor and its exponent
    for (const auto &[prime, exponent] : primeFactors)
    {
        vector<int> newFactors;
        // Generate factors by multiplying existing factors with powers of the current prime
        for (int factor : factors)
        {
            int current = 1;
            // Include all powers of the prime from 0 to exponent
            for (int i = 0; i <= exponent; ++i)
            {
                newFactors.push_back(factor * current);
                current *= prime;
            }
        }
        factors = newFactors; // Update factors list
    }
    return factors;
}
//////////////////////Bipartite Graph Code ///////////////////////
//////////////////////////////////////////////////////////////////
bool DFSBipartite(int root, vector<vector<int>> &adj_list, vector<int> &vis, vector<int> &color)
{
    stack<int> s;
    s.push(root);
    // cout << root << " ";
    vis[root] = 1;
    int p = root;
    while (s.empty() == 0)
    {
        p = s.top();
        bool f = 0;
        for (int i = 0; i < adj_list[p].size(); i++)
        {
            if (vis[adj_list[p][i]] == 0)
            {
                f = 1;
                vis[adj_list[p][i]] = 1;
                s.push(adj_list[p][i]);
                // cout << adj_list[p][i] << " ";
                color[adj_list[p][i]] = 3 - color[p];
            }
            else
            {
                if (color[adj_list[p][i]] == color[p])
                {
                    return 0;
                }
            }
        }
        if (!f)
        {
            s.pop();
        }
    }
    return 1;
}

// after calling this, u will have a graph colored with 1 and 2
// 1 is set A and 2 is set B
void Bipartite()
{
    int n, edges;
    cin >> n >> edges;
    vector<vector<int>> adj_list(n + 1);
    vector<int> vis(n + 1, 0);
    vector<int> color(n + 1, 0);

    while (edges--)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    bool isBarpartite = true;

    for (int i = 1; i <= n; i++)
        if (vis[i] == 0)
        {

            if (!color[i])
            {
                color[i] = 1;
                if (DFSBipartite(i, adj_list, vis, color) == 0)
                {
                    isBarpartite = false;
                    break;
                }
            }
        }
}

//////////////////////////////////////Dijkstra///////////////////////////
/**
 * Important Note
 *
 * This is for SPARSE graphs only
 */
const int N = 1e6 + 10;
vector<ll> dist;
vector<ll> parent;
void init()
{
    dist.assign(N, LLONG_MAX);
    parent.assign(N, -1);
}

void Dijkstra(vector<vector<pair<int, ll>>> &adj_list,
              priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> &pq, int src)
{
    // only for testing
    pq.push({0, src});
    vector<bool> vis(N, 0);

    dist[src] = 0;

    while (pq.empty() == 0)
    {

        int p = pq.top().second;
        pq.pop();

        if (vis[p])
            continue;

        vis[p] = 1;

        for (int i = 0; i < adj_list[p].size(); i++)
        {
            int ch = adj_list[p][i].first;

            ll w = adj_list[p][i].second;

            if (dist[ch] > dist[p] + w)
            {
                parent[ch] = p;

                dist[ch] = dist[p] + w;
                pq.push({dist[ch], ch});
            }
        }
    }
}

//////////////////////Dijkstra for dense graphs - adj matrix representation///////////////////////
//////////////////////////////////////////////////////////////////

/**
 * Important Note
 *
 * This is for DENSE graphs
 */
vector<vector<int>> adj;
vector<int> d;
vector<int> p;

void dijkstra(int s)
{
    int n = adj.size();
    d.assign(n, INT_MAX);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int v = -1;

        for (int j = 0; j < n; j++)
        {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INT_MAX)
            break;

        u[v] = true;

        for (int to = 0; to < n; to++)
        {
            int w = adj[v][to];

            if (d[v] + w < d[to])
            {
                d[to] = d[v] + w;
                p[to] = v;
            }
        }
    }
}
//////////////////////Dijkstra for dense graphs///////////////////////
//////////////////////////////////////////////////////////////////

/**
 * Important Note
 *
 * adj list representation
 */

vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> &d, vector<int> &p)
{
    int n = adj.size();
    d.assign(n, INT_MAX);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
        {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INT_MAX)
            break;

        u[v] = true;
        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}
//////////////////////Floyd Warshall ///////////////////////
//////////////////////////////////////////////////////////////////
void floyd(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d[i][k] != INT_MAX && d[k][j] != INT_MAX)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

//////////////////////DSU Helper functions///////////////////////
//////////////////////////////////////////////////////////////////

void initDSU(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}

int rootDSU(vector<int> arr, int i)
{
    // get arr[i] till arr[i]==i

    while (arr[i] != i)
    {
        i == arr[i];
    }

    return i;
}

void unionDSU(vector<int> &arr, int a, int b)
{

    // b->a: b is the parent
    int rootA = rootDSU(arr, a);

    int rootB = rootDSU(arr, b);

    arr[rootA] = rootB;
}
// if they have the same rootDSU, there will be a cycle
bool findDSU(vector<int> arr, int a, int b)
{
    int rootA = rootDSU(arr, a);
    int rootB = rootDSU(arr, b);
    if (rootA == rootB)
    {
        // cycle detected
        return 1;
    }
    return 0;
}

//////////////////////MST: Kruskal `O(E* Log(V))`///////////////////////
//////////////////////////////////////////////////////////////////

/**
 * Important Note
 *
 * DSU must be written before kruskal
 */

ll kruskal(vector<pair<ll, pair<int, int>>> &p, int edges, int n)
{
    vector<int> arr(n);
    initDSU(arr, n);

    ll minCost = 0;

    for (int i = 0; i < edges; i++)
    {
        int a = p[i].second.first;
        int b = p[i].second.second;

        ll cost = p[i].first;

        if (!findDSU(arr, a, b))
        {
            minCost += cost;

            unionDSU(arr, a, b);
        }
    }

    return minCost;
}

// Main code for kruskal just for studying
void solveKruskal()
{

    int n;
    cin >> n;

    int edges;
    cin >> edges;

    vector<pair<ll, pair<int, int>>> p(edges);

    for (int i = 0; i < edges; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        p[i] = make_pair(w, make_pair(u, v));
    }

    sort(p.begin(), p.end());

    cout << kruskal(p, edges, n);
}

//////////////////////Bit Masks Code ///////////////////////
//////////////////////////////////////////////////////////////////

// Get bit

bool getBit(int num, int i)
{
    return ((num & (1 << i)) != 0);
}

// Set bit

int setBit(int num, int i)
{
    return num | (1 << i);
}

// Clear bit

int clearBit(int num, int i)
{
    int mask = (1 << i);
    return num & mask;
}

// Clear all bits from MSB to i inclusive

int clearBitsMSBthroughI(int num, int i)
{
    int mask = (1 << i) - 1;
    return num & mask;
}

// Clear all bits from LSB to i inclusive

int clearBitsLSBthroughI(int num, int i)
{
    int mask = (-1 << (i + 1));
    return num & mask;
}

// Update bit : How can we need this if we can set and clear any bit ?)

int updateBit(int num, int i, bool bitisl)
{
    int value = bitisl ? 1 : 0;
    int mask = (1 << i);
    return (num & mask) | (value << i);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // FOR IO with files
    /**
     * Important Note
     *
     * Add ur proper files name in the
     */
    IOFilesOpen();
    int q;
    cin >> q;
    while (q--)
        solve();
}