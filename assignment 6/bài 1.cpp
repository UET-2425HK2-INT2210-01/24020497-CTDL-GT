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
        if (value < root->data) {//Duyệt node trong cây nếu < root thì duyệt node con bên trái
            insert(root->left, value);//Bằng đệ quy
        }
        else if (value > root->data) {//Duyệt node trong cây nếu >root thì duyệt node con bên phái
            insert(root->right, value);//Bằng đệ quy
        }
    }

    node* minright(node* temp) {//Tìm node nhỏ nhất của nhánh(hay node trái sâu nhất)
        while (temp && temp->left != nullptr) {//Sử dụng vòng lặp while tìm node sao cho node đấy hoặc con bên trái của nó null
            temp = temp->left;
        }
        return temp;//Trả về node tìm được
    }

    void deleted(node*& root, int value) {//Hàm xóa phần tử trong cây
        if (root == nullptr) return;//Điều kiện dừng đệ quy

        if (value < root->data) {//Duyệt node trong cây nếu < root thì duyệt node con bên trái
            deleted(root->left, value);//Bằng đệ quy
        }
        else if (value > root->data) {//Duyệt node trong cây nếu >root thì duyệt node con bên phái
            deleted(root->right, value);//Bằng đệ quy
        }
        else {//Khi root là node cần xóa
            if (root->left == nullptr) {//Nếu node con trái null thì đẩy node con phải lên làm root
                node* temp = root->right;
                delete root;
                root = temp;
            }
            else if (root->right == nullptr) {//Nếu node con phải null thì đẩy node con trái lên làm root
                node* temp = root->left;
                delete root;
                root = temp;
            }
            else {//Trường hợp có cả 2 con
                node* temp = minright(root->right);//tìm node nhỏ nhất nhánh bên phải
                root->data = temp->data;//Thay cho node cần xóa
                deleted(root->right, temp->data);//Xóa node
            }
        }
    }

    void inorder(node* root) {//Hàm inorder để check nếu inorder ra dãy số tăng dần thì đúng
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};

int main() {
    binarytree tree;//Thêm 2,1,10,6,3,8,7,13,20
    tree.insert(tree.root, 2);
    tree.insert(tree.root, 1);
    tree.insert(tree.root, 10);
    tree.insert(tree.root, 6);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 8);
    tree.insert(tree.root, 7);
    tree.insert(tree.root, 13);
    tree.insert(tree.root, 20);
//Thêm 14,0,35
    tree.insert(tree.root, 14);
    tree.insert(tree.root, 0);
    tree.insert(tree.root, 35);
//Xóa 6,13,35
    tree.deleted(tree.root, 6);
    tree.deleted(tree.root,13);
    tree.deleted(tree.root,35);
    return 0;
}
