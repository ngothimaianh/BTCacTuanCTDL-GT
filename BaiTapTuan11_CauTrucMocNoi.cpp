#include <iostream>
#include <string>
using namespace std;

struct Node {
    string DuLieu; 
    Node* left;
    Node* right;

    Node(string gt) {
        DuLieu = gt;
        left = NULL;
        right = NULL;
    }
};
//Duyệt trước
void truoc(Node* p) {
    if (p != NULL) {
        cout << p->DuLieu << " ";
        truoc(p->left);
        truoc(p->right);
    }
}

// Duyệt giữa 
void giua(Node* p) {
    if (p != NULL) {
        giua(p->left);
        cout << p->DuLieu << " ";
        giua(p->right);
    }
}

// Duyệt sau 
void sau(Node* p) {
    if (p != NULL) {
        sau(p->left);
        sau(p->right);
        cout << p->DuLieu << " ";
    }
}
    // Tạo các cây
    // Cay đầy đủ
    Node* TaoCayDayDu() {
    Node* goc = new Node("1");
    goc->left = new Node("2");
    goc->right = new Node("3");
    goc->left->left = new Node("4");
    goc->left->right = new Node("5");
    goc->right->left = new Node("6");
    goc->right->right = new Node("7");
    return goc;
}
    // Cây lệch trái
    Node* CayLechTrai() {
    Node* root = new Node("1");
    root->left = new Node("2");
    root->left->left = new Node("3");
    root->left->left->left = new Node("4");
    root->left->left->left->left = new Node("5");
    return root;
}

// Cây lệch phải 
Node* CayLechPhai() {
    Node* root = new Node("1");
    root->right = new Node("2");
    root->right->right = new Node("3");
    root->right->right->right = new Node("4");
    root->right->right->right->right = new Node("5");
    return root;
}

// Cây Zigzac 
Node* CayZigzac() {
    Node* root = new Node("1");
    root->left = new Node("2");
    root->left->right = new Node("3");
    root->left->right->left = new Node("4");
    root->left->right->left->right = new Node("5");
    return root;
}

// Cây biểu thức: (a * b + c) / d - (e * f - h) ^ g
Node* CayBieuThuc() {
    Node* root = new Node("-");
    
    // Vế trái của dấu '-'
    root->left = new Node("/");
    root->left->right = new Node("d");
    root->left->left = new Node("+");
    root->left->left->right = new Node("c");
    root->left->left->left = new Node("*");
    root->left->left->left->left = new Node("a");
    root->left->left->left->right = new Node("b");

    // Vế phải của dấu '-'
    root->right = new Node("^");
    root->right->right = new Node("g");
    root->right->left = new Node("-");
    root->right->left->right = new Node("h");
    root->right->left->left = new Node("*");
    root->right->left->left->left = new Node("e");
    root->right->left->left->right = new Node("f");
    
    return root;
}

int main() {
    Node* Tree = CayBieuThuc();
    
    cout << "Duyet Truoc "; truoc(Tree); cout << endl;
    cout << "Duyet Giua: "; giua(Tree); cout << endl;
    cout << "Duyet Sau: "; sau(Tree); cout << endl;
    
    return 0;
}