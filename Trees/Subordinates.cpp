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

void dfs(int node, vector<int>&sub , vector<int>&vis , vector<vector<int>>&adj){
    vis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it , sub , vis, adj);
        }
        
        // when the dfs call over for the child add the sub[child] to sub[node]
        sub[node] += sub[it] + 1;
    }

}

void solve() {
    int n;
    cin >> n;

    // kind of like a tree structure
    // first we have to make a tree structure
    vector<vector<int>>adj(n+1);
    for(int i = 0; i < n-1; i++){
        int a;
        cin >> a;
        // a is the boss of the i+2th employee
        adj[a].push_back(i+2);
    }

    vector<int>sub(n+1, 0);
    vector<int>vis(n+1, 0);

    dfs(1, sub , vis , adj);

    for(int i = 1; i < n+1; i++){
        cout << sub[i] << " ";
    }

    return;
    
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
