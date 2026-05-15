#include <iostream>
#include <string>
using namespace std;

// Cấu trúc Node cô dạy
struct Node {
    string data; // Để dùng cho cả số và toán tử (+, -, *, /)
    Node* left;
    Node* right;

    Node(string val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};