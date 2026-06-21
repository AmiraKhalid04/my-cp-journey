#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void io()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void solveA()
{
    int a, b;
    cin >> a >> b;

    if (a != 3 && b != 3)
        cout << a + b;
    else if (a == 3 && b != 3)
        cout << b;
    else if (b == 3 && a != 3)
        cout << a;
    else
        cout << 0;
}

void solveB()
{
    ll a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    if (((min(a1, b1) - min(a2, b2))) * (max(a1, b1) - max(a2, b2)) >= 0)
    {
        cout << abs(a1 * b1 - a2 * b2);
    }
    else
        cout << -1;
}

void solveC()
{
    int n, k, m;

    cin >> n >> k >> m;

    vector<pair<ll, int>> vec(n);

    map<int, int> mapo;

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].first >> vec[i].second;

        // mapo[vec[i].second]++;
    }
    sort(vec.rbegin(), vec.rend());

    // reverse(vec.begin(), vec.end());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {

        if (mapo[vec[i].second] < m)
        {
            ans += vec[i].first;
            mapo[vec[i].second]++;
            k--;

            if (!k)
            {
                cout << ans << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
}

void solveD()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    vector<vector<int>> freq(n, vector<int>(32));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            if (vec[i] & (1 << j))
            {
                freq[i][j]++;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 31; j++)
        {

            {
                freq[i][j] += freq[i - 1][j];
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        l--, r--;
        ll ans = 0;

        {

            for (int j = 0; j < 31; j++)
            {

                ll ones = freq[r][j];
                if (l)
                    ones = freq[r][j] - freq[l - 1][j];

                ll zeros = r - l + 1 - ones;

                ans += ones * zeros * (1 << j);
            }
        }

        cout << ans << endl;
    }
}

void solve()
{
}
int main()
{
    io();
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }

    return 0;
}