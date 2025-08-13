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

long long find(long long i){
    long x = (i*i)*(i*i - 1);
    long y = x/2;
    long z = 4 * (i-1) * (i-2);
    return y-z;

}

void solve() {
    int n;
    cin >> n;

    // purely observation and mathematical base 
    // put one knight -> n*n ways
    // other knight -> n*n-1 ways
    // total ways we can put them -> (n*n)*(n*n-1)/2 ways because they are identical knights
    // now we have subtract the ways they can attack each other 
    // they can attack in two ways in a 2*3 and 3*2 rectangle
    // number of ways we can arrange 2*3 rectangle vertically in a square will be by taking n-1 rows
    // and horizontally by n-2 cols
    // hence total would be 2 * (n-1) * (n-2) and simillary for the 3*2

    // final formula becomes -> ((n*n)*(n*n-1))/2 - (4*(n-1)*(n-2)) ways

    for(int i = 1; i <= n ; i++){

        long long ans = find(i);
        cout << ans << endl;
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
