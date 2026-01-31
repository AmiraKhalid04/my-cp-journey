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
        vector<int>
            v(n);
        vector<int> indx(n + 1);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            indx[v[i]] = i;
        }
        int element = n;
        int saved = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] != element)
            {
                saved = i;
                break;
            }
            element--;
        }

        for (int i = 0; i < saved; i++)
        {
            cout << v[i] << " ";
        }
        for (int i = indx[element]; i >= saved; i--)
        {
            cout << v[i] << " ";
        }
        for (int i = indx[element] + 1; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    return 0;
}