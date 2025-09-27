#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

vector<ll> primes;

void sieve(int n)
{
    vector<char> cm(n + 1, false);
    cm[0] = cm[1] = true;

    for (int i = 2; i <= n; i++)
    {
        if (!cm[i])
            primes.push_back(i);

        for (int j = 0; j < primes.size() && (i * primes[j] <= n); i++)
        {
            cm[i * primes[j]] = true;

            if (i * primes[j] == 0)
                break;
        }
    }
}

map<int, int> primeFactors(int n)
{
    map<int, int> factors;

    for (int prime : primes)
    {
        if (prime * prime > n)
            break;

        while (n % prime == 0)
        {
            factors[prime]++;
            n /= prime;
        }

        if (n == 1)
            break;
    }

    if (n > 1)
        factors[n] = 1;

    return factors;
}

vector<int> factors(const map<int, int> &primeFactors)
{
    vector<int> factors = {1};

    for (const auto &[prime, exp] : primeFactors)
    {
        vector<int> newFactors;

        for (int factor : factors)
        {
            int curr = 1;

            for (int i = 0; i <= exp; ++i)
            {
                newFactors.push_back(factor * curr);
                curr *= prime;
            }
        }

        factors = newFactors;
    }

    return factors;
}

ll fastPower(ll x, ll n, ll m = 1e9 + 7)
{
    ll res = 1;
    x = x % m;

    while (n > 0)
    {
        if (n % 2)
        {
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2;
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
    {
        return false;
    }

    int s = 0;
    ll d = n - 1;

    while (!(d % 2))
    {
        d /= 2;
        s++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
        {
            return true;
        }

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

const int N = 1000006;

ll factorialNumInverse[N + 1];

ll naturalNumInverse[N + 1];

ll fact[N + 1];

void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
    }
}

void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
    }
}

void factorial(ll p)
{
    fact[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % p;
    }
}

ll Binomial(ll N, ll R, ll P)
{
    ll ans = ((fact[N] * factorialNumInverse[R]) % P * factorialNumInverse[N - R]) % P;
    return ans;
}

struct SegmentTree
{
    int N;
    vector<int> tree;

    SegmentTree(int n)
    {
        N = 1;
        while (N < n)
        {
            N <<= 1;
        }
        tree.resize(N << 1);
    }

    void update(int node, int l, int r, int idx, int value)
    {
        if (l == r)
        {
            tree[node] = value;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
        {
            update(node << 1, l, mid, idx, value);
        }
        else
        {
            update(node << 1 | 1, mid + 1, r, idx, value);
        }

        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    int query(int node, int l, int r, int ql, int qr)
    {
        if (l >= ql && r <= qr)
        {
            return tree[node];
        }
        if (l > qr || r < ql)
        {
            return 0;
        }

        int mid = l + (r - l) / 2;

        int left_query = query(node << 1, l, mid, ql, qr);
        int right_query = query(node << 1 | 1, mid + 1, r, ql, qr);

        return left_query + right_query;
    }

    void update(int idx, int value)
    {
        update(1, 0, N - 1, idx, value);
    }

    int query(int ql, int qr)
    {
        return query(1, 0, N - 1, ql, qr);
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<int> a;
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
        mp[x] = i + 1;
    }

    sort(a.begin(), a.end());

    SegmentTree segtree(n);

    for (int i = 0; i < n; i++)
    {
        segtree.update(0, n - 1, )
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    io();

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
