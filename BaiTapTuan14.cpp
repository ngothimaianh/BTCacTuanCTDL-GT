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