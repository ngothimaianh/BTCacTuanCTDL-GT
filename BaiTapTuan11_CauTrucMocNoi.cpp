#include <iostream>
#include <string>
using namespace std;

struct Node {
    string DuLieu; 
    Node* left;
    Node* right;

    Node(string gt) {
        DuLieu = gt;
        left = NULL;
        right = NULL;
    }
};