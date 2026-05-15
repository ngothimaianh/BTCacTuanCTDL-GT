#include <iostream>
#include <string>

using namespace std;
const int MAX = 100;
string Cay[MAX];
string Rong = "NULL"; 

void TaoCayRong() {
    for (int i = 0; i < MAX; i++) {
        Cay[i] = Rong;
    }
}

void DuyetTruoc(int i) {
    if (i < MAX && Cay[i] != Rong) {
        cout << Cay[i] << " ";            
        DuyetTruoc(2 * i + 1); 
        DuyetTruoc(2 * i + 2); 
    }
}

void DuyetGiua(int i) {
    if (i < MAX && Cay[i] != Rong) {
        DuyetGiua(2 * i + 1);    
        cout << Cay[i] << " ";          
        DuyetGiua(2 * i + 2);    
    }
}

void DuyetSau(int i) {
    if (i < MAX && Cay[i] != Rong) {
        DuyetSau(2 * i + 1);      
        DuyetSau(2 * i + 2);      
        cout << Cay[i] << " ";          
    }
}

void TaoCayDayDu() {
    TaoCayRong();
    for(int i = 0; i < 7; i++) {
        Cay[i] = to_string(i + 1);
    }
}

void TaoCayLechTrai() {
    TaoCayRong();
    int index = 0;
    for(int i = 1; i <= 5; i++) {
        Cay[index] = to_string(i);
        index = 2 * index + 1; 
    }
}

void TaoCayLechPhai() {
    TaoCayRong();
    int index = 0;
    for(int i = 1; i <= 5; i++) {
        Cay[index] = to_string(i);
        index = 2 * index + 2; 
    }
}

void TaoCayZigZac() {
    TaoCayRong();
    Cay[0] = "1"; 
    Cay[1] = "2"; 
    Cay[4] = "3"; 
    Cay[9] = "4";
    Cay[20] = "5";
}

void TaoCayBieuThuc() {
    TaoCayRong();
    Cay[0] = "-";                       
    Cay[1] = "/"; Cay[2] = "^";       
    Cay[3] = "+"; Cay[4] = "d";        
    Cay[5] = "-"; Cay[6] = "g";     
    Cay[7] = "*"; Cay[8] = "c";         
    Cay[11] = "*"; Cay[12] = "h";    
    Cay[15] = "a"; Cay[16] = "b";       
    Cay[23] = "e"; Cay[24] = "f";       
}

int main() {
   
    cout << "\nCay Bieu Thuc: " << endl;
    TaoCayBieuThuc();
    cout << "Duyet Truoc: "; DuyetTruoc(0);
    cout << "\nDuyet Giua: "; DuyetGiua(0);
    cout << "\nDuyet Sau: "; DuyetSau(0);
    
    return 0; 
} 