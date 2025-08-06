#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

// int rec(int num, vector<int>& memo, vector<vector<int>>& divisors) {
//     if (num == 0 || num == 1) {
//         return 0;
//     }

//     if (memo[num] != INT_MAX) {
//         // cout << num << " " << memo[num] << endl;
//         return memo[num];
//     }

//     for (int i = 0; i < divisors[num].size(); i++) {
//         if (divisors[num][i] == 1) {
//             return memo[num] = 1 + rec(num - 1, memo, divisors);
//         }

//         int ans = min(1 + rec(num - 1, memo, divisors),
//             divisors[num][i] + rec(num / divisors[num][i], memo, divisors));
//         memo[num] = min(ans, memo[num]);
//     }

//     return memo[num];
// }

void findDivisors(int n, vector<vector<int>> &divisors)
{
    // for (ll i = 1; i <= sqrt(n); i++) {
    //     if (n % i == 0) {
    //         divisors.push_back(i);
    //     }
    // }

    // // start in reverse to get second half sorted ascendingly
    // for (ll i = divisors.size() - 1; i >= 0; i--) {
    //     if (n / divisors[i] != sqrt(n)) {
    //         divisors.push_back(n / divisors[i]);
    //     }
    // }

    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            divisors[j].push_back(i);
        }
    }
}

set<int> getFactors(int num, vector<int> &primes)
{
    set<int> factors;

    factors.insert(num);

    for (int i = 0; primes[i] * primes[i] <= num; i++)
    {
        int divisor = primes[i];

        while (divisor != 0 && num % divisor == 0)
        {
            factors.insert(divisor);
            factors.insert(num / divisor);
            divisor *= divisor;
        }
    }

    return factors;
}

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
void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    int maxNum = INT_MIN;

    for (auto &x : a)
    {
        cin >> x;
        maxNum = max(x, maxNum);
    }

    vector<int> memo(maxNum + 1, INT_MAX);
    memo[0] = 0;
    memo[1] = 0;

    vector<int> primes = linearSieve(maxNum);

    for (int i = 2; i <= 1e6; i++)
    {
        set<int> factors = getFactors(i, primes);
        for (auto it = factors.begin(); it != factors.end(); it++)
        {
            memo[i] = min(memo[i], 1 + memo[i - 1]);
            memo[i] = min(memo[i], *it + memo[i / *it]);
        }
    }
}
void IOFilesOpen()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}
int main()
{
    // IOFilesOpen();
    int q;
    cin >> q;

    int maxNum = 1e6;

    vector<int> memo(maxNum + 1, INT_MAX);
    memo[0] = 0;
    memo[1] = 0;

    vector<int> primes = linearSieve(maxNum);

    for (int i = 2; i <= 1e6; i++)
    {
        set<int> factors = getFactors(i, primes);
        for (auto it = factors.begin(); it != factors.end(); it++)
        {
            memo[i] = min(memo[i], 1 + memo[i - 1]);
            memo[i] = min(memo[i], *it + memo[i / *it]);
        }
    }

    while (q--)
    {
        int ans = 0;
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a)
        {
            cin >> x;
        }
        for (auto x : a)
        {
            ans += memo[x];
        }

        cout << ans << "\n";
    }
    return 0;
}