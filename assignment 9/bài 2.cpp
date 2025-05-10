#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 10005;
vector<int> adj[MAXN];
vector<bool> visited(MAXN, false);
vector<int> dist(MAXN, -1);
vector<int> parent(MAXN, -1);

// BFS từ đỉnh start
void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

// Truy vết đường đi từ start đến end
vector<int> getPath(int start, int end) {
    vector<int> path;
    if (!visited[end]) return path; // không có đường đi

    for (int v = end; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n, m;
    cin >> n >> m;  // số đỉnh và số cạnh

    // Nhập danh sách cạnh
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // đồ thị vô hướng
    }

    int start, end;
    cin >> start >> end;

    bfs(start);

    if (!visited[end]) {
        cout << "No path from " << start << " to " << end << endl;
    }
    else {
        vector<int> path = getPath(start, end);
        cout << dist[end] << endl;
    }

    return 0;
}
