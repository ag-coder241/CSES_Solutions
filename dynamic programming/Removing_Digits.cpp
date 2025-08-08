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

int func(int n ,vector<int>& dp){
    /// base case
    if(n < 0) return 1e8;
    if(n == 0) return 0; // valid case

    if(dp[n] != -1) return dp[n];


    // try to subtract every digit 
    int temp = n;
    int steps = INT_MAX;

    while(n != 0){
        int digit = n % 10;
        if(digit != 0) steps = min(steps , 1 + func(temp - digit , dp));
        n = n / 10;
    }

    return dp[n] = steps;
}

void solve() {
    int n ;
    cin >> n;

    // try to subtract each digit 
    // vector<int>dp(n+1 , -1);
    // int ans = func(n , dp);
    // cout << ans << endl;

    // tabulation approach
    vector<int>dp(n+1 , 0);

    // possible values of n
    for(int i = 1; i <= n ; i++){
        int temp = i;
        int steps = INT_MAX;
        // i is the number
        // temp is for storing the orignal number

        while(temp != 0){
            int digit = temp % 10;
            if(digit != 0 && i - digit >= 0) steps = min(steps , 1 + dp[i - digit]);
            temp = temp / 10;
        }

        dp[i] = steps;
    }

    int ans = dp[n];
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
