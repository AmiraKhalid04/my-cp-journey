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
        int n, s, x;
        cin >> n >> s >> x;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int sum = accumulate(v.begin(), v.end(), 0);
        if (s - sum >= 0)
        {
            if ((s - sum) % x == 0)
            {
                cout << "yes" << endl;
                continue;
            }
        }
        cout << "no" << endl;
    }

    return 0;
}