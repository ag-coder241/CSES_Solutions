#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
const int MOD = 1e9 + 7;

void dfs(vector<vector<char>>&mat, int row, int col, vector<vector<int>>&vis , int n , int m){
    vis[row][col] = 1;

    // go to his adjacent neighbours
    vector<int>dr = {-1, 0, 1, 0};
    vector<int>dc = {0, 1, 0, -1};
    
    for(int i = 0 ; i < 4 ; i++){
        int nrow = row + dr[i];
        int ncol = col + dc[i];

        if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == '.'){
            dfs(mat , nrow , ncol , vis, n , m);
        }
    }

}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>>mat(n, vector<char>(m));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < m ; j++){
            cin >> mat[i][j];
        }
    }

    int rooms = 0;
    vector<vector<int>>vis(n , vector<int>(m , 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            if(!vis[i][j] && mat[i][j] == '.'){
                dfs(mat, i , j , vis, n, m );
                rooms++;
            }

        }
    }

    cout << rooms << endl;

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
