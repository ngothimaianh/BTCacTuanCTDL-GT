#include <iostream>
using namespace std;

struct Node
{
    int dl;
    Node *left;
    Node *right;
};
Node *TaoNut(int x)
{
    Node *p = new Node;
    p->dl = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void ThemNode(Node *&T, int x)
{
    if (T == NULL)
    {
        T = TaoNut(x);
    }
    else
    {
        if (x < T->dl)
        {
            ThemNode(T->left, x);
        }
        else
        {
            ThemNode(T->right, x);
        }
    }
}