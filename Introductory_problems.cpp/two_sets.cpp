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
    ll n;
    cin >> n;
    
    ll totSum = (n*(n+1))/2;
    if(totSum % 2 != 0){
        cout << "NO" << endl;
        return;
    }
    ll required = totSum/2;

    // required should be a integer

    vector<int>vis(n+1 ,0);
    ll cnt1 = 0;

    for(ll i = n; i >= 1 ; i--){
        if(i <= required && vis[i] == 0){
            required = required - i;
            vis[i] = 1;
            cnt1++;
        }
        else{
            // just add the required value
            if(required >= 1 && vis[required] == 0){
                vis[required] = 1;
                required = 0;
                cnt1++;
            }
        }
    }

    if(required > 0){
        cout << "NO" << endl;
        return;
    }


    cout << "YES" << endl;
    cout << cnt1 << endl;
    for(ll i = 1; i <= n ; i++){
        if(vis[i] == 1){
            cout << i << " ";
        }
    }

    cout << n-cnt1 << endl;
    for(ll i = 1; i <= n ; i++){
        if(vis[i] != 1){
            cout << i << " ";
        }
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
