#include <iostream>
using namespace std;
//Khai báo cấu trúc node
struct node {
    int data;//Gía trị của node
    node* firstchildren;//ptr nối với con đầu tiên bên trái của node
    node* nextsibling;//ptr nối các node anh em có cùng cha 
    node(int value) {//Khai báo giá trị
        data = value;
        firstchildren = nullptr;
        nextsibling = nullptr;
    }
};

//Khai báo class tree
class tree {
public:
    node* root = nullptr;//Gán gốc(root) bằng null

    //Khai báo hàm tìm kiếm với root và giá trị cần tìm kiếm
    node* find(node* root, int value) {
        if (root == nullptr) return nullptr;//Nếu cây rỗng thì trả về null
        if (root->data == value) return root;//Gía trị cần tìm là giá trị của gốc

        node* foundInChildren = find(root->firstchildren, value);//Sử dụng đệ quy để tìm kiếm ở phần con
        if (foundInChildren) return foundInChildren;

        return find(root->nextsibling, value);//Sử dụng đệ quy để tìm kiếm ở phần anh em
    }

    // Hàm thêm vào 
    void add(int parent, int value) {//Khai báo giá trị của node cha và giá trị thêm vào
        if (root == nullptr) {
            root = new node(parent); // Tree rỗng,gán gốc bằng node cha
            root->firstchildren = new node(value); // gán node con
            return;
        }

        node* Parent = find(root, parent);//Sử dụng đệ quy để tìm kiếm
        if (Parent == nullptr) return;//Trường hợp không tìm kiếm thấy node cha

        node* newnode = new node(value);//Khai báo node mới có giá trị cần thêm

        if (Parent->firstchildren == nullptr) {//Trường hợp node cha chưa có con nào
            Parent->firstchildren = newnode;
        }
        else {
            node* temp = Parent->firstchildren;//Khai báo temp là con đầu của node cha
            while (temp->nextsibling != nullptr) {//Sử dụng vòng lặp để tìm node con cuối cùng của node cha
                temp = temp->nextsibling;
            }
            temp->nextsibling = newnode;//Gán node mới vào cuối
        }
    }

    // Duyệt Preorder (Root -> Children -> Siblings)
    void preorder(node* root) {
        if (root == nullptr) return;//Điều kiện dừng đệ quy
        cout << root->data << " ";//In ra từng phần tử theo cách duyệt preorder
        preorder(root->firstchildren);//Đệ quy tại con
        preorder(root->nextsibling);//Đệ quy tại anh em
    }

    // Duyệt Postorder (Children -> Siblings -> Root)
    void postorder(node* root) {
        if (root == nullptr) return;
        postorder(root->firstchildren);
        cout << root->data << " ";
        postorder(root->nextsibling);
    }

    // Hàm check cây nhị phân
    bool binarytree(node* root) {
        if (root == nullptr) return true;//Điều kiện dừng đệ quy

        node* child = root->firstchildren;//Gán con đầu của node cha
        int count = 0;//Biến đếm

        while (child) {//Dùng vong lặp duyệt từng phần tử
            count++;
            if (count > 2) return false;//Nếu có nhiều hơn 2 con thì không phải cây nhị phân
            child = child->nextsibling;
        }

        return binarytree(root->firstchildren) && binarytree(root->nextsibling);//Đệ quy duyệt cả tree
    }

    // Duyệt inorder (Chỉ cho binarytree)
    void inorder(node* root) {
        if (root == nullptr) return;

         inorder(root->firstchildren); // Duyệt từ con bên trái
        cout << root->data << " ";  

        if (root->firstchildren && root->firstchildren->nextsibling) {
            inorder(root->firstchildren->nextsibling); // Phải
        }
    }

    // tính độ sâu của tree
    int height(node* root) {
        if (root == nullptr) return -1;//nếu không có gì độ sâu là -1 vì khi chỉ có gốc độ sâu bằng 0

        int maxheight = -1;
        node* child = root->firstchildren;//Duyệt từ con
        while (child) {
            maxheight = max(maxheight, height(child)); //Tìm độ sâu nhất 
            child = child->nextsibling;//Duyệt sang ae
        }

        return maxheight + 1;
    }
};

int main() {
    tree list;//Khai báo tree
    int n, m;
    cin >> n >> m;//m là số hành động ,n là phần tử

    while (m--) {
        int a, b;//Khai báo giá trị phần tử cha và con
        cin >> a >> b;
        list.add(a, b);//dùng hàm add để thêm
    }

    cout  << list.height(list.root) << endl;//IN ra độ sâu

    list.preorder(list.root);//duyệt preorder
    cout << endl;

    list.postorder(list.root);//Duyệt postorder
    cout << endl;

    if (list.binarytree(list.root)) {//Nếu là binary tree mới duyệt được inorder
        list.inorder(list.root);
        cout << endl;
    }
    else {//Nếu không phải binarytree
        cout << "NOT BINARY TREE\n";
    }

    return 0;
}
