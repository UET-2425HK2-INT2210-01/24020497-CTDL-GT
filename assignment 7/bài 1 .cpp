#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input("numbers.txt");//file input
    ofstream output("numbers.sorted");//file output
    int *a=new int[100];//Khai báo mảng động
  int num;
    // Đọc các số từ file
    while (input >> num) {
        a.push_back(num);
    }
    int n = a.size();//Gán n là số lượng phần tử
    // Vòng lặp bên ngoài của thuật toán Selection Sort
for (int j = 0; j < n; j++) {
    // Vòng lặp bên trong tìm phần tử nhỏ nhất còn lại trong đoạn [j+1, n-1]
    for (int i = j + 1; i < n; i++) {
        // Nếu phần tử hiện tại nhỏ hơn phần tử tại vị trí j, thì hoán đổi
        if (a[j] > a[i]) {
            swap(a[i], a[j]); // Hoán đổi 2 phần tử để đưa phần tử nhỏ hơn về trước
        }
    }
}
// Ghi các số đã sắp xếp vào file output
for (int i = 0; i < n; i++) {
    output << a[i]; // Ghi số thực thứ i vào file
    if (i != n - 1) output << " "; // Thêm dấu cách sau số, trừ số cuối
}
    input.close();
    output.close();
    return 0;
}
