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
void KhoiTaoDanhBa(DanhBa &db) {
    db.head = NULL;
    db.tail = NULL;
}
Node* TaoNode(LienHe lh) {
    Node* nodeMoi = new Node;
    nodeMoi->duLieu = lh;
    nodeMoi->prev = NULL;
    nodeMoi->next = NULL;
    return nodeMoi;
}
void GiaiPhongBoNho(DanhBa &db) {
    Node* p = db.head;
    while (p != NULL) {
        Node* nodeCanXoa = p; 
        p = p->next;          
        delete nodeCanXoa;    
    }
    db.head = NULL;
    db.tail = NULL;
    cout << "[He thong] Da giai phong toan bo bo nho cua Danh Ba!\n";
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
    cout << "\nKet qua tim kiem voi tenCantim '" << tenCantim << "':" << endl;
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
            themLienHe(db, ten, sdt);
            dem++;
        }
    }
    file.close();
    cout << "-> Da doc thanh cong " << dem << " lien he tu file '" << fileName << "'!\n";
}
void KhoiTaoLichSu(LichSuCuocGoi &ls) {
    ls.head = NULL;
}
void GhiNhanCuocGoi(LichSuCuocGoi &ls, string sdt) {
    NodeLichSu* nodeMoi = new NodeLichSu;
    nodeMoi->sdt = sdt;
    nodeMoi->next = ls.head;
    ls.head = nodeMoi;
    
    cout << "Dang goi toi so: " << sdt << "...\n";
    cout << "[Lich su] Da ghi nhan cuoc goi thanh cong!\n";
}
void HienThiLichSu(LichSuCuocGoi ls) {
    if (ls.head == NULL) {
        cout << "[Lich su] Chua co cuoc goi nao duoc ghi nhan!\n";
        return;
    }
    cout << "\n--- LICH SU CUOC GOI GAN DAY (MOI NHAT O DAU) ---\n";
    NodeLichSu* p = ls.head;
    int stt = 1;
    while (p != NULL) {
        cout << stt++ << ". So dien thoai: " << p->sdt << "\n";
        p = p->next;
    }
}
void GiaiPhongLichSu(LichSuCuocGoi &ls) {
    NodeLichSu* p = ls.head;
    while (p != NULL) {
        NodeLichSu* temp = p;
        p = p->next;
        delete temp;
    }
    ls.head = NULL;
}
int main() {
    DanhBa db;
    KhoiTaoDanhBa(db); // Kh?i t?o danh b?
    LichSuCuocGoi lichSu;
    KhoiTaoLichSu(lichSu); // Kh?i t?o l?ch s? cu?c g?i
    int luaChon;
    string ten, sdt;
    do {
        cout << "\n================ MENU QUAN LY DANH BA & LICH SU ================\n";
        cout << "1. Them lien he moi\n";
        cout << "2. Xoa lien he theo SDT\n";
        cout << "3. Hien thi danh ba (Duyet xuoi / Mac dinh)\n";
        cout << "4. Hien thi danh ba (Duyet nguoc)\n";
        cout << "5. Sap xep danh ba theo ten (A-Z)\n";
        cout << "6. Tim kiem theo tien to ten\n";
        cout << "7. Thuc hien cuoc goi (Ghi nhan lich su)\n";
        cout << "8. Xem lich su cuoc goi gan day\n";
        cout << "9. Ghi danh ba ra file\n";
        cout << "10. Doc danh ba tu file\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "================================================================\n";
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
                duyetXuoi(db);
                break;
            case 4:
                duyetNguoc(db);
                break;
            case 5:
                SapXepDanhBa(db);
                cout << "-> Da sap xep danh ba theo ten thanh cong!\n";
                break;
            case 6:
                cout << "Nhap tien to ten can tim: ";
                getline(cin, ten);
                TimKiemTheoTen(db, ten);
                break;
            case 7: {
                cout << "Nhap so dien thoai muon goi: ";
                getline(cin, sdt);
                GhiNhanCuocGoi(lichSu, sdt);
                break;
            }
            case 8:
                HienThiLichSu(lichSu);
                break;
            case 9:
                ghiFile(db, "danhba.txt");
                break;
            case 10:
                docFile(db, "danhba.txt");
                break;
            case 0:
                GiaiPhongBoNho(db);
                GiaiPhongLichSu(lichSu);
                cout << "Da thoat va giai phong toan bo bo nho thanh cong!\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (luaChon != 0);
    return 0;
}