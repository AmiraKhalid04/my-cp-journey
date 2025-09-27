
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
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
    segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
}
// sum func
int sum(vector<int> &segTree, int sl, int sr, int l, int r, int i = 0)
{
    if (l <= sl && sr <= r) // complete overlap
        return segTree[i];

    if (sl > r || sr < l) // no overlap
        return -1;

    // else is partial overlap->go left and right
    int sm = sl + (sr - sl) / 2;
    return max(sum(segTree, sl, sm, l, r, 2 * i + 1), sum(segTree, sm + 1, sr, l, r, 2 * i + 2));
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

    segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
}

int main()
{
    io();

    int n;
    cin >> n;

    vector<int> v(n);
    vector<set<int>> freq(51);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];

        freq[v[i]].insert(i);
    }

    // index

    vector<int> ans(n, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        bool f = 0;
        for (int j = v[i] + 1; j <= 50; j++)
        {
            auto it = freq[j].upper_bound(i);

            if (it != freq[j].end())
            {
                f = 1;
                ans[i] = min(ans[i], *it);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (ans[i] != INT_MAX)
            cout << v[ans[i]];

        else
            cout << -1;

        cout << " ";
    }
}