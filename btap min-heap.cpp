#include <iostream>
#include <utility>
using namespace std;

class min_heap {
public:
    int* heap;
    int size;
    min_heap() {
        size = 0;
        heap = new int[1000];
    }
    void push_up(int index) {
        int parent;
        while (index > 0) {
            parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }
    void push(int value) {
        heap[size] = value;
        push_up(size);
        size++;
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void pop() {
        if (size == 0) {
            return;
        }
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }
};

int main() {
    min_heap a;
    a.push(10);
    a.push(14);
    a.push(19);
    a.push(26);
    a.push(31);
    a.push(42);
    a.push(27);
    a.push(44);
    a.push(35);
    a.push(33);
    a.pop();//xóa gốc
    a.push(8);//thêm 8
    for (int i = 0; i < a.size; i++) {
        cout << a.heap[i]<<" ";
    }
}
