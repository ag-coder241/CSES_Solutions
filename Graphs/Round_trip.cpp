#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> parent, visited;
int startNode = -1, endNode = -1;

bool dfs(int node, int par) {
    visited[node] = 1;
    parent[node] = par;

    for (int neigh : adj[node]) {
        if (neigh == par) continue;

        if (!visited[neigh]) {
            if (dfs(neigh, node)) return true;
        } else {
            // Found a back edge -> cycle detected
            startNode = neigh;
            endNode = node;
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, -1)) break;
    }

    if (startNode == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    // Reconstruct path from endNode back to startNode
    vector<int> cycle;
    cycle.push_back(startNode);
    for (int v = endNode; v != startNode; v = parent[v]) {
        cycle.push_back(v);
    }
    cycle.push_back(startNode); // close the cycle

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for (int x : cycle) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
