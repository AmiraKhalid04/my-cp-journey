
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
vector<int> primes;
vector<int> linearSieve(int n)
{
    vector<int> primes;
    vector<char> composite(n + 1, false);
    composite[0] = composite[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!composite[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && (i * primes[j]) <= n; j++)
        {
            composite[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    return primes;
}

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
    primes = linearSieve(1e7 + 5);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);

        vector<vector<int>> adj_list(n + 1);
        vector<int> vis(n + 1, 0);
        vector<int> color(n + 1, 0);

        bool isBarpartite = true;
        vector<vector<int>> freq(1e7 + 1);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == 1)
                color[i] = 1;
            map<int, int> factors = getPrimeFactorization(v[i]);

            for (auto it = factors.begin(); it != factors.end(); it++)
            {
                freq[it->first].push_back(i);
            }
        }

        for (int i = 0; i < primes.size(); i++)
        {
            if (freq[primes[i]].size() > 2)
            {
                cout << -1;
                return;
            }
            else if (freq[primes[i]].size() == 2)
            {
                for (int j = 0; j < 2; j++)
                {
                    adj_list[freq[primes[i]][j]].push_back(freq[primes[i]][1 - j]);
                }
            }
        }
        for (int i = 0; i < n; i++)
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
        // for (int i = 0; i < primes.size(); i++)
        // {
        //     if (freq[primes[i]].size() == 1)
        //     {
        //         color[freq[primes[i]][0]] = 1;
        //     }
        // }

        if (isBarpartite)
            for (int i = 0; i < n; i++)
            {
                cout << color[i] << " ";
            }
        else
        {
            cout << -1;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    IOFilesOpen();

    Bipartite();
    return 0;
}