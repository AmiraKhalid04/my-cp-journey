
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int mod = 1e7 + 7;

vector<ll> score(10, 0);
void IOFilesOpen()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

// C++ program to answer queries
// of nCr in O(1) time.
const int N = 1e7 + 7;

// array to store factorial of first N numbers
int fact[N + 1];

// Function to precompute inverse of numbers

// Function to calculate factorial of 1 to N
void factorial(int p)
{
    fact[0] = 1;

    // precompute factorials
    for (int i = 1; i < N; i++)
    {
        fact[i] = i * fact[i - 1] % p;
    }
}

void solve()
{
    factorial(mod);

    int n;
    cin >> n;

    for (int i = 1; i < mod; i++)
    {
        fact[i] += fact[i - 1];
        fact[i] %= mod;
    }

    cout << fact[min(n, mod - 1)];

    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout.tie(0);
    IOFilesOpen();
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}