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

// C++ program to answer queries
// of nCr in O(1) time.
const int N = 1000006;

// array to store inverse of 1 to N
ll factorialNumInverse[N + 1];

// array to precompute inverse of 1! to N!
ll naturalNumInverse[N + 1];

// array to store factorial of first N numbers
ll fact[N + 1];

// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;

    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

// Function to calculate factorial of 1 to N
void factorial(ll p)
{
    fact[0] = 1;

    // precompute factorials
    for (int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % p;
    }
}

// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p)
{
    if (N < R)
        return 0;
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p;
    return ans;
}
void buildSegTree(const vector<int> &arr,
                  vector<vector<int>> &segTree,
                  int l, int r,
                  int i = 0)
{
    if (l == r)
    {
        // segTree[i] = arr[l];

        for (int j = 0; j < 30; j++)
        {
            segTree[i][j] = getBit(arr[l], j);
        }
        return;
    }

    int mid = l + (r - l) / 2;
    buildSegTree(arr, segTree, l, mid, 2 * i + 1);
    buildSegTree(arr, segTree, mid + 1, r, 2 * i + 2);
    // segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    for (int j = 0; j < 30; j++)
    {
        segTree[i][j] = segTree[2 * i + 1][j] + segTree[2 * i + 2][j];
    }
}
vector<int> sum(vector<vector<int>> &segTree, int sl, int sr, int l, int r, int i = 0)
{

    vector<int> res(30, 0);
    if (l <= sl && sr <= r) // complete overlap
        return segTree[i];

    if (sl > r || sr < l) // no overlap
        return res;

    // else is partial overlap->go left and right
    int sm = sl + (sr - sl) / 2;
    vector<int> left = sum(segTree, sl, sm, l, r, 2 * i + 1);

    vector<int> right = sum(segTree, sm + 1, sr, l, r, 2 * i + 2);
    for (int j = 0; j < 30; j++)
    {
        res[j] = left[j] + right[j];
    }

    return res;
}
void update(vector<vector<int>> &segTree, int sl, int sr, int pos, int newVal, int i = 0)
{
    if (sl == sr)
    {
        // segTree[i] = newVal;
        for (int j = 0; j < 30; j++)
        {
            segTree[i][j] = getBit(newVal, j);
        }
        return;
    }

    int sm = sl + (sr - sl) / 2;
    if (pos <= sm)
        update(segTree, sl, sm, pos, newVal, 2 * i + 1);
    else
        update(segTree, sm + 1, sr, pos, newVal, 2 * i + 2);

    // segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    for (int j = 0; j < 30; j++)
    {
        segTree[i][j] = segTree[2 * i + 1][j] + segTree[2 * i + 2][j];
    }
}

ll subset(vector<vector<int>> &segTree, int l, int r, int k, int n)
{
    int len = r - l + 1;
    vector<int> res = sum(segTree, 0, n - 1, l, r);
    ll ans = 0;

    for (int i = 0; i < 30; i++)
    {
        int ones = res[i];
        int zeros = len - ones;
        ll permutation = (Binomial(len, k, mod) - Binomial(zeros, k, mod) + mod) % mod;

        ans = (ans + (permutation * (1LL << i) % mod)) % mod;
    }

    return ans;
}
void solve()
{
    int n;
    cin >> n;

    InverseofNumber(mod);
    InverseofFactorial(mod);
    factorial(mod);
    // cout << Binomial(2, 2, mod);
    vector<int> v(n);
    vector<vector<int>> segTree(4 * n, vector<int>(30, 0));

    for (int i = 0; i < n; i++)
        cin >> v[i];

    buildSegTree(v, segTree, 0, n - 1);

    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        if (num == 1)
        {
            int l, r, k;
            cin >> l >> r >> k;
            l--, r--;
            // int ans = 0;
            // vector<int> res = sum(segTree, 0, n - 1, l, r);

            // for (int i = 0; i < 30; i++)
            // {
            //     if (res[i])
            //     {
            //         ans += pow(2, i);
            //     }
            // }

            // cout << ans << endl;

            cout << subset(segTree, l, r, k, n) << endl;
        }
        else
        {
            int p, v;
            cin >> p >> v;
            p--;
            update(segTree, 0, n - 1, p, v);
        }
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
