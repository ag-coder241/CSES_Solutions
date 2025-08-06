#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;
const int MOD = 1e9 + 7;
void bfs(vector<vector<int>>&adj , int node , vector<int>&vis , bool& flag){
    // mark node 1 or 2
    vis[node] = 1;
    queue<pair<int,int>>q;
    q.push({node, 1});

    while(!q.empty()){
        pair<int,int>temp = q.front();
        int n = temp.first;
        int type = temp.second;
        q.pop();

        for(auto it: adj[n]){
            int neigh = it;
            if(type == vis[neigh]) flag = false;
            if(vis[neigh] == -1){
                if(type == 1) {
                    q.push({neigh, 2}); 
                    vis[neigh] = 2;
                }
                else{
                    q.push({neigh ,1}); 
                    vis[neigh] = 1;
                }
            }
        }
    }
}

void solve() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>>adj(n+1);
    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // bipartite graph
    vector<int>vis(n+1, -1);
    bool flag = true;

    for(int i = 0; i < n ; i++){
        if(vis[i] == -1){
            bfs(adj, i , vis , flag);
        }
    }

    if(flag == false){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for(int i = 1 ; i <= n ; i++){
        cout << vis[i] << " ";
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
