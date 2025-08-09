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
    int n, x;
    cin >> n >> x;
    vector<int>arr(n);
    for(int i = 0 ;i < n ; i++){
        cin >> arr[i];
    }

    /// for min in each box try to fit 2 children
    int ans = 0;
    sort(arr.begin() , arr.end());
    int i = 0;
    int j = n-1;


    // logic = lighter childs are the key , they can be clubbed with the heavier childs

    while(i <= j){
        int child1 = arr[i];
        int child2 = arr[j];

        // for this child try to find if arr[i+1] can sit with him
        if(child1 + child2 <= x){
            // we can club them
            ans++;
            i++;
            j--;
        }
        else if(child1 == child2){
            // same child
            ans++;
            i++;
        }
        else{
            // only club the heavier child
            // try to club the lighter child with someone less heavy
            j--;
            ans++;
        }
        
    }

    // {5 7} {8} {8} {8} {8}{ 9} {9} {10} {10}

    cout << ans << endl;
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
