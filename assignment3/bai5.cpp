#include <iostream>
using namespace std;
class Stack {
private:
    int* a;
    int size;
public:
    Stack() {
        a = nullptr;
        size = 0;
    }
    void push(int value) {
        int* newArray = new int[size + 1];
        for (int i = 0; i < size; i++) {
            newArray[i] = a[i];
        }
        newArray[size] = value;
        size++;
        delete[] a;
        a = newArray;
    }
    void pop() {
        int* newArray = new int[size - 1];
        for (int i = 0; i < size - 1; i++) {
            newArray[i] = a[i];
        }
        size--;
        delete[] a;
        a = newArray;
    }
    void print() {
        for (int i = 0; i < size; i++) {
            cout << a[i];
        }
    }
};

int main() {
    int t;
    cin >> t;
    string s;
    Stack q;
    while (t--) {
        cin >> s;
        if (s == "push") {
            int n;
            cin >> n;
            q.push(n);
        }
        else if (s == "pop") {
            q.pop();
        }
    }
    q.print();
}
