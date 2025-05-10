#include <iostream>
#include <vector>

using namespace std;

// Khai báo danh sách kề (adjacency list) cho tối đa 10^4 đỉnh
vector<int> adj[10005];    

// Mảng đánh dấu đỉnh đã được duyệt hay chưa
vector<bool> visited(10005, false);

// Danh sách các thành phần liên thông, mỗi thành phần là 1 vector chứa các đỉnh
vector<vector<int>> components;

// Hàm DFS theo phong cách truyền thống
void dfs(int u, vector<int>& component) {
    visited[u] = true;          // Đánh dấu đỉnh u đã thăm
    component.push_back(u);     // Thêm đỉnh u vào thành phần liên thông hiện tại

    // Duyệt qua tất cả các đỉnh kề với u
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];      // Lấy đỉnh kề v

        if (!visited[v]) {
            dfs(v, component);  // Gọi đệ quy DFS cho v nếu chưa được thăm
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;  // Nhập số đỉnh n và số cạnh m

    // Nhập danh sách các cạnh
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        // Thêm cạnh u-v vào danh sách kề (vì là đồ thị vô hướng nên thêm 2 chiều)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Tìm các thành phần liên thông
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            vector<int> component;         // Tạo 1 thành phần mới
            dfs(i, component);             // Gọi DFS từ đỉnh i
            components.push_back(component);  // Thêm thành phần này vào danh sách
        }
    }

    // In ra số lượng thành phần liên thông tìm được
    cout << components.size() << endl;

    return 0;
}

