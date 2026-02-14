#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
        int n, k;

        cin >> n >> k;
        vector<ll> v(n);
        ll mx = INT_MIN;
        ll mn = INT_MAX;
        map<int, int> mapo;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mx = max(mx, v[i]);
            mn = min(mn, v[i]);
            mapo[v[i]]++;
        }

        ll sum = accumulate(v.begin(), v.end(), 0);

        if (((mx - mn - 1 == k) && mapo[mx] >= 2) || (mx - mn - 1 > k))
        {
            cout << "Jerry" << endl;
            continue;
        }

        if (sum % 2)
        {
            cout << "Tom";
        }
        else
            cout << "Jerry";
        cout << endl;
    }

    return 0;
}