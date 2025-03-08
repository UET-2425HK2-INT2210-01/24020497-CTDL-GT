#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};

class  linkedlist{
public:
    node* head;
    int size=0;
    linkedlist() : head(nullptr) {}
    void append(int value) {
        node* newnode = new node();
        newnode->data = value;
        if (head == nullptr) {
            head = newnode;
        }
        else {
            node* temp=head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        size++;
    }
    void search(int value) {
        node* temp=head;
        int index = 0;
        while (temp->next != nullptr) {
            if (temp->data == value) {
                cout << index;
                return;
            }
            temp = temp->next;
            index++;
        }
        cout << "NO";
    }
    void reverse() {
        int* arr = new int[size];
        node* temp = head;
        int index = 0;
        while (temp->next != nullptr) {
            arr[index] = temp->data;
            temp = temp->next;
            index++;
        }
        temp = head;
        while (temp->next != nullptr) {
            temp->data = arr[index];
            cout << temp->data << " ";
            index--;
            temp = temp->next;
       }
    }
};

int main() {
    int n;
    cin >> n;
    linkedlist list;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "append") {
            int value;
            cin >> value;
            list.append(value);
        }
        else if (s == "search") {
            int value;
                cin >> value;
                list.search(value);
        }
        else if (s == "reverse") {
            list.reverse();
        }
    }
}
