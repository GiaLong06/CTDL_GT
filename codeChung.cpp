#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct LienHe {
    string ten;
    string sdt;
};
struct Node {
    LienHe duLieu;
    Node* prev;
    Node* next;
};
struct DanhBa {
    Node* head;
    Node* tail;
};
struct NodeLichSu {
    string sdt;
    NodeLichSu* next;
};
struct LichSuCuocGoi {
    NodeLichSu* head;
};