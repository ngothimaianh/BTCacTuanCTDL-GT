#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};
int ChieuCao(Node* p) {
    if (p == NULL)
        return -1;
    return p->height;
}
int max(int a, int b) {
    return (a > b) ? a : b;

}
Node* TaoNut(int x) {
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    p->height = 0;
    return p;
}
void XoayDonTrai(Node* &k2){
       Node* k1 = k2->left;

    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(ChieuCao(k2->left),
                     ChieuCao(k2->right)) + 1;

    k1->height = max(ChieuCao(k1->left),
                     k2->height) + 1;

    k2 = k1;
}
void XoayDonPhai(Node* &k1){
    Node* k2 = k1->right;

    k1->right = k2->left;
    k2->left = k1;

    k1->height = max(ChieuCao(k1->left),
                     ChieuCao(k1->right)) + 1;

    k2->height = max(ChieuCao(k2->right),
                     k1->height) + 1;

    k1 = k2;
}
void XoayKepTraiPhai(Node* &k3){
    XoayDonPhai(k3->left);
    XoayDonTrai(k3);
}
void XoayKepPhaiTrai(Node* &k1){
    XoayDonTrai(k1->right);
    XoayDonPhai(k1);
}
void Chen(int x, Node* &t){
    if (t == NULL)
        t = TaoNut(x);
    else if (x < t->data) {
        Chen(x, t->left);
        if (ChieuCao(t->left) - ChieuCao(t->right) == 2) {
            if (x < t->left->data)
                XoayDonTrai(t);
            else
                XoayKepTraiPhai(t);
        }
    }
    else if (x > t->data) {
        Chen(x, t->right);
        if (ChieuCao(t->right) - ChieuCao(t->left) == 2) {
            if (x > t->right->data)
                XoayDonPhai(t);
            else
                XoayKepPhaiTrai(t);
        }
    }
    t->height = max(ChieuCao(t->left), ChieuCao(t->right)) + 1;

}
void DuyetLNR(Node* &T) {
    if (T != NULL) {
        DuyetLNR(T->left);
        cout << T->data << " ";
        DuyetLNR(T->right);
    }
}
void DuyetNLR(Node* &T) {
    if (T != NULL) {
        cout << T->data << " ";
        DuyetNLR(T->left);
        DuyetNLR(T->right);
    }
}
void DuyetLRN(Node* &T) {
    if (T != NULL) {
        DuyetLRN(T->left);
        DuyetLRN(T->right);
        cout << T->data << " ";
    }
}

}
int main (){
    Node*T =NULL;
    int a[]= {32, 51, 27, 83, 96, 11, 45, 75, 66};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++) {
        Chen(a[i], T);
    }
    cout << "Duyet LNR: ";
    DuyetLNR(T);
    cout << "\nDuyet NLR: ";
    DuyetNLR(T);
    cout << "\nDuyet LRN: ";
    DuyetLRN(T);

    return 0;
}