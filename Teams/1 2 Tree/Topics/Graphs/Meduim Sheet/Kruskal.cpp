#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void initDSU(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}

int rootDSU(vector<int> arr, int i)
{
    // get arr[i] till arr[i]==i

    while (arr[i] != i)
    {
        i = arr[i];
    }

    return i;
}

void unionDSU(vector<int> &arr, int a, int b)
{

    // b->a: b is the parent
    int rootA = rootDSU(arr, a);

    int rootB = rootDSU(arr, b);

    arr[rootA] = rootB;
}
// if they have the same rootDSU, there will be a cycle
bool findDSU(vector<int> arr, int a, int b)
{
    int rootA = rootDSU(arr, a);
    int rootB = rootDSU(arr, b);
    if (rootA == rootB)
    {
        // cycle detected
        return 1;
    }
    return 0;
}

ll kruskal(vector<pair<ll, pair<int, int>>> &p, int edges, int n)
{
    vector<int> arr(n);
    initDSU(arr, n);

    ll minCost = 0;

    for (int i = 0; i < edges; i++)
    {
        int a = p[i].second.first;
        int b = p[i].second.second;

        ll cost = p[i].first;

        if (!findDSU(arr, a, b))
        {
            minCost += cost;

            unionDSU(arr, a, b);
        }
    }

    return minCost;
}
void IOFilesOpen()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}
int main()
{
    IOFilesOpen();

    int n;
    cin >> n;

    int edges;
    cin >> edges;

    vector<pair<ll, pair<int, int>>> p(edges);

    for (int i = 0; i < edges; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        p[i] = make_pair(w, make_pair(u, v));
    }

    sort(p.begin(), p.end());

    cout << kruskal(p, edges, n);
}