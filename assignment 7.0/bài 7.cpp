#include <iostream>
using namespace std;

// Hàm đệ quy phụ: truyền kết quả đang xây dần
int reverseHelper(int n, int result) {
    if (n == 0) return result;
    return reverseHelper(n / 10, result * 10 + (n % 10));
}

// Hàm chính: gọi reverseHelper với kết quả ban đầu là 0
int reverseNumber(int n) {
    bool isNegative = n < 0;
    n = abs(n);
    int reversed = reverseHelper(n, 0);
    return isNegative ? -reversed : reversed;
}

int main() {
    int n;
    cin >> n;

    cout << reverseNumber(n) << endl;
    return 0;
}
