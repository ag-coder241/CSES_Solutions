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

bool check(vector<vector<pair<int,ll>>>adj , int node, int n){
    queue<int>q;
    q.push(node);
    vector<int>vis(n , 0);
    vis[node] = 1;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto it : adj[temp]){
            int adjNode = it.first;
            if(!vis[adjNode]){
                vis[adjNode] = 1;
                q.push(adjNode);
            }
        }
    }

   return vis[n-1] == 1;
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

    vector<int>nodes;

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
                nodes.push_back(u); // collect all nodes which are part of a cycle
            }
        }
    }
        // check if this node is connecting to node n-1 and 0 using bfs
        for(int i = 0; i < nodes.size() ; i++){
            if(check(adj , nodes[i] , n)){
                cout << -1 << endl;
                return;
            }
        }

        cout << -1 * dist[n-1] << endl;
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
