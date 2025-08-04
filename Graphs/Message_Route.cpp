#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
const int MOD = 1e9 + 7;

void solve() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>>adj(n+1);

    for(int i = 0; i < m ; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // print the min number of computers on the path and also the path
    vector<int>parent(n+1, -1);

    // 1 ---> n
    vector<int>vis(n+1 , 0);
    queue<int>q; 
    q.push(1);
    // {node, number of computers it took to reach}
    bool connected = false;

    while(!q.empty()){
       int node = q.front();
       q.pop();

        if(node == n){
            connected = true;
            break;
        }

        for(auto it: adj[node]){
            if(!vis[it]){
                parent[it] = node;
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    if(connected == false){
        cout << "IMPOSSIBLE";
        return;
    }

    // trace back the path
    vector<int>path;
    int a = n;
    while(a != 1){
        path.push_back(a);
        a = parent[a];
    }

    path.push_back(1);

    int len = path.size();

    reverse(path.begin() , path.end());
    cout << len << endl;
    for(int i = 0 ; i < len ; i++){
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
