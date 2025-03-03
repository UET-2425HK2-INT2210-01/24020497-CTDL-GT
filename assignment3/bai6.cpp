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

class Stack {
public:
    Linkedlist list;
    void push(int value) {
        node* newnode = new node();
        newnode->data = value;
        node* temp;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
        list.len++;
  }
    void pop(){
        node* temp;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        delete temp;
        list.len--;
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
