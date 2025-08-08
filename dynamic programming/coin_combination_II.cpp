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

void solve() {
    int n , x;
    cin >> n >> x;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    // number of ways to produce the desired sum
    // we can use a coin unlimited number of times
    // vector<vector<int>>dp(n , vector<int>(x+1 , -1));

    // int ans =  func(arr, n-1, x , dp);

    //tabulation 
    vector<vector<int>>dp(n , vector<int>(x+1 , 0));

    for(int i = 0; i < n ; i++){
        dp[i][0] = 1; // target 0 is always achievable
    }

    for(int i = 1; i <= x ; i++){
        if(i % arr[0] == 0) dp[0][i] = 1;
    }

    for(int ind = 1 ; ind < n ; ind++){
        for(int target = 1 ; target <= x ; target++){
            int notTake = dp[ind-1][target];
            int take = 0;
            if(target >= arr[ind]) take = dp[ind][target-arr[ind]]; // stay at the same ind

            dp[ind][target] = (take + notTake) % MOD;
        }
    }

    int ans = dp[n-1][x];

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
