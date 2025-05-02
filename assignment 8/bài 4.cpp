#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k; // Nhập số lượng đồ vật (n) và trọng lượng tối đa của balo (k)

    int data[100][100]; // Mảng lưu thông tin từng đồ vật: data[i][0] là trọng lượng, data[i][1] là giá trị

    // Nhập dữ liệu cho từng món đồ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> data[i][j]; // Nhập trọng lượng và giá trị của món đồ thứ i
        }
    }

    int temp[100][100]; // Mảng DP: temp[i][j] là giá trị lớn nhất với i đồ và balo sức chứa j

    // Khởi tạo bảng DP với 0
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            temp[i][j] = 0;
        }
    }

    // Bắt đầu điền bảng DP
    for (int i = 1; i <= n; i++) {         // Duyệt từng món đồ từ 1 đến n
        for (int j = 1; j <= k; j++) {     // Duyệt từng trọng lượng từ 1 đến k
            if (data[i][0] > j) {          // Nếu trọng lượng món đồ i > sức chứa hiện tại
                temp[i][j] = temp[i - 1][j]; // Không thể chọn món này, giữ nguyên giá trị từ dòng trước
            }
            else {
                // So sánh:
                // - Không chọn món i: temp[i - 1][j]
                // - Chọn món i: temp[i - 1][j - trọng lượng] + giá trị
                temp[i][j] = max(temp[i - 1][j], temp[i - 1][j - data[i][0]] + data[i][1]);
            }
        }
    }

    // In ra giá trị lớn nhất có thể đạt được với n món và balo trọng lượng k
    cout << temp[n][k];
}
