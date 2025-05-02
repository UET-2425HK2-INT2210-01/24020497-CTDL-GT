#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k; // Nhập vào số học sinh (n) và tổng số tuổi cần kiểm tra (k)

    bool age[100]; // Tạo mảng
    for (int i = 0; i <= k; i++) {
        age[i] = 0; // Khởi tạo tất cả các giá trị là false (chưa thể đạt được)
    }
    age[0] = 1; // Tổng 0 luôn có thể đạt được (chọn không ai cả)

    int* data = new int[100]; // Mảng lưu tuổi của từng học sinh
    for (int i = 0; i < n; i++) {
        cin >> data[i]; // Nhập tuổi học sinh thứ i
        if (data[i] <= k) {
            age[data[i]] = 1; // Nếu tuổi học sinh <= k thì đánh dấu tổng đó đạt được từ 1 người
        }
    }

    // Duyệt từng học sinh để cập nhật các tổng có thể tạo được
    for (int i = 0; i < n; i++) {
        // Duyệt ngược để tránh dùng lại kết quả vừa cập nhật
        for (int j = k; j >= data[i]; j--) {
            if (age[j - data[i]]) {
                age[j] = 1; // Nếu đã có thể tạo tổng j - data[i], thì cộng thêm data[i] sẽ được tổng j
            }
        }
    }

    // Sau khi cập nhật xong, kiểm tra xem có tạo được tổng k không
    if (age[k]) {
        cout << "YES"; // Có thể tạo tổng k từ một số học sinh
    }
    else {
        cout << "NO"; // Không thể tạo tổng k
    }
}
