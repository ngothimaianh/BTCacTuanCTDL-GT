#include <iostream>
using namespace std;

struct DaThuc{
    float heSo[100]; 
    int bac;        
};

void TaoMang(DaThuc &dt) {
    for(int i = 0; i < 100; i++) dt.heSo[i] = 0;
    dt.bac = 0;
}

void inDT(DaThuc dt, char ten[]) {
    cout << ten << " = ";
    bool DauTien = true;
    for(int i = dt.bac; i >= 0; i--) {
        if(dt.heSo[i] != 0) {
            if(!DauTien && dt.heSo[i] > 0) cout << " + ";
            cout << dt.heSo[i] << "x^" << i;
            DauTien = false;
        }
    }
    cout << endl;
}

int main() {
    DaThuc f, g, tong;
    TaoMang(f); TaoMang(g); TaoMang(tong);

    f.heSo[7] = 1; f.heSo[6] = 1; f.heSo[3] = 3; f.heSo[1] = 1; f.heSo[0] = 1;
    f.bac = 7;

    g.heSo[11] = 2; g.heSo[5] = 5; g.heSo[2] = 1; g.heSo[0] = 1;
    g.bac = 11;
    tong.bac = (f.bac > g.bac) ? f.bac : g.bac;
    for(int i = 0; i <= tong.bac; i++) {
        tong.heSo[i] = f.heSo[i] + g.heSo[i];
    }

    cout << "Ket qua: " << endl;
    inDT(f, "f(x)");
    inDT(g, "g(x)");
    inDT(tong, "Tong");

    return 0;
}