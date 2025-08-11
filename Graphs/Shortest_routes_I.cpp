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

void dijkstra(vector<vector<pair<int,long long>>>&adj , int src , vector<long long>& distance){
    // this function will return the min distance from src to node
    priority_queue<pair<long long,int> ,vector<pair<long long,int>> , greater<>>pq;
    pq.push({0LL, src});
    distance[src] = 0LL;

    while(!pq.empty()){
        auto it = pq.top();
        long long dist = it.first;
        int temp = it.second;
        pq.pop();

        if(dist > distance[temp]) continue; // dont process this, we can already reach it a at a better distance

        for(auto it : adj[temp]){
            int adjNode = it.first;
            long long edgeWt = it.second;

            if(dist + edgeWt < distance[adjNode]){
             distance[adjNode] = dist + edgeWt;
             pq.push({dist + edgeWt , adjNode});
            }
        }
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,long long>>>adj(n);
    for(int i = 0 ; i < m ; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b,c}); // directed graph
    }

    // we can use this algorithm to solve this
    vector<long long>distance(n , LLONG_MAX);
    dijkstra(adj , 0 , distance);

    // use dijsktra for every node
    for(int i = 0; i < n ; i++){
         cout << distance[i] << " ";
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
