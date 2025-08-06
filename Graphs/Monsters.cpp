#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int row;
    int col;
};

int drow[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};
char directionChar[4] = {'U', 'R', 'D', 'L'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Input grid
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> monsterTime(n, vector<int>(m, 1e9));
    vector<vector<int>> playerTime(n, vector<int>(m, -1));
    vector<vector<int>> parentDir(n, vector<int>(m, -1));

    queue<Node> monsterQueue;
    Node start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') {
                monsterQueue.push({i, j}); // store all the monsters intially
                monsterTime[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    // Multi-source BFS for monsters
    while (!monsterQueue.empty()) {
        Node current = monsterQueue.front();
        monsterQueue.pop();

        for (int k = 0; k < 4; k++) {
            int newRow = current.row + drow[k];
            int newCol = current.col + dcol[k];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                if (grid[newRow][newCol] != '#' && monsterTime[newRow][newCol] > monsterTime[current.row][current.col] + 1) {
                    monsterTime[newRow][newCol] = monsterTime[current.row][current.col] + 1;
                    monsterQueue.push({newRow, newCol});
                }
            }
        }
    }

    // BFS for player
    queue<Node> playerQueue;
    playerQueue.push(start);
    playerTime[start.row][start.col] = 0;

    while (!playerQueue.empty()) {
        Node current = playerQueue.front();
        playerQueue.pop();

        // Check if we reached boundary
        if ((current.row == 0 || current.row == n - 1 || current.col == 0 || current.col == m - 1) && grid[current.row][current.col] != '#') {
            // Reconstruct path
            string path;
            int r = current.row;
            int c = current.col;

            while (parentDir[r][c] != -1) {
                int p = parentDir[r][c];
                path.push_back(directionChar[p]);
                r -= drow[p];
                c -= dcol[p];
            }

            reverse(path.begin(), path.end());

            cout << "YES\n";
            cout << path.size() << "\n";
            cout << path << "\n";
            return 0;
        }

        // Explore neighbors
        for (int k = 0; k < 4; k++) {
            int newRow = current.row + drow[k];
            int newCol = current.col + dcol[k];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                if (grid[newRow][newCol] != '#' && playerTime[newRow][newCol] == -1) {
                    if (playerTime[current.row][current.col] + 1 < monsterTime[newRow][newCol]) {
                        playerTime[newRow][newCol] = playerTime[current.row][current.col] + 1;
                        parentDir[newRow][newCol] = k;
                        playerQueue.push({newRow, newCol});
                    }
                }
            }
        }
    }

    // If BFS finishes without reaching boundary
    cout << "NO\n";
    return 0;
}
