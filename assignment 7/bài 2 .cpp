int main() {
    int m, n;//Khai báo số hàng số cột
    cin >> m >> n;//Input

    vector<vector<int>> A(m, vector<int>(n));//Khai báo ma trận đầu vào
    vector<vector<int>> prefix(m, vector<int>(n, 0));//Khai báo ma trận preflix sum

    // Nhập ma trận và tính prefix theo hàng
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];//Input ma trận đầu vào
            prefix[i][j] = A[i][j] + (j > 0 ? prefix[i][j - 1] : 0);//Cách hoạt động của prefix sum (cộng từ số đấu đến số đó )
        }
    }

    int maxSum = INT_MIN;
    int finalTop = 0, finalLeft = 0, finalBottom = 0, finalRight = 0;

    // Duyệt các cặp cột
    for (int left = 0; left < n; left++) {
        for (int right = left; right < n; right++) {
            vector<int> temp(m, 0);

            for (int i = 0; i < m; i++) {
                temp[i] = prefix[i][right] - (left > 0 ? prefix[i][left - 1] : 0);
            }

            // Kadane 1D trên temp
            int sum = 0, tempTop = 0;
            for (int i = 0; i < m; i++) {
                sum += temp[i];
                if (sum > maxSum) {
                    maxSum = sum;
                    finalTop = tempTop;
                    finalBottom = i;
                    finalLeft = left;
                    finalRight = right;
                }
                if (sum < 0) {
                    sum = 0;
                    tempTop = i + 1;
                }
            }
        }
    }

    // In kết quả (đánh số từ 1 như đề bài yêu cầu)
    cout << finalTop + 1 << " " << finalLeft + 1 << " "
        << finalBottom + 1 << " " << finalRight + 1 << " "
        << maxSum << endl;

    return 0;
}
