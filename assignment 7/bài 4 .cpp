#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
// Hàm chuyển số thập phân sang nhị phân dạng chuỗi có length bit
string toBinary(int num, int totalBits) {
    string binary = bitset<64>(num).to_string();  // Tối đa 64 bit
    // Lấy phần bên phải có totalBits độ dài
    return binary.substr(64 - totalBits);
}

// Hàm nhóm chuỗi nhị phân theo sizePerGroup (vd 8, 4, 16...)
string formatBinaryGroup(const string& bin, int sizePerGroup) {
    string result;
    int len = bin.length();
    for (int i = 0; i < len; i++) {
        result += bin[i];
        // Nếu đến cuối một nhóm và chưa hết chuỗi, thêm khoảng trắng
        if ((i + 1) % sizePerGroup == 0 && i + 1 < len) {
            result += ' ';
        }
    }
    return result;
}
int main() {
    int n;
    cin >> n;
    int maxbinary = 0;
    for (int i = 0; i < n; i++) {
        maxbinary += pow(2, i);
   }
    for (int i = 0; i < maxbinary; i++) {
       string ans= toBinary(i, n);
       cout << ans << endl;
    }
}
