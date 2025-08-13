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
    int k;
    cin >> k;
    for(int i = 0; i < k ; i++){
        ll a,b;
        cin >> a >> b;

        ll p = (2 * a) - b;
        ll q = (2 * b) - a;
        if(p < 0 ||q < 0 || p % 3 != 0 || q % 3 != 0){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
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
