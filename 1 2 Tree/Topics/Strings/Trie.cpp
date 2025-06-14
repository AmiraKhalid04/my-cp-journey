#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <iomanip>
#include <list>
#include <deque>
#include <queue>
#include <bitset>
#include <stack>
#include <climits>

typedef long long ll;
ll mod = 1000000007;

struct Trie
{
    struct Node
    {
        Node *children[26];
        int prefix, end;
        Node()
        {
            prefix = end = 0;
            for (int i = 0; i < 26; i++)
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

            int idx = str[i] - 'a';
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
            int idx = str[i] - 'a';
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
            int idx = str[i] - 'a';
            if (current->children[idx] == nullptr)
            {
                return 0;
            }
            current = current->children[idx];
        }
        return current->prefix;
    }
};
void IOFilesOpen()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int main()
{
    // IOFilesOpen();
    Trie trie;
    int q, n;
    cin >> n >> q;
    while (n--)
    {
        string str;
        cin >> str;
        trie.insert(str);
    }

    while (q--)
    {
        string str;
        cin >> str;
        cout << trie.countPrefixes(str) << endl;
    }

    return 0;
}