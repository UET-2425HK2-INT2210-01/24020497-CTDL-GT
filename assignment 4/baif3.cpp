#include <iostream>

using namespace std;


struct node {
    int data;
    node* next;
};

class Stack {
public:
    node* head;

    Stack() : head(nullptr) {}

    void push(char x) {
        node* newnode = new node();
        newnode->data = x;
        newnode->next = head;  
        head = newnode;
    }

    void pop() {
        if (head == nullptr) return; 

        node* temp = head;
        head = head->next;
        delete temp;
    }
};
bool check(string s) {
    Stack a;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            a.push(s[i]);
        }
        if (s[i] == '}' &&'{' == a.head->data) {
            a.pop();
        }
        if (s[i] == ']' && '[' == a.head->data) {
            a.pop();
        }
        if (s[i] == ')' && '(' == a.head->data) {
            a.pop();
        }
    }
    if (a.head == nullptr) {
        return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if (check(s)) {
        cout << "Valid";
    }
    else {
        cout << "Invalid";
    }
}
