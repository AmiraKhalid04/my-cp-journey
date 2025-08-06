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
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
// ordered_multiset;

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

void BFS(int root, vector<vector<int> > &adj_list,
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
void solveA(string str, int i, int n)
{
    if (i == n)
    {
        cout << str << endl;
        return;
    }
    solveA(str + "1", i + 1, n);
    solveA(str + "0", i + 1, n);
}
void solveB(string str, int index, int n, int k)
{
    if (index == n)
    {
        cout << str << endl;
        return;
    }
    for (int i = 0; i < k; i++)
        solveB(str + to_string(i), index + 1, n, k);
}
void solveC()
{
}
void solveD(int n, int sum, int &cnt)
{
    if (sum > n)
        return;
    if (sum == n)
    {
        cnt++;
        return;
    }

    solveD(n, sum + 1, cnt);
    solveD(n, sum + 2, cnt);
    solveD(n, sum + 3, cnt);
}
void solveC(vector<int> &vec, int i, vector<int> &seq, vector<int> &maxSeq)
{
    if (i == vec.size())
    {
        if (seq.size() > maxSeq.size())
        {
            vector<int> temp = seq;
            sort(temp.begin(), temp.end());
            if (temp == seq)
                maxSeq = seq;
        }
        return;
    }
    solveC(vec, i + 1, seq, maxSeq);
    seq.push_back(vec[i]);
    solveC(vec, i + 1, seq, maxSeq);
    seq.pop_back();
}

bool solve8(string str, int i, int n)
{
    if (i == 3)
    {
        if (((!int(str[0]) - 48) ||
             (int(str[1]) - 48) || (!int(str[2]) - 48)) &&
            ((!int(str[0]) - 48) ||
             (int(str[1]) - 48) || (int(str[2]) - 48)) &&
            ((int(str[0]) - 48) ||
             (!int(str[1]) - 48) ||
             (!int(str[2]) - 48)))
        {
            cout << str << endl;
            return 1;
        }
        else
            return 0;
    }
    return solve8(str + "1", i + 1, 3) || solve8(str + "0", i + 1, 3);
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

bool pG(vector<ll> &vec, int i, ll sum)
{
    if (i == vec.size())
    {
        if (sum == 0 || sum % 360 == 0)
            return 1;
        return 0;
    }

    return pG(vec, i + 1, sum + vec[i]) || pG(vec, i + 1, sum - vec[i]);
}

void pI(int i, int l, int r, int x, vector<int> &vec, int mn, int mx, int sum, int &ctr, vector<int> seq)
{
    if (i == vec.size())
    {
        sort(seq.begin(), seq.end());

        if (sum <= r && sum >= l && seq[seq.size() - 1] - seq[0] >= x)
        {
            ctr++;
        }
        return;
    }

    pI(i + 1, l, r, x, vec, mn, mx, sum, ctr, seq);
    seq.push_back(vec[i]);
    pI(i + 1, l, r, x, vec, mn, mx, sum + vec[i], ctr, seq);

    seq.pop_back();
}

/////////////////////////////////////////////
// Repeat
void pL(ll num, ll x, ll y, int n, set<int> &s)
{
    if (num > n)
        return;
    else if (num)
        s.insert(num);
    if (num || x)
        pL(num * 10 + x, x, y, n, s);
    if (num || y)
        pL(num * 10 + y, x, y, n, s);
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
int main()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin>>n;
       

        for(int i=1;i<2*n;i=i+2){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}