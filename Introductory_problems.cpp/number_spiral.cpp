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
    for(int i = 0; i < k; i++){
        ll row, col;
        cin >> row >> col;
        ll Y = row;
        ll X = col;

        if (Y > X) {
        ll ans = (Y - 1) * (Y - 1);
        ll add = 0;

        if (Y % 2 != 0) {
            add = X;
        }
        else {
            add = 2 * Y - X;
        }
        cout << ans + add << "\n";
    }
    else {

        ll ans = (X - 1) * (X - 1);
        ll add = 0;

        if (X % 2 == 0) {
            add = Y;
        }
        else {
            add = 2 * X - Y;
        }
        cout << ans + add << "\n";
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
