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
const ll INF = 10000000000000;

void dfs(ll u, ll p , vector<vector<ll>>&adj , vector<vector<ll>>&dp)
{
    dp[0][u] = 0;
    dp[1][u] = -INF; // currently not matched with any of the child

    for (ll v : adj[u]) {
        if (v == p) // if it's the parent skip it
            continue;

        dfs(v, u , adj, dp); // call the dfs of the child

        dp[0][u] += max(dp[1][v],dp[0][v]); // add the best possible from each child if we skip the node u

        ll opt = min(dp[0][v] - dp[1][v],(long long)0);
        dp[1][u] = max(dp[1][u], opt);
    }

    dp[1][u] += dp[0][u];
    dp[1][u]++;

    // dp[i][u] = dp[0][u] - max(dp[0][v] , dp[1][v]) + dp[0][v] + 1;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<ll>>adj(n+1);
    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    

    vector<vector<ll>>dp(2, vector<ll>(n+1, 0));
    dfs(1, -1 , adj, dp);

    cout << max(dp[0][1] , dp[1][1]) << endl;
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
