#include <iostream>
using namespace std;

class Queue {
public:
    vector<int> arr;
    int size;
    int capacity;
    int front;

    Queue(int qSize) {
        size = 0;
        front = 0;
        capacity = qSize;
        arr.resize(qSize);
    }
    void enqueue(int x) {
        if (size == capacity) {
            return;
        }
        arr[size] = x;
        size++;
    }
    void dequeue() {
        if (size == 0) {
            return;
        }
        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }
        size--;
    }

};

int main() {
    int size;
    cin >> size;
    Queue* q = new Queue(size);

}
