#include <iostream>
using namespace std;

struct Node {
    float heso;
    int mu;
    Node* next;
};

Node* TaoNode(float hs, int m) {
    Node* p = new Node;
    p->heso = hs;
    p->mu = m;
    p->next = NULL;
    return p;
}

// Thêm một hạng tử vào cuối danh sách
void ThemCuoi(Node* &head, float hs, int m) {
    Node* p = TaoNode(hs, m);
    if (head == NULL) head = p;
    else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = p;
    }
}
void inDT(Node* head, char ten[]) {
    cout << ten << " = ";
    Node* t = head;
    while (t != NULL) {
        cout << t->heso << "x^" << t->mu;
        if (t->next != NULL) cout << " + ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    Node *f = NULL, *g = NULL, *tong = NULL;

    ThemCuoi(f, 1, 7); ThemCuoi(f, 1, 6); ThemCuoi(f, 3, 3); ThemCuoi(f, 1, 1); ThemCuoi(f, 1, 0);

    ThemCuoi(g, 2, 11); ThemCuoi(g, 5, 5); ThemCuoi(g, 1, 2); ThemCuoi(g, 1, 0);

    Node *p1 = f, *p2 = g;
    while (p1 != NULL || p2 != NULL) {
        if (p1 != NULL && (p2 == NULL || p1->mu > p2->mu)) {
            ThemCuoi(tong, p1->heso, p1->mu);
            p1 = p1->next;
        } 
        else if (p2 != NULL && (p1 == NULL || p2->mu > p1->mu)) {
            ThemCuoi(tong, p2->heso, p2->mu);
            p2 = p2->next;
        } 
        else { 
            float TongHS = p1->heso + p2->heso;
            if (TongHS != 0) ThemCuoi(tong, TongHS, p1->mu);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    cout << "Ket qua: " << endl;
    inDT(f, "f(x)");
    inDT(g, "g(x)");
    inDT(tong, "Tong");

    return 0;
}