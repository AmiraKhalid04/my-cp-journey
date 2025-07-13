#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <iomanip>
#include <list>
#include <deque>
#include <queue>
#include <bitset>
#include <stack>
#include <climits>

typedef long long ll;
ll mod = 1000000007;

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
int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

/// SegTree
void buildSegTree(const vector<int> &arr,
                  vector<int> &segTree,
                  int l, int r,
                  int i = 0)
{
    if (l == r)
    {
        segTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildSegTree(arr, segTree, l, mid, 2 * i + 1);
    buildSegTree(arr, segTree, mid + 1, r, 2 * i + 2);
    segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
}
// sum func
int sum(vector<int> &segTree, int sl, int sr, int l, int r, int i = 0)
{
    if (l <= sl && sr <= r) // complete overlap
        return segTree[i];

    if (sl > r || sr < l) // no overlap
        return 0;

    // else is partial overlap->go left and right
    int sm = sl + (sr - sl) / 2;
    return sum(segTree, sl, sm, l, r, 2 * i + 1) + sum(segTree, sm + 1, sr, l, r, 2 * i + 2);
}
void update(vector<int> &segTree, int sl, int sr, int pos, int newVal, int i = 0)
{
    if (sl == sr)
    {
        segTree[i] = newVal;
        return;
    }

    int sm = sl + (sr - sl) / 2;
    if (pos <= sm)
        update(segTree, sl, sm, pos, newVal, 2 * i + 1);
    else
        update(segTree, sm + 1, sr, pos, newVal, 2 * i + 2);

    segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
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
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p;
    return ans;
}

// ALGO
ll kadane(vector<ll> v)
{
    ll sum = 0;
    ll mx = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i] % mod;
        mx = max(sum, mx);
        if (sum <= 0)
        {
            sum = 0;
        }
    }
    return mx % mod;
}
vector<int> manacher_odd(string s)
{
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while (s[i - p[i]] == s[i + p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > r)
        {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
// vector<int> ans(2 * 1e5 + 9);
// void DFS(int root, vector<vector<int>> &adj_list, vector<bool> &vis,
//          vector<int> &values, set<int> &setValues, int n)
// {
//     stack<int> s;
//     s.push(root);
//     setValues.erase(values[s.top()]);
//     if (setValues.empty() == 0)
//         ans[root] = *setValues.begin();

//     else
//         ans[root] = n;
//     // cout << root << " ";
//     vis[root] = 1;
//     int p = root;
//     while (s.empty() == 0)
//     {
//         p = s.top();
//         bool f = 0;
//         for (int i = 0; i < adj_list[p].size(); i++)
//         {
//             if (vis[adj_list[p][i]] == 0)
//             {
//                 f = 1;
//                 vis[adj_list[p][i]] = 1;
//                 s.push(adj_list[p][i]);
//                 // cout << adj_list[p][i] << " ";
//                 setValues.erase(values[s.top()]);
//                 if (setValues.empty() == 0)
//                     ans[adj_list[p][i]] = *setValues.begin();

//                 else
//                     ans[adj_list[p][i]] = n;
//             }
//         }
//         if (!f)
//         {
//             setValues.insert(values[s.top()]);
//             s.pop();
//         }
//     }
// }
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

// LeetCode
void subset(vector<int> &vec, int i, vector<int> &seq)
{
    if (i == vec.size())
    {
        for (int i = 0; i < seq.size(); i++)
            cout << seq[i] << " ";
        cout << endl;
        return;
    }
    subset(vec, i + 1, seq);
    seq.push_back(vec[i]);
    subset(vec, i + 1, seq);
    seq.pop_back();
}

void diffCombination(vector<int> &vec, int i, int sum, int target, vector<int> &seq)
{
    if (i == vec.size() || sum >= target)
    {

        if (sum == target)
        {
            for (int i = 0; i < seq.size(); i++)
                cout << seq[i] << " ";
            cout << endl;
        }
        return;
    }
    // for (int j = 0; j < target / vec[i]; j++)
    {
        diffCombination(vec, i + 1, sum, target, seq);
        seq.push_back(vec[i]);
        diffCombination(vec, i, sum + vec[i], target, seq);
        seq.pop_back();
    }
}
void permutation(vector<int> &vec, int i, vector<int> &seq, int index, vector<bool> &is_used)
{
    if (index == vec.size())
    {
        for (int i = 0; i < seq.size(); i++)
            cout << seq[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < vec.size(); i++)
    {
        if (!is_used[i])
        {
            is_used[i] = true;
            seq.push_back(vec[i]);
            permutation(vec, i, seq, index + 1, is_used);
            is_used[i] = false;
            seq.pop_back();
        }
    }
}

// str is the string i append in
void combination(map<char, vector<char>> &mapo, int i, string str, string word)

{
    if (i == word.size())
    {
        cout << str << endl;
        return;
    }
    for (int j = 0; j < mapo[word[i]].size(); j++)
    {
        combination(mapo, i + 1, str + mapo[word[i]][j], word);
    }
}
void combinationSum(vector<int> &seq, int sum, int i, int k, int n)
{
    if (sum >= n || seq.size() >= k || i >= n)
    {
        if (sum == n && seq.size() == k)
        {
            for (int i = 0; i < seq.size(); i++)
                cout << seq[i] << " ";
            cout << endl;
        }
        return;
    }
    combinationSum(seq, sum, i + 1, k, n);
    seq.push_back(i);
    combinationSum(seq, sum + i, i + 1, k, n);
    seq.pop_back();
}

// Dynamic Programming
int knap_sack(vector<int> weights, vector<int> benefits, int i, int totCap, int cap, vector<vector<int>> &dp)
{
    if (i == weights.size() || totCap >= cap)
    {
        return dp[i][totCap] = 0;
    }
    if (dp[i][totCap] < 0)
    {
        // try to pick and not pick
        int benefit1 = knap_sack(weights, benefits, i + 1, totCap, cap, dp);
        int benefit2 = 0;
        if (totCap < cap)
        {
            benefit2 = benefits[i] + knap_sack(weights, benefits, i + 1, totCap + weights[i], cap, dp);
        }
        dp[i][totCap] = max(benefit1, benefit2);
    }

    return dp[i][totCap];
}
int LCS(string str1, string str2, int i, int j, vector<vector<int>> &dp)
{
    if (i == str1.size() || j == str2.size())
    {
        return dp[i][j] = 0;
    }
    if (dp[i][j] < 0)
    {
        if (str1[i] == str2[j])

        {
            dp[i][j] = 1 + LCS(str1, str2, i + 1, j + 1, dp);
        }
        else
        {
            int ch1 = LCS(str1, str2, i, j + 1, dp);
            int ch2 = LCS(str1, str2, i + 1, j, dp);
            dp[i][j] = max(ch1, ch2);
        }
    }
    return dp[i][j];
}
// Push loop to parameter
ll coinChange(int coin, vector<int> coins, int i, vector<vector<int>> &dp)
{
    if (i == coins.size() || coin < 0)
    {
        return dp[i][coin] = 0;
    }
    if (dp[i][coin] < 0)
    {
        if (coin == 0)
            return dp[i][coin] = 1;

        else
        {
            ll count = 0;
            count += coinChange(coin - coins[i], coins, i, dp);
            count += coinChange(coin, coins, i + 1, dp);
            dp[i][coin] = count;
        }
    }
    return dp[i][coin];
}
void IOFilesOpen()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}
void DFSrec(vector<vector<int>> &adj, int u, vector<bool> &visited, stack<int> &stk, vector<int> &values, set<int> &setValues, int n, vector<int> &ans)
{
    visited[u] = true;
    stk.push(u);
    setValues.erase(values[stk.top()]);
    if (setValues.empty() == 0)
        ans[u] = *setValues.begin();

    else
        ans[u] = n;
    for (auto i : adj[u])
    {
        if (visited[i] == false)

        {
            DFSrec(adj, i, visited, stk, values, setValues, n, ans);
        }
    }

    setValues.insert(values[stk.top()]);
}
void topological(vector<vector<pair<int, ll>>> &adj, stack<int> &stk, int v, int i)
{
    vector<bool> visited(v, false);
    ;

    // DFSrec(adj, i, visited, stk);
}

vector<ll> shortestpath(vector<vector<pair<int, ll>>> &adj, stack<int> &stk, int source)
{
    int v = adj.size();
    vector<ll> dist(v, LLONG_MAX);
    dist[source] = 0;

    while (stk.empty() != true)
    {
        int u = stk.top();
        stk.pop();

        for (auto i : adj[u])
        {
            if (dist[i.first] > dist[u] + i.second)
                dist[i.first] = dist[u] + i.second;
        }
    }
    return dist;
}
void solve()
{
    int n;
    cin >> n;

    vector<int> values(n + 1);
    vector<bool> vis(n + 1, 0);
    vector<int> ans(n + 1);

    set<int>
        setValues;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        values[i] = x;

        setValues.insert(i - 1);
    }

    vector<vector<int>> adj_list(n + 1);

    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;

        adj_list[x].push_back(i);
        adj_list[i].push_back(x);
    }

    // DFS(1, adj_list, vis, values, setValues, n);

    stack<int> stk;
    DFSrec(adj_list, 1, vis, stk, values, setValues, n, ans);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}
int main()
{
    IOFilesOpen();

    int q;
    cin >> q;
    while (q--)
        solve();

    return 0;
}