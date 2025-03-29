#include <iostream>
using namespace std;

// Định nghĩa node của cây nhị phân
struct node {
    int data;
    node* left;
    node* right;

    node(int value) {//Khai báo node
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

//Định nghĩa lớp binarytree
class binarytree {
public:
    node* root = nullptr;//Khai báo gốc là null
    //Hàm thêm phần tử 
    void insert(node*& root, int value) {//Khai báo node gốc và giá trị cần thêm
        if (root == nullptr) { //Lệnh  để dừng đệ quy khi gốc bằng null
            root = new node(value);//Gán giá trị thêm vào
            return;
        }
        if (value < root->data) {//
            insert(root->left, value);
        }
        else if (value > root->data) {
            insert(root->right, value);
        }
    }

    node* minright(node* temp) {
        while (temp && temp->left != nullptr) {
            temp = temp->left;
        }
        return temp;
    }

    void deleted(node*& root, int value) {
        if (root == nullptr) return;

        if (value < root->data) {
            deleted(root->left, value);
        }
        else if (value > root->data) {
            deleted(root->right, value);
        }
        else {
            if (root->left == nullptr) {
                node* temp = root->right;
                delete root;
                root = temp;
            }
            else if (root->right == nullptr) {
                node* temp = root->left;
                delete root;
                root = temp;
            }
            else {
                node* temp = minright(root->right);
                root->data = temp->data;
                deleted(root->right, temp->data);
            }
        }
    }

    void inorder(node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};

int main() {
    binarytree tree;
    tree.insert(tree.root, 2);
    tree.insert(tree.root, 1);
    tree.insert(tree.root, 10);
    tree.insert(tree.root, 6);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 8);
    tree.insert(tree.root, 7);
    tree.insert(tree.root, 13);
    tree.insert(tree.root, 20);

    tree.insert(tree.root, 14);
    tree.insert(tree.root, 0);
    tree.insert(tree.root, 35);

    tree.deleted(tree.root, 6);
    tree.deleted(tree.root,13);
    tree.deleted(tree.root,35);
    return 0;
}
