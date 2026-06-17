#include <iostream>
using namespace std;
const int MAX = 20;

string TenTinh[MAX] =
{
    "Ha Noi",
    "Hai Duong",
    "Hung Yen",
    "Phu Ly",
    "Hoa Binh",
    "Son Tay",
    "Thai Nguyen",
    "Bac Ninh",
    "Bac Giang",
    "Uong Bi",
    "Hai Phong"
};
int n = 11;
struct Node
{
    int info;
    Node* next;
};
Node* adj[MAX];

void KhoiTao()
{
    for(int i=0;i<n;i++)
        adj[i] = NULL;
}

Node* TaoNode(int x)
{
    Node* p = new Node;

    p->info = x;
    p->next = NULL;

    return p;
    }

void ThemDau(Node* &head,int x)
{
    Node* p = TaoNode(x)

    p->next = head;
    head = p;
}

void ThemCanh(int u,int v)
{
    ThemDau(adj[u],v);
    ThemDau(adj[v],u);
}
