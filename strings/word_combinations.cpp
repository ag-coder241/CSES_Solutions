#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;
const int MOD = 1e9 + 7;
using ll = long long;

vector<int>dp(5005);
vector<vector<int>> trie(1e6 + 5, vector<int>(26));
vector<bool> isEndofWord(1e6 + 5);
int trieNodeCount = 0;

void insertWordInTrie(string& word){
    int currentNode = 0;
    for(char& ch : word){
        if(!trie[currentNode][ch - 'a']){
            trie[currentNode][ch - 'a'] = ++trieNodeCount;
        }
        currentNode = trie[currentNode][ch - 'a'];
    }

    isEndofWord[currentNode] = true;
}

int countWays(int start, string& S)
{
    int currentNode = 0, ways = 0;
    for (int i = start; i < S.size(); i++) {
        if (!trie[currentNode][S[i] - 'a'])
            return ways;
        currentNode = trie[currentNode][S[i] - 'a'];
        if (isEndofWord[currentNode])
            ways = (ways + dp[i + 1]) % MOD; 
    }
    return ways;
}

void solve() {
    string s;
    cin >> s;
    int k ;
    cin >> k;
    vector<string>dict(k);
    for(int i = 0 ; i < k ; i++){
        cin >> dict[i];
    }

    // how many ways we can create the word using the words in the dictionary
    // can choose a word multiple times

    for(int i = 0 ; i < k; i++){
        insertWordInTrie(dict[i]);
    }

    dp[s.size()] = 1;  // only one way to form empty string 
    for (int i = s.size() - 1; i >= 0; i--) {
        dp[i] = countWays(i, s);
    }
    // The answer is the number of ways to form the string from index 0
    cout << dp[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; 
    // cin >> t;  // Uncomment if multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}
