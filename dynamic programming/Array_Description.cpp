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

// int func(vector<int>&arr, int ind, int prev , int m, vector<vector<int>>&dp){
//     // base case
//     if(ind == 0 && arr[0] != 0){
//         if(prev == -1 || abs(arr[0] - prev) <= 1) return 1;
//         else return 0;
//     }
//     else if(ind == 0 && arr[0] == 0){
//         // check for all possible values
//         int count = 0;
//         for(int i = 1 ; i <= m ; i++){
//             if(prev == -1 || abs(i-prev) <= 1) count++;
//         }
//         return count;
//     }

//     if(dp[ind][prev +1 ] != -1) return dp[ind][prev +1 ];
    
//     int ways = 0;
//     if(arr[ind] != 0) return dp[ind][prev +1 ] = func(arr, ind-1 , arr[ind] , m , dp) % MOD;
//     else{
//         for(int i = 1 ; i <= m ; i++){
//             if(prev == -1 || abs(i-prev) <= 1){
//                 ways = ways + func(arr, ind-1, i, m , dp) % MOD;
//             }
//     }
    
//     return dp[ind][prev +1] = ways % MOD;
//     }
// }

// void solve() {
//     int n,m;
//     cin >> n >> m;
//     vector<int>arr(n);
//     for(int i= 0; i < n ; i++){
//         cin >> arr[i];
//     }

//     // we have to fill possible values from 1 to m 
//     // also keep check of the condition that max difference can be 1 between adjacent elements

//     vector<vector<int>>dp(n , vector<int>(m+1, -1));
//     // shift prev by 1 index

//     // base case
//     if(arr[0] == 0){
//         for(int i = 1; i <= m ; i++){
//             dp[0][i] = 1;
//         }
//     }
//     else{
//             dp[0][arr[0]] = 1;
//     }

//     for(int i = 1 ; i < n ; i++){

//         if(arr[0] != 0){

//         }
//         else{

//         }
//     }

//     int ans = 0;
//     for(int i = 0 ; i < n ; i++){
//         ans += dp[n-1][]
//     }
//     cout << ans << endl;
//     return;

//     // int ans = func(arr, n-1, -1 , m , dp);
//     // cout << ans << endl;
//     // return;
// }

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    // dp[i][j] = number of ways to fill up to index i with value j
    vector<vector<int>> dp(n, vector<int>(m + 2, 0));  // m+2 to avoid bounds check

    // base case
    if (arr[0] == 0) {
        for (int j = 1; j <= m; ++j)
            dp[0][j] = 1;
    } else {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; ++i) {
        if (arr[i] == 0) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = ((dp[i - 1][j] + dp[i - 1][j - 1]) % MOD + dp[i - 1][j + 1]) % MOD;
            }
        } else {
            int j = arr[i];
            dp[i][j] = ((dp[i - 1][j] + dp[i - 1][j - 1]) % MOD + dp[i - 1][j + 1]) % MOD;
        }
    }

    // sum up all possibilities at the last position
    int ans = 0;
        if(arr[n-1] == 0) {
            for(int i = 1; i <= m; i++) {
                ans = (ans + dp[n-1][i]) % MOD;
            }
        } else {
       ans = dp[n-1][arr[n-1]];
    }

    cout << ans << '\n';
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
