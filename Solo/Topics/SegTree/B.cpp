
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

bool odd = true;

void io()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

/// SegTree
void buildSegTree(const vector<int> &arr,
                  vector<int> &segTree,
                  int l, int r, int level, int i = 0)
{
    if (l == r)
    {
        segTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildSegTree(arr, segTree, l, mid, level + 1, 2 * i + 1);
    buildSegTree(arr, segTree, mid + 1, r, level + 1, 2 * i + 2);

    if (!odd)
        if (level % 2)
            segTree[i] = (segTree[2 * i + 1] | segTree[2 * i + 2]);
        else
            segTree[i] = (segTree[2 * i + 1] ^ segTree[2 * i + 2]);

    else
    {
        if (level % 2 == 0)
            segTree[i] = (segTree[2 * i + 1] | segTree[2 * i + 2]);
        else
            segTree[i] = (segTree[2 * i + 1] ^ segTree[2 * i + 2]);
    }
}
// sum func
int query(vector<int> &segTree, int sl, int sr, int l, int r, int level, int i = 0)
{
    if (l <= sl && sr <= r) // complete overlap
        return segTree[i];

    if (sl > r || sr < l) // no overlap
        return 0;

    // else is partial overlap->go left and right
    int sm = sl + (sr - sl) / 2;

    if (!odd)
    {
        if (level % 2)
            return (query(segTree, sl, sm, l, r, 2 * i + 1) | query(segTree, sm + 1, sr, l, r, level + 1, 2 * i + 2));
        else
            return (query(segTree, sl, sm, l, r, 2 * i + 1) ^ query(segTree, sm + 1, sr, l, r, level + 1, 2 * i + 2));
    }
    else
    {
        if (level % 2 == 0)
            return (query(segTree, sl, sm, l, r, 2 * i + 1) | query(segTree, sm + 1, sr, l, r, level + 1, 2 * i + 2));
        else
            return (query(segTree, sl, sm, l, r, 2 * i + 1) ^ query(segTree, sm + 1, sr, l, r, level + 1, 2 * i + 2));
    }
}
void update(vector<int> &segTree, int sl, int sr, int pos, int newVal, int level, int i = 0)
{
    if (sl == sr)
    {
        segTree[i] = newVal;
        return;
    }

    int sm = sl + (sr - sl) / 2;
    if (pos <= sm)
        update(segTree, sl, sm, pos, newVal, level + 1, 2 * i + 1);
    else
        update(segTree, sm + 1, sr, pos, newVal, level + 1, 2 * i + 2);

    if (!odd)
        if (level % 2)
            segTree[i] = (segTree[2 * i + 1] | segTree[2 * i + 2]);
        else
            segTree[i] = (segTree[2 * i + 1] ^ segTree[2 * i + 2]);

    else
    {
        if (level % 2 == 0)
            segTree[i] = (segTree[2 * i + 1] | segTree[2 * i + 2]);
        else
            segTree[i] = (segTree[2 * i + 1] ^ segTree[2 * i + 2]);
    }
}

int main()
{
    io();

    int n;
    cin >> n;
    int q;

    if (n % 2 == 0)
        odd = 0;

    cin >> q;
    int sz = int(pow(2, n));
    vector<int> segTree(2 * sz + 2);
    vector<int>
        v(sz);
    for (int i = 0; i < sz; i++)
    {
        cin >> v[i];
    }
    buildSegTree(v, segTree, 0, sz - 1, 0);

    while (q--)
    {
        int idx, val;
        cin >> idx >> val;
        idx--;

        update(segTree, 0, sz - 1, idx, val, 0);
        cout << query(segTree, 0, sz - 1, 0, sz - 1, 0) << endl;
        ;
    }
}

// index
