#include<iostream>
using namespace std;
const int MAX = 20;
string TenTinh[MAX] = 
{   "Ha Noi",
    "Hai Duong", 
    "Hung Yen",
    "Phu Ly",
    "Hoa Binh",
    "Son Tay",
    "Thai Nguyen",
    "Bac Ninh",
    "Bac Giang",
    "Uong Bi",
    "Hai Phong"}
};
int a[MAX][MAX];
int n = 11;
struct Queue
{
    int data[MAX];
    int dau;
    int cuoi;
};

void KhoiTaoQueue(Queue &q)
{
    q.dau = 0;
    q.cuoi = -1;
}

bool Rong(Queue q)
{
    return q.dau > q.cuoi;
}

void Enqueue(Queue &q, int x)
{
    q.cuoi++;
    q.data[q.cuoi] = x;
}
int Dequeue(Queue &q)
{
    int x = q.data[q.dau];
    q.dau++;
    return x;
}
void ThemCanh(int u, int v)
{
    a[u][v] = 1;
    a[v][u] = 1;
}
void BFS(int start)
{
    bool visited[MAX];

    for(int i=0;i<n;i++)
        visited[i] = false;

    Queue q;
    KhoiTaoQueue(q);

    visited[start] = true;
    Enqueue(q,start);

    while(!Rong(q))
    {
        int u = Dequeue(q);
    cout << TenTinh[u] << endl;

        for(int v=0;v<n;v++)
        {
            if(a[u][v] == 1 && visited[v] == false)
            {
                visited[v] = true;
                Enqueue(q,v);
            }
        }
    }
}
int main()
{
    ThemCanh(0,1);
    ThemCanh(1,2);
    ThemCanh(2,3);
    ThemCanh(3,0);
    ThemCanh(4,0);
    ThemCanh(5,0);
    ThemCanh(6,0);
    ThemCanh(0,7);
    ThemCanh(7,8);
    ThemCanh(8,9);
    ThemCanh(7,9);
    ThemCanh(9,10);
    ThemCanh(1,10);

    cout << "BFS bat dau tu Ha Noi:\n\n";

    BFS(0);

    return 0;
}
2. BFS với DANH SÁCH LIÊN KẾT

Ở đây mới đúng phần cô thường thích hỏi.

Node
struct Node
{
    int info;
    Node* next;
};

Mỗi đỉnh sẽ có một danh sách các đỉnh kề.

Code đầy đủ
#include <iostream>
using namespace std;

const int MAX = 20;

string tenTinh[MAX] =
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

//================ NODE ==================

struct Node
{
    int info;
    Node* next;
};

//================ DANH SACH KE ==================

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
    Node* p = TaoNode(x);

    p->next = head;
    head = p;
}

void ThemCanh(int u,int v)
{
    ThemDau(adj[u],v);
    ThemDau(adj[v],u);
}

//================ HANG DOI ==================

struct Queue
{
    int data[MAX];
    int front;
    int rear;
};

void KhoiTaoQueue(Queue &q)
{
    q.front = 0;
    q.rear = -1;
}

bool Rong(Queue q)
{
    return q.front > q.rear;
}

void Enqueue(Queue &q,int x)
{
    q.rear++;
    q.data[q.rear] = x;
}

int Dequeue(Queue &q)
{
    int x = q.data[q.front];
    q.front++;

    return x;
}

//================ BFS ==================

void BFS(int start)
{
    bool visited[MAX];

    for(int i=0;i<n;i++)
        visited[i] = false;

    Queue q;
    KhoiTaoQueue(q);

    visited[start] = true;

    Enqueue(q,start);

    while(!Rong(q))
    {
        int u = Dequeue(q);

        cout << tenTinh[u] << endl;

        Node* p = adj[u];

        while(p != NULL)
        {
            int v = p->info;

            if(visited[v] == false)
            {
                visited[v] = true;

                Enqueue(q,v);
            }

            p = p->next;
        }
    }
}

int main()
{
    KhoiTao();

    ThemCanh(0,1);
    ThemCanh(1,2);
    ThemCanh(2,3);
    ThemCanh(3,0);
    ThemCanh(4,0);
    ThemCanh(5,0);
    ThemCanh(6,0);
    ThemCanh(0,7);
    ThemCanh(7,8);
    ThemCanh(8,9);
    ThemCanh(7,9);
    ThemCanh(9,10);
    ThemCanh(1,10);

    cout << "BFS tu Ha Noi:\n\n";

    BFS(0);

    return 0;
}