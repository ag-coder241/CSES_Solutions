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

int func(vector<int>&coins , int sum , int ind , vector<vector<int>>&dp){
    // base case
    if(sum == 0) return 0; // achieved the target
    else if (ind == 0){
        if(sum % coins[0] == 0) return sum / coins[0];
        else return 1e9; // can't be possible
    }

    if(dp[ind][sum] != -1 ) return dp[ind][sum];

    int notTake = func(coins , sum , ind-1 , dp);
    int take = 1e9;
    if(sum >= coins[ind]) take = 1 + func(coins , sum - coins[ind] , ind , dp); // stay at the same index

    return dp[ind][sum] = min(take , notTake);
}

void solve() {
    int n , x;
    cin >> n >> x;
    vector<int>coins(n);
    for(int i = 0; i < n ; i++){
        cin >> coins[i];
    }
    // achieve the target in min number of coins
    // vector<vector<int>>dp(n , vector<int>(x+1 , -1));
    // int ans = func(coins , x , n-1 , dp);

    // tabulation approach
    vector<vector<int>>dp(n , vector<int>(x+1 , 0));

    for(int i = 0; i <= x ; i++){
        if(i % coins[0] == 0) dp[0][i] = i / coins[0];
        else dp[0][i] = 1e9;
    }

    for(int ind = 1 ; ind < n ; ind++){
        for(int sum = 0 ; sum <= x ;sum++){
            int notTake = dp[ind-1][sum];
            int take = 1e9;
            if(sum >= coins[ind]) take = 1 + dp[ind][sum - coins[ind]]; // stay at the same index
             dp[ind][sum] = min(take , notTake);
        }
    }

    int ans = dp[n-1][x];

    if(ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
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
