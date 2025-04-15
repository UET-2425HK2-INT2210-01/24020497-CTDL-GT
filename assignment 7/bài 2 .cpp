int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> A(m, vector<int>(n));
    vector<vector<int>> prefix(m, vector<int>(n, 0));

    // Nhập ma trận và tính prefix theo hàng
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            prefix[i][j] = A[i][j] + (j > 0 ? prefix[i][j - 1] : 0);
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
