#include <iostream>
using namespace std;

// Hàm phân hoạch theo sơ đồ Lomuto
int partition(int a[], int low, int high) {
    int pivot = a[high];         // Chọn phần tử cuối làm pivot
    int index = low - 1;         // index sẽ theo dõi vị trí đúng để đặt phần tử < pivot

    // Duyệt từ low đến high - 1
    for (int i = low; i < high; i++) {
        if (a[i] < pivot) {
            index++;             // Tăng chỉ số vùng phần tử < pivot
            swap(a[index], a[i]); // Đưa phần tử nhỏ hơn pivot về đầu
        }
    }

    // Đặt pivot vào đúng vị trí sau cùng
    swap(a[index + 1], a[high]);

    return index + 1;            // Trả về chỉ số pivot sau phân hoạch
}

// Hàm quicksort (sắp xếp nhanh) dùng đệ quy
void quicksort(int a[], int low, int high) {
    if (low < high) {                            // Điều kiện dừng: mảng con còn ít nhất 2 phần tử
        int temp = partition(a, low, high);      // Phân hoạch, temp là vị trí đúng của pivot

        // Gọi đệ quy sắp xếp 2 phần còn lại
        quicksort(a, low, temp - 1);             // Sắp xếp bên trái pivot
        quicksort(a, temp + 1, high);            // Sắp xếp bên phải pivot
    }
}

int main() {
    int n;
    cin >> n;               // Nhập số lượng phần tử
    int a[100];             // Mảng có tối đa 100 phần tử

    // Nhập các phần tử vào mảng
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Gọi quicksort để sắp xếp toàn bộ mảng
    quicksort(a, 0, n - 1); // Chú ý: low = 0, high = n - 1

    // In mảng sau khi sắp xếp
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
