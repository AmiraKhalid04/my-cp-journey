
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

void solve()
{
    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;

    vector<pair<int, int>> points(k);
    set<vector<pair<int, int>>> sets;

    for (int i = 0; i < k; i++)
    {
        cin >> points[i].first;
        cin >> points[i].second;
    }

    int ans = 0;

    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            int x1 = points[i].first, x2 = points[j].first;
            int y1 = points[i].second, y2 = points[j].second;

            int dist_x = abs(points[i].first - points[j].first);
            int dist_y = abs(points[i].second - points[j].second);

            // two sides

            if (dist_x && !dist_y)
            {

                // plus in y

                auto it = find(points.begin() + i + 1, points.end(), make_pair(x1, y1 + dist_x));

                if (it != points.end())
                {
                    auto it2 = find(points.begin() + j + 1, points.end(), make_pair(x2, y2 + dist_x));

                    if (it2 != points.end())
                    {
                        ans++;

                        vector<pair<int, int>> v = {{x1, y1},
                                                    {x2, y2},
                                                    {x2, y2 + dist_x},
                                                    {x1, y1 + dist_x}};

                        sort(v.begin(), v.end());
                        sets.insert(v);
                    };
                }

                // minus in y
                it = find(points.begin() + i + 1, points.end(), make_pair(x1, y1 - dist_x));

                if (it != points.end())
                {
                    auto it2 = find(points.begin() + j + 1, points.end(), make_pair(x2, y2 - dist_x));

                    if (it2 != points.end())
                    {
                        vector<pair<int, int>> v = {{x1, y1},
                                                    {x2, y2},
                                                    {x2, y2 + dist_x},
                                                    {x1, y1 + dist_x}};
                        sort(v.begin(), v.end());

                        sets.insert(v);
                    }
                }
            }
            if (!dist_x && dist_y)
            {
                // plus in x

                auto it = find(points.begin() + i + 1, points.end(), make_pair(x1 + dist_y, y1));

                if (it != points.end())
                {
                    auto it2 = find(points.begin() + j + 1, points.end(), make_pair(x2 + dist_y, y2));

                    if (it2 != points.end())
                    {
                        vector<pair<int, int>> v = {{x1, y1},
                                                    {x2, y2},
                                                    {x2, y2 - dist_x},
                                                    {x1, y1 - dist_x}};
                        sort(v.begin(), v.end());

                        sets.insert(v);
                    }
                }

                // minus in x
                it = find(points.begin() + i + 1, points.end(), make_pair(x1 - dist_y, y1));

                if (it != points.end())
                {
                    auto it2 = find(points.begin() + j + 1, points.end(), make_pair(x2 - dist_y, y2));

                    if (it2 != points.end())
                    {
                        vector<pair<int, int>> v = {{x1, y1},
                                                    {x2, y2},
                                                    {x2, y2 - dist_x},
                                                    {x1, y1 - dist_x}};
                        sort(v.begin(), v.end());

                        sets.insert(v);
                    }
                }
            }
        }
    }
    cout << sets.size() / 2;
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