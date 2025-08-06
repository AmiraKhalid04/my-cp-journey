#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define CHAR_NUM 10

// This only works for only lowercase string
struct Trie
{
    struct Node
    {
        int prefix, end;
        Node *children[CHAR_NUM];
        Node()
        {
            prefix = end = 0;
            for (int i = 0; i < CHAR_NUM; i++)
            {
                children[i] = nullptr;
            }
        }
    };

    Node *root = new Node();

    void insert(string str)
    {
        Node *current = root;

        for (int i = 0; i < str.size(); i++)
        {
            int idx = str[i] - '0';
            if (current->children[idx] == nullptr)
            {
                current->children[idx] = new Node();
            }
            current = current->children[idx];
            current->prefix++;
        }
        current->end++;
    }

    int countStrings(string str)
    {
        Node *current = root;

        for (int i = 0; i < str.size(); i++)
        {
            int idx = str[i] - '0';

            if (current->children[idx] == nullptr)
            {
                return 0;
            }

            current = current->children[idx];
        }

        return current->end;
    }

    int countPrefixes(string str)
    {
        Node *current = root;

        for (int i = 0; i < str.size(); i++)
        {
            int idx = str[i] - '0';

            if (current->children[idx] == nullptr)
            {
                return 0;
            }

            current = current->children[idx];
        }

        return current->prefix;
    }
};

bool cmp(pair<char, int> &a,
         pair<char, int> &b)
{
    return a.second > b.second;
}

// Function to sort the map according
// to value in a (key-value) pairs
vector<pair<char, int>> sortMap(map<char, int> &M)
{
    vector<pair<char, int>> A;

    for (auto &it : M)
    {
        A.push_back(it);
    }

    sort(A.begin(), A.end(), cmp);

    return A;
}

int LCS(string a, string b)
{

    int n = a.size();
    int m = b.size();

    vector<int> prev(n + 1, 0);
    vector<int> current(n + 1, 0);

    int maximum = 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        bool match = false;
        bool repeated = false;
        for (int j = 1; j <= n; j++)
        {
            if (a[j - 1] == b[i - 1])
            {
                current[j] = prev[j - 1] + 1;
                if (current[j] > prev[j])
                {
                    match = true;
                }
                else
                {
                    repeated = true;
                }
            }
            else
            {
                current[j] = max(current[j - 1], prev[j]);
            }
        }
        if (match)
        {
            maximum = max(maximum, current[n]);
            prev = current;
        }
        else if (repeated)
        {
            fill(prev.begin(), prev.end(), 0);
            i--;
        }
        else
        {
            fill(prev.begin(), prev.end(), 0);
        }
    }

    return maximum;
}

// // Driver program to test methods of graph class
// int main()
// {
//     int V = 5;
//     int src = 0;

//     // edge list format: {u, v, weight}
//     vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10}};

//     vector<int> result = dijkstra(V, edges, src);

//     // Print shortest distances in one line
//     for (int dist : result)
//         cout << dist << " ";

//     return 0;
// }

void bfs(vector<vector<int>> &graph, int S,
         vector<int> &par, vector<int> &dist)
{
    // queue to store the nodes in the order they are
    // visited
    queue<int> q;
    // Mark the distance of the source node as 0
    dist[S] = 0;
    // Push the source node to the queue
    q.push(S);

    // Iterate till the queue is not empty
    while (!q.empty())
    {
        // Pop the node at the front of the queue
        int node = q.front();
        q.pop();

        // Explore all the neighbours of the current node
        for (int neighbour : graph[node])
        {
            // Check if the neighbouring node is not visited
            if (dist[neighbour] == 1e9)
            {
                // Mark the current node as the parent of
                // the neighbouring node
                par[neighbour] = node;
                // Mark the distance of the neighbouring
                // node as distance of the current node + 1
                dist[neighbour] = dist[node] + 1;
                // Insert the neighbouring node to the queue
                q.push(neighbour);
            }
        }
    }
}

set<int> getFactors(int num, vector<int> &primes)
{
    set<int> factors;

    factors.insert(num);

    for (int i = 0; primes[i] * primes[i] <= num; i++)
    {
        int divisor = primes[i];

        while (divisor != 0 && num % divisor == 0)
        {
            factors.insert(divisor);
            factors.insert(num / divisor);
            divisor *= divisor;
        }
    }
    factors.insert(1);
    return factors;
}

vector<int> linearSieve(int n)
{
    vector<int> primes;
    vector<char> composite(n + 1, false);
    composite[0] = composite[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!composite[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && (i * primes[j]) <= n; j++)
        {
            composite[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    return primes;
}

void getAllFactors(map<int, set<int>> &factors)
{
    vector<int> primes = linearSieve(1e5);
    factors[1].insert(1);
    for (int i = 2; i <= 1e5; i++)
    {
        factors[i] = getFactors(i, primes);
    }
}

void solve()
{

    // factors code

    map<int, set<int>> factors;
    getAllFactors(factors);

    int q;

    int studentsNumber;
    cin >> studentsNumber;

    vector<int> enterTime(studentsNumber + 1);

    vector<int> studentGroup(studentsNumber + 1);

    vector<ll> groupMoney(1e5 + 1, 0);

    vector<vector<pair<int, ll>>> groups(1e5 + 1);
    cin >> q;
    int time = 0;

    while (q--)
    {
        time++;
        int queryNumber;
        cin >> queryNumber;
        // assign students to group
        if (queryNumber == 1)
        {
            int student;
            cin >> student;
            int group;
            cin >> group;
            studentGroup[student] = group;
            enterTime[student] = time;
        }
        // give groups money y
        else if (queryNumber == 2)
        {
            ll x, y;
            cin >> x >> y;

            // may be replaced for better memory

            groupMoney[x] += y;

            groups[x].push_back({time, groupMoney[x]});

            // update all multiples
        }

        else if (queryNumber == 3)
        {
            int student;
            cin >> student;

            int groupOfStudent = studentGroup[student];

            // multiples code
            ll totMoney = 0;

            for (auto it = factors[groupOfStudent].begin(); it != factors[groupOfStudent].end(); it++)
            {
                if (groups[*it].size())
                    totMoney += groups[*it][groups[*it].size() - 1].second;
                else
                    continue;

                auto it2 = lower_bound(groups[*it].begin(), groups[*it].end(), std::make_pair(enterTime[student], 0ll));
                if (it2 == groups[*it].begin() || groups[*it].size() == 0)
                {
                    continue;
                }
                it2--;
                ll moneyBefore = 0;

                // if (it2 < groups[*it].begin())
                // {
                //     moneyBefore = 0;
                // }
                // else
                // {
                moneyBefore = it2->second;
                // }

                totMoney -= moneyBefore;
            }

            cout << totMoney << endl;
        }
    }
}

int main()
{

    {

        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
    int t = 1e6;

    while (t--)
    {
        cout << 1;
    }
}