
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

void khoiTao(DanhBa &db) {
    db.head = NULL;
    db.tail = NULL ;
}

void themLienHe(DanhBa &db, string ten, string sdt) {
    Node* moi = new Node;

    moi->duLieu.ten = ten;
    moi->duLieu.sdt = sdt;
    moi->prev = NULL;
    moi->next = NULL;

    if (db.head == NULL) {
        db.head = moi;
        db.tail = moi;
    } else {
        moi->prev = db.tail;
        db.tail->next = moi;
        db.tail = moi;
    }

    cout << "Them lien he thanh cong!\n";
}

bool xoaLienHe(DanhBa &db, string sdt) {
    Node* p = db.head;

    while (p != NULL && p->duLieu.sdt != sdt) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Khong tim thay lien he!\n";
        return false;
    }

    if (p->prev != NULL) {
        p->prev->next = p->next;
    } else {
        db.head = p->next;
    }

    if (p->next != NULL) {
        p->next->prev = p->prev;
    } else {
        db.tail = p->prev;
    }

    delete p;

    cout << "Xoa lien he thanh cong!\n";
    return true;
}


void hienThiDanhBa(DanhBa &db) {
    if (db.head == NULL) {
        cout << "Danh ba dang rong!\n";
        return;
    }

    Node* p = db.head;

    cout << "\n DANH SACH LIEN HE \n";

    while (p != NULL) {
        cout << "Ten: " << p->duLieu.ten << endl;
        cout << "So dien thoai: " << p->duLieu.sdt << endl;
        

        p = p->next;
    }
}

void giaiPhongDanhBa(DanhBa &db) {
    Node* p = db.head;

    while (p != NULL) {
        Node* tam = p;
        p = p->next;
        delete tam;
    }

    db.head = NULL;
    db.tail = NULL;
}

int main() {
    DanhBa db;
    khoiTao(db);

    int luaChon;
    string ten, sdt;

    do {
        cout << "\nQUAN LY DANH BA \n";
        cout << "1. Them lien he\n";
        cout << "2. Xoa lien he\n";
        cout << "3. Hien thi danh ba\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";

        if (!(cin >> luaChon)) {
            cout << "Vui long nhap lua chon bang so!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore(10000, '\n');

        switch (luaChon) {
            case 1:
                cout << "Nhap ten: ";
                getline(cin, ten);

                cout << "Nhap so dien thoai: ";
                getline(cin, sdt);

                themLienHe(db, ten, sdt);
                break;

            case 2:
                cout << "Nhap so dien thoai can xoa: ";
                getline(cin, sdt);

                xoaLienHe(db, sdt);
                break;

            case 3:
                hienThiDanhBa(db);
                break;

            case 0:
                cout << "Ket thuc chuong trinh!\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (luaChon != 0);

    giaiPhongDanhBa(db);

    return 0;
}

