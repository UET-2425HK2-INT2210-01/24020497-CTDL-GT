#include <iostream>

using namespace std;

struct node {
    int data;
    int priority;
    node* next;
    node* pre;
    node(int d, int p) : data(d), priority(p), next(nullptr), pre(nullptr) {}
};

class priority_queue {
public:
    node* head;
    int size;

    priority_queue() : head(nullptr), size(0) {}

    bool empty() {
        return head == nullptr;
    }

    void enqueue(int value, int value_priority) {
        node* newnode = new node(value, value_priority);
        if (empty()) { 
            head = newnode;
            size++;
            return;
        }
        node* temp = head;
        if (value_priority > head->priority) {
            newnode->next = head;
            head->pre = newnode;
            head = newnode;
        }
        else {
            while (temp->next && value_priority <= temp->next->priority) {
                temp = temp->next;
            }
            newnode->next = temp->next;
            if (temp->next) {
                temp->next->pre = newnode;
            }
            temp->next = newnode;
            newnode->pre = temp;
        }
        size++;
    }

    void dequeue() {
        if (empty()) {  
            return;
        }
        node* temp = head;
        head = head->next;
        if (head) {
            head->pre = nullptr;
        }
        delete temp;
        size--;
    }

    void display() {
        node* temp = head;
        while (temp) {
            cout << "(" << temp->data << ", " << temp->priority << ") ;";
            temp = temp->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    priority_queue list;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "enqueue") {
            int value, priority;
            cin >> value >> priority;
            list.enqueue(value, priority);
        }
        else if (s == "dequeue") {
            list.dequeue();
        }
    }
    list.display();
    return 0;
}
