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
Node *TimKiem(Node *T, int x)
{
    if (T == NULL)
    {
        return NULL;
    }
    else
    {
        if (T->dl == x)
        {
            return T;
        }
        else
        {
            if (x < T->dl)
            {
                return TimKiem(T->left, x);
            }
            else
            {
                return TimKiem(T->right, x);
            }
        }
    }
}
void DuyetLNR(Node *T)
{
    if (T != NULL)
    {
        DuyetLNR(T->left);
        cout << T->dl << " ";
        DuyetLNR(T->right);
        }
    }
    
}