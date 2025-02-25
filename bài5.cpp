#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class linkedlist {
public:
    node* head;
    linkedlist() : head(nullptr) {}

    void push(int x) {
        node* newnode = new node();
        newnode->data = x;
        newnode->next = nullptr;
        if (head == nullptr) {
            head = newnode;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void pop() {
        if (head == nullptr) return; //  khi danh sách rỗng

        if (head->next == nullptr) { //khi chỉ có một phần tử
            delete head;
            head = nullptr;
            return;
        }

        node* temp = head;
        while (temp->next->next != nullptr) { // Dừng trước phần tử cuối cùng
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }


};

int main() {
    int n;
    cin >> n;
    linkedlist stack;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            stack.push(x);
        }
        else if (s == "pop") {
            stack.pop();
        }
    }

    node* temp = stack.head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
