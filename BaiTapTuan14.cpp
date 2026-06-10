#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
}
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
    p->left = NULL
    p->right = NULL;
    p->height = 0;
    return p;
}
void XoayDonTrai(Node* k2){
    Node* k1 = k2 -> left;
    k2 -> left = k1->right
    k1 -> right = k2;
    k2 -> height = max(ChieuCao(k2->left), ChieuCao(k2->right)) + 1;
    k1 -> height = max(ChieuCao(k1->left), ChieuCao(k1->right)) + 1;
    k2 = k1;
}
void XoayKepTraiPhai(Node* k3){
    XoayDonTrai(k3->left);
    XoayDonPhai(k3);
}
voide XoayKepPhaiTrai(Node* k1){
    XoayDonPhai(k1->right);
    XoayDonTrai(k1);
}
]