#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>

using namespace std;
const int MOD = 1e9 + 7;
using ll = long long;

vector<ll> dijsktra(vector<vector<pair<int,ll>>>adj , int start , int n){
    vector<ll>dist(n, LLONG_MAX);
    dist[start] = 0LL;
    priority_queue<pair<ll,int> , vector<pair<ll,int>> , greater<>>pq;
    pq.push({0LL, start});

    while(!pq.empty()){
        auto [d ,node] = pq.top();
        pq.pop();

        if(dist[node] < d) continue; // we have better than this already

        // go to it's neighbours
        for(auto it : adj[node]){
            int adjNode = it.first;
            ll wt = it.second;

            if(d + wt < dist[adjNode]){
                dist[adjNode] = d + wt;
                pq.push({d+wt, adjNode});
            }
        }
    }

   return dist;

}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>>dist(n, vector<ll>(n , LLONG_MAX));
    for(int i = 0 ; i < m ; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--; // converting to 0 based indexing
        dist[a][b] = min(dist[a][b], c); // handle multiple edges
        dist[b][a] = min(dist[b][a], c); // remove this if directed
    }

    for(int i = 0 ; i < n ; i++) dist[i][i] = 0;
    
    for(int k = 0; k < n; k ++){
        for(int i = 0;  i < n ; i++){
            // go via every node
            for(int j = 0; j < n ; j++){
                int u = i;
                int v = j;
                if(dist[u][k] < LLONG_MAX && dist[k][v] < LLONG_MAX){
                dist[u][v] = min(dist[u][v] , dist[u][k] + dist[k][v]);
                }
            }
        }
    }

    vector<pair<int,int>>query(q);
    // vector<vector<ll>> distFromSource(n);
    for(int i = 0 ; i < q ; i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        query[i] = {a,b};
        
        if(dist[a][b] != LLONG_MAX) cout  << dist[a][b] << endl;
        else cout << -1 << endl;
    }

    return;
        // int src = query[i].first;
        // int dst = query[i].second;

    //     if(distFromSource[src].empty()) {
    //         distFromSource[src] = dijsktra(adj, src, n);
    //     }
    //     ll ans = distFromSource[src][dst];
    //     if(ans == LLONG_MAX) cout << -1 << "\n";
    //     else cout << ans << "\n";
    // }

    // optimisation -> store the source node and the corresponding ending nodes
    // apply dijsktra for a particular source node

    // floyd warshall algorithm
    // go via every node

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
