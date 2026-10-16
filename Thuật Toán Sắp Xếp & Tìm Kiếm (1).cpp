#include <iostream>
#include <string>

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

void ThemVaoCuoi(DanhBa &db, string ten, string sdt) {
    Node* p = new Node;
    p->duLieu.ten = ten;
    p->duLieu.sdt = sdt;
    p->next = NULL;
    p->prev = db.tail;

    if (db.head == NULL) {
        db.head = db.tail = p;
    } else {
        db.tail->next = p;
        db.tail = p;
    }
}

void InDanhBa(DanhBa db) {
    Node* p = db.head;
    while (p != NULL) {
        cout << "- " << p->duLieu.ten << " : " << p->duLieu.sdt << endl;
        p = p->next;
    }
}

void SapXepDanhBa(DanhBa &db) {
    if (db.head == NULL || db.head->next == NULL) return;

    bool swapped;
    Node* p;
    Node* lastPtr = NULL;

    do {
        swapped = false;
        p = db.head;

        while (p->next != lastPtr) {
            if (p->duLieu.ten > p->next->duLieu.ten) {
                LienHe temp = p->duLieu;
                p->duLieu = p->next->duLieu;
                p->next->duLieu = temp;
                swapped = true;
            }
            p = p->next;
        }
        lastPtr = p;
    } while (swapped);
}

void TimKiemTheoTen(DanhBa db, string tenCantim) {
    Node* p = db.head;
    bool timThay = false;

    cout << "\nKet qua tim kiếm voi tenCantim '" << tenCantim << "':" << endl;
    while (p != NULL) {
        if (p->duLieu.ten.find(tenCantim) == 0) {
            cout << " -> " << p->duLieu.ten << " : " << p->duLieu.sdt << endl;
            timThay = true;
        }
        p = p->next;
    }

    if (!timThay) {
        cout << " -> Khong tim thay lien he nao phu hop!" << endl;
    }
}

int main() {
    DanhBa db = {NULL, NULL};
    ThemVaoCuoi(db, "Tran Hoai Linh", "0912345678");
    ThemVaoCuoi(db, "Vo Gia Long", "0901234567");
    ThemVaoCuoi(db, "Nguyen Thi Thanh Ha", "0987654321");
    ThemVaoCuoi(db, "Hoang Ha Hanh Ngan", "0933445566");
    ThemVaoCuoi(db, "Ung Thanh Nam", "0934567890");
    ThemVaoCuoi(db, "Vo Thanh Keonho", "0123456789");
    ThemVaoCuoi(db, "Nguyen Le Martin", "0987654321");
    ThemVaoCuoi(db, "Tran Thi Seohyun", "0933445522");
    ThemVaoCuoi(db, "Tran Thi Cardi B", "0998877665");
    ThemVaoCuoi(db, "Tran Thi Dung", "0224433771");

    cout << "=== DANH BA BAN DAU ===" << endl;
    InDanhBa(db);

    SapXepDanhBa(db);
    cout << "\n=== DANH BA SAU KHI SAP XEP===" << endl;
    InDanhBa(db);

    TimKiemTheoTen(db, "Nguyen"); 
    TimKiemTheoTen(db, "Tran");
    TimKiemTheoTen(db, "Vo"); 
    TimKiemTheoTen(db, "Le");   

    return 0;
}