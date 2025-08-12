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
    string s;
    cin >> s;

    int n = s.size();
    char c = s[0];
    int count = 0;
    int maxi = -1;

    for(int i = 0; i < n ; i++){

        if(s[i] == c){
            count++;
        }
        else{
            maxi = max(maxi , count);
            c = s[i];
            count = 1;
        }

    }

    maxi = max(maxi , count);

    cout << maxi << endl;
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
