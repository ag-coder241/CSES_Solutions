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

void dfs(vector<vector<pair<int,ll>>>adj,  int node1 , int node2 , vector<int>&parent , vector<int>&vis){
    // base case
    vis[node2] = 1; // mark as visited
    if(node2 == node1) return;
    
    // go to the adjacent nodes
    for(auto it: adj[node2]){
        int node = it.first;
        if(!vis[node]){
            parent[node] = node2;
            dfs(adj, node1, node, parent, vis);
        }
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    // directed graph

    vector<vector<pair<int,ll>>>adj(n);
    for(int i = 0 ; i < m ;i++){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--; // 0 based indexing
        adj[a].push_back({b, -1*c});
    }

    // we have to go from room 1 to n 
    // one way tunnel only
    // edge wt can be negative only
    // we have to find the length of the longest path form 1 to n
    // algorithm name -> "bellman ford"
    // relax all edges sequentially m-1 times
    vector<ll>dist(n , LLONG_MAX);
    dist[0] = 0; // from source node 0

    int node1 = -1;
    int node2 = -1;

    for(int k = 0; k < n-1 ; k++){
        // m-1 times
        for(int i = 0; i < n ; i++){
            for(auto it : adj[i]){
                int u = i;
                int v = it.first;
                ll wt  = it.second;
                // u -- > v
                if(dist[u] != LLONG_MAX && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }

    // try to relax edges one more time
    for(int i = 0; i < n ; i++){
        for(auto it : adj[i]){
            int u = i;
            int v = it.first;
            ll wt = it.second;

            if(dist[u] != LLONG_MAX && dist[u] + wt < dist[v]){
                // u is a part of cycle
                node1 = u;
                node2 = v;
                break;
            }
        }
    }

    if(node1 == -1 ){
        cout << "NO" << endl;
        return;
    }


    // find the cycle using dijsktra
    // node1 ----------> node2
    // start with node2
    vector<int>parent;
    vector<int>vis(n , 0);
    parent[node2] = node2;
    dfs(adj, node1 , node2 , parent , vis);

    // construct the path back from the parent 
    vector<int>path;
    path.push_back(node1); //u

    while(node1 != node2){
        int p = parent[node1];
        path.push_back(p);
    }

    path.push_back(node2); // v

    for(int i = 0; i < path.size() ; i++){
        cout << path[i] << " ";
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
