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
    vector<long long>arr(n);
    for(int i = 0; i < n ; i++){
        cin >> arr[i];
    }

    // minimum moves required to make the array increasing
    long long moves = 0;
    for(int i = 1 ;i < n ; i++){
        if(arr[i] >= arr[i-1]){
            continue;
        }
        else{
            // make it atleast arr[i+1]
            long long temp = arr[i-1] - arr[i];
            arr[i] = arr[i-1];
            moves += temp;
        }
    }

    cout << moves << endl;
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
