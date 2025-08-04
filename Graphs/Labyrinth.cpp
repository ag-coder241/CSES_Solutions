#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m));
    int startR, startC, endR, endC;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'A') {
                startR = i;
                startC = j;
            } else if (mat[i][j] == 'B') {
                endR = i;
                endC = j;
            }
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1})); // to track back the path
    vector<vector<char>> moveTaken(n, vector<char>(m, 0)); // to get the moves for the path

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    vector<char> dir = {'U', 'R', 'D', 'L'};

    queue<pair<int,int>> q;
    q.push({startR, startC});
    vis[startR][startC] = 1;

    bool found = false;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == endR && c == endC) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] &&
                (mat[nr][nc] == '.' || mat[nr][nc] == 'B')) {

                vis[nr][nc] = 1; // mark when pushing
                parent[nr][nc] = {r, c};
                moveTaken[nr][nc] = dir[i];
                q.push({nr, nc});
            }
        }
    }

    if (!found) {
        cout << "NO\n";
        return;
    }

    // Reconstruct path
    string path;
    int r = endR, c = endC;
    while (make_pair(r, c) != make_pair(startR, startC)) {
        path += moveTaken[r][c];
        auto p = parent[r][c];
        r = p.first;
        c = p.second;
    }
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
