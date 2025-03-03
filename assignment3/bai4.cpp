#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
class Linkedlist {
public:
    node* head;
    int len;
    Linkedlist() :head(nullptr), len(0) {}
};

class Queue {
public:
    Linkedlist list;
    void enqueue(int value) {
        node* newnode = new node();
        newnode->data = value;
        if (list.head == nullptr) {
            list.head = newnode;
        }
        else {
            node* temp = list.head;
            while (temp->next == nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        list.len++;
    }
    void dequeue() {
        if (list.head == nullptr) {
            return;
        }
        else {
            node* temp = list.head;
            list.head = temp->next;
            delete temp;
            list.len--;
        }
    }
    void print() {
        node* p = list.head;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
    }
};

int main() {
    int t;
    cin >> t;
    string s;
    Queue q;
    while (t--) {
        cin >> s;
        if (s == "enqueue") {
            int n;
            cin >> n;
            q.enqueue(n);
        }
        else if (s == "dequeue") {
            q.dequeue();
        }
    }
    q.print();
}
