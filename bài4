#include <iostream>

using namespace std;

class node {
    public:
    int data;
    node* next;
    node* prev;
    node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class queue {
    public:
    int size = 0;
    node* head;
    node* tail;
    queue() {
        head = nullptr;
        tail = nullptr;
    }
    void enqueue(int data) {
        node* newnode = new node(data);
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
        }
        else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        ++size;
    }
    void dequeue() {
        if (head == nullptr) {
            return ;
        }
        else {
            node* tmp = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            else {
                head->prev = nullptr;
            }
            delete tmp;
            --size;
        }
    }
    void print() {
        node* p = head;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    string s;
    queue q;
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
