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

ll powmod(ll base , ll exp){
        ll result = 1;
        while(exp > 0){
            if(exp & 1){
                // if it's odd
                result = (result * base) % MOD;
            }

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return result;
}

void solve() {
    int n;
    cin >> n;

    // n 1's in the string
    // ans is pow(2,n);
    cout << powmod(2, n) << endl;
    
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
