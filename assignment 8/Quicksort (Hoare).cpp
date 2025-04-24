#include <iostream>
using namespace std;

// Hàm phân hoạch sử dụng sơ đồ Hoare
int partition(int a[], int left, int right) {
    int pivot = a[left];         // Chọn pivot là phần tử đầu tiên
    int i = left - 1;            // i sẽ chạy từ trái qua phải
    int j = right + 1;           // j sẽ chạy từ phải qua trái

    while (true) {
        // Di chuyển i sang phải cho đến khi a[i] >= pivot
        while (true) {
            i++;
            if (a[i] >= pivot) break;
        }

        // Di chuyển j sang trái cho đến khi a[j] <= pivot
        while (true) {
            j--;
            if (a[j] <= pivot) break;
        }

        // Nếu i và j đã vượt nhau, kết thúc phân hoạch
        if (i >= j) return j;

        // Nếu chưa, hoán đổi a[i] và a[j]
        swap(a[i], a[j]);
    }
}

// Hàm quicksort đệ quy
void quicksort(int a[], int left, int right) {
    if (left < right) {
        // Phân hoạch mảng và lấy chỉ số phần tử chia
        int temp = partition(a, left, right);

        // Gọi đệ quy sắp xếp hai phần còn lại
        quicksort(a, left, temp);       // bên trái vùng chia
        quicksort(a, temp + 1, right);  // bên phải vùng chia
    }
}

int main() {
    int n;
    cin >> n;               // Nhập số lượng phần tử
    int a[100];             // Mảng tối đa 100 phần tử (giả định)

    // Nhập các phần tử vào mảng
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Gọi quicksort trên toàn mảng
    quicksort(a, 0, n - 1);

    // In kết quả sau khi sắp xếp
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
