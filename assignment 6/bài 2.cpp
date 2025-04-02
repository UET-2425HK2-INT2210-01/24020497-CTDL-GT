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

    void deleted(int value) {
        int index;
        for (int i = 0; i < size; i++) {
            if (heap[i] == value) {
                index = i;
                break;
            }
        }
            heap[index] = heap[size-1];
        heapifyDown(index);
        size--;
    }
};

int main() {
    min_heap a;
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

    a.deleted(6);
    a.deleted(13);
    a.deleted(35);
    for (int i = 0; i < a.size; i++) {
        cout << a.heap[i] << " ";
    }
}
