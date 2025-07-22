
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
bool customCompare(const std::pair<int, ll> &a, const std::pair<int, ll> &b)
{
    if (a.second == b.second)
    {
        return score[a.first] > score[b.first];
    }
    return a.second > b.second;
}

void solve()
{
    int n;
    cin >> n;
    // calculate distance
    vector<bool> elExist(10, 0);
    vector<int> firstOccurence(10, -1);
    vector<int> lastOccurence(10, 0);
    vector<pair<int, ll>> elScores(10);
    vector<int> vec(n);

    vector<ll> dist(10, 0);

    // calcualte frequency of every element between any two elements

    vector<vector<ll>> freq(10, vector<ll>(10, 0));

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];

        if (!elExist[vec[i]])
        {
            firstOccurence[vec[i]] = i;
            elExist[vec[i]] = true;
        }

        lastOccurence[vec[i]] = i;

        // calc distance

        dist[vec[i]] = lastOccurence[vec[i]] - firstOccurence[vec[i]];
    }
    for (int i = 0; i < 10; i++)
    {
        if (firstOccurence[i] != -1)
            for (int j = firstOccurence[i] + 1; j < lastOccurence[i]; j++)
            {
                if (vec[j] != i)
                    freq[i][vec[j]]++;
            }
    }
    // score before adding distance
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            score[i] += freq[j][i];
        }
    }

    // total score = score + dist
    //  i want to sort this pair based on tot score
    // then if two elements have the same tot score, i will compare they score

    for (int i = 0; i < score.size(); i++)
    {
        elScores[i].first = i;
        elScores[i].second = score[i] + dist[i];
        // cout << elScores[i].second << " ";
    }

    sort(elScores.begin(), elScores.end(), customCompare);

    // our code begins here on elScores

    vector<ll> ans(n - 1, 0);
    ll currentAns = 0;
    int saved = 0;
    ll maxDistance = 0;
    for (int d = n - 1; d > 0; d--)
    {
        maxDistance = *max_element(dist.begin(), dist.end());

        while (d < maxDistance)
        {
            // we delete this element
            int el = elScores[saved].first;
            currentAns++;

            for (int j = 0; j < 10; j++)
            {
                if (dist[j] && j != el)
                    dist[j] -= freq[j][el];

                dist[el] = 0;
            }
            maxDistance = *max_element(dist.begin(), dist.end());
            saved++;
        }

        ans[d - 1] = currentAns;
    }
    if (ans.size() == 0)
        cout << 0;

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }
}

int main()
{
    IOFilesOpen();

    // int t;
    // cin >> t;
    // while (t--)

    solve();
    return 0;
}