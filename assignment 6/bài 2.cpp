#include <iostream>
#include <utility>  // Thư viện để sử dụng swap()
using namespace std;

class min_heap { // Khai báo lớp min_heap (cây heap nhỏ)
public:
    int* heap; // Con trỏ đến mảng động lưu trữ các phần tử của heap
    int size;  // Kích thước hiện tại của heap

    // Constructor khởi tạo heap với kích thước ban đầu là 0 và cấp phát mảng động
    min_heap() {
        size = 0;
        heap = new int[1000]; // Cấp phát động một mảng có kích thước tối đa 1000 phần tử
    }

    // Hàm đẩy phần tử lên trên nếu nó nhỏ hơn phần tử cha
    void push_up(int index) {
        int parent;
        while (index > 0) { // Duyệt lên đến khi đạt đỉnh hoặc không cần đổi chỗ nữa
            parent = (index - 1) / 2; // Tìm chỉ số của phần tử cha
            if (heap[index] < heap[parent]) { // Nếu phần tử con nhỏ hơn cha, đổi chỗ
                swap(heap[index], heap[parent]);
                index = parent; // Tiếp tục xét với phần tử cha
            } else {
                break; // Nếu đã đúng vị trí thì dừng
            }
        }
    }

    // Hàm thêm một phần tử vào heap
    void push(int value) {
        heap[size] = value; // Đặt phần tử vào vị trí cuối cùng
        push_up(size); // Đưa phần tử về đúng vị trí trong heap
        size++; // Tăng kích thước heap
    }

    // Hàm đẩy phần tử xuống dưới để duy trì tính chất heap
    void heapifyDown(int index) {
        int left = 2 * index + 1;  // Chỉ số con trái
        int right = 2 * index + 2; // Chỉ số con phải
        int smallest = index; // Giả sử node hiện tại là nhỏ nhất

        // So sánh với con trái
        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        // So sánh với con phải
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        // Nếu smallest đã thay đổi, cần hoán đổi và tiếp tục đệ quy
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // Hàm xóa một phần tử khỏi heap
    void deleted(int value) {
        int index = -1; // Biến lưu chỉ số của phần tử cần xóa
        for (int i = 0; i < size; i++) { // Tìm vị trí của phần tử cần xóa
            if (heap[i] == value) {
                index = i;
                break;
            }
        }
        if (index == -1) return; // Nếu không tìm thấy phần tử thì không làm gì

        heap[index] = heap[size - 1]; // Thay thế phần tử cần xóa bằng phần tử cuối cùng
        size--; // Giảm kích thước của heap
        heapifyDown(index); // Đưa phần tử về đúng vị trí để đảm bảo tính chất heap
    }
};

int main() {
    min_heap a; // Tạo một cây min heap

    // Thêm các phần tử vào heap
    a.push(2);
    a.push(1);
    a.push(10);
    a.push(6);
    a.push(3);
    a.push(8);
    a.push(7);
    a.push(13);
    a.push(20);
    a.push(14);
    a.push(0);
    a.push(35);

    // Xóa một số phần tử khỏi heap
    a.deleted(6);
    a.deleted(13);
    a.deleted(35);

    // In ra các phần tử của heap sau khi thêm và xóa
    for (int i = 0; i < a.size; i++) {
        cout << a.heap[i] << " ";
    }
}
