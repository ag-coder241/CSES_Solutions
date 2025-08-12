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
    int n;
    cin >> n;
    
    // find the missing number
    // sort the array and index should match the numbr
    vector<int>arr;
    for(int i = 0 ; i < n-1 ; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin() , arr.end());
    int num = -1;

    for(int i = 0 ; i < n-1 ; i++){
        if(arr[i] != i+1){
            num = i + 1; 
            break;
        }
    }

    if(num == -1) cout << n << endl;
    else cout << num << endl;
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
