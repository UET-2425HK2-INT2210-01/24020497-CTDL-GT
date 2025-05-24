#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Số đỉnh tối đa
const int MAX = 100005;

// Danh sách kề: adj[u] chứa danh sách các đỉnh mà u có cạnh đến
vector<int> adj[MAX];

// Mảng đánh dấu các đỉnh đã được thăm
vector<bool> visited;

// Stack lưu kết quả topo ngược (sẽ được pop ra sau)
stack<int> topo;

// Biến để kiểm tra xem đồ thị có chu trình không
bool hasCycle = false;

// Mảng đánh dấu các đỉnh đang nằm trên stack đệ quy DFS
// Dùng để phát hiện chu trình (kiểm tra cạnh ngược)
vector<bool> onStack;

// Hàm DFS bắt đầu từ đỉnh u
void dfs(int u) {
    visited[u] = true;    // Đánh dấu đỉnh u đã được thăm
    onStack[u] = true;    // Đặt u đang nằm trong stack (đang xét)

    for (int v : adj[u]) {   // Duyệt tất cả đỉnh kề với u
        if (!visited[v]) {
            // Nếu v chưa thăm, tiếp tục DFS
            dfs(v);

            // Nếu trong quá trình DFS phát hiện chu trình thì dừng lại
            if (hasCycle) return;
        }
        else if (onStack[v]) {
            // Nếu v đã thăm và vẫn còn nằm trên stack -> phát hiện chu trình
            hasCycle = true;
            return;
        }
    }

    // Ra khỏi đệ quy: đỉnh u không còn trên stack đệ quy nữa
    onStack[u] = false;

    // Đỉnh u đã được xử lý xong -> đẩy vào stack topo
    topo.push(u);
}

int main() {
    int n, m;
    cin >> n >> m;  // Nhập số đỉnh (n) và số cạnh (m)

    // Nhập m cạnh có hướng: u -> v
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  // Thêm cạnh vào danh sách kề
    }

    // Khởi tạo mảng visited và onStack với false
    visited.assign(n + 1, false);   // Đánh dấu chưa thăm đỉnh nào
    onStack.assign(n + 1, false);   // Không đỉnh nào đang nằm trên stack đệ quy

    // Gọi DFS cho từng đỉnh chưa thăm (nhiều thành phần liên thông)
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
            if (hasCycle) break;  // Nếu có chu trình thì dừng
        }
    }

    if (hasCycle) {
        // Nếu có chu trình thì không tồn tại thứ tự topo hợp lệ
        cout << "There is a cycle, no valid order.\n";
    }
    else {
        // In kết quả topo (đảo ngược thứ tự stack là thứ tự topo đúng)
        while (!topo.empty()) {
            cout << topo.top() << " ";
            topo.pop();
        }
        cout << endl;
    }

    return 0;
}
