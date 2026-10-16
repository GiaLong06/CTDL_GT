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

    DanhBa() {
        head = NULL;
        tail = NULL;
    }
};
Node* taoNode(string ten, string sdt) {
    Node* newNode = new Node();
    newNode->duLieu.ten = ten;
    newNode->duLieu.sdt = sdt;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void themCuoi(DanhBa& db, string ten, string sdt) {
    Node* newNode = taoNode(ten, sdt);
    if (db.head == NULL) {
        db.head = db.tail = newNode;
    } else {
        db.tail->next = newNode;
        newNode->prev = db.tail;
        db.tail = newNode;
    }
}
void duyetXuoi(const DanhBa& db) {
    if (db.head == NULL) {
        cout << "Danh ba hien tai dang rong.\n";
        return;
    }
    cout << "\n================ DANH SACH LIEN HE (DUYET XUOI) ================\n";
    Node* temp = db.head;
    int stt = 1;
    while (temp != NULL) {
        cout << stt++ << ". " << temp->duLieu.ten << " - " << temp->duLieu.sdt << endl;
        temp = temp->next;
    }
}
void duyetNguoc(const DanhBa& db) {
    if (db.tail == NULL) {
        cout << "Danh ba hien tai dang rong.\n";
        return;
    }
    cout << "\n================ DANH SACH LIEN HE (DUYET NGUOC) ================\n";
    Node* temp = db.tail;
    int stt = 1;
    while (temp != NULL) {
        cout << stt++ << ". " << temp->duLieu.ten << " - " << temp->duLieu.sdt << endl;
        temp = temp->prev;
    }
}
void ghiFile(const DanhBa& db, string fileName) {
    ofstream file(fileName.c_str());
    if (!file.is_open()) {
        cout << "Loi: Khong the mo file de ghi!\n";
        return;
    }

    Node* temp = db.head;
    while (temp != NULL) {
        file << temp->duLieu.ten << endl;
        file << temp->duLieu.sdt << endl;
        temp = temp->next;
    }
    file.close();
    cout << "-> Da ghi du lieu danh ba vao file '" << fileName << "' thanh cong!\n";
}
void docFile(DanhBa& db, string fileName) {
    ifstream file(fileName.c_str());
    if (!file.is_open()) {
        cout << "Loi: Khong the mo file de doc!\n";
        return;
    }
    string ten, sdt;
    int dem = 0;
    while (getline(file, ten) && getline(file, sdt)) {
        if (!ten.empty() && !sdt.empty()) {
            themCuoi(db, ten, sdt);
            dem++;
        }
    }
    file.close();
    cout << "-> Da doc thanh cong " << dem << " lien he tu file '" << fileName << "'!\n";
}
void giaiPhong(DanhBa& db) {
    Node* temp = db.head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    db.head = db.tail = NULL;
}
struct NodeLichSu {
    string sdt;
    NodeLichSu* next;
};
struct LichSuCuocGoi {
    NodeLichSu* head;

    LichSuCuocGoi() {
        head = NULL;
    }
};
int main() {
    DanhBa db;
    string fileName = "danhba.txt";
    cout << "1. KHOI TAO VA GHI FILE:\n";
    themCuoi(db, "Nguyen Van A", "0901234567");
    themCuoi(db, "Tran Thi B", "0987654321");
    themCuoi(db, "Le Van C", "0911223344");
    ghiFile(db, fileName);
    giaiPhong(db);
    cout << "\n2. NAP DU LIEU TU FILE VA DUYET:\n";
    DanhBa dbMoi;
    docFile(dbMoi, fileName);
    duyetXuoi(dbMoi);
    duyetNguoc(dbMoi);
    giaiPhong(dbMoi);
    return 0;
}
