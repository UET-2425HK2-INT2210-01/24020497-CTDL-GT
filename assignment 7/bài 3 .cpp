#include <iostream>
using namespace std;
int gcd(int a, int b) {//Hàm geatest common devisor
    while (b != 0) {// Vòng lặp
        int temp = a % b;//Khai báo biến temp là số dư của a chia cho b
        a = b;//Gán a bằng b
        b = temp;//Gán b bằng temp
    }
    return a;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout<<gcd(m, n);
    return 0;
}
