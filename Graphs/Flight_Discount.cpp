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

    vector<vector<ll>>dist(n , vector<ll>(2, LLONG_MAX)); // with and without using a coupon

    // using dijsktra but trying to apply coupon at every stop if it hasn't been applied before
    priority_queue<pair<pair<ll,int>, int> , vector<pair<pair<ll,int>, int>> , greater<>>pq;
    // {{price, node} , used}

    pq.push({{0, 0} ,0});
    dist[0][0] = 0;
    dist[0][1] = 0;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.first.second;
        ll totprice =it.first.first;
        int used = it.second;

        if(totprice > dist[node][used]) continue; // don't process old nodes

        for(auto k : adj[node]){
            // go to the adjacent neighbours
            if(used == 0){
                // didn't used the coupon on this path
                // can use or can't use
                int adjNode = k.first;
                ll price = k.second;
                ll half = (ll)price/2LL;

                if(totprice + price < dist[adjNode][0]){
                    dist[adjNode][0] = totprice + price;
                    pq.push({{dist[adjNode][0] , adjNode} , 0});
                }
                

                // use the coupon
                if(totprice + half < dist[adjNode][1]){
                    dist[adjNode][1] = totprice + half;
                    pq.push({{dist[adjNode][1] , adjNode} , 1});
                }
            }
            else{
                // already used the coupon
                int adjNode = k.first;
                ll price = k.second;

                if(totprice + price < dist[adjNode][1]){
                    dist[adjNode][1] = totprice + price;
                    pq.push({{dist[adjNode][1] , adjNode} , 1});
                }
            }

        }
    }

    ll ans = min(dist[n-1][0] , dist[n-1][1]);
    cout << ans << endl;
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
