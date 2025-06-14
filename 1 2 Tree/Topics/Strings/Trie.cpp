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
    int countStrings(string str )
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
    { Node *current = root;
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


int main()
{
    Trie trie;
    trie.insert("hello");
    trie.insert("hell");
    trie.insert("heaven");
    
    cout << "Count of strings with prefix 'he': " << trie.countPrefixes("he") << endl; // Output: 3
    cout << "Count of strings with prefix 'hell': " << trie.countPrefixes("hell") << endl; // Output: 2
    cout << "Count of strings with prefix 'hello': " << trie.countPrefixes("hello") << endl; // Output: 1
    cout << "Count of strings with prefix 'heaven': " << trie.countPrefixes("heaven") << endl; // Output: 1
    cout << "Count of strings with prefix 'hi': " << trie.countPrefixes("hi") << endl; // Output: 0
    
    cout << "Count of exact string 'hello': " << trie.countStrings("hello") << endl; // Output: 1
    cout << "Count of exact string 'hell': " << trie.countStrings("hell") << endl; // Output: 1
    cout << "Count of exact string 'heaven': " << trie.countStrings("heaven") << endl; // Output: 1
    cout << "Count of exact string 'hi': " << trie.countStrings("hi") << endl; // Output: 0

    return 0;
}