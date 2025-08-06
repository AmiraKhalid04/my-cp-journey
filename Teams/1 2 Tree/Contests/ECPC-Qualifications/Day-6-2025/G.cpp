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

vector<ll> primes;
vector<ll> linearSieve(int n)
{
    vector<ll> primes;
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

void primeFactors(int &n, vector<int> &f)
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

void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void solve()
{

    int n;
    cin >> n;

    set<vector<double>> ans;

    while (n--)
    {
        double x1, y1, x2, y2, x3, y3;

        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        double dot1 = x1 * x2 + y1 * y2;
        double dot2 = x1 * x3 + y1 * y3;
        double dot3 = x3 * x2 + y3 * y2;

        double mag1 = sqrt((x1 * x1 + y1 * y1)) * sqrt((x2 * x2 + y2 * y2));
        double mag2 = sqrt((x1 * x1 + y1 * y1)) * sqrt((x3 * x3 + y3 * y3));
        double mag3 = sqrt((x3 * x3 + y3 * y3)) * sqrt((x2 * x2 + y2 * y2));

        // double ang1 = dot1 / mag1;
        // double ang2 = dot2 / mag2;
        // double ang3 = dot3 / mag3;

        vector<double>
            slopes(3);

        if (mag1)
            slopes[0] = dot1 / mag1;
        else
        {
            slopes[0] = std::numeric_limits<double>::infinity();
        }
        if (mag2)
            slopes[1] = dot2 / mag2;
        else
        {
            slopes[1] = std::numeric_limits<double>::infinity();
        }
        if (mag3)
            slopes[2] = dot3 / mag3;
        else
        {
            slopes[2] = std::numeric_limits<double>::infinity();
        }
        for (double &slope : slopes)
        {
            if (slope != std::numeric_limits<double>::infinity())
            {
                slope = std::round(slope * 1000000) / 1000000.0; // Round to 6 decimal places
            }
        }
        sort(slopes.begin(), slopes.end());

        ans.insert(slopes);
    }

    cout << ans.size();
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
