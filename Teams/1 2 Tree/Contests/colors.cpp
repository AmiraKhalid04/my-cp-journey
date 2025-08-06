#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    // vector<int> freq(n + 1);
    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }

    // 2 pointers
    int i = 0;
    int j = n - 1;

    while (i != j)
    {
        if (a[i] == a[j])
        {
            freq[a[i]] -= 1;
            i++;
            // j--;
        }
        else
        {
            // move pointer that has freq 1
            if (freq[a[i]] == 1 || i + 1 < n && a[i] == a[i + 1])
            {
                freq[a[i]]--;
                i++;
                continue;
            }
            else if (freq[a[j]] == 1 || j - 1 >= 0 && a[j] == a[j - 1])
            {
                freq[a[j]]--;
                j--;
                continue;
            }
            else
            {
                break;
            }
        }
    }

    if (i == j)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}