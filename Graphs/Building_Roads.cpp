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

void dfs(vector<vector<int>>&adj , int city , vector<int>&vis){
    vis[city] = 1;
    for(auto it: adj[city]){
        if(!vis[it]){
            dfs(adj , it, vis);
        }
    }
}

void solve() {
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>>adj(n+1); // 1 based indexing
    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // number of roads to be built = number of components- 1
    vector<pair<int,int>>roads; // roads to be built
    vector<int>vis(n+1, 0);
    int required = 0;
    vector<int>comp; 
   
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            comp.push_back(i);
            dfs(adj , i , vis);
            required++;
        }
    }

    required--;

    for(int i = 0; i < comp.size()-1 ; i++){
        roads.push_back({comp[i] , comp[i+1]});
    }

    // . . . . 

    cout << required << endl;
    
    for(int i = 0; i < required ; i++){
        // print the roads
        pair<int,int>temp = roads[i];
        int a = temp.first;
        int b = temp.second;

        cout << a << ' ' << b << endl;
    }

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
