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

int findWays(int sum , vector<int>&dp){
    // base case
    if(sum == 0) return 1; // achieved the target
    // at each chance we can choose any number between 1 and 6
    if(dp[sum] != -1) return dp[sum];
    int ways = 0;
    for(int i = 1 ; i <= 6 ; i++){
        if(sum >= i) ways = (ways + findWays(sum-i , dp)) % MOD; // only executed when sum is greater than the number
    }

    return dp[sum] = ways % MOD;
}

void solve() {
    int n;
    cin >> n;
    // we can take an element more than once also
    vector<int>dp(n+1 , -1);
    int ans = findWays(n, dp) % MOD;

    cout << ans << endl;
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
