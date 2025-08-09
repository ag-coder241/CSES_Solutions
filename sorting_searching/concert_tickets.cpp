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
    int n,m;
    cin >> n >> m;
    vector<int>ticket(n);
    for(int i = 0; i < n; i++){
        cin >> ticket[i];
    }
    vector<int>customer(m);
    for(int i = 0 ; i < m ; i++){
        cin >> customer[i];
    }
    
    multiset<int>mpp;

    for(int i = 0 ; i < n ; i++){
        mpp.insert(ticket[i]);
    }

    vector<int>ans(m);

    for(int i = 0 ; i < m ; i++){
        // go through every customer
        int temp = customer[i];
        multiset<int>::iterator itr = mpp.upper_bound(temp);

        if(itr == mpp.begin()){
            // if it points to the first element then no price is affordable for the customer
            ans[i] = -1;
        }
        else{
            itr--;
            ans[i] = (*itr);
            mpp.erase(itr);
        }

    }

    for(int i = 0; i < m ; i++){
        cout << ans[i] << endl;
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
