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

int func(vector<int>&price, vector<int>&pages, int ind , int budget , vector<vector<int>>&dp){
    // base case
    if(ind == 0){
        if(budget >= price[0]) return pages[0];
        else return 0;
    }

    if(dp[ind][budget] != -1) return dp[ind][budget];

    int notPick = func(price, pages, ind-1, budget ,dp);
    int pick = INT_MIN;
    if(budget >= price[ind]) pick = pages[ind] + func(price, pages, ind-1, budget-price[ind] ,dp);

    return dp[ind][budget] = max(notPick , pick);

}

void solve() {
    int n,x;
    cin >> n >> x;
    vector<int>price(n);
    vector<int>pages(n);

    for(int i = 0 ; i < n ; i++) cin >> price[i];
    for(int i = 0 ; i < n ; i++) cin >> pages[i];

    vector<vector<int>>dp(n , vector<int>(x+1 , 0));

    // int ans = func(price, pages, n-1 , x , dp);

    // tabulation approach
    for(int i = 1; i <= x; i++){
        if(i >= price[0]) dp[0][i] = pages[0];
        else dp[0][i] = 0;
    }

    for(int ind = 1; ind < n ; ind++){
        for(int budget = 1; budget <= x ; budget++){
            int notPick = dp[ind-1][budget];
            int pick = INT_MIN;
            if(budget >= price[ind]) pick = pages[ind] + dp[ind-1][budget-price[ind]];

            dp[ind][budget] = max(notPick , pick);

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
