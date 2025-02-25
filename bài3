#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
    node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class doublylinkedlist {
public:
    node* head;
    node* tail;
    int size = 0;
    doublylinkedlist() {
        head = nullptr;
        tail = nullptr;
    }
    void append(int data) {
        node* newnode = new node(data);
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
        }else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        ++size;
    }
    int triplets() {
        int count = 0;
        if (size < 3) {
            return count;
        }
        else {
            int count = 0;
            node* p = head->next;
            while (p->next != nullptr) {
                int a = p->prev->data;
                int b = p->data;
                int c = p->next->data;
                if (a + b + c == 0) {
                    ++count;
                }
                p = p->next;
            }
            return count;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    doublylinkedlist list;
    for (int i = 0; i < t; ++i) {
        int a;
        cin >> a;
        list.append(a);
    }
    cout << list.triplets();
}
