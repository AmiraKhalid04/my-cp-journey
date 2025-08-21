
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
bool getBit(int num, int i)
{
    return ((num & (1 << i)) != 0);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    set<int> row;
    set<int> col;

    for (int i = 0; i < n; i++)
        row.insert(i);
    for (int i = 0; i < m; i++)
        col.insert(i);
    for (int i = 0; i < n; i++)

        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            if (c == '.')
            {
                if (row.find(i) != row.end())
                    row.erase(i);
                if (col.find(j) != col.end())
                    col.erase(j);
            }
        }

    int r = row.size();
    int c = col.size();

    int rs = r == n ? r : 1e8;
    int cs = c == m ? m : 1e8;
    cout << r * c << " " << min({max(r, c), cs, rs});
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout.tie(0);
    IOFilesOpen();
    // int t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}