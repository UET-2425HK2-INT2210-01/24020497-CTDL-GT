#include <iostream>
#include <vector>

using namespace std;
vector<int> adj[10005];    
vector<bool> visited(10005, false);
vector<vector<int>> components;

void dfs(int u, vector<int>& component) {
    visited[u] = true;
    component.push_back(u);

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, component);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;  // n: số đỉnh, m: số cạnh

    // Nhập đồ thị
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Đồ thị vô hướng
    }

    // Tìm các connected components
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, component);
            components.push_back(component);
        }
    }

    // In kết quả
    cout << components.size();

    return 0;
}
