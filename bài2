#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
    node(int value) {
        data = value;
        next = nullptr;
     }
};

class linkedlist {
public:
    node* head;
    int size = 0;
    linkedlist() {
        head = nullptr;
    }
    void insert(int p, int data) {
        node* newnode = new node(data);
        if (p == 0) {
            newnode->next = head;
            head = newnode;
        }
        else {
            node* tmp = head;
            if (p > size) {
                return;
            }
            else {
                for (int i = 0; i < p - 1; ++i) {
                    tmp = tmp->next;
                }
                newnode->next = tmp->next;
                tmp->next = newnode;
            }
        }
        ++size;
    }
    void del (int p) {
        node* travel = head;
        if (head == nullptr || p > size) {
            return;
        }
        else {
            if (p == 0) {
                head = head->next;
                delete travel;
            }
            else {
                for (int i = 0; i < p-1; ++i) {
                    travel = travel->next;
                }
                node* tmp = travel->next;
                travel->next = travel->next->next;
                delete tmp;
                }
            --size;
            }
        }
    void print() {
        node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }
};

int main()
{
    linkedlist l;
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s == "insert") {
            int a, b;
            cin >> a >> b;
            l.insert(a, b);
        }
        if (s == "delete") {
            int a;
            cin >> a;
            l.del(a);
        }
    }
    l.print();
}
