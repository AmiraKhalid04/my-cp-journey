
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

void solve()
{
    int n, k;
    cin >> n >> k;

    multiset<int> a;
    multiset<int> b;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        a.insert(x % k);
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        b.insert(x % k);
    }
    int cnt = 0;
    for (auto it = a.begin(); it != a.end(); it++)
    {
        auto it2 = b.find(*it);
        if (it2 != b.end())
        {
            b.erase(it2);
            cnt++;
        }
        else
        {
            it2 = b.find(k - *it);
            if (it2 != b.end())
            {
                b.erase(it2);
                cnt++;
            }
        }
    }

    if (cnt == n)
        cout << "yes";
    else
        cout << "no";

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout.tie(0);
    // IOFilesOpen();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}