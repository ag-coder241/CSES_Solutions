#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <climits>

using namespace std;
const int MOD = 1e9 + 7;

void backtrack(vector<vector<pair<int,int>>>parent, string& path , int row , int col , int startRow, int startCol){

    while(row != startRow || col != startCol){
        auto it = parent[row][col];
        int prow = it.first;
        int pcol = it.second;

        // check the movement 
        if(prow == row + 1) path += 'U';
        else if(prow == row - 1) path += 'D';
        else if(pcol == col + 1) path += 'L';
        else if(pcol == col -1) path += 'R';

        row = prow;
        col = pcol;
    }

    reverse(path.begin() , path.end());
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<char>>mat(n , vector<char>(m));
    queue<pair<pair<int,int>,int>>q;
    // {{row , col} , dist}
    queue<pair<pair<int,int>,int>>qq;
    int startRow = -1;
    int startCol = -1;
    vector<vector<int>>minDistance(n, vector<int>(m, INT_MAX)); 

    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'M'){
                q.push({{i,j},0}); // store all the monsters
                minDistance[i][j] = 0;
            }
            else if(mat[i][j] == 'A'){
                qq.push({{i,j},0}); // keep the starting position
                startRow = i;
                startCol = j;
            }
        }
    }

    // strategy -> first find out min time take by the monsters to reach all the squares in the matrix
    // then start the bfs from our position and see if we can reach any boundary square before encountering any monster

    vector<int>drow = {-1, 0, 1, 0};
    vector<int>dcol = {0, 1, 0, -1};

    // to track the min distance of the monsters

    while(!q.empty()){
        auto it = q.front();
        int row = it.first.first;
        int col = it.first.second;
        int dist = it.second;
        q.pop();
        // keep track of minimum distance
        

        // this monster can move in the 4 directions
        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] != '#' &&
            dist + 1 < minDistance[nrow][ncol]){
                // valid cell
                minDistance[nrow][ncol] = dist + 1;
                q.push({{nrow , ncol} , dist+1});
            }
        }
    }

    vector<vector<int>>vis(n ,vector<int>(m, 0));
    vis[startRow][startCol] = 1;
    vector<vector<pair<int,int>>>parent(n, vector<pair<int,int>>(m));
    parent[startRow][startCol] = {startRow, startCol};

        while(!qq.empty()){
            auto it = qq.front();
            int row = it.first.first;
            int col = it.first.second;
            int dist = it.second;
            qq.pop();

            if(row == 0 || row == n-1 || col == 0 || col == m-1){
                // reached the boundary
                cout << "YES" << endl;
                string path = "";
                backtrack(parent, path , row, col , startRow , startCol);
                cout << path.size() << endl;
                cout << path << endl;
                return;
            }
             
            for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] != '#' && !vis[nrow][ncol] && dist + 1 < minDistance[nrow][ncol]){
                // valid cell(we can reach it before the monsters)
                parent[nrow][ncol] = {row,col}; // keep the parent to backtrack
                vis[nrow][ncol] = 1;
                qq.push({{nrow , ncol} , dist+1});
            }
        }

        }

        cout << "NO" << endl;
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
