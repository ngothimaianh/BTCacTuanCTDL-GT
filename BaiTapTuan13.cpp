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

int main(){
int a[]={2001, 2002, 2006, 2007, 2008, 2004, 2005, 2001, 1999, 2004};
int n = 10;
{
    Node* T= NULL;
    for(int i=0; i<n; i++)
    {
        ThemNode(T, a[i]);
    }
    cout<<"Cay nhi phan tim kiem sau khi duyet LNR: "<<endl;
    DuyetLNR(T);
    int x = 2004;
    Node* p = TimKiem(T, x);
    if(p != NULL)
    {
        cout<<"\nTim thay "<<x<<" trong cay nhi phan tim kiem."<<endl;
    }
    else
    {
        cout<<"\nKhong tim thay "<<x<<" trong cay nhi phan tim kiem."<<endl;
    }
     return 0;
}
}