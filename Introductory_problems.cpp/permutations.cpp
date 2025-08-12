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

    if(n == 1){
        cout << 1 << endl;
        return;
    }

    // no adjacent element whose difference is 1
    if(n == 2 || n == 3){
        cout << "NO SOLUTION" << endl;
        return;
    }
    deque<int>ans;
    ans.push_back(3);
    ans.push_back(1);
    ans.push_back(4);
    ans.push_back(2);

    int i = 5;

    while(i <= n){
        // on odd chance append at the end
        // on even chance append at the begining
        if(i % 2 == 0){
            ans.push_front(i);
            if(i+1 <= n ){
                ans.push_back(i+1);
                i = i + 2;
            }
            else{
                i++;
            }
        }
        else{
            ans.push_back(i);
            if(i+1 <= n) {
                ans.push_front(i+1);
                i = i + 2;
            }
            else{
                i++;
            }
        }
    }

    for(int x : ans){
        cout << x << " ";
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
