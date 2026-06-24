#include <iostream>
#include <queue>
#include <string>
using namespace std;
const int MAX = 11;
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
int A[MAX][MAX];
bool visited[MAX];
void KhoiTaoDoThi()
{
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            A[i][j] = 0;
        }
    }
    auto ThemCanh = [&](int u, int v)
    {
        A[u][v] = 1;
        A[v][u] = 1;
    };
ThemCanh(0,1);   // Ha Noi - Hai Duong
    ThemCanh(1,2);   // Hai Duong - Hung Yen
    ThemCanh(2,3);   // Hung Yen - Phu Ly
    ThemCanh(3,0);   // Phu Ly - Ha Noi

    ThemCanh(0,4)   // Hoa Binh
    ThemCanh(0,5);   // Son Tay
    ThemCanh(0,6);   // Thai Nguyen

    ThemCanh(0,7);   // Bac Ninh
    ThemCanh(7,8);   // Bac Giang
    ThemCanh(8,9);   // Uong Bi

    ThemCanh(7,9);   // Bac Ninh - Uong Bi
    ThemCanh(9,10);  // Uong Bi - Hai Phong

    ThemCanh(1,10)
    bool DFS(int u, int t)
{
    visited[u] = true;

    if(u == t)
        return true;

    for(int v = 0; v < MAX; v++)
    {
        if(A[u][v] == 1 & !visited[v])
        {
            if(DFS(v, t))
                return true;
        }
    }

    return false;
}
