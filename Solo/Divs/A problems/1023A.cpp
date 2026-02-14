#include <bits/stdc++.h>
using namespace std;

void io()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}
int main()
{
    io();
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int mx = INT_MIN;
        int mn = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mx = max(mx, v[i]);
            mn = min(v[i], mn);
        }

        if (mx == mn)
        {
            cout << "no" << endl;
            continue;
        }

        cout << "yes" << endl;

        for (int i = 0; i < n; i++)
        {
            if (v[i] == mx)
                cout << 1 << " ";
            else
                cout << 2 << " ";
        }
        cout << endl;
    }

    return 0;
}