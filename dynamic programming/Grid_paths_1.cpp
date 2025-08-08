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

int func(vector<vector<char>>& mat , int row , int col , vector<vector<int>>&dp){
    // base case
    if(row < 0 || col < 0) return 0; // crossed the boundary
    if(row == 0 && col == 0) return 1; // reached the destination

    if(dp[row][col] != -1) return dp[row][col];

    // can move left or up
    int left = 0;
    if(col-1 >= 0 && mat[row][col-1] != '*') left = func(mat , row , col-1 , dp);
    int up = 0;
    if(row-1 >= 0 && mat[row-1][col] != '*') up = func(mat, row-1, col , dp);

    return dp[row][col] = (left + up) % MOD;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<char>>mat(n, vector<char>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            char c;
            cin >> c;
            mat[i][j] = c;
        }
    }
    
    vector<vector<int>>dp(n , vector<int>(n , 0));

    if(mat[n-1][n-1] == '*' || mat[0][0] == '*'){
        cout << 0 << endl;
        return;
    }

    // int ans =  func(mat, n-1, n-1  ,dp);
    // cout << ans << endl;
    // return;

    // tabulation approach

    dp[0][0] = 1;
    
    for(int row = 0; row < n ; row++){
        for(int col = 0; col < n ; col++){
            // if(mat[row][col] == '*'){
            //     continue;
            // }

            if (row == 0 && col == 0) continue;
            int left = 0;
            if(col-1 >= 0 && mat[row][col-1] != '*') left = dp[row][col-1];
            int up = 0;
            if(row-1 >= 0 && mat[row-1][col] != '*') up = dp[row-1][col];

            dp[row][col] = (left + up) % MOD;
        }
    }

    int ans = dp[n-1][n-1];
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
