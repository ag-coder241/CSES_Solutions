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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>desire(n);
    for(int i = 0 ; i < n ; i++){
        cin >> desire[i];
    }
    vector<int>size(m);
    for(int i = 0 ; i < m ; i++){
        cin >> size[i];
    }

    int count = 0;

    // for each appartment size find how many applicants are willing to take it
    int i = 0;
    int j = 0;
    sort(desire.begin() , desire.end());
    sort(size.begin() , size.end());

    while(i <= n-1 && j <= m-1){
        if(abs(desire[i] - size[j]) <= k){
            // we can give this one a apartment
            count++;
            i++;
            j++;
        }
        else if(desire[i] > size[j]){
            // this applicant has greater size desire
            // move to the next apartmen
            j++;
        }
        else if(desire[i] < size[j]){
            // this one has smaller desire but unfortunately the smaller size apartments have been given away
            // move to the next applicant
            i++;
        }
    }

    cout << count << endl;
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
